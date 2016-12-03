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


#ifndef assembler_class_hpp
#define assembler_class_hpp


#include "misc_types.hpp"
#include "misc_includes.hpp"
#include "misc_bitwise_funcs.hpp"
#include "misc_output_class.hpp"

#include "instruction_stuff.hpp"
#include "string_parsing_stuff.hpp"
#include "cstm_containers.hpp"

//class label
//{
//public:		// variables
//	size_t line_num;
//	std::string some_str;
//};

class assembler
{
public:		// variables
	
	// Map line_numbers to entire_lines
	std::map< size_t, std::string > line_map;
	
	
	//// Map label names to label instances
	//std::map< std::string, label > label_map;
	
	// Map label names (without the ending colon) to line numbers
	std::map< std::string, size_t > label_map;
	
	// Map line numbers to token vectors
	std::map< size_t, std::vector<token> > tok_vec_map;
	
public:		// functions
	
	inline assembler( const std::string& prog_file_name )
	{
		std::ifstream prog_file(prog_file_name);
		
		if (!prog_file.is_open())
		{
			quit_with_misc_output( "Unable to open ", prog_file_name, 
				"\n" );
		}
		
		split_prog_file_into_lines(prog_file);
		split_lines_into_tokens();
		find_labels();
	}
	
	
protected:		// functions
	void split_prog_file_into_lines( std::ifstream& prog_file );
	void split_lines_into_tokens();
	
	void find_labels();
	
	// This is for a FULL label token, including the ":" (which should
	// definitely exist for a full label token)
	bool label_tok_valid( const token& label_tok );
	
	
	inline bool character_is_alpha( char c )
	{
		return ( ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ) );
	}
	inline bool character_is_numeric( char c )
	{
		return ( c >= '0' && c <= '9' );
	}
	bool str_only_alphanumeric_underscore( const std::string& to_check );
	
	
	template< typename... arg_types >
	inline void quit_with_misc_output( arg_types&&... args ) const
	{
		show_misc_output(args...);
		exit(1);
	}
	
};


#endif		// assembler_class_hpp
