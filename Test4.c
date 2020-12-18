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
void revise(int* p){
p[3]=2;

}
void revise2(int integer){
integer =5;

}
int main(void){
int array[10];
array[3]=1;
int integer=6; 
revise(array);
printf("%d\n%d\n",array[3],integer);

return 0;
}