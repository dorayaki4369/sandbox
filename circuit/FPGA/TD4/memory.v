module memory(address, order);
	input  [3:0] address;
	output [7:0] order;
	
	assign order = rom(order);
	
	function [7:0] rom;
		input [3:0] address;
		
		case(address)
			4'b0000 : rom <= 8'hb3;
			4'b0001 : rom <= 8'hb6;
			4'b0010 : rom <= 8'hbc;
			4'b0011 : rom <= 8'hb8;
			4'b0100 : rom <= 8'hb8;
			4'b0101 : rom <= 8'hbc;
			4'b0110 : rom <= 8'hb6;
			4'b0111 : rom <= 8'hb3;
			4'b1000 : rom <= 8'hb1;
			4'b1001 : rom <= 8'h90;
			default : rom <= 8'h00;
		endcase
	endfunction
endmodule
