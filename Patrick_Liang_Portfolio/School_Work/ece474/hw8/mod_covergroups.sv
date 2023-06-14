
parameter TEST = 2'h0;
parameter SWAP = 2'h1;
parameter SUBT = 2'h2;
parameter DONE = 2'h3;


covergroup cg_fsm_state @(posedge tb.clk);
    cp_fsm_ps: coverpoint tb.gcd_0.gcd_ctrl_0.ps;
    cp_fsm_ns: coverpoint tb.gcd_0.gcd_ctrl_0.ns;
    cp_fsm_both: cross cp_fsm_ps, cp_fsm_ns{
        ignore_bins ignore_bin1 = cp_fsm_both with (cp_fsm_ps == SUBT && cp_fsm_ns == DONE);
        ignore_bins ignore_bin2 = cp_fsm_both with (cp_fsm_ps == SWAP && cp_fsm_ns == DONE);
        ignore_bins ignore_bin3 = cp_fsm_both with (cp_fsm_ps == DONE && cp_fsm_ns == SWAP);
        ignore_bins ignore_bin4 = cp_fsm_both with (cp_fsm_ps == DONE && cp_fsm_ns == SUBT);
        ignore_bins ignore_bin5 = cp_fsm_both with (cp_fsm_ps == SUBT && cp_fsm_ns == SWAP);
        ignore_bins ignore_bin6 = cp_fsm_both with (cp_fsm_ps == SWAP && cp_fsm_ns == SWAP);
        ignore_bins ignore_bin7 = cp_fsm_both with (cp_fsm_ps == TEST && cp_fsm_ns == TEST);
        ignore_bins ignore_bin8 = cp_fsm_both with (cp_fsm_ps == SUBT && cp_fsm_ns == SUBT);
        ignore_bins ignore_bin9 = cp_fsm_both with (cp_fsm_ps == SWAP && cp_fsm_ns == TEST);
    }
endgroup

covergroup cg_op_mon @(posedge tb.clk);
    cp_gcd_op: coverpoint tb.result{
        bins bin_1 = {[0:500]};
        bins bin_2 = {[500:999]};
        bins bin_3 = {[1000:2000]};
        bins bin_4 = {[3000:3500]}; 
        bins bin_5 = {[7000:8000]}; 
        bins bin_6 = {5000}; 
    }
endgroup

covergroup cg_fsm_ps_mon @(posedge tb.clk);
    cp_gdc_ps_mon: coverpoint tb.gcd_0.gcd_ctrl_0.ps{
        illegal_bins illegal = (2'h3 => 2'b1);
    }
endgroup

covergroup cg_reg_mon @(posedge tb.clk);
    cp_swap_reg: coverpoint tb.gcd_0.swap_registers{
        bins bin_0 = {0};
        bins bin_1 = {1};
    }
    cp_sub_reg: coverpoint tb.gcd_0.subtract_registers{
        bins bin_0 = {0};
        bins bin_1 = {1};
    }
    cp_both_reg: cross cp_swap_reg, cp_sub_reg{
        illegal_bins illegal = (binsof(cp_swap_reg.bin_1) && binsof(cp_sub_reg.bin_1));
    }
endgroup

property cvr_seq;
    @(posedge tb.clk) tb.reset_n |-> ##[0:2] tb.start |-> ##[70:80] tb.done;
endproperty

property cvr_silly;
    @(posedge tb.clk) tb.done;
endproperty