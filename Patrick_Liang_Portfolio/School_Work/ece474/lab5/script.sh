vlog tb.sv manip.sv -work rtl_work
vsim rtl_work.tb -c -voptargs=+acc -t ns -do do.do