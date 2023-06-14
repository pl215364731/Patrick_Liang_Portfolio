/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : L-2016.03-SP2
// Date      : Thu Apr 27 16:42:04 2023
/////////////////////////////////////////////////////////////


module arbiter ( clk, rst_n, req, dly, done, reset, gnt, tout );
  input clk, rst_n, req, dly, done, reset;
  output gnt, tout;
  wire   N18, N19, N20, N21, N22, N23, N24, n3, n4, n19, n20, n21, n22, n23,
         n24, n25, n26, n27, n28, n29, n30, n31, n32, n33, n34, n35, n36, n37,
         n38;

  DFFX1 \counter_reg[0]  ( .D(N18), .CLK(clk), .QN(n36) );
  DFFX1 \current_state_reg[1]  ( .D(N21), .CLK(clk), .QN(n4) );
  DFFX1 \current_state_reg[4]  ( .D(N24), .CLK(clk), .Q(tout), .QN(n20) );
  DFFX1 \current_state_reg[3]  ( .D(N23), .CLK(clk), .QN(n37) );
  DFFX1 \current_state_reg[0]  ( .D(N20), .CLK(clk), .QN(n38) );
  DFFX1 \current_state_reg[2]  ( .D(N22), .CLK(clk), .Q(n19), .QN(n3) );
  DFFX1 \counter_reg[1]  ( .D(N19), .CLK(clk), .Q(n35) );
  NAND2X0 U25 ( .IN1(n4), .IN2(n3), .QN(gnt) );
  NOR2X0 U26 ( .IN1(n21), .IN2(n22), .QN(N24) );
  OA22X1 U27 ( .IN1(n4), .IN2(n23), .IN3(reset), .IN4(n20), .Q(n21) );
  INVX0 U28 ( .IN(n24), .QN(n23) );
  AND3X1 U29 ( .IN1(rst_n), .IN2(n25), .IN3(n26), .Q(N23) );
  INVX0 U30 ( .IN(dly), .QN(n25) );
  AND3X1 U31 ( .IN1(dly), .IN2(n26), .IN3(rst_n), .Q(N22) );
  AO221X1 U32 ( .IN1(n27), .IN2(done), .IN3(reset), .IN4(tout), .IN5(n19), .Q(
        n26) );
  NOR2X0 U33 ( .IN1(n4), .IN2(n24), .QN(n27) );
  NOR2X0 U34 ( .IN1(n28), .IN2(n22), .QN(N21) );
  OA22X1 U35 ( .IN1(n24), .IN2(n29), .IN3(n30), .IN4(n31), .Q(n28) );
  OR2X1 U36 ( .IN1(done), .IN2(n4), .Q(n29) );
  AO21X1 U37 ( .IN1(n32), .IN2(n31), .IN3(n22), .Q(N20) );
  INVX0 U38 ( .IN(rst_n), .QN(n22) );
  INVX0 U39 ( .IN(req), .QN(n31) );
  AO22X1 U40 ( .IN1(n33), .IN2(n24), .IN3(n35), .IN4(N18), .Q(N19) );
  NOR2X0 U41 ( .IN1(n35), .IN2(n36), .QN(n24) );
  AND2X1 U42 ( .IN1(n36), .IN2(n33), .Q(N18) );
  AND4X1 U43 ( .IN1(n30), .IN2(rst_n), .IN3(n34), .IN4(n3), .Q(n33) );
  NOR2X0 U44 ( .IN1(tout), .IN2(n4), .QN(n34) );
  INVX0 U45 ( .IN(n32), .QN(n30) );
  NAND2X0 U46 ( .IN1(n37), .IN2(n38), .QN(n32) );
endmodule

