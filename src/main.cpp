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


#include "misc_types.hpp"
#include "misc_includes.hpp"
#include "misc_output_class.hpp"

#include "instruction_stuff.hpp"
#include "string_parsing_stuff.hpp"
#include "cstm_containers.hpp"

//struct label
//{
//public:		// variables
//	size_t line_num;
//	std::string some_str;
//};
//
//
//struct instr
//{
//	
//};




int main( int argc, char** argv )
{
	
	const std::string prog_file_name("inouts/test_program.spcpu");
	std::ifstream prog_file(prog_file_name);
	
	
	if (!prog_file.is_open())
	{
		cout << "Unable to open " << prog_file_name << endl;
		return 1;
	}
	
	
	
	// < line_number, entire_line >
	std::map< size_t, std::string > line_map;
	
	// < line_number, label_name >
	std::map< size_t, std::string > label_map;
	
	// < line_number, tok_vec >
	std::map< size_t, std::vector<token> > tok_vec_map;
	
	
	for ( size_t line_num=1; ; ++line_num ) 
	{
		std::string temp_str;
		
		getline( prog_file, temp_str );
		
		if ( temp_str.size() <= 0 )
		{
			break;
		}
		line_map[line_num] = temp_str;
	}
	
	prog_file.close();
	
	//{
	//	std::vector<token> line_5_tok_vec;
	//	const std::string line_5 = line_map.at(5);
	//	
	//	split_line( line_5, line_5_tok_vec );
	//	
	//	
	//	for ( auto iter : line_5_tok_vec )
	//	{
	//		show_misc_output( iter.start_pos, "\t\t", iter.str, "\n" );
	//	}
	//	
	//}
	
	
	// Split the line_map into a map of vectors of tokens so further
	// processing can be done
	for ( auto iter : line_map )
	{
		std::vector<token> tok_vec;
		
		split_line( iter.second, tok_vec );
		
		show_misc_output( iter.first, " | ", iter.second, "\n" );
		//show_misc_output( tok_vec.size(), "\n" );
		
		tok_vec_map[iter.first] = std::move(tok_vec);
		
		for ( auto tok : tok_vec )
		{
			show_misc_output( tok.start_pos, "\t\t", tok.str, "\n" );
		}
		
		cout << "\n\n";
	}
	
	
	
	return 0;
}




