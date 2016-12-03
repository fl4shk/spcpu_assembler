#ifndef cstm_containers_hpp
#define cstm_containers_hpp


#include "misc_types.hpp"
#include "misc_includes.hpp"



template< typename container_type, typename... arg_types >
inline void multi_push_back( container_type& container, 
	const arg_types&... args )
{
	cout << "const lvalue references!\n";
	( container.push_back(args), ... );
}
template< typename container_type, typename... arg_types >
inline void multi_push_back( container_type& container, 
	arg_types&&... args )
{
	cout << "rvalue references!\n";
	( container.push_back(std::move(args)), ... );
}


template< typename container_type >
void print_container( const container_type& container, 
	const size_t num_cols=8 )
{
	size_t temp = 0;
	
	//for ( auto& iter : container )
	for ( auto iter=container.cbegin(); iter!=container.cend(); ++iter )
	{
		cout << *iter << ";\t";
		
		++temp;
		
		if ( temp == num_cols )
		{
			temp = 0;
			cout << endl;
		}
	}
	
	cout << "\n\n";
}


template< typename arr_type, typename... arg_types >
void raw_assign_to_arr( arr_type some_arr, arg_types&&... args )
	__attribute__((noinline));


template< typename arr_type >
class raw_assign_to_arr_backend
{
protected:		// functions
	
	static inline void func( arr_type some_arr )
	{
	}
	
	
	template< typename first_type, typename... rem_arg_types >
	static inline void func( arr_type some_arr, 
		first_type& first_val, rem_arg_types... rem_args )
	{
		*some_arr = first_val;
		
		func( some_arr + 1, rem_args... );
	}
	
	template< typename other_arr_type, typename... arg_types >
	friend void raw_assign_to_arr( other_arr_type some_arr, 
		arg_types&&... args );
	
} __attribute__((_align4));

template< typename arr_type, typename... arg_types >
void raw_assign_to_arr( arr_type some_arr, arg_types&&... args )
{
	raw_assign_to_arr_backend<arr_type>::func( some_arr, args... );
}



// This is a small class for the purposes of holding the states of
// "previous" and "current" pairs.  It is primarily intended for use with
// SMALL types, such as vec2's, built-in types, and so on and so forth.
template< typename type >
class prev_curr_pair
{
public:		// variables
	type prev, curr;
	
public:		// functions
	
	inline void back_up()
	{
		prev = curr;
	}
	
	inline void back_up_and_update( const type& n_curr )
	{
		prev = std::move(curr);
		curr = n_curr;
	}
	inline void back_up_and_update( type&& n_curr )
	{
		prev = std::move(curr);
		curr = std::move(n_curr);
	}
	
	inline bool has_changed() const
	{
		return ( prev != curr );
	}
	
} __attribute__((_align4));



template< typename container_type, typename functor >
void piecewise_assign_op( container_type& a, container_type& b, 
	functor&& func )
{
	auto b_iter = b.cbegin();
	
	for ( auto& val : a )
	{
		val = func( val, *b_iter );
		++b_iter;
	}
}
template< typename container_type, typename type, typename functor >
void piecewise_assign_op( container_type& a, const type& to_use, 
	functor&& func )
{
	for ( auto& val : a )
	{
		val = func( val, to_use );
	}
}

template< typename container_type, typename functor >
container_type piecewise_op( const container_type& a, 
	const container_type& b, functor&& func )
{
	container_type temp;
	auto temp_iter = temp.begin();
	auto b_iter = b.cbegin();
	
	for ( auto&& val : a )
	{
		*temp_iter = func( val, *b_iter );
		
		++temp_iter;
		++b_iter;
	}
	
	return temp;
}
template< typename container_type, typename type, typename functor >
container_type piecewise_op( const container_type& a, const type& to_use, 
	functor&& func )
{
	container_type temp;
	auto temp_iter = temp.begin();
	
	for ( auto&& val : a )
	{
		*temp_iter = func( val, to_use );
		
		++temp_iter;
	}
	
	return temp;
}

template< typename container_type, typename functor >
bool piecewise_cmp( const container_type& a, const container_type& b, 
	functor&& func )
{
	auto b_iter = b.cbegin();
	
	for ( auto&& val : a )
	{
		if ( !func( val, *b_iter ) )
		{
			return false;
		}
		
		++b_iter;
	}
	
	return true;
}



#endif		// cstm_containers_hpp
