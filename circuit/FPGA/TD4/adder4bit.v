module adder4bit(inputA, inputB, outputY, carry);
	input  [3:0] inputA, inputB;
	output [3:0] outputY;
	output [3:0] carry;
	
	wire [4:0] rslt;
	
	assign rslt = inputA + inputB;
	assign carry = rslt[4];
	assign outputY = rslt[3:0];
endmodule
