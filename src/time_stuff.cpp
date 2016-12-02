#include "time_stuff.hpp"

prng::instance_type prng::instance(get_initial_seed());

std::chrono::high_resolution_clock::time_point profiler::start_tp,
	profiler::end_tp;

