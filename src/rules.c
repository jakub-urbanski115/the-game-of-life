#include "spr.h"


int rule1(int nlive, int whatmi)
{
	if(whatmi==1)
	{
		if(nlive>1)
		{
			if(nlive<4)
			{
				return 1;
			}
			return 0;
		}
		return 0;
	}
	else if (whatmi ==0)
	{
		if(nlive==3)
		{
			return 1;
		}
		return 0;
	}

	return -1;
}
