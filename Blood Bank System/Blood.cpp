#include "Blood.h"
Blood::Blood()
{
	expiry.tm_mday = received.tm_mday;
	expiry.tm_mon = received.tm_mon+1;

 }

