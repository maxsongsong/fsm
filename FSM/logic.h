#ifndef __LOGIC_H_
#define __LOGIC_H_
#include"fsm_run.h"


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
extern FsmObj fsm_1;
extern FsmObj fsm_2;

// 给每个状态机创建3个状态对象
extern FsmStateObj fsm1_state_1, fsm1_state_2, fsm1_state_3;
extern FsmStateObj fsm2_state_1, fsm2_state_2, fsm2_state_3;

void fsm1_test_init();
void fsm2_test_init();
void logic_run();
extern  int a,b,c;

#endif