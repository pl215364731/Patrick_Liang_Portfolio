module multiplier_4_bit (
    input logic clk, reset, start,
    input logic [3:0] a_in, b_in,
    output logic [7:0] product,
    output logic done
);

logic [3:0] multiplicand_reg;
logic [7:0] product_reg;
logic prod_reg_ld_high, prod_reg_shift_right;

logic [3:0] sum;
logic [3:0] prog_reg_high_pre_load;


assign product = product_reg;
assign sum = product_reg[7:4] + multiplicand_reg;
assign prog_reg_high_pre_load = start ? 4'd0 : sum;


mult_control mult_control(
    .clk(clk),
    .reset(reset),
    .start(start),
    .multiplier_bit_0(product_reg[0]),
    .prod_reg_ld_high(prod_reg_ld_high),
    .prod_reg_shift_right(prod_reg_shift_right),
    .done(done)
);

always_ff @ (posedge clk) begin
    if(reset) begin
        product_reg <= 8'd0;
        multiplicand_reg <= 4'd0;
    end
    else begin
        if(start) begin
            multiplicand_reg <= a_in;
            product_reg[3:0] <= b_in;
        end
        if(prod_reg_ld_high) begin
            product_reg[7:4] <= prog_reg_high_pre_load;
        end
        if(prod_reg_shift_right) begin
            product_reg <= {1'b0, product_reg[7:1]};
        end
    end
end

endmodule