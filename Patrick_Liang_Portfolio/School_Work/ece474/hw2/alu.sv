// I copied the testcases from gate_do.do over to rtl_do.do.
// That's how I get the same waveforms for both rtl and gate

module alu(
	input [7:0] in_a,
	input [7:0] in_b,
	input [3:0] opcode,
	output reg [7:0] alu_out,
	output reg alu_zero, // logic '1' when alu_out is all zeros
	output reg alu_carry //indicates a carry out from ALU
);

parameter c_add = 4'h1;
parameter c_sub = 4'h2;
parameter c_inc = 4'h3;
parameter c_dec = 4'h4;
parameter c_or  = 4'h5;
parameter c_and = 4'h6;
parameter c_xor = 4'h7;
parameter c_shr = 4'h8;
parameter c_shl = 4'h9;
parameter c_onescomp = 4'ha;
parameter c_twoscomp = 4'hb;

always_comb begin
	case(opcode)
		c_add: begin
			{alu_carry, alu_out} = in_a + in_b;
			alu_zero = !alu_out;
		end
		c_sub: begin
			{alu_carry, alu_out} = in_a - in_b;
			alu_zero = !alu_out;
		end
		c_inc: begin
			{alu_carry, alu_out} = in_a + 1;
			alu_zero = !alu_out;
		end
		c_dec: begin
			{alu_carry, alu_out} = in_a - 1;
			alu_zero = !alu_out;
		end
		c_or: begin
			alu_out = in_a | in_b;
			alu_carry = '0;
			alu_zero = !alu_out;
		end
		c_and: begin
			alu_out = in_a & in_b;
			alu_carry = '0;
			alu_zero = !alu_out;
		end
		c_xor: begin
			alu_out = in_a ^ in_b;
			alu_carry = '0;
			alu_zero = !alu_out;
		end
		c_shr: begin
			alu_out = {1'b0, in_a[7:1]};
			alu_carry = '0;
			alu_zero = !alu_out;
		end
		c_shl: begin
			alu_out = {in_a[6:0], 1'b0};
			alu_carry = in_a[7];
			alu_zero = !alu_out;
		end
		c_onescomp: begin
			alu_out = ~in_a;
			alu_carry = 0;
			alu_zero = !alu_out;
		end
		c_twoscomp: begin
			{alu_carry, alu_out} = (~in_a) + 1;
			alu_zero = !alu_out;
		end
		default: begin
			alu_out = '0;
			alu_carry = '0;
			alu_zero = '0;
		end
	endcase
end

endmodule
