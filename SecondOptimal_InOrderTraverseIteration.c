#include <stdio.h>
#include<stdlib.h>
#include<math.h>
# define OK 0;
# define ERROR -1;
int top=-1;
typedef int Status;

typedef struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

void push(BiTNode** a,BiTNode* elem){
    a[++top]=elem;
}
//弹栈函数
void pop( ){
    if (top==-1) {
        return ;
    }
    top--;
}
//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode* elem){
    printf("%d ",elem->data);
}
//拿到栈顶元素
BiTNode* getTop(BiTNode**a){
    return a[top];
}
//中序遍历非递归算法
void InOrderTraverse1(BiTree Tree){
    BiTNode* a[20];//定义一个顺序栈
    BiTNode * p;//临时指针
    push(a, Tree);//根结点进栈
    while (top!=-1) {//top!=-1说明栈内不为空，程序继续运行
        while ((p=getTop(a)) &&p){//取栈顶元素，且不能为NULL
            push(a, p->lchild);//将该结点的左孩子进栈，如果没有左孩子，NULL进栈
        }
        pop();//跳出循环，栈顶元素肯定为NULL，将NULL弹栈
        if (top!=-1) {
            p=getTop(a);//取栈顶元素
            pop();//栈顶元素弹栈
            displayElem(p);
            push(a, p->rchild);//将p指向的结点的右孩子进栈
        }
    }
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
void InOrderTraverse2(BiTree Tree){
    BiTNode* a[20];//定义一个顺序栈
    BiTNode * p;//临时指针
    p=Tree;
    //当p为NULL或者栈为空时，表明树遍历完成
    while (p || top!=-1) {
        //如果p不为NULL，将其压栈并遍历其左子树
        if (p) {
            push(a, p);
            p=p->lchild;
        }
        //如果p==NULL，表明左子树遍历完成，需要遍历上一层结点的右子树
        else{
            p=getTop(a);
            pop();
            displayElem(p);
            p=p->rchild;
        }
    }
}
int main(void) { 
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sw[10]={0.0,1.0,3.0,6.0,10.0,15.0,21.0,28.0,36.0,45.0};
    BiTree T;
    SecondOptimal(&T,num,sw,1,9);
    printf("中序遍历算法1：\n");
InOrderTraverse1(T);
printf("\n中序遍历算法2：\n");
InOrderTraverse2(T);
	return 0;
}
