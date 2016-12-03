#ifndef misc_output_class_hpp
#define misc_output_class_hpp

#include "misc_types.hpp"
#include "misc_includes.hpp"

template< typename... arg_types >
inline void show_misc_output( arg_types&&... args );

class misc_output
{
protected:		// functions
	static inline void show_misc_output_backend()
	{
	}
	template< typename first_type, typename... rem_types >
	static inline void show_misc_output_backend
		( const first_type& first_val, rem_types&&... rem_args )
	{
		cout << first_val;
		show_misc_output_backend(rem_args...);
	}
	
	template< typename... arg_types >
	friend void show_misc_output( arg_types&&... args );
};


template< typename... arg_types >
inline void show_misc_output( arg_types&&... args )
{
	misc_output::show_misc_output_backend(args...);
}


#endif		// misc_output_class_hpp