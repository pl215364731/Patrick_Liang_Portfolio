vlog tb_arbiter.sv arbiter.sv -work rtl_work
vsim rtl_work.tb_arbiter -voptargs=+acc -t ns -do testbench.do