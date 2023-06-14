Spice simulation of Source Degenerated CE BJT Circuit

* model
.include LM358.mod



vcc	vcc	gnd	dc	9
vcc2	vcc2	gnd	dc	4.5
vin1 vin1 gnd sin(4.5 50m 1k)
vin2 vin2 gnd sin(4.5 2.5 1k)
Cin1  vin1 v1  10u
Cin2  vin2 v2  10u
R1a	v1	vin-	470
R1b	v2	vin-	470
R2	vin-	vout	10k
R3	vcc2	vin+	470

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
* print v(vin1) v(vin2) v(vout) ; print DC voltages      
*  plot vm(vin1) vm(vin2) vm(vout)       ; plot AC magnitude 
  plot v(vin1) v(vin2) v(vout)           ; plot AC voltages  
*  hardcopy diode.ps i(vis)
.endc
.end
