vlog tb_controller.sv controller.sv -work rtl_work
vsim rtl_work.tb_controller -voptargs=+acc -t ns -do testbench.do