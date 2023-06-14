module controller(
    input logic [2:0] req,
    input logic [2:0] done,
    input logic reset, clk,
    output logic [3:0] mstate,
    output logic [1:0] accmodule
);
logic m2_m3_alt; //M2 is 0, M3 is 1
logic [1:0] clk_counter;
logic interrupt;

enum logic [3:0] {
    IDLE = 4'b0001,
    M1   = 4'b0010,
    M2   = 4'b0100,
    M3   = 4'b1000
} current_state, next_state;

// output logic
always_comb begin
    case(current_state)
        IDLE: accmodule = 2'b00;
        M1: accmodule = 2'b01;
        M2: accmodule = 2'b10;
        M3: accmodule = 2'b11;
    endcase
end

assign mstate = current_state;

// internal logic
always_ff @ (posedge clk or posedge reset) begin
    if(reset) begin
        m2_m3_alt <= 1'b0;
        clk_counter <= 2'b00;
        interrupt <= 1'b0;
    end
    else begin
        // M2 M3 alternating logic
        if(req[1] & req[2] & (next_state == M2 | next_state == M3))
            m2_m3_alt <= ~m2_m3_alt;
        
        // interrupt logic
        if((current_state == M2 | current_state == M3) & next_state == M1)
            interrupt <= 1'b1;
        if(current_state == M1 & next_state != M1)
            interrupt <= 1'b0;

        // clk_counter logic
        if(current_state != next_state)
            clk_counter <= 2'b00;
        else
            clk_counter <= clk_counter + 1;

    end
end

// current_state logic
always_ff @ (posedge clk or posedge reset) begin
    if(reset)
        current_state <= IDLE;
    else
        current_state <= next_state;
end

// next_state logic
always_comb begin
    case(current_state)
        IDLE: begin
            if(req[0]) 
                next_state = M1;
            else if(req[1] & req[2])
                next_state = m2_m3_alt ? M3 : M2;
            else if(req[1])
                next_state = M2;
            else if(req[2])
                next_state = M3;
            else
                next_state = IDLE;
        end
        M1: begin
            if((clk_counter == 2'b1 & interrupt) | done[0]) begin
                if(req[1] & req[2])
                    next_state = m2_m3_alt ? M3 : M2;
                else if(req[1])
                    next_state = M2;
                else if(req[2])
                    next_state = M3;
                else
                    next_state = IDLE;
            end
            else
                next_state = M1;
        end
        M2: begin
            if(req[0])
                next_state = M1;
            else if(clk_counter == 2'b1 | done[1]) begin
                if(req[0]) 
                    next_state = M1;
                else if(req[2])
                    next_state = M3;
                else
                    next_state = IDLE;
            end
            else
                next_state = M2;
        end
        M3: begin
            if(req[0])
                next_state = M1;
            else if(clk_counter == 2'b1 | done[2]) begin
                if(req[0]) 
                    next_state = M1;
                else if(req[1])
                    next_state = M2;
                else
                    next_state = IDLE;
            end
            else
                next_state = M3;
        end
    endcase
end


endmodule