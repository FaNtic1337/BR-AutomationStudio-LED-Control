#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	time_cnt = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	// 10Hz - 100ms
	led1 = !led1;
	
	// 5Hz - 200ms
	if (time_cnt % 2)
	{
		led2 = !led2;
	}
		
	// 2Hz - 500ms
	if (time_cnt % 2)
	{
		led3 = !led3;
	}
	
	// 1Hz - 1000ms
	if (time_cnt % 2)
	{
		led4 = !led4;
	}
	
	time_cnt++;
}

void _EXIT ProgramExit(void)
{

}

