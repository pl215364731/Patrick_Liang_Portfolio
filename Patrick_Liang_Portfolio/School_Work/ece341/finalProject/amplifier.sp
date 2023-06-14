Spice simulation of Source Degenerated CE BJT Circuit

* model
.include LM358.mod



vcc	vcc	gnd	dc	9
vcc2	vcc2	gnd	dc	4.5
vin vin gnd sin(4.5 50m 1k)
Cin  vin v1  10u
R1	v1	vin-	270
R2	vin-	vout	5.6k
R3	vcc2	vin+	220

X1	vin+ vin- vcc gnd vout	LM358


.control
  set hcopydevtype=postscript
  set hcopypscolor=true
  set color0=rgb:f/f/f
  set color1=rgb:0/0/0
  op                : analyze DC operating point 
 * ac dec 10 1 1meg ; AC small sig analysis
*                    decade variation, 10 points per decade, 1 hz to 1mhz
* tran 1u 200u sweep amp points 2 10m 30m
  tran 20u 5m       ;plot every 20uS for 5mS
* print v(vin) v(vout) ; print DC voltages      
*  plot vm(vin) vm(vout)       ; plot AC magnitude 
  plot v(vin) v(vout)           ; plot AC voltages  
*  hardcopy diode.ps i(vis)
.endc
.end
