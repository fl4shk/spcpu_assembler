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


void assembler::split_prog_file_into_lines( std::ifstream& prog_file )
{
	// Start line numbering at 1 because that's what most text editors do
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
}


void assembler::split_lines_into_tokens()
{
	// Split the line_map into a map of vectors of tokens so further
	// processing can be done
	for ( auto iter : line_map )
	{
		std::vector<token> tok_vec;
		split_line( iter.second, tok_vec );
		tok_vec_map[iter.first] = std::move(tok_vec);
	}
}

void assembler::find_labels()
{
	for ( auto iter : tok_vec_map )
	{
		// Labels must be on their own lines for ease of parsing
		if ( iter.second.size() != 1 )
		{
			continue;
		}
		
		if ( !label_tok_valid(iter.second.front()) )
		{
			show_misc_output( "Line ", iter.first, ":  INVALID label ",
				"name\n" );
			continue;
		}
		//else // if ( label_tok_valid(iter.second.front()) )
		//{
		//	show_misc_output( "Line ", iter.first, ":  label name ",
		//		"okay\n" );
		//}
		
		label_map[ iter.second.front().str.substr( 0,
			iter.second.front().str.size() - 1 ) ] = iter.first;
	}
}


bool assembler::label_tok_valid( const token& label_tok )
{
	//return ( ( label_tok.str.back() == ":" ) 
	//	&& str_only_alphanumeric_underscore( label_tok.str.substr
	//	( 1, label_tok.str.size() - 1 ) ) );
	
	// FULL label tokens should have at least one character
	if ( label_tok.str.size() <= 1 )
	{
		return false;
	}
	
	// Because this function is for a FULL label token, there should be a
	// colon at the end of the FULL string
	else if ( label_tok.str.back() != ':' )
	{
		return false;
	}
	
	else if ( character_is_numeric(label_tok.str.front()) )
	{
		return false;
	}
	
	else if ( !str_only_alphanumeric_underscore( label_tok.str.substr
		( 1, label_tok.str.size() - 2 ) ) )
	{
		return false;
	}
	
	return true;
}

bool assembler::str_only_alphanumeric_underscore
	( const std::string& to_check )
{
	for ( auto c : to_check )
	{
		if ( !( c == '_' ) && !character_is_numeric(c)
			&& !character_is_alpha(c) )
		{
			return false;
		}
	}
	
	return true;
}

