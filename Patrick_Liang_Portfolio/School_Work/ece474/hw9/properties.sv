// Used gcd.start as triggering event because the assertion of gcd.start is what starts this property
property p_startonce;
    @(posedge gcd.start) gcd.start |=> always !gcd.start;
endproperty

// Used gcd.start as triggering event because the requirement said "whenever start is asserted"
property p_evdone;
    @(posedge gcd.start) ##[0:$] gcd.done;
endproperty

// Used gcd.start as triggering event because the requirement said "at every start of calculation" 
// and the start of calculation is defined by gcd.start
property p_sanity;
    @(posedge gcd.start) if(gcd.a_in <= gcd.b_in) s_eventually (gcd.result <= gcd.a_in);
endproperty

// Used gcd.done as triggering event because the requirement said "when calculation is done".
// gcd.done is when the calculation concludes.
property p_divides;
    @(posedge gcd.done) (((gcd.a_in % gcd.result) == 0) && ((gcd.b_in % gcd.result) == 0));
endproperty