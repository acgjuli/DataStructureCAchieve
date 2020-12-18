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
void revise(BiTNode* p){

    p->data=2;
}
int main(void){
int c=2;

long a=(long)&c;
printf("%p\n",&c);
int *b=(int*)a;
*b=3;
printf("%d",c);

}