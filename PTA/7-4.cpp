#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
#define MAXQSIZE 10
typedef int QElemType;
typedef int Status;
typedef struct{
    QElemType *base;
    int rear;
    int front;
}SqQueue;
Status InitQueue(SqQueue &Q)
{
    Q.base=new QElemType[MAXQSIZE];
    if(!Q.base) return ERROR;
    Q.front=Q.rear=0;
    return OK;
}
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}
Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear)return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}
Status IsEmpty(SqQueue &Q){
	if(Q.front==Q.rear)return OK;
    else{
        return ERROR;
    }
}
Status IsFull(SqQueue &Q){
	if((Q.rear+1)%MAXQSIZE==Q.front){return OK;}
    else{return ERROR;}
} 
Status DestroyQueue(SqQueue &Q){
    free(Q.base);
    Q.base=0;
    Q.front=0;
    if(Q.base==0){
        return  OK;
    }
    else{
        return  ERROR;
    }
}
int main(){
    SqQueue Q;
    int n,i,op,e;
    InitQueue(Q);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>op;
        if(op){
        if(IsFull(Q))cout<<"FULL ";
        else EnQueue(Q,op);
		}else{
        if(IsEmpty(Q))cout<<"EMPTY ";
        else{
        DeQueue(Q,e);
        cout<< e<<" ";
        }
        }
    }
    cout.put('\n');
    while(!IsEmpty(Q)){
        DeQueue(Q,e);
        cout<<e<<" ";
    }
//     cout<<endl;
    DestroyQueue(Q);
    return 0;
}