#ifndef misc_includes_hpp
#define misc_includes_hpp

#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <map>

#include <string>
#include <sstream>
#include <fstream>
#include <regex>

#include <algorithm>
#include <chrono>
#include <random>

#include <iterator>
#include <type_traits>

using std::cout;
using std::cin;
using std::endl;


#define _align4 aligned(4)


#define asm_comment( stuff ) \
	asm volatile( "//@ ---" stuff " ---" )


#endif		// misc_includes_hpp
