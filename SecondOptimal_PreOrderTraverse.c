#include <stdio.h>
#include<stdlib.h>
#include<math.h>
# define OK 0;
# define ERROR -1;

typedef int Status;

struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
};

typedef struct BiTNode *BiTree;
Status PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return OK;
    }
    else {
        printf("%d", T->data);
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

int main(void) { 
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sw[10]={0.0,1.0,3.0,6.0,10.0,15.0,21.0,28.0,36.0,45.0};
    BiTree T;
    SecondOptimal(&T,num,sw,1,9);
PreOrderTraverse(T);
	return 0;
}
