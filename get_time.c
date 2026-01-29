#include "general.h"

/*What to return?*/	get_time(void)//Approach from isromero
int	get_time(** time)//My idea: return 1 or 0 in case of success or wrong, 
			 //and get time by reference
{
	unsigned long long	time_in_ms;//I' not sure to do this in long long
	struct timeval		current_time;//Used by gettimeofday
	
	time_in_ms = 0;
	if (gettimeofday(&current_time, NULL) == -1)
	{
		//Print error and return something to say this is wrong
	}
	time_in_ms = (current_time.tv_sec * 1000) +
		(current_time.tv_usec / 1000);//Learn what happens here. 
					      //Obviously, turn seconds to ms
}

//What arpsao- said to isromero
/*
unsigned long long start = get_time()
...
...
...
... bla bla some time
unsigned long long end = get_time()
unsigned long long time_passed = end - start;*/
