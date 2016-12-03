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
	
	assembler test_assembler(prog_file_name);
	//encoded_ig1_instr test_ig1_instr
	
	//for ( auto iter : test_assembler.label_map )
	//{
	//	show_misc_output( iter.first, "\t\t", iter.second, "\n" );
	//}
	
	return 0;
}


