Ngspice simulation of diode in circuit

*Sweeps voltage source to create diode VI curve for two possible
*diodes. The 1N4148 diode crosses 100uA forward current at 600mV.
*The bat17 diode crosses 100uA forward current at 400mV.

.include bat17.subckt   ;schottky diode
.include 1n4148.subckt  ;common silicon switching diode

vin input_v  gnd  dc 0  ; input voltage source to be swept
r1  input_v  node1   1k ; current limiting resistor
vis node1    node2   0  ; current sensing voltage source
*xd1  node2    gnd  bat17     ; schottky 
xd1  node2    gnd  1n4148    ; silicon 

.control
  set hcopydevtype=postscript
  set hcopypscolor=true
  set color0=rgb:f/f/f
  set color1=rgb:0/0/0
  dc vin -1 1 0.01  ;sweep dc source from -1 to +1 volts in 10mv steps
  plot i(vis)       ;plot current through diode
  hardcopy diode.ps i(vis)
.endc
.end
