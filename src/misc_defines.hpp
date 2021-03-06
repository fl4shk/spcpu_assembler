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


#ifndef misc_defines_hpp
#define misc_defines_hpp


#define width_to_msb_pos( some_width ) ( some_width - 1 )
#define bprange_to_mask( bit_pos_hi, bit_pos_lo ) \
	( ( 1 << ( bit_pos_hi - bit_pos_lo + 1 ) ) - 1 )
#define bprange_to_shifted_mask( bit_pos_hi, bit_pos_lo ) \
	( ( ( 1 << ( bit_pos_hi - bit_pos_lo + 1 ) ) - 1 ) << bit_pos_lo )

#define _align4 aligned(4)
#define _align2 aligned(2)


#define asm_comment( stuff ) \
	asm volatile( "//@ ---" stuff " ---" )


#endif		// misc_defines_hpp
