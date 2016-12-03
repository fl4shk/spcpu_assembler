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



#endif		// instruction_stuff_hpp
