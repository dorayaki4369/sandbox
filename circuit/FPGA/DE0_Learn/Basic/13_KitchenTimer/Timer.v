module Timer(clk, oclk);
	parameter scale = 100;	//oclk = 1kHz/scale
	input clk;
	output oclk;
	
	reg [15:0] cnt1;
	reg [11:0] cnt2;
	reg [3:0] dcnt;
	wire iclk1;	//1kHz clock
	wire iclk2;	//scaled clock
	reg rclk;
	
	//1/50000 PreScaler
	assign iclk1 = (cnt1 == 16'd49999) ? 1'b1 : 1'b0;
	always @(posedge clk) begin
		cnt1 = (iclk1 == 1'b1) ? 0 : cnt1 + 1;
	end
	
	//1/100 PreScaler
	assign iclk2 = (cnt2 == (scale - 1)) ? 1'b1 : 1'b0;
	always @(posedge clk) begin
		if(iclk1 == 1'b1) begin
			cnt2 = (iclk2 == 1'b1) ? 0 : cnt2 + 1;
		end
	end
	
	//clock out FF
	always @(posedge clk) rclk = iclk2;
	assign oclk = rclk;
endmodule