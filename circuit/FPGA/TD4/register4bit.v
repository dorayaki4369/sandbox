module register4bit(clock, reset, load, indata, outdata);
	input        clock, reset, load;
	input  [3:0] indata;
	output [3:0] outdata;
	
	reg    [3:0] outdata;
	
	always @(posedge clock or negedge reset) begin
		if(!reset) begin
			outdata <= 4'b0000;
		end
		if(load) begin
			outdata <= indata;
		end
	end
endmodule
