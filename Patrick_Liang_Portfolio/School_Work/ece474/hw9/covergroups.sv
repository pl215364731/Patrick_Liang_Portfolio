

covergroup cg_out @(posedge tb.clk);
  cp_sr: coverpoint tb.gcd_0.gcd_ctrl_0.swap_registers;
  cp_done: coverpoint tb.gcd_0.gcd_ctrl_0.done_flag;
  cp_both: cross cp_sr, cp_done;
endgroup

covergroup cg_ain @(posedge tb.clk);
   coverpoint tb.gcd_0.a_in iff (tb.start)  {
    bins tiny        = {[0:5]};
    bins yuuuge      = {2100000};
  }
  cp_b_in : coverpoint tb.gcd_0.b_in;
endgroup

covergroup cg_fsmtrans @(posedge tb.clk);
  cp_b : coverpoint tb.gcd_0.gcd_ctrl_0.ps {
	bins rr  = (2'h1 => 2'h2);
	illegal_bins bad_trans = (2'h3 => 2'h1);
        //illegal_bins bad2 = (2'h1 => 2'h2 );
  }
endgroup
