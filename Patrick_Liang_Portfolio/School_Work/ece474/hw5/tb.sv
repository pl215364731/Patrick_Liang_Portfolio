module tb();

logic clk;
logic rst;

logic [7:0] a_in_8;
logic [15:0] a_in_16;
logic [20:0] a_in_21;

logic [1:0] sel_8;
logic [1:0] sel_16;
logic [1:0] sel_21;


logic start_8;
logic start_16;
logic start_21;

// output
logic done_8;
logic done_16;
logic done_21;
logic [7:0] cntout_8;
logic [15:0] cntout_16;
logic [20:0] cntout_21;

count #(.WIDTH(8)) DUT_8 (
    .a_in(a_in_8),
    .sel(sel_8),
    .clk(clk),
    .start(start_8),
    .rst(rst),
    .done(done_8),
    .cntout(cntout_8)
);

count #(.WIDTH(16)) DUT_16 (
    .a_in(a_in_16),
    .sel(sel_16),
    .clk(clk),
    .start(start_16),
    .rst(rst),
    .done(done_16),
    .cntout(cntout_16)
);

count #(.WIDTH(21)) DUT_21 (
    .a_in(a_in_21),
    .sel(sel_21),
    .clk(clk),
    .start(start_21),
    .rst(rst),
    .done(done_21),
    .cntout(cntout_21)
);


initial begin
    clk = 0;
    sel_8 = 0;
    sel_16 = 0;
    sel_21 = 0;
    start_8 = 0;
    start_16 = 0;
    start_21 = 0;
    rst = 0;
    a_in_8 = 0;
    a_in_16 = 0;
    a_in_21 = 0;

    // Reset
    @(posedge clk) rst = 1;
    @(posedge clk) rst = 0;

    test_8();
    test_16();
    test_21();
    edgecases();

    $stop;
end

always
    #5 clk = ~clk;


task test_8();
    //Test 1: 8 bits, count 2 zeros
    @(posedge clk); 
    a_in_8 = 8'b11111010;
    start_8 = 1;
    sel_8 = 2'b01;
    @(posedge clk);
    start_8 = 0;
    repeat(8) @ (posedge clk);
    @(negedge clk) $display("Test 1: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_8, sel_8, cntout_8);
    repeat(4) @ (posedge clk);

    //Test 2: 8 bits, count 6 ones
    @(posedge clk); 
    a_in_8 = 8'b11111010;
    start_8 = 1;
    sel_8 = 2'b10;
    @(posedge clk);
    start_8 = 0;
    repeat(8) @ (posedge clk);
    @(negedge clk) $display("Test 2: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_8, sel_8, cntout_8);
    repeat(4) @ (posedge clk);

    //Test 3: 8 bits, a_in set to z, should count 0 zeros
    @(posedge clk); 
    a_in_8 = 8'bzzzzzzzz;
    start_8 = 1;
    sel_8 = 2'b01;
    @(posedge clk);
    start_8 = 0;
    repeat(8) @ (posedge clk);
    @(negedge clk) $display("Test 3: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_8, sel_8, cntout_8);
    repeat(4) @ (posedge clk);

    //Test 4: 8 bits, a_in set to z, should count 0 ones
    @(posedge clk); 
    a_in_8 = 8'bzzzzzzzz;
    start_8 = 1;
    sel_8 = 2'b10;
    @(posedge clk);
    start_8 = 0;
    repeat(8) @ (posedge clk);
    @(negedge clk) $display("Test 4: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_8, sel_8, cntout_8);
    repeat(4) @ (posedge clk);
endtask

task test_16();
    //Test 5: 16 bits, count 11 zeros
    @(posedge clk); 
    a_in_16 = 16'b1011110000000000;
    start_16 = 1;
    sel_16 = 2'b01;
    @(posedge clk);
    start_16 = 0;
    repeat(16) @ (posedge clk);
    @(negedge clk) $display("Test 5: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_16, sel_16, cntout_16);
    repeat(4) @ (posedge clk);

    //Test 6: 16 bits, count 9 ones
    @(posedge clk); 
    a_in_16 = 16'b1000111110101010;
    start_16 = 1;
    sel_16 = 2'b10;
    @(posedge clk);
    start_16 = 0;
    repeat(16) @ (posedge clk);
    @(negedge clk) $display("Test 6: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_16, sel_16, cntout_16);
    repeat(4) @ (posedge clk);

    //Test 7: 16 bits, a_in set to z, should count 0 zeros
    @(posedge clk); 
    a_in_16 = 16'bzzzzzzzzzzzzzzzz;
    start_16 = 1;
    sel_16 = 2'b01;
    @(posedge clk);
    start_16 = 0;
    repeat(16) @ (posedge clk);
    @(negedge clk) $display("Test 7: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_16, sel_16, cntout_16);
    repeat(4) @ (posedge clk);

    //Test 8: 16 bits, a_in set to z, should count 0 ones
    @(posedge clk); 
    a_in_16 = 16'bzzzzzzzzzzzzzzzz;
    start_16 = 1;
    sel_16 = 2'b10;
    @(posedge clk);
    start_16 = 0;
    repeat(16) @ (posedge clk);
    @(negedge clk) $display("Test 8: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_16, sel_16, cntout_16);
    repeat(4) @ (posedge clk);
endtask

task test_21();
    //Test 9: 21 bits, count 12 zeros
    @(posedge clk); 
    a_in_21 = 21'b101111000000110010100;
    start_21 = 1;
    sel_21 = 2'b01;
    @(posedge clk);
    start_21 = 0;
    repeat(21) @ (posedge clk);
    @(negedge clk) $display("Test 9: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_21, sel_21, cntout_21);
    repeat(4) @ (posedge clk);

    //Test 10: 21 bits, count 10 ones
    @(posedge clk); 
    a_in_21 = 21'b100011111010100001010;
    start_21 = 1;
    sel_21 = 2'b10;
    @(posedge clk);
    start_21 = 0;
    repeat(21) @ (posedge clk);
    @(negedge clk) $display("Test 10: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_21, sel_21, cntout_21);
    repeat(4) @ (posedge clk);

    //Test 11: 21 bits, a_in set to z, should count 0 zeros
    @(posedge clk); 
    a_in_21 = 21'bzzzzzzzzzzzzzzzzzzzzz;
    start_21 = 1;
    sel_21 = 2'b01;
    @(posedge clk);
    start_21 = 0;
    repeat(21) @ (posedge clk);
    @(negedge clk) $display("Test 11: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_21, sel_21, cntout_21);
    repeat(4) @ (posedge clk);

    //Test 12: 21 bits, a_in set to z, should count 0 ones
    @(posedge clk); 
    a_in_21 = 21'bzzzzzzzzzzzzzzzzzzzzz;
    start_21 = 1;
    sel_21 = 2'b10;
    @(posedge clk);
    start_21 = 0;
    repeat(21) @ (posedge clk);
    @(negedge clk) $display("Test 12: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_21, sel_21, cntout_21);
    repeat(4) @ (posedge clk);
endtask


task edgecases();
    //Test 13: 8 bits, start asserted in the middle of count state
    @(posedge clk); 
    a_in_8 = 8'b11001010;
    start_8 = 1;
    sel_8 = 2'b01;
    @(posedge clk);
    start_8 = 0;
    repeat(3) @ (posedge clk);
    @(posedge clk) start_8 = 1;
    @(posedge clk) start_8 = 0;
    repeat(3) @ (posedge clk);
    @(negedge clk) $display("Test 13: time=%t, a_in=%b, sel=%d, cntout=%d\n", $time, a_in_8, sel_8, cntout_8);
    repeat(4) @ (posedge clk);

    //Test 14: 8 bits, a_in changes in the middle of count
    @(posedge clk); 
    a_in_8 = 8'b11101010;
    start_8 = 1;
    sel_8 = 2'b10;
    @(posedge clk);
    start_8 = 0;
    repeat(4) @ (posedge clk);
    @(posedge clk) a_in_8 = 8'b11111111;
    repeat(3) @ (posedge clk);
    @(negedge clk) $display("Test 14: time=%t, old a_in=11101010, new a_in=11111111, sel=%d, cntout=%d\n", $time, sel_8, cntout_8);
    repeat(4) @ (posedge clk);

endtask

endmodule