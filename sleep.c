#include "sleep.h"

void sleep(long t)
{
	t *= 24000;
	while(t--);
}
