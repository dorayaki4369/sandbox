module multiplexer4bit(inputA, inputB, inputC, inputD, outputY, select);
	input  [3:0] inputA, inputB, inputC, inputD;
	output [3:0] outputY;
	input  [1:0] select;
	
	assign outputY = func_multiplexer(inputA, inputB, inputC, inputD);
	
	function [3:0] func_multiplexer;
		input [3:0] inputA, inputB, inputC, inputD;
		input [1:0] select;
		
		case(select)
			2'b00 : func_multiplexer <= inputA;
			2'b01 : func_multiplexer <= inputB;
			2'b10 : func_multiplexer <= inputC;
			2'b11 : func_multiplexer <= inputD;
			default : func_multiplexer <= 2'b0000;
		endcase
	endfunction
endmodule
