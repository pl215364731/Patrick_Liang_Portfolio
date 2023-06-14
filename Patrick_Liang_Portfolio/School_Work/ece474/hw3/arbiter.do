add wave *

# Initial values
force clk 0 0, 1 5 -r 10
force rst_n 1'h0 0
force dly 1'h0 0
force done 1'h0 0
force req 1'h0 0
force reset 1'h0 0

force rst_n 1'h1 10

# Test case 1: IDLE > BUSY > WAIT > FREE > IDLE
force req 1'h1 30
force done 1'h1 40
force dly 1'h1 40
force req 1'h0 40
force done 1'h0 50
force dly 1'h0 50
force req 1'h0 50

# Test case 2: IDLE > BUSY > TIMEOUT> WAIT > FREE > IDLE
force req 1'h1 100
force reset 1'h0 100
force dly 1'h1 120
force req 1'h0 120
force reset 1'h1 140
force reset 1'h0 150
force dly 1'h0 150

# Test case 3: IDLE > BUSY > TIMEOUT> FREE > IDLE
force req 1'h1 200
force req 1'h0 220
force reset 1'h1 220

# Test case 4: IDLE > BUSY > FREE > IDLE
force req 1'h1 270
force req 1'h0 280
force done 1'h1 280
force done 1'h0 290


run 310

quit