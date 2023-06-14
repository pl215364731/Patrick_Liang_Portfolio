Simulation of capacitor charging through a resistor (rc.sp)

vsrc vin   0    PULSE(0 3.3 1ns 100p 100p 100e-9 250e-9) ;voltage source
r1   vin   tie  400  ;series resistor   
c1   tie   0   10pf ;capacitor to ground 

.control
  set hcopydevtype=postscript
  set hcopypscolor=0
  set color0=rgb:f/f/f
  set color1=rgb:0/0/0
  tran 10ps 20ns
  plot  V(tie) xl 0.1ns 20ns
  gnuplot sim_output V(tie) xl 10ps 20ns
.endc
.end
