`timescale 1ns/1ns
// Example testbench for homework 4 memory controller.
// Author: Richard Yu
// Date: 05/02/2022

module tb_controller ();

parameter MONE = 0, MTWO = 1, MTHREE = 2;

logic [2:0] req;
logic [2:0] done;
logic clk, rst;  // Input signals to the DUT.

logic [3:0] mstate;
logic [1:0] accmodule;

controller iDUT(.req(req), .done(done), .reset(rst), .clk(clk), .mstate(mstate), .accmodule(accmodule));



initial begin

clk = 0;
rst = 1;
req[MONE] = 0;
req[MTWO] = 0;
req[MTHREE] = 0;
done[MONE] = 0;
done[MTWO] = 0;
done[MTHREE] = 0;

# 14 rst = 0;

// Module 1 requests, module 2 tries to interupts but fails.
# 2 req[MONE] = 1;
# 10 req[MONE] = 0;

# 20 req[MTWO] = 1;
# 10 req[MTWO] = 0;

# 5 done[MONE] = 1;
# 5 done[MONE] = 0;

// Module 2 requests, module 1 to interupts.
# 20 req[MTWO] = 1;
# 10 req[MTWO] = 0;

# 10 req[MONE] = 1;
# 10 req[MONE] = 0;

# 35 done[MONE] = 1;
# 5  done[MONE] = 0;

// Module 3 requests, module 1 to interupts.
# 20 req[MTHREE] = 1;
# 10 req[MTHREE] = 0;

# 10 req[MONE] = 1;
# 10 req[MONE] = 0;

# 35 done[MONE] = 1;
# 5  done[MONE] = 0;

// Module 2 and module 3 both request, access given to module 2.
# 20 req[MTHREE] = 1;
	 req[MTWO] = 1;
# 10 req[MTHREE] = 0;
	 req[MTWO] = 0;

# 15 done[MTWO] = 1;
# 5 done[MTWO] = 0;

// Module 2 and module 3 both request again, access given to module 3.
# 10 req[MTHREE] = 1;
	 req[MTWO] = 1;
# 10 req[MTHREE] = 0;
	 req[MTWO] = 0;

# 15 done[MTWO] = 1;
# 5 done[MTWO] = 0;

// Module 2 and module 3 both request again, access given to module 2.
# 10 req[MTHREE] = 1;
	 req[MTWO] = 1;
# 10 req[MTHREE] = 0;
	 req[MTWO] = 0;

# 15 done[MTWO] = 1;
# 5 done[MTWO] = 0;

// Module 2 and module 3 both request again, access given to module 3.
# 10 req[MTHREE] = 1;
	 req[MTWO] = 1;
# 10 req[MTHREE] = 0;
	 req[MTWO] = 0;

# 15 done[MTWO] = 1;
# 5 done[MTWO] = 0;

// Module 2 and module 3 both request again, access given to module 2.
# 10 req[MTHREE] = 1;
	 req[MTWO] = 1;
# 10 req[MTHREE] = 0;
	 req[MTWO] = 0;

# 15 done[MTWO] = 1;
# 5 done[MTWO] = 0;

// Module 1 to 2 to 3 back to back
# 10 req[MONE] = 1;
# 10 req[MONE] = 0;
	 req[MTWO] = 1;

# 5 done[MONE] = 1;

# 5 done[MONE] = 0;
	req[MTWO] = 0;

# 10 req[MTHREE] = 1;

# 5 done[MTWO] = 1;

# 5 done[MTWO] = 0;
	req[MTHREE] = 0;

# 20
# 20 $dumpflush;
$stop;


end

initial begin
$dumpfile("test.vcd");
$dumpvars(1, tb_controller);

end


always
	#5 clk = ~clk;

endmodule