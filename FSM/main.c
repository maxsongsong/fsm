#include"stdio.h"
#include "fsm_run.h"

// 状态机1的状态
enum fsm_1_state
{
	FSM1_STATE_1 = 0,
	FSM1_STATE_2 ,
	FSM1_STATE_3 
};

// 状态机2的状态
enum fsm_2_state
{
	FSM2_STATE_1 = 0,
	FSM2_STATE_2 ,
	FSM2_STATE_3 
};

// 创建两个状态机对象
FsmObj fsm_1;
FsmObj fsm_2;

// 给每个状态机创建3个状态对象
FsmStateObj fsm1_state_1, fsm1_state_2, fsm1_state_3;
FsmStateObj fsm2_state_1, fsm2_state_2, fsm2_state_3;

// 声明一下每个状态对象的状态处理函数
unsigned char fsm1_state_1_hdl(void);
unsigned char fsm1_state_2_hdl(void);
unsigned char fsm1_state_3_hdl(void);

unsigned char fsm2_state_1_hdl(void);
unsigned char fsm2_state_2_hdl(void);
unsigned char fsm2_state_3_hdl(void);



void fsm1_test_init()
{
        // 初始化状态机
	fsm_init(&fsm_1, "fsm 1", FSM1_STATE_1);
	fsm_init(&fsm_2, "fsm 2", FSM2_STATE_1);
       
        // 初始化状态对象
	fsm_state_init(&fsm1_state_1, FSM1_STATE_1, fsm1_state_1_hdl);
	fsm_state_init(&fsm1_state_2, FSM1_STATE_2, fsm1_state_2_hdl);
	fsm_state_init(&fsm1_state_3, FSM1_STATE_3, fsm1_state_3_hdl);

    // 将状态对象添加到相应的状态机中
	fsm_state_add(&fsm_1, &fsm1_state_1);
	fsm_state_add(&fsm_1, &fsm1_state_2);
	fsm_state_add(&fsm_1, &fsm1_state_3);

     

}

void fsm2_test_init()
{
	fsm_init(&fsm_2, "fsm 2", FSM2_STATE_1);
	fsm_state_init(&fsm2_state_1, FSM2_STATE_1, fsm2_state_1_hdl);
	fsm_state_init(&fsm2_state_2, FSM2_STATE_2, fsm2_state_2_hdl);
	fsm_state_init(&fsm2_state_3, FSM2_STATE_3, fsm2_state_3_hdl);
	fsm_state_add(&fsm_2, &fsm2_state_1);
	fsm_state_add(&fsm_2, &fsm2_state_2);
	fsm_state_add(&fsm_2, &fsm2_state_3);
}
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
		printf("\n>> %d\n", i++);

                // 运行状态机， 这个可以嵌套形成层次状态机
		fsm_exec(&fsm_1);
		fsm_exec(&fsm_2);
		if (i>100)
		{
			return 0;
		}
		
	}

	return 0;
}


// 相应的状态处理函数实现

unsigned char fsm1_state_1_hdl()
{
	printf(">> Fsm1 state 1 is running ... ");
	printf(":: fsm1 next state is state 2 \n");

	fsm_change_state(&fsm_1, FSM1_STATE_2);
	return 0;
}

unsigned char fsm1_state_2_hdl()
{
	printf(">> Fsm1 state 2 is running ... ");
	printf(":: fsm1 next state is state 3 \n");
	fsm_change_state(&fsm_1, FSM1_STATE_3);
	return 0;
}

unsigned char fsm1_state_3_hdl()
{
	printf(">> Fsm1 state 3 is running ... ");
	printf(":: fsm1 next state is state 1 \n");
	fsm_change_state(&fsm_1, FSM1_STATE_1);
	return 0;
}


unsigned char fsm2_state_1_hdl()
{
	printf(">> Fsm2 state 1 is running ... ");
	printf(":: fsm2 next state is state 3 \n");
	fsm_change_state(&fsm_2, FSM2_STATE_3);
	return 0;
}

unsigned char fsm2_state_2_hdl()
{
	printf(">> Fsm2 state 2 is running ... ");
	printf(":: fsm2 next state is state 1 \n");
	fsm_change_state(&fsm_2, FSM2_STATE_1);
	return 0;
}

unsigned char fsm2_state_3_hdl()
{
	printf(">> Fsm2 state 3 is running ... ");
	printf(":: fsm2 next state is state 2 \n");
	fsm_change_state(&fsm_2, FSM2_STATE_2);
	return 0;
}