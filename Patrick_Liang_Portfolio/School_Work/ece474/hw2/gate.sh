vlog alu.gate.v /nfs/guille/a1/cadlibs/synop_lib/SAED_EDK90nm/Digital_Standard_Cell_Library/verilog/*.v -work gate_work
vsim gate_work.alu -c -voptargs=+acc -t ns -do gate_do.do