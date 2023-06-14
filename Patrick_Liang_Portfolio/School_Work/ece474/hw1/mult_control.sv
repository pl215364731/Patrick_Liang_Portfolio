module mult_control(
input  logic clk, reset,
input  logic start, 
input  logic multiplier_bit_0,
output logic prod_reg_ld_high,
output logic prod_reg_shift_right,
output logic done
);

logic [3:0] counter;

enum logic [3:0] {
    S_IDLE  = 4'b0001,
    S_SHIFT = 4'b0010,
    S_LOAD  = 4'b0100,
    S_DONE  = 4'b1000
} next_state, current_state;

always_ff @ (posedge clk) begin
    if(reset) begin
        current_state <= S_IDLE;
    end
    else begin
        current_state <= next_state;
    end
end

always_ff @ (posedge clk) begin
    if(reset) begin
        counter <= 3'b0;
    end
    else begin
        if(current_state == S_LOAD)
            counter <= counter + 1;
    end
end

always_comb begin
    case(current_state)
        S_IDLE: begin
            prod_reg_ld_high = 1'b1;
            prod_reg_shift_right = 1'b0;
            done = 1'b0;
        end
        S_SHIFT: begin
            prod_reg_ld_high = 1'b0;
            prod_reg_shift_right = 1'b1;
        end
        S_LOAD: begin
            prod_reg_shift_right = 1'b0;
            prod_reg_ld_high = multiplier_bit_0;
        end
        S_DONE: begin
            prod_reg_ld_high = 1'b0;
            prod_reg_shift_right = 1'b0;
            done = 1'b1;
        end
    endcase
end

always_comb begin
    case(current_state)
        S_IDLE: begin
            if(start) next_state = S_LOAD;
            else next_state = S_IDLE;
        end
        S_SHIFT: begin
            if(counter == 3'd4) next_state = S_DONE;
            else next_state = S_LOAD;
        end
        S_LOAD: begin
            next_state = S_SHIFT;
        end
        S_DONE: begin
            next_state = S_IDLE;
        end
    endcase
end

endmodule