module count #(
    parameter WIDTH = 8
)(
    input logic [WIDTH-1:0] a_in,
    input logic [1:0] sel,
    input logic clk,
    input logic start,
    input logic rst,
    output logic done,
    output logic [WIDTH-1:0] cntout
);

logic [WIDTH-1:0] a_in_d;
logic [WIDTH-1:0] count_0;
logic [WIDTH-1:0] count_1;
logic [$clog2(WIDTH)-1:0] counter;

enum logic [3:0] {
    IDLE  = 4'b0001,
    COUNT = 4'b0010,
    DONE_0  = 4'b0100,
    DONE_1  = 4'b1000
} current_state, next_state;

// internal logic
always_ff @ (posedge clk or posedge rst) begin
    if(rst) begin
        a_in_d <= '0;
        count_0 <= '0;
        count_1 <= '0;
        counter <= '0;
    end
    else begin
        case(current_state)
            IDLE: begin
                a_in_d <= a_in;
                count_0 <= '0;
                count_1 <= '0;
                counter <= '0;
            end
            COUNT: begin
                if(a_in_d[counter] == 1) 
                    count_1 <= count_1 + 1;
                if(a_in_d[counter] == 0) 
                    count_0 <= count_0 + 1;
                counter <= counter + 1;
            end
        endcase
    end
end

// current state logic
always_ff @ (posedge clk or posedge rst) begin
    if(rst) begin
        current_state <= IDLE;
    end
    else begin
        current_state <= next_state;
    end
end

// next state logic
always_comb begin
    unique case(current_state)
            IDLE: begin
                if(start)
                    next_state = COUNT;
                else
                    next_state = IDLE;
            end
            COUNT: begin
                if(counter < (WIDTH-1))
                    next_state = COUNT;
                else begin
                    unique case(1'b1)
                    sel[0]:
                        next_state = DONE_0;
                    sel[1]:
                        next_state = DONE_1;
                    endcase
                end
            end
            DONE_0: begin
                next_state = IDLE;
            end
            DONE_1: begin
                next_state = IDLE;
            end
    endcase
end

// output logic
always_comb begin
    unique case(current_state)
            IDLE: begin
                cntout = '0;
                done = 1'b0;
            end
            COUNT: begin
                cntout = '0;
                done = 1'b0;
            end
            DONE_0: begin
                cntout = count_0;
                done = 1'b1;
            end
            DONE_1: begin
                cntout = count_1;
                done = 1'b1;
            end
    endcase
end

endmodule