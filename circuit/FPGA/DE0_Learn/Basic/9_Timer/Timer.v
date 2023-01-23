module Timer(clk, led);
	input clk;
	output [9:0] led;
	
	reg [15:0] cnt1;
	reg [6:0] cnt2;
	reg [3:0] dcnt;
	wire iclk1;	//1kHz clock
	wire iclk2;	//1Hz  clock
	
	//1/50000 PreScaler
	assign iclk1=(cnt1==16'd49999) ? 1'b1 : 1'b0;
	always @(posedge clk) begin
		cnt1 = (iclk1==1'b1) ? 0 : cnt1 + 1;
	end
	
	//1/100 PreScaler
	assign iclk2=(cnt2==7'd99) ? 1'b1 : 1'b0;
	always @(posedge clk) begin
		if(iclk1==1'b1) begin
			cnt2 = (iclk2==1'b1) ? 0 : cnt2 + 1;
		end
	end
	
	//decimal counter
	always @(posedge clk) begin
		if((iclk1==1'b1) && (iclk2==1'b1)) begin
			dcnt = (dcnt==4'd9) ? 0 : dcnt + 1;
		end
	end
	
	//decorder
	function Decorder;
		input [3:0] cnt;
		input [3:0] num;
		begin
			Decorder = (cnt==num) ? 1'b1 : 1'b0;
		end
	endfunction
	
	assign led[0] = Decorder(dcnt, 4'd0);
	assign led[1] = Decorder(dcnt, 4'd1);
	assign led[2] = Decorder(dcnt, 4'd2);
	assign led[3] = Decorder(dcnt, 4'd3);
	assign led[4] = Decorder(dcnt, 4'd4);
	assign led[5] = Decorder(dcnt, 4'd5);
	assign led[6] = Decorder(dcnt, 4'd6);
	assign led[7] = Decorder(dcnt, 4'd7);
	assign led[8] = Decorder(dcnt, 4'd8);
	assign led[9] = Decorder(dcnt, 4'd9);
endmodule
