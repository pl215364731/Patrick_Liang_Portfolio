# Part 2
vlog tb.sv gcd*.sv -work rtl_work
vsim rtl_work.tb -c -t ns -voptargs=+acc -do run.do +two
mv -f report.rpt func.low.rpt

# Part 3
vlog tb.sv gcd*.sv -work rtl_work +define+MOD
vsim rtl_work.tb -c -t ns -voptargs=+acc -do run.do +three
mv -f report.rpt func.high.rpt

# Part 5
vlog tb.sv gcd*.sv -work rtl_work +define+MOD 
start=`date +%s`
vsim rtl_work.tb -c -t ns -voptargs=+acc -do run.do +five
end=`date +%s`
runtime=$((end-start))
echo "Runtime: " $runtime "seconds"
mv -f report.rpt func.random.rpt