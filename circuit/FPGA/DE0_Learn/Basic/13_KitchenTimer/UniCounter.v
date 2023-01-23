module UniCounter(clk, reset, bin, bout, q);
	parameter maxcnt = 15;	//default HEX counter
	input clk;
	input reset;
	input bin;
	output bout;
	output [3:0] q;
	reg [3:0] cnt;
	
	assign q = cnt;
	
	always @(posedge clk or posedge reset) begin
		if(reset == 1'b1) begin
			cnt = 0;
		end 
		else begin
			if(bin == 1'b1) begin
				cnt = (cnt == 0) ? maxcnt : cnt - 1;
			end
		end
	end
	
	assign bout = ((cnt == 0) && (bin 1'b1)) ? 1'b1 : 1'b0;