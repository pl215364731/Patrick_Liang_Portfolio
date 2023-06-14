vlog tb.sv gcd*.sv -work rtl_work -cover sbcef "+cover=f" -O0
vsim rtl_work.tb -c -t ns -do do.do -coverage