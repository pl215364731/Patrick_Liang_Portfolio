module tb();

logic[7:0] in;
logic [1:0] out;
int result;

manip DUT(
    .in(in),
    .out(out),
    .result(result)
);

initial begin
#1 in = 3;
$monitor("time=%t, in=%d, out=%d, result=%d\n", $time, in, out, result);
#1 in = 8;
$monitor("time=%t, in=%d, out=%d, result=%d\n", $time, in, out, result);
#1 in = 10;
$monitor("time=%t, in=%d, out=%d, result=%d\n", $time, in, out, result);
#1 in = 6;
$monitor("time=%t, in=%d, out=%d, result=%d\n", $time, in, out, result);

end

endmodule