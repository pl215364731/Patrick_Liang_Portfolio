coverage exclude -srcfile tb.sv
add wave *
run -all
coverage report -details -output pre-coverage.rpt
run -all
coverage report -details -output post-coverage.rpt
quit