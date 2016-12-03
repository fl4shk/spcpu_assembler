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


#include "string_parsing_stuff.hpp"

str_size_type find_non_ws_char_index( const std::string& to_search, 
	str_size_type search_start_pos )
{
	str_size_type ret;
	
	bool found_non_ws_index = false;
	
	for ( ret=search_start_pos; ret<to_search.size(); ++ret )
	{
		const char& temp_char = to_search.at(ret);
		
		if ( ( temp_char != ' ' ) && ( temp_char != '\t' ) )
		{
			found_non_ws_index = true;
			break;
		}
	}
	
	if (found_non_ws_index)
	{
		return ret;
	}
	
	return std::string::npos;
}

str_size_type find_ws_char_index( const std::string& to_search, 
	str_size_type search_start_pos )
{
	str_size_type ret;
	
	bool found_ws_index = false;
	
	for ( ret=search_start_pos; ret<to_search.size(); ++ret )
	{
		const char& temp_char = to_search.at(ret);
		
		if ( ( temp_char == ' ' ) || ( temp_char == '\t' ) )
		{
			found_ws_index = true;
			break;
		}
	}
	
	if (found_ws_index)
	{
		return ret;
	}
	
	return std::string::npos;
}


void find_token_range( const std::string& to_search, 
	str_size_type search_start_pos, str_size_type& token_start_pos, 
	str_size_type& token_size )
{
	token_start_pos = find_non_ws_char_index( to_search, 
		search_start_pos );
	
	if ( token_start_pos == std::string::npos )
	{
		token_size = std::string::npos;
		return;
	}
	
	str_size_type temp = find_ws_char_index( to_search, token_start_pos );
	
	if ( temp == std::string::npos )
	{
		token_size = to_search.size() - token_start_pos;
	}
	else
	{
		token_size = temp - token_start_pos;
	}
}


void find_token( const std::string& to_search, 
	str_size_type search_start_pos, token& ret )
{
	str_size_type token_size;
	
	find_token_range( to_search, search_start_pos, ret.start_pos,
		token_size );
	
	//show_misc_output( search_start_pos, " ", ret.start_pos, " ",
	//	token_size, "\n" );
	
	if ( token_size == std::string::npos )
	{
		//ret.start_pos = std::string::npos;
		ret.str = "";
		
		return;
	}
	
	ret.str = to_search.substr( ret.start_pos, token_size );
}


void split_line( const std::string& line, std::vector<token>& tok_vec )
{
	for ( token to_push; to_push.start_pos!=std::string::npos; )
	{
		if ( to_push.str.size() == 0 )
		{
			find_token( line, 0, to_push );
		}
		else // if ( to_push.str.size() > 0 )
		{
			find_token( line, tok_vec.back(), to_push );
		}
		
		if ( to_push.start_pos != std::string::npos )
		{
			tok_vec.push_back(to_push);
		}
	}
}


