// This file is part of SPCPU Assembler.
// 
// Copyright 2016 by Andrew Clark (FL4SHK).
// 
// SPCPU Assembler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the
// Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
// 
// SPCPU Assembler is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along
// with SPCPU Assembler.  If not, see <http://www.gnu.org/licenses/>.


#ifndef instruction_stuff_hpp
#define instruction_stuff_hpp

#include "cpu_constants.hpp"


// Instruction constants

// Most instructions, except for group 6, are 16 bits long
constexpr size_t instr_main_width = 16;
constexpr size_t instr_main_msb_pos = width_to_msb_pos(instr_main_width);

// Instruction decoder constants

// There are six instruction groups (counting instr_grp_unknown), so use a
// 3-bit enum
constexpr size_t instr_grp_width = 3;
constexpr size_t instr_grp_msb_pos = width_to_msb_pos(instr_grp_width);




// Instruction Group 1 constants
// Encoding:  0ooo aaaa iiii iiii
constexpr size_t instr_g1_id = 0b0;
constexpr size_t instr_g1_id_pos = 15;

// Instruction group 1 has 3 opcode bits
constexpr size_t instr_g1_op_width = 3;
constexpr size_t instr_g1_op_msb_pos = width_to_msb_pos(instr_g1_op_width);
constexpr size_t instr_g1_op_range_hi = 14;
constexpr size_t instr_g1_op_range_lo = instr_g1_op_range_hi 
	- instr_g1_op_msb_pos;

// Instruction group 1 has a 4-bit index for rA
constexpr size_t instr_g1_ra_index_width = cpu_reg_index_ie_width;
constexpr size_t instr_g1_ra_index_msb_pos = cpu_reg_index_ie_msb_pos;
constexpr size_t instr_g1_ra_index_range_hi = instr_g1_op_range_lo - 1;
constexpr size_t instr_g1_ra_index_range_lo = instr_g1_ra_index_range_hi 
	- instr_g1_ra_index_msb_pos;

// Instruction group 1 has an 8-bit immediate value
constexpr size_t instr_g1_imm_value_width = cpu_imm_value_8_width;
constexpr size_t instr_g1_imm_value_msb_pos = cpu_imm_value_8_msb_pos;
constexpr size_t instr_g1_imm_value_range_hi = instr_g1_ra_index_range_lo 
	- 1;
constexpr size_t instr_g1_imm_value_range_lo = instr_g1_imm_value_range_hi 
	- instr_g1_imm_value_msb_pos;




// Instruction Group 2 constants
// Encoding:  10oo oooo aaaa bbbb
constexpr size_t instr_g2_id = 0b10;
constexpr size_t instr_g2_id_range_hi = 15;
constexpr size_t instr_g2_id_range_lo = 14;

// Instruction group 2 has 6 opcode bits
constexpr size_t instr_g2_op_width = 6;
constexpr size_t instr_g2_op_msb_pos = width_to_msb_pos(instr_g2_op_width);
constexpr size_t instr_g2_op_range_hi = instr_g2_id_range_lo - 1;
constexpr size_t instr_g2_op_range_lo = instr_g2_op_range_hi 
	- instr_g2_op_msb_pos;

// Instruction group 2 has a 4-bit index for rA (or rAp)
constexpr size_t instr_g2_ra_index_width = cpu_reg_index_ie_width;
constexpr size_t instr_g2_ra_index_msb_pos = cpu_reg_index_ie_msb_pos;
constexpr size_t instr_g2_ra_index_range_hi = instr_g2_op_range_lo - 1;
constexpr size_t instr_g2_ra_index_range_lo = instr_g2_ra_index_range_hi 
	- instr_g2_ra_index_msb_pos;

// Instruction group 2 has a 4-bit index for rB (or rBp)
constexpr size_t instr_g2_rb_index_width = cpu_reg_index_ie_width;
constexpr size_t instr_g2_rb_index_msb_pos = cpu_reg_index_ie_msb_pos;
constexpr size_t instr_g2_rb_index_range_hi = instr_g2_ra_index_range_lo 
	- 1;
constexpr size_t instr_g2_rb_index_range_lo = instr_g2_rb_index_range_hi 
	- instr_g2_rb_index_msb_pos;




// Instruction Group 3 constants
// Encoding:  1100 ooaa aabb bccc
constexpr size_t instr_g3_id = 0b1100;
constexpr size_t instr_g3_id_range_hi = 15;
constexpr size_t instr_g3_id_range_lo = 12;

// Instruction group 3 has 2 opcode bits
constexpr size_t instr_g3_op_width = 2;
constexpr size_t instr_g3_op_msb_pos = width_to_msb_pos(instr_g3_op_width);
constexpr size_t instr_g3_op_range_hi = instr_g3_id_range_lo - 1;
constexpr size_t instr_g3_op_range_lo = instr_g3_op_range_hi
	- instr_g3_op_msb_pos;

// Instruction group 3 has a 4-bit index for rA
constexpr size_t instr_g3_ra_index_width = cpu_reg_index_ie_width;
constexpr size_t instr_g3_ra_index_msb_pos = cpu_reg_index_ie_msb_pos;
constexpr size_t instr_g3_ra_index_range_hi = instr_g3_op_range_lo - 1;
constexpr size_t instr_g3_ra_index_range_lo = instr_g3_ra_index_range_hi 
	- instr_g3_ra_index_msb_pos;

// Instruction group 3 has a 3-bit index for rBp
constexpr size_t instr_g3_rbp_index_width = cpu_rp_index_ie_width;
constexpr size_t instr_g3_rbp_index_msb_pos = cpu_rp_index_ie_msb_pos;
constexpr size_t instr_g3_rbp_index_range_hi = instr_g3_ra_index_range_lo 
	- 1;
constexpr size_t instr_g3_rbp_index_range_lo = instr_g3_rbp_index_range_hi 
	- instr_g3_rbp_index_msb_pos;

// Instruction group 3 has a 3-bit index for rCp
constexpr size_t instr_g3_rcp_index_width = cpu_rp_index_ie_width;
constexpr size_t instr_g3_rcp_index_msb_pos = cpu_rp_index_ie_msb_pos;
constexpr size_t instr_g3_rcp_index_range_hi = instr_g3_rbp_index_range_lo 
	- 1;
constexpr size_t instr_g3_rcp_index_range_lo = instr_g3_rcp_index_range_hi 
	- instr_g3_rcp_index_msb_pos;



// Instruction Group 4 constants
// Encoding:  1101 oooo iiii iiii
constexpr size_t instr_g4_id = 0b1101;
constexpr size_t instr_g4_id_range_hi = 15;
constexpr size_t instr_g4_id_range_lo = 12;

// Instruction group 4 has 4 opcode bits
constexpr size_t instr_g4_op_width = 4;
constexpr size_t instr_g4_op_msb_pos = width_to_msb_pos(instr_g4_op_width);
constexpr size_t instr_g4_op_range_hi = instr_g4_id_range_lo - 1;
constexpr size_t instr_g4_op_range_lo = instr_g4_op_range_hi
	- instr_g4_op_msb_pos;


// Instruction group 4 has an 8-bit immediate value
constexpr size_t instr_g4_imm_value_width = cpu_imm_value_8_width;
constexpr size_t instr_g4_imm_value_msb_pos = cpu_imm_value_8_msb_pos;
constexpr size_t instr_g4_imm_value_range_hi = instr_g4_op_range_lo - 1;
constexpr size_t instr_g4_imm_value_range_lo = instr_g4_imm_value_range_hi 
	- instr_g4_imm_value_msb_pos;




// Instruction Group 5 constants
// Encoding:  1110 00oo oaaa abbb   iiii iiii jjjj jjjj
// "ihi" is short for "Instruction High", which is the high 16 bits of
// a 32-bit instruction
// "ilo" is short for "Instruction Low", which is the low 16 bits of a
// 32-bit instruction
constexpr size_t instr_g5_ihi_id = 0b111000;
constexpr size_t instr_g5_ihi_id_range_hi = 15;
constexpr size_t instr_g5_ihi_id_range_lo = 10;

// Instruction group 5 has 3 opcode bits
constexpr size_t instr_g5_op_width = 3;
constexpr size_t instr_g5_op_msb_pos = width_to_msb_pos(instr_g5_op_width);
constexpr size_t instr_g5_ihi_op_range_hi = instr_g5_ihi_id_range_lo - 1;
constexpr size_t instr_g5_ihi_op_range_lo = instr_g5_ihi_op_range_hi 
	- instr_g5_op_msb_pos;

// Instruction group 5 has a 4-bit index for rA
constexpr size_t instr_g5_ihi_ra_index_width = cpu_reg_index_ie_width;
constexpr size_t instr_g5_ihi_ra_index_msb_pos = cpu_reg_index_ie_msb_pos;
constexpr size_t instr_g5_ihi_ra_index_range_hi = instr_g5_ihi_op_range_lo 
	- 1;
constexpr size_t instr_g5_ihi_ra_index_range_lo
	= instr_g5_ihi_ra_index_range_hi - instr_g5_ihi_ra_index_msb_pos;

// Instruction group 5 has a 3-bit index for rBp
constexpr size_t instr_g5_ihi_rbp_index_width = cpu_rp_index_ie_width;
constexpr size_t instr_g5_ihi_rbp_index_msb_pos = cpu_rp_index_ie_msb_pos;
constexpr size_t instr_g5_ihi_rbp_index_range_hi
	= instr_g5_ihi_ra_index_range_lo - 1;
constexpr size_t instr_g5_ihi_rbp_index_range_lo
	= instr_g5_ihi_rbp_index_range_hi - instr_g5_ihi_rbp_index_msb_pos;

// Instruction group 5 has a 16-bit immediate value
constexpr size_t instr_g5_ilo_imm_value_width = cpu_imm_value_16_width;
constexpr size_t instr_g5_ilo_imm_value_msb_pos = cpu_imm_value_16_msb_pos;
constexpr size_t instr_g5_ilo_imm_value_range_hi = 15;
constexpr size_t instr_g5_ilo_imm_value_range_lo 
	= instr_g5_ilo_imm_value_range_hi - instr_g5_ilo_imm_value_msb_pos;



enum instr_group
{
	// Non-branching instructions with 8-bit immediate values
	instr_grp_1,
	
	// The instruction group with the most opcodes
	instr_grp_2,
	
	// Instructions with one register and two register pairs
	instr_grp_3,
	
	// Branching instructions
	instr_grp_4,
	
	// Instructions encoded with four bytes instead of two so that
	// there can be 16-bit immediate values
	instr_grp_5,
	
	
	// The instruction is of an unknown group
	instr_grp_unknown
	
};


// Instruction group 1 has 3 opcode bits
// Encoding:  0ooo aaaa iiii iiii
enum instr_grp_1_oper
{
	// Arithmetic instructions:
	instr_g1_op_addi,
	instr_g1_op_adci,
	
	instr_g1_op_cmpi,
	
	//Copy instructions:
	
	// (CoPY Immediate)
	instr_g1_op_cpyi 
};


// Instruction group 2 has 6 opcode bits
// Encoding:  10oo oooo aaaa bbbb
enum instr_grp_2_oper
{
	// Arithmetic instructions:
	instr_g2_op_add,
	instr_g2_op_adc,
	
	instr_g2_op_sub,
	instr_g2_op_sbc,
	
	instr_g2_op_cmp,
	
	// Bitwise instructions with two register operands:
	instr_g2_op_and,
	instr_g2_op_orr,
	instr_g2_op_xor,
	
	// Complement instructions with one register operand (rB ignored):
	
	// (one's complement of rA)
	instr_g2_op_inv,
	
	// (one's complement of rAp)
	instr_g2_op_invp,
	
	// (two's complement of rA)
	instr_g2_op_neg,
	
	// (two's complement of rAp)
	instr_g2_op_negp,
	
	
	// Bitshifting (and rotating) instructions that use the value of rB
	// as the number of bits to shift by:
	instr_g2_op_lsl,
	instr_g2_op_lsr,
	instr_g2_op_asr,
	instr_g2_op_rol,
	instr_g2_op_ror,
	
	
	// Bit rotating instructions that use carry as bit 8 for a 9-bit
	// rotate of { carry, rA } by one bit:
	instr_g2_op_rolc,
	instr_g2_op_rorc,
	
	
	// Bitshifting (and rotating) instructions that do a 16-bit shift
	// or rotate on the reg pair rAp, using rB as the number of bits to
	// shift by:
	instr_g2_op_lslp,
	instr_g2_op_lsrp,
	instr_g2_op_asrp,
	instr_g2_op_rolp,
	instr_g2_op_rorp,
	
	
	// Bit rotating instructions that use carry as bit 16 for a 17-bit
	// rotate of { carry, rAp } by one bit:
	instr_g2_op_rolcp,
	instr_g2_op_rorcp,
	
	
	// Copy instructions:
	
	// (CoPY from one register to another register)
	instr_g2_op_cpy,
	
	// (CoPY from reg Pair rAp to reg Pair rBp)
	instr_g2_op_cpyp,
	
	
	// Swap instructions:
	// (SWap register Pair, also can be used as a combined "call",
	// "jump", and "return" instruction by swapping some other register
	// pair with the "pc" [r14p] register pair)
	instr_g2_op_swp,
	
	
	// Call instruction (Description:  sets the link register to the
	// return address, then sets the program counter to the address
	// contained in the reg pair rAp):
	
	// (CALL subroutine at address in reg pair rAp)
	instr_g2_op_call,
	
	
	// 8-bit Load/store instructions:
	
	// (LoaD contents into Register rA from memory at address in rBp)
	instr_g2_op_ldr,
	
	// (STore Register rA contents to memory at address in rBp)
	instr_g2_op_str 
	
};


// Instruction group 3 has 2 opcode bits
// Encoding:  1100 ooaa aabb bccc
enum instr_grp_3_oper
{
	// Indexed Load/store instructions:
	
	// Load 8-bit value from memory at address [rBp + rCp] into rA
	instr_g3_op_ldrx,
	
	// Store rA to memory at address [rBp + rCp]
	instr_g3_op_strx 
};


// Instruction group 4 has 4 opcode bits
// Encoding:  1101 oooo iiii iiii
enum instr_grp_4_oper
{
	// Branching instructions (note that iiii iiii is a SIGNED 8-bit
	// integer):
	
	// (branch always)
	instr_g4_op_bra,
	
	// (branch never, a form of NOP)
	instr_g4_op_bnv,
	
	// (branch when Z == 0)
	instr_g4_op_bne,
	
	// (branch when Z == 1)
	instr_g4_op_beq,
	
	// (branch when C == 0 [unsigned less than])
	instr_g4_op_bcc,
	
	// (branch when C == 1 [unsigned greater than or equal])
	instr_g4_op_bcs,
	
	// (branch when C == 0 and Z == 1 [unsigned less than or equal])
	instr_g4_op_bls,
	
	// (branch when C == 1 and Z == 0 [unsigned greater than])
	instr_g4_op_bhi
	
};


// Instruction group 5 has 3 opcode bits
// Encoding:  1110 00oo oaaa abbb   iiii iiii jjjj jjjj
enum instr_grp_5_oper
{
	// Extended copy instructions:
	
	// (COPY Pair Immediate, which sets the a register pair rAp to a
	// 16-bit value in one instruction, but in twice the number of
	// cycles due to using more than two bytes [can be used a as a jump
	// immediate by copying a 16-bit immediate value to the pc] [this
	// instruction ONLY has an advantage over using two successive cpyi
	// instructions when used to copy a 16-bit immediate value to the
	// pc])
	instr_g5_op_cpypi,
	
	// Call instructions
	
	// (CALL Immediate, which sets the link register to the return
	// address, then sets the program counter to the destination
	// address)
	instr_g5_op_calli,
	
	// Indexed Load/store instructions:
	
	// (Load 8-bit value from memory at address [rBp + 16-bit Immediate
	// value] into rA)
	instr_g5_op_ldrxi,
	
	// (Store rA to memory at address [rBp + 16-bit Immediate value])
	instr_g5_op_strxi
	
};



// Encoded instructions

// Group 1 (Non-branching instructions with 8-bit immediate values):  
// Encoding:  0ooo aaaa iiii iiii
struct encoded_ig1_instr
{
public:		// variables
	//u16 id : 1;
	//u16 op : instr_g1_op_width; 
	//u16 ra_index : instr_g1_ra_index_width;
	//u16 imm_value : instr_g1_imm_value_width;
	u16 data = 0;
	
public:		// variables
	inline void set_id( size_t n_id )
	{
		clear_and_set_bits_with_range( data, n_id, instr_g1_id_pos,
			instr_g1_id_pos );
	}
	inline void set_op( instr_grp_1_oper n_op )
	{
		clear_and_set_bits_with_range( data, n_op, instr_g1_op_range_hi,
			instr_g1_op_range_lo );
	}
	inline void set_ra_index( u32 n_ra_index )
	{
		clear_and_set_bits_with_range( data, n_ra_index,
			instr_g1_ra_index_range_hi, instr_g1_ra_index_range_lo );
	}
	inline void set_imm_value( u32 n_imm_value )
	{
		clear_and_set_bits_with_range( data, n_imm_value,
			instr_g1_imm_value_range_hi, instr_g1_imm_value_range_lo );
	}
	
	// Debugging getters
	inline size_t get_id() const
	{
		return get_bits_with_range( data, instr_g1_id_pos, 
			instr_g1_id_pos );
	}
	inline size_t get_op() const
	{
		return get_bits_with_range( data, instr_g1_op_range_hi, 
			instr_g1_op_range_lo );
	}
	inline size_t get_ra_index() const
	{
		return get_bits_with_range( data, instr_g1_ra_index_range_hi, 
			instr_g1_ra_index_range_lo );
	}
	inline size_t get_imm_value() const
	{
		return get_bits_with_range( data, instr_g1_imm_value_range_hi, 
			instr_g1_imm_value_range_lo );
	}
	
	
} __attribute__((_align2));


// Group 2 (The instruction group with the most opcodes):  
// Encoding:  10oo oooo aaaa bbbb
struct encoded_ig2_instr
{
public:		// variables
	//u16 id : instr_g2_id_range_hi - instr_g2_id_range_lo + 1;
	//u16 op : instr_g2_op_width;
	//u16 ra_index : instr_g2_ra_index_width;
	//u16 rb_index : instr_g2_rb_index_width;
	u16 data;
	
public:		// variables
	//inline void set_id( u32 val )
	//{
	//	
	//}
	
} __attribute__((_align2));


// Group 3 (Instructions with one register and two register pairs):  
// Encoding:  1100 ooaa aabb bccc
struct encoded_ig3_instr
{
public:		// variables
	u16 id : instr_g3_id_range_hi - instr_g3_id_range_lo + 1;
	u16 op : instr_g3_op_width;
	u16 ra_index : instr_g3_ra_index_width;
	u16 rbp_index : instr_g3_rbp_index_width;
	u16 rcp_index : instr_g3_rcp_index_width;
} __attribute__((_align2));






// "Expanded" instruction classes are used during processing and eventually
// get converted to "encoded" instruction structs

// Group 1 (Non-branching instructions with 8-bit immediate values):  
// Encoding:  0ooo aaaa iiii iiii
class expanded_ig1_instr
{
public:		// variables
	static constexpr size_t id = instr_g1_id;
	instr_grp_1_oper op;
	u32 ra_index;
	u8 imm_value;
	
public:		// functions
	//inline encoded_ig1_instr encode() const
	//{
	//	
	//}
	
};

// Group 2 (The instruction group with the most opcodes):  
// Encoding:  10oo oooo aaaa bbbb
class expanded_ig2_instr
{
public:		// variables
	static constexpr size_t id = instr_g2_id;
	instr_grp_2_oper op;
	u32 ra_index, rb_index;
	bool ra_index_is_for_pair, rb_index_is_for_pair;
	
public:		// functions
	//inline encoded_ig2_instr encode() const
	//{
	//	encoded_ig2_instr ret;
	//	
	//	ret.
	//}
	
};

// Group 3 (Instructions with one register and two register pairs):  
// Encoding:  1100 ooaa aabb bccc
class expanded_ig3_instr
{
public:		// variables
	static constexpr size_t id = instr_g3_id;
	instr_grp_3_oper op;
	u32 ra_index, rbp_index, rcp_index;
	
public:		// functions
	//inline encoded_ig3_instr encode() const
	//{
	//	
	//}
};



#endif		// instruction_stuff_hpp
