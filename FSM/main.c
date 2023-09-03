#include"stdio.h"
#include "fsm_run.h"
#include "logic.h"
unsigned int i = 0;
int main()
{
	
	fsm1_test_init();
	fsm2_test_init();
        
        // 测试状态机框架的一些函数
	printf(">> FSM 1 current state is: %d \n", fsm_state_get(&fsm_1));  //得到当前状态机状态
	printf(">> FSM 2 current state is: %d \n", fsm_state_get(&fsm_2));

	printf("\n");
	printf(">> fsm1_state_1 link is: %d \n", fsm_state_link(&fsm1_state_1));
	printf(">> fsm1_state_2 link is: %d \n", fsm_state_link(&fsm1_state_2));
	printf(">> fsm1_state_3 link is: %d \n", fsm_state_link(&fsm1_state_3));

	printf("\n");
	printf(">> fsm2_state_1 link is: %d \n", fsm_state_link(&fsm2_state_1));
	printf(">> fsm2_state_2 link is: %d \n", fsm_state_link(&fsm2_state_2));
	printf(">> fsm2_state_3 link is: %d \n", fsm_state_link(&fsm2_state_3));

	printf("\n");
	printf(">> fsm1_state_2 is belongs to: %s \n", fsm_state_blelong_to(&fsm1_state_2));
	printf(">> fsm2_state_3 is belongs to: %s \n", fsm_state_blelong_to(&fsm2_state_3));

	printf("\n   ================ FSM start run =====================\n\n");

	while (1)
	{
		printf("\n");
		i++;
		logic_run();
		if (i>100){
			return 0;
		}
		
	}
	return 0;
}