#include"logic.h"
#include "stdio.h"

// 创建两个状态机对象
FsmObj fsm_1;
FsmObj fsm_2;

// 给每个状态机创建3个状态对象
FsmStateObj fsm1_state_1, fsm1_state_2, fsm1_state_3;
FsmStateObj fsm2_state_1, fsm2_state_2, fsm2_state_3;


// 相应的状态处理函数实现
 int a,b,c;
unsigned char fsm1_state_1_hdl()
{
	printf(">> Fsm1 state 1 is running ... \n");
	printf(">> set next state is state: ");
    scanf(" %d",&a);

    if (a == 2){
        printf(":: fsm1 next state is state 2 \n");
	    fsm_change_state(&fsm_1, FSM1_STATE_2);
    } else if (a == 3) {
        printf(":: fsm1 next state is state 3 \n");
	    fsm_change_state(&fsm_1, FSM1_STATE_3); 
    }
	return 0;
}

unsigned char fsm1_state_2_hdl()
{
	printf(">> Fsm1 state 2 is running ... \n");
	printf(">> set next state is state: ");
    scanf(" %d",&b);
    if (b == 1){
        printf(":: fsm1 next state is state 1 \n");
	    fsm_change_state(&fsm_1, FSM1_STATE_1);
    } else if (b == 3) {
        printf(":: fsm1 next state is state 3 \n");
	    fsm_change_state(&fsm_1, FSM1_STATE_3); 
    }
	return 0;
}

unsigned char fsm1_state_3_hdl()
{
	printf(">> Fsm1 state 3 is running ... \n");
	printf(">> set next state is state: ");
    scanf(" %d",&c);
    if (c == 1){
        printf(":>> fsm1 next state is state 1 \n");
	    fsm_change_state(&fsm_1, FSM1_STATE_1);
    } else if (c == 2) {
        printf(">> fsm1 next state is state 2 \n");
	    fsm_change_state(&fsm_1, FSM1_STATE_2); 
    }
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



void fsm1_test_init()
{
        // 初始化状态机
	fsm_init(&fsm_1, "fsm 1", FSM1_STATE_1);  
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



void logic_run()
{
    // 运行状态机， 这个可以嵌套形成层次状态机
	fsm_exec(&fsm_1);
	//fsm_exec(&fsm_2);
}
