#include <stdio.h>
#include<stdlib.h>
#include<math.h>
# define OK 0;
# define ERROR -1;
#define TRUE 1;
#define FALSE 0;
typedef int Status;
typedef struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;
void SwapAddress(BiTNode*p1,BiTNode*p2){
BiTNode* p3=(BiTNode*)malloc(sizeof(BiTNode));
*p3=*p1;
long temp1=(long)p1;
BiTNode* temp2=(BiTNode*)temp1;
*temp2=*p2;
long temp3=(long)p2;
BiTNode* temp4=(BiTNode*)temp3;
*temp4=*p3;
free(p3);
}


Status PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return OK;
    }
    else {
        printf("%d  ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
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
Status InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return OK;
    }
    else {
        InOrderTraverse(T->lchild);
        printf("%d  ", T->data);
        InOrderTraverse(T->rchild);
    }
    return OK;
}
int main(void) {
    int key=10; 
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sw[10]={0.0,1.0,3.0,6.0,10.0,15.0,21.0,28.0,36.0,45.0};
    BiTree T;
    SecondOptimal(&T,num,sw,1,9);
    BiTNode a;
    a.data=1;
    a.lchild=&a;
    BiTNode b;
    b.data=1;
    b.lchild=&b;
    BiTNode* p1=&a;
    BiTNode* p2=&b;
    printf("%p\n%p\n",&a,&b);
    SwapAddress(&a,&b);
    printf("%p\n%p\n",&a,&b);
	return 0;
}
