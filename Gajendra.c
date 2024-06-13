#include <stdio.h>

int main(void) {

	/* please modify according to the ordering of your control word */
	unsigned int PC_INC 	= 14;
	unsigned int PC_OUT	= 13;
	unsigned int PC_LOAD	= 12;
	unsigned int MEM_IN	= 11;
	unsigned int MEM_OUT	= 10;
	unsigned int IR_IN	= 9;
	unsigned int IR_OUT	= 8;
	unsigned int MAR_IN	= 7;
	unsigned int REGA_IN	= 6;
	unsigned int REGA_OUT	= 5;
	unsigned int REGB_IN	= 4;
	unsigned int REGB_OUT	= 3;
	unsigned int REGC_IN	= 2;
	unsigned int REGC_OUT	= 1;
	unsigned int ALU_OUT	= 0;

	/* Add your own control words. Here, I have 5 dummy instructions, each taking 5 T-states or 5 machine cycles.
	However if we want to lookup the ROM in this format <4-bit instruction><3-bit T-state value>, we need to skip
	count values 101(5), 110(6), and 111(7), and then continue on the next instruction.
	Example of an instruction with operation 1010.

	<previous instruction>
	------------------------
	1010 000 <control word> fetch 1
	1010 001 <control word> fetch 2
	1010 010 <control word> actual stuff 1
	1010 011 <control word> actual stuff 2
	1010 100 <control word> actual stuff 3
	1010 101 <control word> zeros
	1010 110 <control word> zeros
	1010 111 <control word> zeros
	------------------------
	<next instruction>

	If nothing to do in a machine cycle we pad it with zero.*/

	int control_words[] = {
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  0,			0,		       0,		0, 0, 0,	//NOP 0000
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << IR_OUT | 1 << MAR_IN, 1 << MEM_OUT | 1 << REGA_IN, 0,		0, 0, 0,	//LDA 0001
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << IR_OUT | 1 << REGA_IN, 0, 0,		0, 0, 0,	//LDI 0010
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << IR_OUT | 1 << MAR_IN, 1 << MEM_OUT | 1 << REGB_IN, 1 << REGA_IN | 1 << ALU_OUT,	0, 0, 0,	//ADD 0011
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << IR_OUT | 1 << MAR_IN, 1 << MEM_OUT | 1 << REGB_IN, 1 << REGA_IN | 1 << ALU_OUT,	0, 0, 0,	//SUB 0100
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << ALU_OUT | 1 << REGA_IN,			0,		       0,		0, 0, 0,	//LSHIFT 0101
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << ALU_OUT | 1 << REGA_IN,			0,		       0,		0, 0, 0,	//RSHIFT 0110
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << IR_OUT | 1 << MAR_IN, 1 << MEM_OUT | 1 << REGB_IN, 1 << ALU_OUT,	0, 0, 0,	//CMP 0111
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << IR_OUT | 1 << PC_LOAD, 0, 0,	0, 0, 0,	//JMP 1000
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << REGA_OUT | 1 << REGC_IN, 0, 0, 0, 0, 0,	//HEX 1001
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << REGA_OUT | 1 << REGB_IN,	1 << REGC_OUT | 1 << REGA_IN, 1 << REGB_OUT | 1 << REGC_IN,		0, 0, 0,	//SWAP_AC 1010
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << REGA_OUT | 1 << REGB_IN,			0,		       0,		0, 0, 0,	//MOV_AB 1011
		1 << PC_OUT | 1 << MAR_IN,	1 << PC_INC | 1 << MEM_OUT | 1 << IR_IN,  1 << REGB_OUT | 1 << REGA_IN,			0,		       0,		0, 0, 0,	//MOV_BA 1100
	};

	/* 5 instructions, each instruction has 5 T-states.
	But we are provisioning for 3-bits for the contiguous memory lookup, hence 5x8.
	I understand it can be optimized like anything, but currently we are trying to
	keep things simple and trivial. Hint: only a few UNIQUE control words exisit, how about designing an FSM?*/

	int INST = 0;
	int TSTATE = 0;

	for (INST = 0; INST < 13; INST++) {
		for (TSTATE = 0; TSTATE < 8; TSTATE++) {
			printf("0x%04X,", control_words[INST * 8 + TSTATE]);
		}
		printf("\n");
	}


	return 0;
}
