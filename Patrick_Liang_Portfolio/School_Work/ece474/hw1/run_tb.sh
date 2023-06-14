vlib work
vlog mult_tb.sv multiplier_4_bit.sv mult_control.sv
vsim mult_tb -voptargs=+acc -t ns -do mult_tb.do
