module BCDCounter(clk, btn, hex0, hex1);
	input clk, btn;
	output [7:0] hex0;
	output [7:0] hex1;
	reg [3:0] ff;
	reg [15:0] cnt;
	reg swreg;
	wire c_clk, sw_out;
	reg [3:0] dcnt1;
	reg [3:0] dcnt2;
	wire d_cry;	//Carry
	
	//16bit Counter
	always @(posedge clk) begin
		cnt = cnt + 1;
	end
	assign c_clk = cnt[15]; 	//clock for chattering inhibit
	
	//switch latch
	always @(posedge c_clk) begin
		swreg = btn;
	end
	assign sw_out = swreg;
	
	//decimal counterl
	always @(negedge sw_out) begin
		dcnt1 = (dcnt1==4'h9) ? 0 : dcnt1 + 1;
	end
	
	//Carry
	assign d_cry = (dcnt1==4'h9) ? 1'b1 : 1'b0;
	//decimal counter2
	always @(negedge sw_out) begin
		if(d_cry==1'b1) begin
			dcnt2 = (dcnt2==4'h9) ? 0 : dcnt2 + 1;
		end
	end
	
	//7Segment Decorder
	function [7:0] LedDec;
		input [3:0] num;
		begin
			case(num)
				4'h0:	LedDec = 8'b11000000;
				4'h1: LedDec = 8'b11111001;
				4'h2: LedDec = 8'b10100100;
				4'h3: LedDec = 8'b10110000;
				4'h4: LedDec = 8'b10011001;
				4'h5: LedDec = 8'b10010010;
				4'h6: LedDec = 8'b10000010;
				4'h7: LedDec = 8'b11111000;
				4'h8: LedDec = 8'b10000000;
				4'h9: LedDec = 8'b10011000;
				4'ha: LedDec = 8'b10001000;
				4'hb: LedDec = 8'b10000011;
				4'hc: LedDec = 8'b10100111;
				4'hd: LedDec = 8'b10100001;
				4'he: LedDec = 8'b10000110;
				4'hf: LedDec = 8'b10001110;
				default: LedDec = 8'hff;
			endcase
		end
	endfunction
	
	assign hex0 = LedDec(dcnt1);
	assign hex1 = LedDec(dcnt2);

endmodule
