module ucounter(clk, nclr, cin, cout, q);
	parameter maxcount = 15;
	input clk;
	input nclr;
	input cin;
	output cout;
	output [3:0] q;
	reg [3:0] cnt;
	
	assign q = cnt;
	
	always @(posedge clk or negedge nclr) begin
		if(nclr == 1'b0) begin
			cnt = 4'h0;
		end
		else begin
			if(cin == 1'b1) begin
				cnt = (cnt==maxcount) ? 4'h0 : cnt + 1;
			end
		end
	end
	assign cout = ((cnt == maxcount) && (cin == 1'b1) ? 1'b1 : 1'b0);
endmodule

//chattering remover
module unchatter(din, clk, dout);
	input din;
	input clk;
	output dout;
	reg [15:0] cnt;
	reg dff;
	
	always @(posedge clk) begin
		cnt = cnt + 1;
	end
	
	always @(posedge cnt[15]) begin
		dff = din;
	end
	
	assign dout = dff;
endmodule

//7segment decorder
module LedDec(num, decNum);
	input [3:0] num;
	output [7:0] decNum;
	
	assign decNum = dec(num);
	
	function [7:0] dec;
		input [3:0] dnum;
		
		case(num)
			4'h0:	dec = 8'b11000000;
			4'h1:	dec = 8'b11111001;
			4'h2:	dec = 8'b10100100;
			4'h3:	dec = 8'b10110000;
			4'h4:	dec = 8'b10011001;
			4'h5:	dec = 8'b10010010;
			4'h6:	dec = 8'b10000010;
			4'h7:	dec = 8'b11111000;
			4'h8:	dec = 8'b10000000;
			4'h9:	dec = 8'b10011000;
			4'ha:	dec = 8'b10001000;
			4'hb:	dec = 8'b10000011;
			4'hc:	dec = 8'b10100111;
			4'hd:	dec = 8'b10100001;
			4'he:	dec = 8'b10000110;
			4'hf:	dec = 8'b10001110;
			default: dec = 8'b11111111;
		endcase
	endfunction
endmodule

//Top module
module UniversalCounter(btn2, btn1, clk, hex0, hex1);
	input btn2;
	input btn1;
	input clk;
	output [7:0] hex0;
	output [7:0] hex1;
	wire cclk, cout1, cout2;
	wire [3:0] cnt0;
	wire [3:0] cnt1;
	
	//chattering remover
	unchatter uc(btn2, clk, cclk);
	
	//octal counter
	ucounter #(2) counter1(cclk, btn1, 1'b1, cout, cnt0);
	//decimal counter
	ucounter #(9) counter2(cclk, btn1, cout, cout2, cnt1);
	//7segment decorder
	LedDec ledDec1(cnt0, hex0);
	LedDec ledDec2(cnt1, hex1);
endmodule