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


void fsm_idie()
{
  printf("this is fsm_idie\n");
 fsmEventHandle(&pType,event_1);
}

void fsm_stade()
{
    printf("this is fsm_stade\n");
}
void fsm_running()
{
  printf("this is fsm_running\n");
}
void fsm_stop()
{
    printf("this is fsm_stop\n");
}


StateTable fTable[] =
{
    //{�������¼�����ǰ��״̬����ҪҪִ�еĺ�������һ��״̬}
    { event_1,  state_1,    fsm_idie,  event_2 },
    { event_2,  state_2,    fsm_stade,  event_3 },
    { event_3,  state_3,    fsm_running,  event_4 },
    { event_4,  state_4,    fsm_stop,  event_1 },
    //add your code here
};
 fsmType pType;

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
        if (event == pActTable[i].event && CurState == pActTable[i].CurState)
        {
            flag = 1;
            eventActFun = pActTable[i].eventActFun;
            NextState = pActTable[i].NextState;
            break;
        }
    }


    if (flag) //�������������
    {
        /*����ִ��*/
        if (eventActFun)
        {
            eventActFun();
        }

        //��ת����һ��״̬
        fsmStateTransfer(pFsm, NextState);
    }
    else
    {
        printf("there is no match\n");
    }
}



int main()
{
   
    fsmRegist(&pType,fTable);
    pType.curState = state_1;
    pType.size = sizeof(fTable)/sizeof(StateTable);

    printf("init state:%d\n\n",pType.curState);

    fsmEventHandle(&pType,event_1);
    printf("state:%d\n\n",pType.curState);

    fsmEventHandle(&pType,event_2);
    printf("state:%d\n\n",pType.curState);

    fsmEventHandle(&pType,event_3);
    printf("state:%d\n\n",pType.curState);

    fsmEventHandle(&pType,event_4);
    printf("state:%d\n\n",pType.curState);

    fsmEventHandle(&pType,event_2);
    printf("state:%d\n\n",pType.curState);

    return 0;
}
