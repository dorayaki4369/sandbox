module Chattering(clk, sw, led);
	input clk, sw;
	output [3:0] led;
	reg [3:0] ff;
	reg[15:0] cnt;
	reg swreg;
	wire c_clk, sw_out;
	
	//16bit counter
	always @(posedge clk) begin
		cnt = cnt + 1;
	end
	assign c_clk = cnt[15]; //clock for chattering inhibit
	
	//switch latch
	always @(posedge c_clk) begin
		swreg = sw;
	end
	assign sw_out = swreg;
	
	always @(posedge sw_out) begin
		ff = (ff==4'h9) ? 4'h0 : ff + 1;
	end
	assign led = ff;
endmodule