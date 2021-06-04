#include "Blood.h"

Blood::Blood()
{
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	received.tm_mday = newtime.tm_mday;

	received.tm_mon = 1 + newtime.tm_mon;

	received.tm_year = 1900 + newtime.tm_year;

	if (received.tm_mon == 12)
	{
		expiry.tm_mday = received.tm_mday;
		expiry.tm_mon = 1;
		expiry.tm_year= received.tm_year+1;

	}
	else
	{
		expiry.tm_mday = received.tm_mday;
		expiry.tm_mon =received.tm_mon+ 1;
		expiry.tm_year = received.tm_year;
	}
}

