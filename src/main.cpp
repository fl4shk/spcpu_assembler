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


#include "assembler_class.hpp"




int main( int argc, char** argv )
{
	const std::string prog_file_name("inouts/test_program.spcpu");
	
	//assembler test_assembler(prog_file_name);
	encoded_ig1_instr test_ig1_instr;
	//u8* temp = reinterpret_cast<u8*>(&test_ig1_instr);
	
	
	//cout << sizeof(test_ig1_instr) << endl;
	//test_ig1_instr.id = 1;
	//test_ig1_instr.op = instr_g1_op_addi;
	//test_ig1_instr.ra_index = 10;
	//test_ig1_instr.imm_value = 0xf8;
	test_ig1_instr.set_id(1);
	test_ig1_instr.set_op(instr_g1_op_adci);
	test_ig1_instr.set_ra_index(3);
	test_ig1_instr.set_imm_value(0xf8);
	//show_misc_output( std::hex, static_cast<int>(temp[0]), " ", 
	//	static_cast<int>(temp[1]), "\n" );
	show_misc_output( std::hex, test_ig1_instr.data, "\t\t",
		test_ig1_instr.get_id(), " ", test_ig1_instr.get_op(), " ",
		test_ig1_instr.get_ra_index(), " ",
		test_ig1_instr.get_imm_value(), "\n" );
	
	
	return 0;
}


