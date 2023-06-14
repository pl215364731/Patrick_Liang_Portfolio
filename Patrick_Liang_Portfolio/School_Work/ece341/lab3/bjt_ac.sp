.title bjt.sp

.include 2n4401.mod

Vin in gnd ac=0.05 ; for swept source
*Vin in gnd sin(0 0.5m 1000) ;0v offset, 0.5mv, 1Khz signal 
*0.5mv specifies the amplitude, not the peak-to-peak amplitude which will be 1mv

Vcc   vcc         gnd                12v
C2    collector   out                0.1u
C1    in          base               0.1u
R1    vcc         base               27K
R2    base        gnd                4.7K
R3    emitter     gnd                150
R4    vcc         collector          1.2K
R5    out         gnd                2K
Q1    collector   base      emitter  2n4401 


.control
  set hcopydevtype=postscript
  set hcopypscolor=true
  set color0=rgb:f/f/f
  set color1=rgb:0/0/0
  op                : analyze DC operating point 
  ac dec 10 1 1meg ; AC small sig analysis
*                    decade variation, 10 points per decade, 1 hz to 1mhz
* tran 1u 200u sweep amp points 2 10m 30m
*  tran 20u 5m       ;plot every 20uS for 5mS
 * print v(base) v(emitter) v(collector) ; print DC voltages      
  plot vdb(in)+20 vdb(out)+20                   ; plot AC magnitude 
  plot vm(in) vm(out)                   ; plot AC magnitude 
  plot ph(out)*180/3.14                 ; plot AC phase
*  plot v(in) v(out)                      ; plot AC voltages  
*  hardcopy diode.ps i(vis)
.endc

.end
