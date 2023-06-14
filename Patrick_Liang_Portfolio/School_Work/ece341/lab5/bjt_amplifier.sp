Spice simulation of Source Degenerated CE BJT Circuit

* model
.include 2n4401.mod



vin	vcc	gnd	dc	9
vac vac gnd sin(0 5m 1k)
C1  vac vb  0.1u
C2  vc  vd  0.1u
R1	vcc	vb	27k
R2	vb	gnd	4.7k
R3	vcc	vc	1.2k
R4	ve	gnd	150
R5      vd      gnd     10k

Q1	vc	vb	ve	2n4401


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
* print v(vb) v(ve) v(vc) ; print DC voltages      
*  plot vm(vac) vm(vd)                   ; plot AC magnitude 
  plot v(vac) v(vd)                      ; plot AC voltages  
*  hardcopy diode.ps i(vis)
.endc
.end
