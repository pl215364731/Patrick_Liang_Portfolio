`timescale 1ns/1ns

`ifdef MOD
  `include "mod_covergroups.sv"
`else
  `include "covergroups.sv"
`endif

class random;
    rand bit [15:0] a;
    rand bit [15:0] b;
    constraint a_constraint { a >= 10000; }
    constraint b_constraint { b >= 10000; }
    constraint sum_constraint { a % b == 1; }
endclass

module tb; //testbench module 

integer input_file, in, out;
integer i;

parameter CYCLE = 100; 

reg clk, reset_n;
reg start, done;
reg [31:0] a_in, b_in; 
reg [31:0] result;

cg_fsm_state cg_1_inst = new;
cg_op_mon cg_2_inst = new;
cg_fsm_ps_mon cg_3_inst = new;
cg_reg_mon cg_4_inst = new;

cover property(cvr_seq);

// cover property(cvr_silly);

random random_inst = new;

//clock generation for write clock
initial begin
  clk <= 0; 
  forever #(CYCLE/2) clk = ~clk;
end

//release of reset_n relative to two clocks
initial begin
    if($test$plusargs("two")) begin
      input_file  = $fopen("input_data", "rb");
      if (input_file==0) begin 
        $display("ERROR : CAN NOT OPEN input_file"); 
      end
    end
    if($test$plusargs("three")) begin
      input_file  = $fopen("mod_input_data", "rb");
      if (input_file==0) begin 
        $display("ERROR : CAN NOT OPEN input_file"); 
      end
    end
    if($test$plusargs("five")) begin
      input_file = $fopen("rp_input_data", "wb");
      if (input_file==0) begin 
        $display("ERROR : CAN NOT OPEN rp_input_data"); 
      end
      repeat(1000) begin
        assert(random_inst.randomize());
        $fdisplay(input_file, "%d %d", random_inst.a, random_inst.b);
      end
      $fclose(input_file);
      input_file  = $fopen("rp_input_data", "rb");
      if (input_file==0) begin 
        $display("ERROR : CAN NOT OPEN rp_input_file"); 
      end
    end
    a_in='x;
    b_in='x;
    start=1'b0;
    reset_n <= 0;
    #(CYCLE * 1.5) reset_n = 1'b1; //reset for 1.5 clock cycles
end

gcd gcd_0(.*); //instantiate the gcd unit

initial begin
  i = 0;
  #(CYCLE*4);  //delay after reset
  while(! $feof(input_file)) begin 
    $fscanf(input_file,"%d %d", a_in, b_in);
    start=1'b1;
    #(CYCLE);
    start=1'b0;
    while(done != 1'b1) #(CYCLE);
    if($test$plusargs("five")) begin
      i += 1;
      if(i == 50) begin
        $display ("a_in=%d   b_in=%d   result=%d", a_in, b_in, result);
        i = 0;
      end
    end
    else begin
      $display ("a_in=%d   b_in=%d   result=%d", a_in, b_in, result);
    end
    #(CYCLE*2); //2 cycle delay between trials
  end
  #(CYCLE) $display("cg_fsm_state  coverage = %0.2f %%", cg_1_inst.get_inst_coverage());
  #(CYCLE) $display("cg_op_mon     coverage = %0.2f %%", cg_2_inst.get_inst_coverage());
  #(CYCLE) $display("cg_fsm_ps_mon coverage = %0.2f %%", cg_3_inst.get_inst_coverage());
  #(CYCLE) $display("cg_reg_mon    coverage = %0.2f %%", cg_4_inst.get_inst_coverage());
$stop;
$fclose(input_file);
end

endmodule
