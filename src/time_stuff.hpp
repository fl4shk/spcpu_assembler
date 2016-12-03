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


#ifndef time_stuff_hpp
#define time_stuff_hpp
#include <chrono>
#include <random>
#define _align4 aligned(4)

inline auto some_rand();

class prng
{
public:		// typedefs
	typedef decltype(std::chrono::high_resolution_clock::now()
		.time_since_epoch().count()) seed_type;
	
	//typedef std::minstd_rand instance_type;
	//typedef std::mt19937 instance_type;
	typedef std::mt19937_64 instance_type;
	
protected:		// variables
	static instance_type instance;
	
protected:		// functions
	static inline seed_type get_initial_seed()
	{
		return std::chrono::high_resolution_clock::now().time_since_epoch()
			.count();
	}
	
	friend auto some_rand();
	
} __attribute__((_align4));



inline auto some_rand()
{
	//return prng::instance();
	//return prng::instance() & 0xff;
	//return prng::instance() & 0xffff;
	//return prng::instance() % 100'000;
	
	//static constexpr size_t max_val = 10;
	//static constexpr size_t max_val = 100;
	//static constexpr size_t max_val = 1'000;
	//static constexpr size_t max_val = 10'000;
	static constexpr size_t max_val = 100'000;
	
	auto temp = prng::instance() % max_val;
	//auto temp = prng::instance();
	
	//if ( temp > max_val )
	//{
	//	temp = max_val;
	//}
	
	return temp;
}


class profiler
{
protected:		// variables
	static std::chrono::high_resolution_clock::time_point start_tp,
		end_tp;
	
protected:		// functions
	static inline auto get_hrc_now()
	{
		return std::chrono::high_resolution_clock::now();
	}
	
public:		// functions
	static inline void start()
	{
		start_tp = get_hrc_now();
	}
	
	static inline auto stop()
	{
		end_tp = get_hrc_now();
		
		std::chrono::duration<double> diff_dtn = end_tp - start_tp;
		
		return diff_dtn.count();
	}
	
	
} __attribute__((_align4));



#endif		// time_stuff_hpp
