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
BiTNode* temp=(*p)->rchild;
if(!temp){
    *p=NULL;

    }
else{
    (*p)->data=(temp)->data;
    (*p)->lchild=(temp)->lchild;
    (*p)->rchild=(temp)->rchild;
    }

}
void SetLchildToSelf(BiTree* p){
BiTNode* temp=(*p)->lchild;
if(!temp){
    *p=NULL;

    }
else{
    (*p)->data=(temp)->data;
    (*p)->rchild=(temp)->rchild;
    (*p)->lchild=(temp)->lchild;
    }

}

int main(void){
BiTNode* p1=(BiTNode*)malloc(sizeof(BiTNode));
BiTNode* p2=(BiTNode*)malloc(sizeof(BiTNode));
BiTNode* p3=(BiTNode*)malloc(sizeof(BiTNode));
p1->lchild=p2;
p2->data=2;
p2->lchild=p3;
printf("%p\n",p1->lchild);
p3->data=3;
BiTree*p4=&p1;
free(p2);
printf("%p\n%p\n%p\n",p1->lchild,p2->lchild,p3);
SetRchildToSelf(&p2);


}