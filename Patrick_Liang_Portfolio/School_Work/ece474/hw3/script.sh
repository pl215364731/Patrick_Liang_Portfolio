vlog arbiter.sv -work rtl_work
vsim rtl_work.arbiter -c -voptargs=+acc -t ns -do arbiter.do
design_vision-xg -no_gui -f synthesis.do