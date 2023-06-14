# Compile Section
vlog -sv src/gcd*.sv -work rtl_work +define+FORMAL
vlog -sv -mfcu -cuname sva_bind +define+FORMAL properties.sv
# PropCheck Section
onerror {exit 1}
###### add directives
netlist reset reset_n -active_high -async
netlist clock clk -period 100
###### Run PropCheck
formal compile -d rtl_work.gcd -cuname sva_bind
formal verify -timeout 30s

exit 0