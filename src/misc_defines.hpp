#ifndef misc_defines_hpp
#define misc_defines_hpp


#define width_to_msb_pos( some_width ) ( some_width + 1 )

#define _align4 aligned(4)


#define asm_comment( stuff ) \
	asm volatile( "//@ ---" stuff " ---" )


#endif		// misc_defines_hpp
