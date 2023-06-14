add wave -position insertpoint  \
sim:/mult_tb/clk \
sim:/mult_tb/start \
sim:/mult_tb/a_in \
sim:/mult_tb/b_in \
sim:/mult_tb/DUT/multiplicand_reg \
sim:/mult_tb/product \
sim:/mult_tb/DUT/product_reg \
sim:/mult_tb/DUT/mult_control/multiplier_bit_0 \
sim:/mult_tb/DUT/mult_control/current_state \
sim:/mult_tb/done 

run 28

radix signal sim:/mult_tb/a_in binary
radix signal sim:/mult_tb/b_in binary
radix signal sim:/mult_tb/DUT/multiplicand_reg binary
radix signal sim:/mult_tb/product binary
radix signal sim:/mult_tb/DUT/product_reg binary