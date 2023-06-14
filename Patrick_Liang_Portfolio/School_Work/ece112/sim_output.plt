set terminal X11
set title "simulation of capacitor charging through a resistor (rc.sp)"
set xlabel "s"
set ylabel "V"
set grid
unset logscale x 
set xrange [1.000000e-11:2.000000e-08]
unset logscale y 
set yrange [-1.635545e-01:3.434644e+00]
#set xtics 1
#set x2tics 1
#set ytics 1
#set y2tics 1
set format y "%g"
set format x "%g"
plot 'sim_output.data' using 1:2 with lines lw 1 title "v(tie)" 
set terminal push
set terminal postscript eps color
set out 'sim_output.eps'
replot
set term pop
replot
