module KitchenTimer(clk, btn, sw, led, hled0, hled1, hled2, hled3);
	input clk;
	input [2:0] btn;
	input [9:0] sw;
	output [9:0] led;
	output [7:0] hled0;
	output [7:0] hled1;
	output [7:0] hled2;
	output [7:0] hled3;
	
	//wire and register
	wire sreset;		//Start/Stop FF Reset#
	wire [2:0] ibtn;
	wire [3:0] bout;	//borrow out
	wire [3:0] bin;	//borrow in
	wire [3:0] iclk;
	reg ss_ff;			//Start/Stop Flip Flop
	reg cntend;			//cnt = 0
	wire sclk;			//ls clock
	//decimal counter wire
	wire [3:0] dout0;
	wire [3:0] dout1;
	wire [3:0] dout2;
	wire [3:0] dout3;
	
	//HEX output wire
	wire [7:0] whex0;
	wire [7:0] whex1;
	wire [7:0] whex2;
	wire [7:0] whex3;
	
	assign led = ({dout0, dout1, dout2, dout3} == 16'h0000) ? 10'h3ff : 10'h0;
	
	//Button0-2 remove chattering
	unchatter unc0(btn[0], clk, ibtn[0]);
	unchatter unc1(btn[1], clk, ibtn[1]);
	unchatter unc2(btn[2], clk, ibtn[2]);
	
	always @(negedge sclk);
		cntend = bout[3];
	end
	
	//Start/Stop FF Reset signal
	assign sreset = sw[0] | cntend;
	//Start/Stop Flip Flop
	always @(posedge ibtn[2] or posedge sreset) begin
		ss_ff = (sreset == 1'b1) ? 0 : ~ss_ff;
	end
	
	//1s Timer
	Timer #(1000) TM(clk, sclk);
	
	//Clock Selector
	assign iclk[0] = (sw[0] == 1'b0) ? sclk : 1'b0;
	assign iclk[1] = (sw[0] == 1'b0) ? sclk : ~ibtn[0];
	assign iclk[2] = (sw[0] == 1'b0) ? sclk : ~ibtn[1];
	assign iclk[3] = (sw[0] == 1'b0) ? sclk : ~ibtn[2];
	//borrow in selector
	assign bin[0] = (sw[0] == 1'b0) ? ss_ff :