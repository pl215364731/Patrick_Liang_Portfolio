`timescale 1ns/1ns
module arbiter(
    input logic clk, rst_n, req, dly, done, reset,
    output logic gnt, tout
);

logic [1:0] counter;

enum logic [4:0] {
    S_IDLE  = 5'b00001,
    S_BBUSY = 5'b00010,
    S_BWAIT = 5'b00100,
    S_BFREE = 5'b01000,
    S_TOUT  = 5'b10000
} current_state, next_state;

always_ff @(posedge clk) begin
    if(!rst_n) begin
        counter <= 2'd0;
        current_state <= S_IDLE;
    end
    else begin
        current_state <= next_state;
        if(current_state == S_BBUSY)
            counter <= counter + 1;
        else
            counter <= 2'd0;

    end
end

always_ff @(posedge clk) begin
   
end

// Next state logic
always_comb begin
    unique case(current_state)
        S_IDLE: begin
            if(req) next_state = S_BBUSY;
            else next_state = S_IDLE;
        end
        S_BBUSY: begin
            if(counter == 2'b1) next_state = S_TOUT;
            else if(!done) next_state = S_BBUSY;
            else if(dly) next_state = S_BWAIT;
            else next_state = S_BFREE;
        end
        S_BWAIT: begin
            if(!dly) next_state = S_BFREE;
            else next_state = S_BWAIT;
        end
        S_BFREE: begin
            if(req) next_state = S_BBUSY;
            else next_state = S_IDLE;
        end
        S_TOUT: begin
            if(reset) begin
                if(dly)
                    next_state = S_BWAIT;
                else
                    next_state = S_BFREE;
            end
            else begin
                next_state = S_TOUT;
            end
        end
    endcase
end

// Output logic
always_comb begin
    unique case(current_state)
        S_IDLE: begin
            gnt = 1'b0;
            tout = 1'b0;
        end
        S_BBUSY: begin
            gnt = 1'b1;
            tout = 1'b0;
        end
        S_BWAIT: begin
            gnt = 1'b1;
            tout = 1'b0;
        end
        S_BFREE: begin
            gnt = 1'b0;
            tout = 1'b0;
        end
        S_TOUT: begin
            gnt = 1'b0;
            tout = 1'b1;
        end
    endcase
end

initial begin
    forever begin
        @(current_state) $display("%t : [state] becomes: %0s", $time, current_state.name());
        $display("%t : [gnt] becomes: %0b", $time, gnt);
        $display("%t : [tout] becomes: %0b", $time, tout);
    end
end

endmodule