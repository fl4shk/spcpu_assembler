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
	
	for ( auto iter : line_map )
	{
		std::vector<token> tok_vec;
		
		split_line( iter.second, tok_vec );
		
		show_misc_output( iter.first, " | ", iter.second, "\n" );
		//show_misc_output( tok_vec.size(), "\n" );
		
		//tok_vec_map[iter.first] = std::move(tok_vec);
		
		for ( auto tok : tok_vec )
		{
			show_misc_output( tok.start_pos, "\t\t", tok.str, "\n" );
		}
		
		cout << "\n\n";
	}
	
	//std::vector<token> tok_vec;
	//split_line( line_map.at(1), tok_vec );
	
	//{
	//	std::vector<token> line_1_tok_vec;
	//	const std::string line_1 = line_map.at(1);
	//	
	//	
	//	//token tok_0, tok_1, tok_2;
	//	//
	//	//find_token( line_1, 0, tok_0 );
	//	//find_token( line_1, tok_0, tok_1 );
	//	//find_token( line_1, tok_1, tok_2 );
	//	//
	//	//show_misc_output( tok_0.str, "\n", tok_1.str, "\n", tok_2.str, 
	//	//	"\n" );
	//	
	//	split_line( line_1, line_1_tok_vec );
	//	
	//}
	
	
	return 0;
}




