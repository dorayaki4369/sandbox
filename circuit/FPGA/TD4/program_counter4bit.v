module program_counter4bit(clock, reset, load, indata, count);
	input clock, reset, load;
	input  [3:0] indata;
	output [3:0] count;
	
	reg [3:0] count;
		
	always @(posedge clock or negedge reset) begin
		if(!reset) begin
			count <= 4'b0000;
		end
		if(load) begin
			count <= indata;
		end
		else begin
			count <= count + 1;
		end
	end
endmodule
