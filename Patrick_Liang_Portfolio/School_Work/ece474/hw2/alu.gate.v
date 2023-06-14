/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : L-2016.03-SP2
// Date      : Fri Apr 21 15:28:42 2023
/////////////////////////////////////////////////////////////


module alu_DW01_addsub_0 ( A, B, CI, ADD_SUB, SUM, CO );
  input [8:0] A;
  input [8:0] B;
  output [8:0] SUM;
  input CI, ADD_SUB;
  output CO;

  wire   [9:0] carry;
  wire   [8:0] B_AS;
  assign carry[0] = ADD_SUB;

  XOR3X1 U1_8 ( .IN1(A[8]), .IN2(carry[0]), .IN3(carry[8]), .Q(SUM[8]) );
  FADDX1 U1_7 ( .A(A[7]), .B(B_AS[7]), .CI(carry[7]), .CO(carry[8]), .S(SUM[7]) );
  FADDX1 U1_6 ( .A(A[6]), .B(B_AS[6]), .CI(carry[6]), .CO(carry[7]), .S(SUM[6]) );
  FADDX1 U1_5 ( .A(A[5]), .B(B_AS[5]), .CI(carry[5]), .CO(carry[6]), .S(SUM[5]) );
  FADDX1 U1_4 ( .A(A[4]), .B(B_AS[4]), .CI(carry[4]), .CO(carry[5]), .S(SUM[4]) );
  FADDX1 U1_3 ( .A(A[3]), .B(B_AS[3]), .CI(carry[3]), .CO(carry[4]), .S(SUM[3]) );
  FADDX1 U1_2 ( .A(A[2]), .B(B_AS[2]), .CI(carry[2]), .CO(carry[3]), .S(SUM[2]) );
  FADDX1 U1_1 ( .A(A[1]), .B(B_AS[1]), .CI(carry[1]), .CO(carry[2]), .S(SUM[1]) );
  FADDX1 U1_0 ( .A(A[0]), .B(B_AS[0]), .CI(carry[0]), .CO(carry[1]), .S(SUM[0]) );
  XOR2X1 U1 ( .IN1(B[7]), .IN2(carry[0]), .Q(B_AS[7]) );
  XOR2X1 U2 ( .IN1(B[6]), .IN2(carry[0]), .Q(B_AS[6]) );
  XOR2X1 U3 ( .IN1(B[5]), .IN2(carry[0]), .Q(B_AS[5]) );
  XOR2X1 U4 ( .IN1(B[4]), .IN2(carry[0]), .Q(B_AS[4]) );
  XOR2X1 U5 ( .IN1(B[3]), .IN2(carry[0]), .Q(B_AS[3]) );
  XOR2X1 U6 ( .IN1(B[2]), .IN2(carry[0]), .Q(B_AS[2]) );
  XOR2X1 U7 ( .IN1(B[1]), .IN2(carry[0]), .Q(B_AS[1]) );
  XOR2X1 U8 ( .IN1(B[0]), .IN2(carry[0]), .Q(B_AS[0]) );
endmodule


module alu ( in_a, in_b, opcode, alu_out, alu_zero, alu_carry );
  input [7:0] in_a;
  input [7:0] in_b;
  input [3:0] opcode;
  output [7:0] alu_out;
  output alu_zero, alu_carry;
  wire   N12, N13, N14, N15, N16, N17, N18, N28, N29, N30, N31, N32, N33, N34,
         N35, N112, N113, N114, N115, N116, N117, N118, N119, N120,
         \U3/U1/Z_0 , \U3/U1/Z_1 , \U3/U1/Z_2 , \U3/U1/Z_3 , \U3/U1/Z_4 ,
         \U3/U1/Z_5 , \U3/U1/Z_6 , \U3/U1/Z_7 , \U3/U2/Z_0 , \U3/U2/Z_1 ,
         \U3/U2/Z_2 , \U3/U2/Z_3 , \U3/U2/Z_4 , \U3/U2/Z_5 , \U3/U2/Z_6 ,
         \U3/U2/Z_7 , \U3/U3/Z_0 , n129, n130, n131, n132, n133, n134, n135,
         n136, n137, n138, n139, n140, n141, n142, n143, n144, n145, n146,
         n147, n148, n149, n150, n151, n152, n153, n154, n155, n156, n157,
         n158, n159, n160, n161, n162, n163, n164, n165, n166, n167, n168,
         n169, n170, n171, n172, n173, n174, n175, n176, n177, n178, n179,
         n180, n181, n182, n183, n184, n185, n186, n187, n188, n189, n190,
         n191, n192, n193, n194, n195, n196, n197, n198, n199, n200, n201,
         n202, n203, n204, n205, n206, n207, n208, n209, n210, n211, n212,
         n213, n214, n215, n216, n217, n218, n219, n220, n221, n222, n223,
         n224, n225, n226, n227, n228, n229, n230, n231, n232, n233, n234,
         n235, n236, n237, n238, n239, n240, n241, n242, n243, n244, n245,
         n246, n247, n248, n249, n250, n251, n252;

  alu_DW01_addsub_0 r31 ( .A({n252, \U3/U1/Z_7 , \U3/U1/Z_6 , \U3/U1/Z_5 , 
        \U3/U1/Z_4 , \U3/U1/Z_3 , \U3/U1/Z_2 , \U3/U1/Z_1 , \U3/U1/Z_0 }), .B(
        {1'b0, \U3/U2/Z_7 , \U3/U2/Z_6 , \U3/U2/Z_5 , \U3/U2/Z_4 , \U3/U2/Z_3 , 
        \U3/U2/Z_2 , \U3/U2/Z_1 , \U3/U2/Z_0 }), .CI(1'b0), .ADD_SUB(
        \U3/U3/Z_0 ), .SUM({N120, N119, N118, N117, N116, N115, N114, N113, 
        N112}) );
  INVX0 U147 ( .IN(n169), .QN(n190) );
  INVX0 U148 ( .IN(n168), .QN(n185) );
  INVX0 U149 ( .IN(n136), .QN(n188) );
  INVX0 U150 ( .IN(n137), .QN(n189) );
  INVX0 U151 ( .IN(opcode[1]), .QN(n186) );
  INVX0 U152 ( .IN(opcode[0]), .QN(n184) );
  INVX0 U153 ( .IN(opcode[2]), .QN(n187) );
  NOR2X0 U154 ( .IN1(n187), .IN2(opcode[3]), .QN(n136) );
  NOR2X0 U155 ( .IN1(n184), .IN2(n188), .QN(n138) );
  AND2X1 U156 ( .IN1(n138), .IN2(opcode[1]), .Q(n175) );
  NOR2X0 U157 ( .IN1(n186), .IN2(opcode[0]), .QN(n167) );
  AND2X1 U158 ( .IN1(n167), .IN2(n136), .Q(n178) );
  XOR2X1 U159 ( .IN1(opcode[3]), .IN2(opcode[0]), .Q(n137) );
  OAI22X1 U160 ( .IN1(n137), .IN2(n186), .IN3(n189), .IN4(opcode[3]), .QN(n140) );
  NAND2X0 U161 ( .IN1(n184), .IN2(n186), .QN(n145) );
  NOR2X0 U162 ( .IN1(n188), .IN2(n145), .QN(n181) );
  AO21X1 U163 ( .IN1(n140), .IN2(n187), .IN3(n181), .Q(n142) );
  AND2X1 U164 ( .IN1(n138), .IN2(n186), .Q(n176) );
  OA22X1 U165 ( .IN1(n247), .IN2(opcode[1]), .IN3(in_a[0]), .IN4(n186), .Q(
        n139) );
  NOR4X0 U166 ( .IN1(opcode[2]), .IN2(n189), .IN3(n140), .IN4(n139), .QN(n141)
         );
  AO221X1 U167 ( .IN1(N112), .IN2(n142), .IN3(n250), .IN4(n176), .IN5(n141), 
        .Q(n143) );
  AO221X1 U168 ( .IN1(N35), .IN2(n175), .IN3(n251), .IN4(n178), .IN5(n143), 
        .Q(alu_out[0]) );
  NAND2X0 U169 ( .IN1(opcode[3]), .IN2(n187), .QN(n169) );
  NOR2X0 U170 ( .IN1(n169), .IN2(n145), .QN(n170) );
  AND2X1 U171 ( .IN1(n190), .IN2(n167), .Q(n180) );
  AO22X1 U172 ( .IN1(n247), .IN2(n180), .IN3(N34), .IN4(n175), .Q(n144) );
  AO221X1 U173 ( .IN1(n170), .IN2(in_a[2]), .IN3(N18), .IN4(n176), .IN5(n144), 
        .Q(n147) );
  NOR3X0 U174 ( .IN1(n169), .IN2(opcode[1]), .IN3(n184), .QN(n177) );
  NOR2X0 U175 ( .IN1(opcode[2]), .IN2(opcode[3]), .QN(n173) );
  NAND2X0 U176 ( .IN1(opcode[0]), .IN2(opcode[1]), .QN(n168) );
  AO221X1 U177 ( .IN1(n173), .IN2(n145), .IN3(n185), .IN4(n190), .IN5(n181), 
        .Q(n163) );
  AO222X1 U178 ( .IN1(n248), .IN2(n178), .IN3(in_a[0]), .IN4(n177), .IN5(N113), 
        .IN6(n163), .Q(n146) );
  OR2X1 U179 ( .IN1(n147), .IN2(n146), .Q(alu_out[1]) );
  AO22X1 U180 ( .IN1(n245), .IN2(n180), .IN3(N33), .IN4(n175), .Q(n148) );
  AO221X1 U181 ( .IN1(n170), .IN2(in_a[3]), .IN3(N17), .IN4(n176), .IN5(n148), 
        .Q(n150) );
  AO222X1 U182 ( .IN1(n246), .IN2(n178), .IN3(n177), .IN4(in_a[1]), .IN5(N114), 
        .IN6(n163), .Q(n149) );
  OR2X1 U183 ( .IN1(n150), .IN2(n149), .Q(alu_out[2]) );
  AO22X1 U184 ( .IN1(n243), .IN2(n180), .IN3(N32), .IN4(n175), .Q(n151) );
  AO221X1 U185 ( .IN1(n170), .IN2(in_a[4]), .IN3(N16), .IN4(n176), .IN5(n151), 
        .Q(n153) );
  AO222X1 U186 ( .IN1(n244), .IN2(n178), .IN3(n177), .IN4(in_a[2]), .IN5(N115), 
        .IN6(n163), .Q(n152) );
  OR2X1 U187 ( .IN1(n153), .IN2(n152), .Q(alu_out[3]) );
  AO22X1 U188 ( .IN1(n241), .IN2(n180), .IN3(N31), .IN4(n175), .Q(n154) );
  AO221X1 U189 ( .IN1(n170), .IN2(in_a[5]), .IN3(N15), .IN4(n176), .IN5(n154), 
        .Q(n156) );
  AO222X1 U190 ( .IN1(n242), .IN2(n178), .IN3(n177), .IN4(in_a[3]), .IN5(N116), 
        .IN6(n163), .Q(n155) );
  OR2X1 U191 ( .IN1(n156), .IN2(n155), .Q(alu_out[4]) );
  AO22X1 U192 ( .IN1(n239), .IN2(n180), .IN3(N30), .IN4(n175), .Q(n157) );
  AO221X1 U193 ( .IN1(n170), .IN2(in_a[6]), .IN3(N14), .IN4(n176), .IN5(n157), 
        .Q(n159) );
  AO222X1 U194 ( .IN1(n240), .IN2(n178), .IN3(n177), .IN4(in_a[4]), .IN5(N117), 
        .IN6(n163), .Q(n158) );
  OR2X1 U195 ( .IN1(n159), .IN2(n158), .Q(alu_out[5]) );
  AO22X1 U196 ( .IN1(n237), .IN2(n180), .IN3(N29), .IN4(n175), .Q(n160) );
  AO221X1 U197 ( .IN1(n170), .IN2(in_a[7]), .IN3(N13), .IN4(n176), .IN5(n160), 
        .Q(n162) );
  AO222X1 U198 ( .IN1(n238), .IN2(n178), .IN3(n177), .IN4(in_a[5]), .IN5(N118), 
        .IN6(n163), .Q(n161) );
  OR2X1 U199 ( .IN1(n162), .IN2(n161), .Q(alu_out[6]) );
  AOI222X1 U200 ( .IN1(N119), .IN2(n163), .IN3(n177), .IN4(in_a[6]), .IN5(n236), .IN6(n178), .QN(n165) );
  AOI222X1 U201 ( .IN1(n235), .IN2(n180), .IN3(N12), .IN4(n176), .IN5(N28), 
        .IN6(n175), .QN(n164) );
  NAND2X0 U202 ( .IN1(n165), .IN2(n164), .QN(alu_out[7]) );
  NOR2X0 U203 ( .IN1(opcode[1]), .IN2(n184), .QN(n166) );
  AO222X1 U204 ( .IN1(n129), .IN2(n167), .IN3(n166), .IN4(n129), .IN5(n129), 
        .IN6(n185), .Q(n172) );
  NOR2X0 U205 ( .IN1(n169), .IN2(n168), .QN(n171) );
  AO222X1 U206 ( .IN1(n173), .IN2(n172), .IN3(n171), .IN4(n129), .IN5(n130), 
        .IN6(n170), .Q(n174) );
  AO221X1 U207 ( .IN1(n134), .IN2(n176), .IN3(n132), .IN4(n175), .IN5(n174), 
        .Q(n183) );
  AO22X1 U208 ( .IN1(n133), .IN2(n178), .IN3(n135), .IN4(n177), .Q(n179) );
  AO221X1 U209 ( .IN1(n129), .IN2(n181), .IN3(n131), .IN4(n180), .IN5(n179), 
        .Q(n182) );
  OR2X1 U210 ( .IN1(n183), .IN2(n182), .Q(alu_zero) );
  INVX0 U211 ( .IN(n191), .QN(n236) );
  INVX0 U212 ( .IN(n192), .QN(n238) );
  INVX0 U213 ( .IN(n193), .QN(n240) );
  INVX0 U214 ( .IN(n194), .QN(n242) );
  INVX0 U215 ( .IN(n195), .QN(n244) );
  INVX0 U216 ( .IN(n196), .QN(n246) );
  INVX0 U217 ( .IN(n197), .QN(n248) );
  INVX0 U218 ( .IN(n198), .QN(n250) );
  INVX0 U219 ( .IN(n199), .QN(n251) );
  NOR2X0 U220 ( .IN1(in_a[0]), .IN2(n200), .QN(n135) );
  NOR4X0 U221 ( .IN1(n201), .IN2(n202), .IN3(in_b[4]), .IN4(in_b[3]), .QN(n134) );
  NAND3X0 U222 ( .IN1(n203), .IN2(n204), .IN3(n205), .QN(n202) );
  NAND4X0 U223 ( .IN1(n130), .IN2(n198), .IN3(n206), .IN4(n207), .QN(n201) );
  NOR2X0 U224 ( .IN1(in_b[0]), .IN2(in_a[0]), .QN(n198) );
  NOR2X0 U225 ( .IN1(n208), .IN2(n209), .QN(n133) );
  NAND4X0 U226 ( .IN1(n199), .IN2(n197), .IN3(n196), .IN4(n195), .QN(n209) );
  NAND2X0 U227 ( .IN1(in_b[3]), .IN2(in_a[3]), .QN(n195) );
  NAND2X0 U228 ( .IN1(in_b[2]), .IN2(in_a[2]), .QN(n196) );
  NAND2X0 U229 ( .IN1(in_b[1]), .IN2(in_a[1]), .QN(n197) );
  NAND2X0 U230 ( .IN1(in_b[0]), .IN2(in_a[0]), .QN(n199) );
  NAND4X0 U231 ( .IN1(n194), .IN2(n193), .IN3(n192), .IN4(n191), .QN(n208) );
  NAND2X0 U232 ( .IN1(in_b[7]), .IN2(in_a[7]), .QN(n191) );
  NAND2X0 U233 ( .IN1(in_b[6]), .IN2(in_a[6]), .QN(n192) );
  NAND2X0 U234 ( .IN1(in_b[5]), .IN2(in_a[5]), .QN(n193) );
  NAND2X0 U235 ( .IN1(in_b[4]), .IN2(in_a[4]), .QN(n194) );
  NOR2X0 U236 ( .IN1(n210), .IN2(n211), .QN(n132) );
  OR4X1 U237 ( .IN1(N28), .IN2(N29), .IN3(N30), .IN4(N31), .Q(n211) );
  OR4X1 U238 ( .IN1(N32), .IN2(N33), .IN3(N34), .IN4(N35), .Q(n210) );
  NOR2X0 U239 ( .IN1(n212), .IN2(n213), .QN(n131) );
  NAND4X0 U240 ( .IN1(in_a[0]), .IN2(in_a[1]), .IN3(in_a[2]), .IN4(in_a[3]), 
        .QN(n213) );
  NAND4X0 U241 ( .IN1(in_a[4]), .IN2(in_a[5]), .IN3(in_a[6]), .IN4(in_a[7]), 
        .QN(n212) );
  NOR2X0 U242 ( .IN1(n200), .IN2(in_a[7]), .QN(n130) );
  NAND4X0 U243 ( .IN1(n245), .IN2(n243), .IN3(n247), .IN4(n214), .QN(n200) );
  AND3X1 U244 ( .IN1(n241), .IN2(n237), .IN3(n239), .Q(n214) );
  NOR2X0 U245 ( .IN1(n215), .IN2(n216), .QN(n129) );
  OR4X1 U246 ( .IN1(N113), .IN2(N112), .IN3(N115), .IN4(N114), .Q(n216) );
  OR4X1 U247 ( .IN1(N117), .IN2(N116), .IN3(N119), .IN4(N118), .Q(n215) );
  NAND2X0 U248 ( .IN1(n217), .IN2(n218), .QN(alu_carry) );
  NAND4X0 U249 ( .IN1(opcode[3]), .IN2(opcode[0]), .IN3(n219), .IN4(in_a[7]), 
        .QN(n218) );
  NOR2X0 U250 ( .IN1(opcode[2]), .IN2(opcode[1]), .QN(n219) );
  NAND2X0 U251 ( .IN1(N120), .IN2(n220), .QN(n217) );
  OR2X1 U252 ( .IN1(n221), .IN2(n252), .Q(n220) );
  NOR2X0 U253 ( .IN1(n204), .IN2(n222), .QN(\U3/U2/Z_7 ) );
  NOR2X0 U254 ( .IN1(n203), .IN2(n222), .QN(\U3/U2/Z_6 ) );
  NOR2X0 U255 ( .IN1(n205), .IN2(n222), .QN(\U3/U2/Z_5 ) );
  NOR2X0 U256 ( .IN1(n223), .IN2(n222), .QN(\U3/U2/Z_4 ) );
  NOR2X0 U257 ( .IN1(n224), .IN2(n222), .QN(\U3/U2/Z_3 ) );
  NOR2X0 U258 ( .IN1(n207), .IN2(n222), .QN(\U3/U2/Z_2 ) );
  NOR2X0 U259 ( .IN1(n206), .IN2(n222), .QN(\U3/U2/Z_1 ) );
  NAND3X0 U260 ( .IN1(n225), .IN2(n226), .IN3(n227), .QN(\U3/U2/Z_0 ) );
  MUX21X1 U261 ( .IN1(n228), .IN2(n229), .S(opcode[1]), .Q(n227) );
  NAND2X0 U262 ( .IN1(n230), .IN2(opcode[0]), .QN(n229) );
  NAND3X0 U263 ( .IN1(n184), .IN2(n231), .IN3(opcode[2]), .QN(n228) );
  NAND2X0 U264 ( .IN1(n232), .IN2(in_b[0]), .QN(n225) );
  INVX0 U265 ( .IN(n222), .QN(n232) );
  NAND2X0 U266 ( .IN1(n230), .IN2(n233), .QN(n222) );
  XNOR2X1 U267 ( .IN1(opcode[1]), .IN2(n184), .Q(n233) );
  MUX21X1 U268 ( .IN1(n221), .IN2(n252), .S(n235), .Q(\U3/U1/Z_7 ) );
  MUX21X1 U269 ( .IN1(n221), .IN2(n252), .S(n237), .Q(\U3/U1/Z_6 ) );
  MUX21X1 U270 ( .IN1(n221), .IN2(n252), .S(n239), .Q(\U3/U1/Z_5 ) );
  MUX21X1 U271 ( .IN1(n221), .IN2(n252), .S(n241), .Q(\U3/U1/Z_4 ) );
  MUX21X1 U272 ( .IN1(n221), .IN2(n252), .S(n243), .Q(\U3/U1/Z_3 ) );
  MUX21X1 U273 ( .IN1(n221), .IN2(n252), .S(n245), .Q(\U3/U1/Z_2 ) );
  MUX21X1 U274 ( .IN1(n221), .IN2(n252), .S(n247), .Q(\U3/U1/Z_1 ) );
  MUX21X1 U275 ( .IN1(n221), .IN2(n252), .S(n249), .Q(\U3/U1/Z_0 ) );
  INVX0 U276 ( .IN(in_a[0]), .QN(n249) );
  INVX0 U277 ( .IN(n226), .QN(n252) );
  NAND4X0 U278 ( .IN1(opcode[3]), .IN2(opcode[1]), .IN3(opcode[0]), .IN4(n187), 
        .QN(n226) );
  AO21X1 U279 ( .IN1(n230), .IN2(opcode[0]), .IN3(\U3/U3/Z_0 ), .Q(n221) );
  AND3X1 U280 ( .IN1(n184), .IN2(n231), .IN3(n234), .Q(\U3/U3/Z_0 ) );
  XNOR2X1 U281 ( .IN1(n187), .IN2(opcode[1]), .Q(n234) );
  INVX0 U282 ( .IN(opcode[3]), .QN(n231) );
  NOR2X0 U283 ( .IN1(opcode[2]), .IN2(opcode[3]), .QN(n230) );
  XOR2X1 U284 ( .IN1(in_a[0]), .IN2(in_b[0]), .Q(N35) );
  XNOR2X1 U285 ( .IN1(in_a[1]), .IN2(n206), .Q(N34) );
  XNOR2X1 U286 ( .IN1(in_a[2]), .IN2(n207), .Q(N33) );
  XNOR2X1 U287 ( .IN1(in_a[3]), .IN2(n224), .Q(N32) );
  XNOR2X1 U288 ( .IN1(in_a[4]), .IN2(n223), .Q(N31) );
  XNOR2X1 U289 ( .IN1(in_a[5]), .IN2(n205), .Q(N30) );
  XNOR2X1 U290 ( .IN1(in_a[6]), .IN2(n203), .Q(N29) );
  XNOR2X1 U291 ( .IN1(in_b[7]), .IN2(n235), .Q(N28) );
  NAND2X0 U292 ( .IN1(n206), .IN2(n247), .QN(N18) );
  INVX0 U293 ( .IN(in_a[1]), .QN(n247) );
  INVX0 U294 ( .IN(in_b[1]), .QN(n206) );
  NAND2X0 U295 ( .IN1(n207), .IN2(n245), .QN(N17) );
  INVX0 U296 ( .IN(in_a[2]), .QN(n245) );
  INVX0 U297 ( .IN(in_b[2]), .QN(n207) );
  NAND2X0 U298 ( .IN1(n224), .IN2(n243), .QN(N16) );
  INVX0 U299 ( .IN(in_a[3]), .QN(n243) );
  INVX0 U300 ( .IN(in_b[3]), .QN(n224) );
  NAND2X0 U301 ( .IN1(n223), .IN2(n241), .QN(N15) );
  INVX0 U302 ( .IN(in_a[4]), .QN(n241) );
  INVX0 U303 ( .IN(in_b[4]), .QN(n223) );
  NAND2X0 U304 ( .IN1(n205), .IN2(n239), .QN(N14) );
  INVX0 U305 ( .IN(in_a[5]), .QN(n239) );
  INVX0 U306 ( .IN(in_b[5]), .QN(n205) );
  NAND2X0 U307 ( .IN1(n203), .IN2(n237), .QN(N13) );
  INVX0 U308 ( .IN(in_a[6]), .QN(n237) );
  INVX0 U309 ( .IN(in_b[6]), .QN(n203) );
  NAND2X0 U310 ( .IN1(n204), .IN2(n235), .QN(N12) );
  INVX0 U311 ( .IN(in_a[7]), .QN(n235) );
  INVX0 U312 ( .IN(in_b[7]), .QN(n204) );
endmodule

