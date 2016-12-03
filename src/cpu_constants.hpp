#ifndef cpu_constants_hpp
#define cpu_constants_hpp

#include "misc_defines.hpp"

constexpr size_t proc_flags_width = 2;
constexpr size_t proc_flags_msb_pos = width_to_msb_pos(proc_flags_width);


// General register constants

// 16 GPRs
constexpr size_t cpu_num_regs = 16;

// 8 GPR pairs
constexpr size_t cpu_num_reg_pairs = 8;


// Instruction encoding things
constexpr size_t cpu_reg_index_ie_width = 4;
constexpr size_t cpu_reg_index_ie_msb_pos 
	= width_to_msb_pos(cpu_reg_index_ie_width);

constexpr size_t cpu_rp_index_ie_width = 3;
constexpr size_t cpu_rp_index_ie_msb_pos 
	= width_to_msb_pos(cpu_rp_index_ie_width);


// Register widths and most significant bit positions
constexpr size_t cpu_reg_width = 8;
constexpr size_t cpu_reg_msb_pos = width_to_msb_pos(cpu_reg_width);

constexpr size_t cpu_rp_width = 16;
constexpr size_t cpu_rp_msb_pos = width_to_msb_pos(cpu_rp_width);

// Immediate value widths and most significant bit positions
constexpr size_t cpu_imm_value_8_width = cpu_reg_width;
constexpr size_t cpu_imm_value_8_msb_pos = cpu_reg_msb_pos;

constexpr size_t cpu_imm_value_16_width = cpu_rp_width;
constexpr size_t cpu_imm_value_16_msb_pos = cpu_rp_msb_pos;


// CPU Register array size stuff
constexpr size_t cpu_reg_arr_width = 16;
constexpr size_t cpu_reg_arr_msb_pos = width_to_msb_pos(cpu_reg_arr_width);


// Non-instruction data in/out size stuff (8-bit because during instruction
// execution, the CPU can only load or store one byte at a time)
constexpr size_t cpu_data_inout_8_width = cpu_reg_width;
constexpr size_t cpu_data_inout_8_msb_pos = cpu_reg_msb_pos;

// Instruction data size stuff (16-bit
constexpr size_t cpu_data_inout_16_width = cpu_rp_width;
constexpr size_t cpu_data_inout_16_msb_pos = cpu_rp_msb_pos;



// Addressing stuff
constexpr size_t cpu_addr_width = cpu_rp_width;
constexpr size_t cpu_addr_msb_pos = cpu_rp_msb_pos;
 
// CPU state stuff
constexpr size_t cpu_state_width = 4;
constexpr size_t cpu_state_msb_pos = width_to_msb_pos(cpu_state_width);


#endif		// cpu_constants_hpp
