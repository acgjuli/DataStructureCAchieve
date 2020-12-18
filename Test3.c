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
void SetRchildToSelf(BiTree* p){

if(!((*p)->rchild)){
    *p=NULL;

    }
else{
    (*p)->data=((*p)->rchild)->data;
    (*p)->lchild=((*p)->rchild)->lchild;
    (*p)->rchild=((*p)->rchild)->rchild;
    }

}
void SetLchildToSelf(BiTree* p){

if(!((*p)->lchild)){
    *p=NULL;

    }
else{
    (*p)->data=((*p)->lchild)->data;
    (*p)->rchild=((*p)->lchild)->rchild;
    (*p)->lchild=((*p)->lchild)->lchild;
    }

}

int main(void){
BiTNode* p1=(BiTNode*)malloc(sizeof(BiTNode));
BiTNode* p2=(BiTNode*)malloc(sizeof(BiTNode));
BiTNode* p3=(BiTNode*)malloc(sizeof(BiTNode));
p1->lchild=p2;
p2->data=2;
printf("%p\n%p\n",p1->lchild,p2);
p2->rchild=p3;
p2=p2->rchild;
printf("%p\n%p\n%p\n%d\n",p1->lchild,p2,p3,(p1->lchild)->data);
free(p1);
free(p2);

}