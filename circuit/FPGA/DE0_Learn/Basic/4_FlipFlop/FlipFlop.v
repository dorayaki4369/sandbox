module FlipFlop(sw, led);
	input sw;
	output led;
	reg ff;
	
	always @(posedge sw) begin
		ff=~ff;
	end
	assign led=ff;
endmodule