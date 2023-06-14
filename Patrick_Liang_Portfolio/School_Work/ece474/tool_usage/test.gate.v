/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : L-2016.03-SP2
// Date      : Fri Apr  7 14:08:10 2023
/////////////////////////////////////////////////////////////


module test ( a_in, b_in, z_out );
  input [31:0] a_in;
  input [31:0] b_in;
  output z_out;
  wire   N0, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18,
         n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31, n32,
         n33, n34, n35, n36, n37, n38, n39, n40, n41, n42, n43, n44, n45, n46,
         n47, n48, n49, n50, n51, n52, n53, n54, n55, n56, n57, n58, n59, n60,
         n61, n62, n63, n64, n65, n66, n67, n68, n69, n70;
  assign z_out = N0;

  AO21X1 U5 ( .IN1(b_in[31]), .IN2(n5), .IN3(n6), .Q(N0) );
  OA22X1 U6 ( .IN1(b_in[31]), .IN2(n5), .IN3(n7), .IN4(n8), .Q(n6) );
  AND2X1 U7 ( .IN1(n9), .IN2(b_in[30]), .Q(n8) );
  OA221X1 U8 ( .IN1(b_in[29]), .IN2(n10), .IN3(b_in[30]), .IN4(n9), .IN5(n11), 
        .Q(n7) );
  AO221X1 U9 ( .IN1(b_in[28]), .IN2(n12), .IN3(b_in[29]), .IN4(n10), .IN5(n13), 
        .Q(n11) );
  OA221X1 U10 ( .IN1(b_in[27]), .IN2(n14), .IN3(b_in[28]), .IN4(n12), .IN5(n15), .Q(n13) );
  AO221X1 U11 ( .IN1(b_in[26]), .IN2(n16), .IN3(b_in[27]), .IN4(n14), .IN5(n17), .Q(n15) );
  OA221X1 U12 ( .IN1(b_in[25]), .IN2(n18), .IN3(b_in[26]), .IN4(n16), .IN5(n19), .Q(n17) );
  AO221X1 U13 ( .IN1(b_in[24]), .IN2(n20), .IN3(b_in[25]), .IN4(n18), .IN5(n21), .Q(n19) );
  OA221X1 U14 ( .IN1(b_in[23]), .IN2(n22), .IN3(b_in[24]), .IN4(n20), .IN5(n23), .Q(n21) );
  AO221X1 U15 ( .IN1(b_in[22]), .IN2(n24), .IN3(b_in[23]), .IN4(n22), .IN5(n25), .Q(n23) );
  OA221X1 U16 ( .IN1(b_in[21]), .IN2(n26), .IN3(b_in[22]), .IN4(n24), .IN5(n27), .Q(n25) );
  AO221X1 U17 ( .IN1(b_in[20]), .IN2(n28), .IN3(b_in[21]), .IN4(n26), .IN5(n29), .Q(n27) );
  OA221X1 U18 ( .IN1(b_in[19]), .IN2(n30), .IN3(b_in[20]), .IN4(n28), .IN5(n31), .Q(n29) );
  AO221X1 U19 ( .IN1(b_in[18]), .IN2(n32), .IN3(b_in[19]), .IN4(n30), .IN5(n33), .Q(n31) );
  OA221X1 U20 ( .IN1(b_in[17]), .IN2(n34), .IN3(b_in[18]), .IN4(n32), .IN5(n35), .Q(n33) );
  AO221X1 U21 ( .IN1(b_in[16]), .IN2(n36), .IN3(b_in[17]), .IN4(n34), .IN5(n37), .Q(n35) );
  OA221X1 U22 ( .IN1(b_in[15]), .IN2(n38), .IN3(b_in[16]), .IN4(n36), .IN5(n39), .Q(n37) );
  AO221X1 U23 ( .IN1(b_in[14]), .IN2(n40), .IN3(b_in[15]), .IN4(n38), .IN5(n41), .Q(n39) );
  OA221X1 U24 ( .IN1(b_in[13]), .IN2(n42), .IN3(b_in[14]), .IN4(n40), .IN5(n43), .Q(n41) );
  AO221X1 U25 ( .IN1(b_in[12]), .IN2(n44), .IN3(b_in[13]), .IN4(n42), .IN5(n45), .Q(n43) );
  OA221X1 U26 ( .IN1(b_in[11]), .IN2(n46), .IN3(b_in[12]), .IN4(n44), .IN5(n47), .Q(n45) );
  AO221X1 U27 ( .IN1(b_in[10]), .IN2(n48), .IN3(b_in[11]), .IN4(n46), .IN5(n49), .Q(n47) );
  OA221X1 U28 ( .IN1(b_in[9]), .IN2(n50), .IN3(b_in[10]), .IN4(n48), .IN5(n51), 
        .Q(n49) );
  AO221X1 U29 ( .IN1(b_in[8]), .IN2(n52), .IN3(b_in[9]), .IN4(n50), .IN5(n53), 
        .Q(n51) );
  OA221X1 U30 ( .IN1(b_in[7]), .IN2(n54), .IN3(b_in[8]), .IN4(n52), .IN5(n55), 
        .Q(n53) );
  AO221X1 U31 ( .IN1(b_in[6]), .IN2(n56), .IN3(b_in[7]), .IN4(n54), .IN5(n57), 
        .Q(n55) );
  OA221X1 U32 ( .IN1(b_in[5]), .IN2(n58), .IN3(b_in[6]), .IN4(n56), .IN5(n59), 
        .Q(n57) );
  AO221X1 U33 ( .IN1(b_in[4]), .IN2(n60), .IN3(b_in[5]), .IN4(n58), .IN5(n61), 
        .Q(n59) );
  OA221X1 U34 ( .IN1(b_in[3]), .IN2(n62), .IN3(b_in[4]), .IN4(n60), .IN5(n63), 
        .Q(n61) );
  AO222X1 U35 ( .IN1(n64), .IN2(n65), .IN3(b_in[2]), .IN4(n66), .IN5(b_in[3]), 
        .IN6(n62), .Q(n63) );
  NAND2X0 U36 ( .IN1(a_in[2]), .IN2(n67), .QN(n66) );
  INVX0 U37 ( .IN(a_in[2]), .QN(n65) );
  INVX0 U38 ( .IN(n67), .QN(n64) );
  AO22X1 U39 ( .IN1(a_in[1]), .IN2(n68), .IN3(n69), .IN4(a_in[0]), .Q(n67) );
  NOR2X0 U40 ( .IN1(b_in[0]), .IN2(n70), .QN(n69) );
  NOR2X0 U41 ( .IN1(a_in[1]), .IN2(n68), .QN(n70) );
  INVX0 U42 ( .IN(b_in[1]), .QN(n68) );
  INVX0 U43 ( .IN(a_in[3]), .QN(n62) );
  INVX0 U44 ( .IN(a_in[4]), .QN(n60) );
  INVX0 U45 ( .IN(a_in[5]), .QN(n58) );
  INVX0 U46 ( .IN(a_in[6]), .QN(n56) );
  INVX0 U47 ( .IN(a_in[7]), .QN(n54) );
  INVX0 U48 ( .IN(a_in[8]), .QN(n52) );
  INVX0 U49 ( .IN(a_in[9]), .QN(n50) );
  INVX0 U50 ( .IN(a_in[10]), .QN(n48) );
  INVX0 U51 ( .IN(a_in[11]), .QN(n46) );
  INVX0 U52 ( .IN(a_in[12]), .QN(n44) );
  INVX0 U53 ( .IN(a_in[13]), .QN(n42) );
  INVX0 U54 ( .IN(a_in[14]), .QN(n40) );
  INVX0 U55 ( .IN(a_in[15]), .QN(n38) );
  INVX0 U56 ( .IN(a_in[16]), .QN(n36) );
  INVX0 U57 ( .IN(a_in[17]), .QN(n34) );
  INVX0 U58 ( .IN(a_in[18]), .QN(n32) );
  INVX0 U59 ( .IN(a_in[19]), .QN(n30) );
  INVX0 U60 ( .IN(a_in[20]), .QN(n28) );
  INVX0 U61 ( .IN(a_in[21]), .QN(n26) );
  INVX0 U62 ( .IN(a_in[22]), .QN(n24) );
  INVX0 U63 ( .IN(a_in[23]), .QN(n22) );
  INVX0 U64 ( .IN(a_in[24]), .QN(n20) );
  INVX0 U65 ( .IN(a_in[25]), .QN(n18) );
  INVX0 U66 ( .IN(a_in[26]), .QN(n16) );
  INVX0 U67 ( .IN(a_in[27]), .QN(n14) );
  INVX0 U68 ( .IN(a_in[28]), .QN(n12) );
  INVX0 U69 ( .IN(a_in[30]), .QN(n9) );
  INVX0 U70 ( .IN(a_in[29]), .QN(n10) );
  INVX0 U71 ( .IN(a_in[31]), .QN(n5) );
endmodule

