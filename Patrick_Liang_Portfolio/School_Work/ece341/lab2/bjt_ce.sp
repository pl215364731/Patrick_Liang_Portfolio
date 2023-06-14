Spice simulation of Source Degenerated CE BJT Circuit

* model
.include 2n4401.mod



vin	vcc	gnd	dc	10
R1	vcc	vb	27k
R2	vb	gnd	4.7k
R3	ve	gnd	150
* measurement source for Ic
vx	vcc	x	0
R4	x	vc	1.2k
* diode
Q1	vc	vb	ve	2n4401


.op
.control
run
print all
.endc
.end
