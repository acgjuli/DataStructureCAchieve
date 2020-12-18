#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

 
typedef struct BiTNode{    //树的节点 
char data; 
struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree; 
 
 
typedef struct{      //队列存储树节点 
 int front, rear;
 BiTNode * data[MAX];
} Queue;
void initQueue (Queue *q)   //初始化队列
{
 q->rear=0;
 q->front=0;
}
int EmptyQueue(Queue *q)   //判断队列是否为空 
{
 if(q->rear==q->front)
	 return 1;
 else
	 return 0;
}
 
BiTNode * DeQueue(Queue *q)    //队尾删除一个元素 
{
 
  return q->data[(q->front)++];
}
 
void InQueue(Queue *q,BiTNode * p)   //队头一个元素 
{
 if (q->rear==MAX)
 {
	 printf("队列已满!"); 
 }
 else
 q->data[(q->rear)++]=p;
}
 

void SecondOptimal(BiTree * T,int R[],float sw[],int low,int high){
    int i=low;
    float min=fabsf(sw[high]-sw[low]);
    float dw=sw[high]+sw[low-1];
    for(int j=low+1;j<high;j++){
        if(fabsf(dw-sw[j]-sw[j-1])<min){
            i=j;
            min=fabsf(dw-sw[j]-sw[j-1]);
        }
    }
     *T=(BiTree)malloc(sizeof(struct BiTNode));
    (*T)->data=R[i];
    if(i==low){
        (*T)->lchild=NULL;
    
    }else{
        
        SecondOptimal(&((*T)->lchild),R,sw,low,i-1);
    }
     if(i==high){
        (*T)->rchild=NULL;
    
    }else{
        
        SecondOptimal(&((*T)->rchild),R,sw,i+1,high);
    }    

    
}
void LevelTravel (BiTree T,Queue *q)     //层序遍历 
{
	BiTNode *p;
	p=T;
	if(p!=NULL)
		InQueue(q,p);  
	while(!EmptyQueue(q))
	{
		p=DeQueue(q);
		printf("%d",p->data);
		if(p->lchild!=NULL)
			InQueue(q,p->lchild);
		if(p->rchild!=NULL)
			InQueue(q,p->rchild);
	}
}

int main(void) { 
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sw[10]={0.0,1.0,3.0,6.0,10.0,15.0,21.0,28.0,36.0,45.0};
    BiTree T;
    SecondOptimal(&T,num,sw,1,9);
    
	Queue q;
    
	initQueue(&q);
    
	LevelTravel(T,&q);
	return 0;
}
