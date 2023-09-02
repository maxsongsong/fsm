#include"stdio.h"
 
/*
 #define fsm_run(fsm) void fsm##_in (void);\
                      void fsm##_exe (void);\
                      void fsm##_out(void);\
                      char fsm##_chk()

 #define alg_logic_run(fsm) fsm##_self (void);\
                            void fsm##_ramp (void);\
                            void fsm##_running(void);\
                            void fsm##_stop(void)
                            */

 #define fsm_run(fsm)  void fsm##_idie (void) ;\
                       void fsm##_stade (void);\
                      void fsm##_running (void);\
                       void fsm##_stop (void);


typedef enum {
  state_1=1,
  state_2,
  state_3,
  state_4
}State;

typedef enum{
  event_1=1,
  event_2,
  event_3,
  event_4,
  event_5
}EventID;

typedef struct {
    int event;   //�¼�
    int CurState;  //��ǰ״̬
    void (*eventActFun)();  //����ָ��
    int NextState;  //��һ��״̬
}StateTable;

void f121()
{
    printf("this is f121\n");
}
void f221()
{
    printf("this is f221\n");
}
void f321()
{
    printf("this is f321\n");
}

void f122()
{
    printf("this is f122\n");
}

StateTable fTable[] =
{
    //{�������¼�����ǰ��״̬����ҪҪִ�еĺ�������һ��״̬}
    { event_1,  state_1,    f121,  event_2 },
    { event_2,  state_2,    f221,  event_3 },
    { event_3,  state_3,    f321,  event_4 },
    { event_4,  state_4,    f122,  event_1 },
    //add your code here
};

/*״̬������*/
typedef struct {
    int curState;//��ǰ״̬
    StateTable * stateTable;//״̬��
    int size;//�������
}fsmType;

/*״̬��ע��,����һ��״̬��*/
void fsmRegist(fsmType* pFsm, StateTable* pTable)
{
    pFsm->stateTable = pTable;
}

/*״̬Ǩ��*/
void fsmStateTransfer(fsmType* pFsm, int state)
{
    pFsm->curState = state;
}

/*�¼�����*/
void fsmEventHandle(fsmType* pFsm, int event)
{
    StateTable* pActTable = pFsm->stateTable;
    void (*eventActFun)() = NULL;  //����ָ���ʼ��Ϊ��
    int NextState;
    int CurState = pFsm->curState;
    int maxNum = pFsm->size;
    int flag = 0; //��ʶ�Ƿ���������

    /*��ȡ��ǰ��������*/
    for (int i = 0; i<maxNum; i++)
    {
        //���ҽ�����ǰ״̬������ָ�����¼����Ҳ�ִ����
        if (event == pActTable[i].event && CurState == pActTable[i].CurState) {
            flag = 1;
            eventActFun = pActTable[i].eventActFun;
            NextState = pActTable[i].NextState;
            break;
        }
    }


    if (flag) {
        /*����ִ��*/
        if (eventActFun){
            eventActFun();
        }
        fsmStateTransfer(pFsm, NextState); ///��ת����һ��״̬
    } else {
        printf("there is no match\n");
    }
}

 fsmType pType;
void fsm_running()
{
    fsmRegist(&pType,fTable);
    pType.curState = state_1;
    pType.size = sizeof(fTable)/sizeof(StateTable);

   
    fsmEventHandle(&pType,event_1);
    fsmEventHandle(&pType,event_2);
    fsmEventHandle(&pType,event_3);
    fsmEventHandle(&pType,event_4);
    fsmEventHandle(&pType,event_2);
}
int main()
{
   
    fsm_running();

    return 0;
}