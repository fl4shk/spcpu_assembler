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


#ifndef string_parsing_stuff_hpp
#define string_parsing_stuff_hpp

#include "misc_types.hpp"
#include "misc_includes.hpp"
#include "misc_output_class.hpp"


typedef std::string::size_type str_size_type;

class token
{
public:		// variables
	str_size_type start_pos = 0;
	std::string str;
	
public:		// functions
	inline token()
	{
	}
	
	inline bool is_valid() const
	{
		return ( start_pos != std::string::npos );
	}
};



str_size_type find_non_ws_char_index( const std::string& to_search, 
	str_size_type search_start_pos=0 );
str_size_type find_ws_char_index( const std::string& to_search, 
	str_size_type search_start_pos=0 );
void find_token_range( const std::string& to_search, 
	str_size_type search_start_pos, str_size_type& token_start_pos, 
	str_size_type& token_size );
//void find_token( const std::string& to_search, 
//	str_size_type search_start_pos, token& ret );

void find_token( const std::string& to_search, 
	str_size_type search_start_pos, token& ret );
inline void find_token( const std::string& to_search,
	const token& prev_tok, token& ret )
{
	find_token( to_search, prev_tok.start_pos + prev_tok.str.size(), ret );
}

void split_line( const std::string& line, std::vector<token>& tok_vec );



#endif		// string_parsing_stuff_hpp
