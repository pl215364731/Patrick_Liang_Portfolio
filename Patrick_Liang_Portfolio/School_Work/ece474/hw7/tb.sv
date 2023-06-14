`timescale 1ns/1ns
`include "bus.sv"

module tb; //testbench module 

integer input_file, post_input_file, output_file, compare_file, in, out;
integer i;
integer comp_result;

parameter CYCLE = 100; 

reg clk, reset_n;
reg start, done;
reg [31:0] a_in, b_in; 
reg [31:0] result;

bus bs = new;


//clock generation for write clock
initial begin
  clk <= 0; 
  forever #(CYCLE/2) clk = ~clk;
end

//release of reset_n relative to two clocks
initial begin
    input_file  = $fopen("input_data", "rb");
    if (input_file==0) begin 
      $display("ERROR : CAN NOT OPEN input_file"); 
    end
    post_input_file  = $fopen("post_input_data", "rb");
    if (post_input_file==0) begin 
      $display("ERROR : CAN NOT OPEN post_input_file"); 
    end
    output_file = $fopen("random-outputs.txt", "wb");
    if (output_file==0) begin 
      $display("ERROR : CAN NOT OPEN output_file"); 
    end
    compare_file = $fopen("comparison.rpt", "wb");
    if (compare_file==0) begin 
      $display("ERROR : CAN NOT OPEN comparison report"); 
    end
    a_in='x;
    b_in='x;
    start=1'b0;
    reset_n <= 0;
    #(CYCLE * 1.5) reset_n = 1'b1; //reset for 1.5 clock cycles
end

gcd gcd_0(.*); //instantiate the gcd unit

initial begin
  // Part 1.1
  #(CYCLE*4);  //delay after reset
  while(! $feof(input_file)) begin 
    $fscanf(input_file,"%d %d", a_in, b_in);
    start=1'b1;
    #(CYCLE);
    start=1'b0;
    while(done != 1'b1) #(CYCLE);
    $display ("a_in=%d   b_in=%d   result=%d", a_in, b_in, result);
    if(result == gcd_ref(a_in, b_in))
      $fdisplay(compare_file, "%d %d match", a_in, b_in);
    else 
      $fdisplay(compare_file, "%d %d gcd:%d behavioral:%d", a_in, b_in, result, gcd_ref(a_in, b_in));
    #(CYCLE*2); //2 cycle delay between trials
  end
  $stop;

  // Part 1.2
  while(! $feof(post_input_file)) begin 
    $fscanf(post_input_file,"%d %d", a_in, b_in);
    start=1'b1;
    #(CYCLE);
    start=1'b0;
    while(done != 1'b1) #(CYCLE);
    $display ("a_in=%d   b_in=%d   result=%d", a_in, b_in, result);
    #(CYCLE*2); //2 cycle delay between trials
  end

  // Transition SUBT -> DONE
  a_in = 100;
  b_in = 70;
  start = 1'b1;
  #(CYCLE);
  start = 1'b0;
  #(CYCLE);
  reset_n = 1'b0;
  #(CYCLE * 2) reset_n = 1'b1;

  // Transition SWAP -> DONE
  a_in = 70;
  b_in = 100;
  start = 1'b1;
  #(CYCLE);
  start = 1'b0;
  #(CYCLE);
  reset_n = 1'b0;
  #(CYCLE * 2) reset_n = 1'b1;

// Part 2: Input coverage
  repeat(501) begin
    #(CYCLE);
    assert(bs.randomize());
      a_in = bs.a_in;
      b_in = bs.b_in;
      start=1'b1;
      #(CYCLE);
      start=1'b0;
      while(done != 1'b1) begin
        #(CYCLE);
      end
      $fdisplay(output_file, "%d %d %d", a_in, b_in, result);
      #(CYCLE * 2); //2 cycle delay between trials
  end
  $fclose(output_file);

  // Part 3: Comparison
  output_file  = $fopen("random-outputs.txt", "rb");
  if (output_file==0) begin 
    $display("ERROR : CAN NOT OPEN input_file"); 
  end
  while(! $feof(output_file)) begin
    $fscanf(output_file,"%d %d %d", a_in, b_in, comp_result);
    if(comp_result == gcd_ref(a_in, b_in))
      $fdisplay(compare_file, "%d %d match", a_in, b_in);
    else 
      $fdisplay(compare_file, "%d %d gcd:%d behavioral:%d", a_in, b_in, comp_result, gcd_ref(a_in, b_in));
  end

  $stop;
  $fclose(input_file);
  $fclose(output_file);
  $fclose(compare_file);
  $fclose(post_input_file);
  
end

function automatic int gcd_ref(int a, b);
  if (b > a) begin
      int temp = a;
      a = b;
      b = temp;
  end
  while (b != 0) begin
      int remainder = a % b;
      a = b;
      b = remainder;
  end
  return a;
endfunction

endmodule
