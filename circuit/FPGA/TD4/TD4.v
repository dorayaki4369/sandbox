module TD4(clock, reset, user_in, user_out);
	input  clock, reset;
	input  [3:0] user_in;
	output [3:0] user_out;
	
	wire iclock;
	wire [3:0] load;
	
	//Clock
	clock_gen #(1000) clkg(clock);
	assign iclock = clkg(clock);
	
	//レジスタ
	register4bit regA(iclock, reset, load[0]);
	register4bit regB(iclock, reset, load[1]);
	register4bit regO(iclock, reset, load[2]);
	program_counter pc(iclock, reset, load[3]);
endmodule
