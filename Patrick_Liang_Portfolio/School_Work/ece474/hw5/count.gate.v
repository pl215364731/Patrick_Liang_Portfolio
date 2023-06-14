/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : L-2016.03-SP2
// Date      : Fri May 12 14:17:07 2023
/////////////////////////////////////////////////////////////


module count_DW01_inc_0 ( A, SUM );
  input [7:0] A;
  output [7:0] SUM;

  wire   [7:2] carry;

  HADDX1 U1_1_1 ( .A0(A[1]), .B0(A[0]), .C1(carry[2]), .SO(SUM[1]) );
  HADDX1 U1_1_6 ( .A0(A[6]), .B0(carry[6]), .C1(carry[7]), .SO(SUM[6]) );
  HADDX1 U1_1_2 ( .A0(A[2]), .B0(carry[2]), .C1(carry[3]), .SO(SUM[2]) );
  HADDX1 U1_1_5 ( .A0(A[5]), .B0(carry[5]), .C1(carry[6]), .SO(SUM[5]) );
  HADDX1 U1_1_4 ( .A0(A[4]), .B0(carry[4]), .C1(carry[5]), .SO(SUM[4]) );
  HADDX1 U1_1_3 ( .A0(A[3]), .B0(carry[3]), .C1(carry[4]), .SO(SUM[3]) );
  INVX0 U1 ( .IN(A[0]), .QN(SUM[0]) );
  XOR2X1 U2 ( .IN1(carry[7]), .IN2(A[7]), .Q(SUM[7]) );
endmodule


module count_DW01_inc_1 ( A, SUM );
  input [7:0] A;
  output [7:0] SUM;

  wire   [7:2] carry;

  HADDX1 U1_1_1 ( .A0(A[1]), .B0(A[0]), .C1(carry[2]), .SO(SUM[1]) );
  HADDX1 U1_1_6 ( .A0(A[6]), .B0(carry[6]), .C1(carry[7]), .SO(SUM[6]) );
  HADDX1 U1_1_2 ( .A0(A[2]), .B0(carry[2]), .C1(carry[3]), .SO(SUM[2]) );
  HADDX1 U1_1_5 ( .A0(A[5]), .B0(carry[5]), .C1(carry[6]), .SO(SUM[5]) );
  HADDX1 U1_1_4 ( .A0(A[4]), .B0(carry[4]), .C1(carry[5]), .SO(SUM[4]) );
  HADDX1 U1_1_3 ( .A0(A[3]), .B0(carry[3]), .C1(carry[4]), .SO(SUM[3]) );
  INVX0 U1 ( .IN(A[0]), .QN(SUM[0]) );
  XOR2X1 U2 ( .IN1(carry[7]), .IN2(A[7]), .Q(SUM[7]) );
endmodule


module count ( a_in, sel, clk, start, rst, done, cntout );
  input [7:0] a_in;
  input [1:0] sel;
  output [7:0] cntout;
  input clk, start, rst;
  output done;
  wire   N26, N27, N28, N29, N30, N31, N32, N33, N34, N35, N36, N37, N38, N39,
         N40, N41, n6, n7, n12, n28, n29, n30, n31, n32, n33, n34, n35, n36,
         n37, n38, n39, n40, n41, n42, n43, n44, n45, n46, n47, n48, n49, n50,
         n51, n52, n53, n54, n55, n56, n57, n58, n59, n60, n61, n62, n63, n64,
         n65, n66, n67, n68, n69, n70, n71, n72, n73, n74, n75, n76, n77, n78,
         n79, n80, n81, n82, n83, n84, n85, n86, n87, n88, n89, n90, n91, n92,
         n93, n94, n95, n96, n97, n98, n99, n100;
  wire   [7:0] count_0;
  wire   [7:0] count_1;
  wire   [3:0] next_state;

  count_DW01_inc_0 add_45 ( .A(count_0), .SUM({N41, N40, N39, N38, N37, N36, 
        N35, N34}) );
  count_DW01_inc_1 add_43 ( .A(count_1), .SUM({N33, N32, N31, N30, N29, N28, 
        N27, N26}) );
  DFFASX1 \current_state_reg[0]  ( .D(next_state[0]), .CLK(clk), .SETB(n100), 
        .Q(n61), .QN(n12) );
  DFFARX1 \current_state_reg[1]  ( .D(next_state[1]), .CLK(clk), .RSTB(n100), 
        .Q(n57), .QN(n93) );
  DFFARX1 \counter_reg[2]  ( .D(n54), .CLK(clk), .RSTB(n100), .Q(n60), .QN(n6)
         );
  DFFARX1 \current_state_reg[3]  ( .D(next_state[3]), .CLK(clk), .RSTB(n100), 
        .Q(n56), .QN(n95) );
  DFFARX1 \current_state_reg[2]  ( .D(next_state[2]), .CLK(clk), .RSTB(n100), 
        .Q(n55), .QN(n94) );
  DFFARX1 \a_in_d_reg[7]  ( .D(n36), .CLK(clk), .RSTB(n100), .Q(n64) );
  DFFARX1 \a_in_d_reg[6]  ( .D(n37), .CLK(clk), .RSTB(n100), .Q(n67), .QN(n98)
         );
  DFFARX1 \a_in_d_reg[5]  ( .D(n38), .CLK(clk), .RSTB(n100), .Q(n63) );
  DFFARX1 \a_in_d_reg[4]  ( .D(n39), .CLK(clk), .RSTB(n100), .Q(n58) );
  DFFARX1 \a_in_d_reg[3]  ( .D(n40), .CLK(clk), .RSTB(n100), .Q(n59) );
  DFFARX1 \a_in_d_reg[2]  ( .D(n41), .CLK(clk), .RSTB(n100), .Q(n62) );
  DFFARX1 \a_in_d_reg[1]  ( .D(n42), .CLK(clk), .RSTB(n100), .Q(n66), .QN(n97)
         );
  DFFARX1 \a_in_d_reg[0]  ( .D(n43), .CLK(clk), .RSTB(n100), .Q(n65), .QN(n96)
         );
  DFFARX1 \counter_reg[0]  ( .D(n53), .CLK(clk), .RSTB(n100), .QN(n99) );
  DFFARX1 \counter_reg[1]  ( .D(n52), .CLK(clk), .RSTB(n100), .QN(n7) );
  DFFARX1 \count_0_reg[7]  ( .D(n28), .CLK(clk), .RSTB(n100), .Q(count_0[7])
         );
  DFFARX1 \count_1_reg[7]  ( .D(n44), .CLK(clk), .RSTB(n100), .Q(count_1[7])
         );
  DFFARX1 \count_0_reg[1]  ( .D(n35), .CLK(clk), .RSTB(n100), .Q(count_0[1])
         );
  DFFARX1 \count_0_reg[2]  ( .D(n33), .CLK(clk), .RSTB(n100), .Q(count_0[2])
         );
  DFFARX1 \count_0_reg[3]  ( .D(n32), .CLK(clk), .RSTB(n100), .Q(count_0[3])
         );
  DFFARX1 \count_0_reg[4]  ( .D(n31), .CLK(clk), .RSTB(n100), .Q(count_0[4])
         );
  DFFARX1 \count_0_reg[5]  ( .D(n30), .CLK(clk), .RSTB(n100), .Q(count_0[5])
         );
  DFFARX1 \count_0_reg[6]  ( .D(n29), .CLK(clk), .RSTB(n100), .Q(count_0[6])
         );
  DFFARX1 \count_1_reg[1]  ( .D(n51), .CLK(clk), .RSTB(n100), .Q(count_1[1])
         );
  DFFARX1 \count_1_reg[2]  ( .D(n49), .CLK(clk), .RSTB(n100), .Q(count_1[2])
         );
  DFFARX1 \count_1_reg[3]  ( .D(n48), .CLK(clk), .RSTB(n100), .Q(count_1[3])
         );
  DFFARX1 \count_1_reg[4]  ( .D(n47), .CLK(clk), .RSTB(n100), .Q(count_1[4])
         );
  DFFARX1 \count_1_reg[5]  ( .D(n46), .CLK(clk), .RSTB(n100), .Q(count_1[5])
         );
  DFFARX1 \count_1_reg[6]  ( .D(n45), .CLK(clk), .RSTB(n100), .Q(count_1[6])
         );
  DFFARX1 \count_0_reg[0]  ( .D(n34), .CLK(clk), .RSTB(n100), .Q(count_0[0])
         );
  DFFARX1 \count_1_reg[0]  ( .D(n50), .CLK(clk), .RSTB(n100), .Q(count_1[0])
         );
  AND3X1 U64 ( .IN1(n68), .IN2(n57), .IN3(sel[1]), .Q(next_state[3]) );
  AND3X1 U65 ( .IN1(n68), .IN2(n57), .IN3(sel[0]), .Q(next_state[2]) );
  AO22X1 U66 ( .IN1(start), .IN2(n61), .IN3(n69), .IN4(n57), .Q(next_state[1])
         );
  INVX0 U67 ( .IN(n68), .QN(n69) );
  OAI21X1 U68 ( .IN1(n12), .IN2(start), .IN3(n70), .QN(next_state[0]) );
  INVX0 U69 ( .IN(rst), .QN(n100) );
  AO222X1 U70 ( .IN1(n71), .IN2(n72), .IN3(n73), .IN4(n74), .IN5(n75), .IN6(
        n60), .Q(n54) );
  MUX21X1 U71 ( .IN1(n76), .IN2(n77), .S(n99), .Q(n53) );
  NOR2X0 U72 ( .IN1(n76), .IN2(n78), .QN(n77) );
  MUX21X1 U73 ( .IN1(n75), .IN2(n73), .S(n7), .Q(n52) );
  NOR3X0 U74 ( .IN1(n76), .IN2(n99), .IN3(n78), .QN(n73) );
  AO21X1 U75 ( .IN1(n99), .IN2(n72), .IN3(n76), .Q(n75) );
  INVX0 U76 ( .IN(n78), .QN(n72) );
  AO22X1 U77 ( .IN1(n79), .IN2(count_1[1]), .IN3(N27), .IN4(n80), .Q(n51) );
  AO22X1 U78 ( .IN1(n79), .IN2(count_1[0]), .IN3(N26), .IN4(n80), .Q(n50) );
  AO22X1 U79 ( .IN1(n79), .IN2(count_1[2]), .IN3(N28), .IN4(n80), .Q(n49) );
  AO22X1 U80 ( .IN1(n79), .IN2(count_1[3]), .IN3(N29), .IN4(n80), .Q(n48) );
  AO22X1 U81 ( .IN1(n79), .IN2(count_1[4]), .IN3(N30), .IN4(n80), .Q(n47) );
  AO22X1 U82 ( .IN1(n79), .IN2(count_1[5]), .IN3(N31), .IN4(n80), .Q(n46) );
  AO22X1 U83 ( .IN1(n79), .IN2(count_1[6]), .IN3(N32), .IN4(n80), .Q(n45) );
  AO22X1 U84 ( .IN1(n79), .IN2(count_1[7]), .IN3(N33), .IN4(n80), .Q(n44) );
  NOR2X0 U85 ( .IN1(n79), .IN2(n78), .QN(n80) );
  AO21X1 U86 ( .IN1(n81), .IN2(n82), .IN3(n76), .Q(n79) );
  INVX0 U87 ( .IN(n83), .QN(n81) );
  MUX21X1 U88 ( .IN1(a_in[0]), .IN2(n65), .S(n82), .Q(n43) );
  MUX21X1 U89 ( .IN1(a_in[1]), .IN2(n66), .S(n82), .Q(n42) );
  MUX21X1 U90 ( .IN1(a_in[2]), .IN2(n62), .S(n82), .Q(n41) );
  MUX21X1 U91 ( .IN1(a_in[3]), .IN2(n59), .S(n82), .Q(n40) );
  MUX21X1 U92 ( .IN1(a_in[4]), .IN2(n58), .S(n82), .Q(n39) );
  MUX21X1 U93 ( .IN1(a_in[5]), .IN2(n63), .S(n82), .Q(n38) );
  MUX21X1 U94 ( .IN1(a_in[6]), .IN2(n67), .S(n82), .Q(n37) );
  MUX21X1 U95 ( .IN1(a_in[7]), .IN2(n64), .S(n82), .Q(n36) );
  AO22X1 U96 ( .IN1(n84), .IN2(count_0[1]), .IN3(N35), .IN4(n85), .Q(n35) );
  AO22X1 U97 ( .IN1(n84), .IN2(count_0[0]), .IN3(N34), .IN4(n85), .Q(n34) );
  AO22X1 U98 ( .IN1(n84), .IN2(count_0[2]), .IN3(N36), .IN4(n85), .Q(n33) );
  AO22X1 U99 ( .IN1(n84), .IN2(count_0[3]), .IN3(N37), .IN4(n85), .Q(n32) );
  AO22X1 U100 ( .IN1(n84), .IN2(count_0[4]), .IN3(N38), .IN4(n85), .Q(n31) );
  AO22X1 U101 ( .IN1(n84), .IN2(count_0[5]), .IN3(N39), .IN4(n85), .Q(n30) );
  AO22X1 U102 ( .IN1(n84), .IN2(count_0[6]), .IN3(N40), .IN4(n85), .Q(n29) );
  AO22X1 U103 ( .IN1(n84), .IN2(count_0[7]), .IN3(N41), .IN4(n85), .Q(n28) );
  NOR2X0 U104 ( .IN1(n84), .IN2(n78), .QN(n85) );
  AO21X1 U105 ( .IN1(n83), .IN2(n82), .IN3(n76), .Q(n84) );
  OA21X1 U106 ( .IN1(n78), .IN2(done), .IN3(n82), .Q(n76) );
  NAND2X0 U107 ( .IN1(n12), .IN2(n57), .QN(n78) );
  NAND3X0 U108 ( .IN1(n70), .IN2(n61), .IN3(n93), .QN(n82) );
  INVX0 U109 ( .IN(done), .QN(n70) );
  NAND2X0 U110 ( .IN1(n94), .IN2(n95), .QN(done) );
  AO21X1 U111 ( .IN1(n68), .IN2(n64), .IN3(n86), .Q(n83) );
  MUX21X1 U112 ( .IN1(n87), .IN2(n88), .S(n99), .Q(n86) );
  AO221X1 U113 ( .IN1(n74), .IN2(n62), .IN3(n71), .IN4(n58), .IN5(n89), .Q(n88) );
  MUX21X1 U114 ( .IN1(n90), .IN2(n91), .S(n7), .Q(n89) );
  NOR2X0 U115 ( .IN1(n96), .IN2(n60), .QN(n91) );
  NOR2X0 U116 ( .IN1(n98), .IN2(n6), .QN(n90) );
  AO222X1 U117 ( .IN1(n74), .IN2(n59), .IN3(n92), .IN4(n7), .IN5(n71), .IN6(
        n63), .Q(n87) );
  AND2X1 U118 ( .IN1(n7), .IN2(n60), .Q(n71) );
  NOR2X0 U119 ( .IN1(n97), .IN2(n60), .QN(n92) );
  NOR2X0 U120 ( .IN1(n60), .IN2(n7), .QN(n74) );
  NOR3X0 U121 ( .IN1(n7), .IN2(n99), .IN3(n6), .QN(n68) );
  AO22X1 U122 ( .IN1(n55), .IN2(count_0[7]), .IN3(n56), .IN4(count_1[7]), .Q(
        cntout[7]) );
  AO22X1 U123 ( .IN1(n55), .IN2(count_0[6]), .IN3(n56), .IN4(count_1[6]), .Q(
        cntout[6]) );
  AO22X1 U124 ( .IN1(n55), .IN2(count_0[5]), .IN3(n56), .IN4(count_1[5]), .Q(
        cntout[5]) );
  AO22X1 U125 ( .IN1(n55), .IN2(count_0[4]), .IN3(n56), .IN4(count_1[4]), .Q(
        cntout[4]) );
  AO22X1 U126 ( .IN1(n55), .IN2(count_0[3]), .IN3(n56), .IN4(count_1[3]), .Q(
        cntout[3]) );
  AO22X1 U127 ( .IN1(n55), .IN2(count_0[2]), .IN3(n56), .IN4(count_1[2]), .Q(
        cntout[2]) );
  AO22X1 U128 ( .IN1(n55), .IN2(count_0[1]), .IN3(n56), .IN4(count_1[1]), .Q(
        cntout[1]) );
  AO22X1 U129 ( .IN1(n55), .IN2(count_0[0]), .IN3(n56), .IN4(count_1[0]), .Q(
        cntout[0]) );
endmodule

