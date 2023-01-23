module Counter(sw, led);
	input sw;
	output [3:0] led;
	reg [3:0] ff;
	
	always @(posedge sw) begin
		ff = (ff==4'h9) ? 4'h0 : ff + 1;
	end
	assign led=ff;
endmodule