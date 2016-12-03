#include "misc_types.hpp"
#include "misc_includes.hpp"
#include "misc_output_class.hpp"

#include "instruction_stuff.hpp"
#include "string_parsing_stuff.hpp"

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
	
	//for ( auto iter : line_map )
	//{
	//	//cout << iter.first << "|   " << iter.second << endl;
	//	//show_misc_output( iter.first, "|   ", std::hex,
	//	//	static_cast<int>(iter.second.back()), "|   ",
	//	//	iter.second.back(), "\n" );
	//}
	
	
	{
		std::vector<token> line_5_tok_vec;
		const std::string line_5 = line_map.at(5);
		
		split_line( line_5, line_5_tok_vec );
		
		
		for ( auto iter : line_5_tok_vec )
		{
			show_misc_output( iter.start_pos, "\t\t", iter.str, "\n" );
		}
		
	}
	
	//for ( auto token_vec_iter : token_vec_map )
	//{
	//	for ( auto iter_2 : iter )
	//	{
	//		cout << iter_2.first
	//	}
	//}
	
	//for ( size_t line_num=1; ; ++line_num )
	//{
	//	
	//}
	
	return 0;
}




