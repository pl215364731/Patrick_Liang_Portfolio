module mult_tb ();

logic clk, reset, start, done;
logic [3:0] a_in, b_in;
logic [7:0] product;

multiplier_4_bit DUT(
    .clk(clk),
    .reset(reset),
    .start(start),
    .a_in(a_in),
    .b_in(b_in),
    .product(product),
    .done(done)
);

//set clock
initial begin
    clk = 0;
    forever begin
    #1 clk = ~clk;
    end
end

initial begin
    reset = 1;
    @(posedge clk) repeat(2);
    reset = 0;
    a_in = 4'b1110;
    b_in = 4'b1001;
    start = 1'b1;
    @(posedge clk);
    start = 1'b0;
    @(posedge clk) repeat(20);
end


endmodule