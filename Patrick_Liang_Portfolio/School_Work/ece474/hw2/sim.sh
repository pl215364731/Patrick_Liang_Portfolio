vlog alu.sv -work rtl_work
vsim rtl_work.alu -c -voptargs=+acc -t ns -do rtl_do.do