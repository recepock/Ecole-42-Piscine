#ifndef FT_BOOLEAN_H

# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum t_bool
{
	true = 1,
	false = 0
}t_bool;

# define EVEN(N) ((N) % 2 == 0)

# define TRUE 1

# define FALSE 0

# define ODD_MSG "I have an odd number of arguments.\n"

# define EVEN_MSG "I have an even number of arguments.\n" 

# define SUCCESS 0

#endif
