#include <stdio.h>
#include<stdlib.h>
#include<math.h>
# define OK 0;
# define ERROR -1;
typedef int Status;
typedef struct BiTNode{
    int data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;
//在二叉排序树中查找元素
BiTree SearchBST(BiTree T,int key){
if ((!T)||(key==(T->data))/* condition */)
{
    return T;/* code */
}
else{
    if(key<(T->data)){
        return SearchBST(T->lchild,key);

    }
    else{

        return SearchBST(T->rchild,key);
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

int main(void) {
    int key=10; 
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sw[10]={0.0,1.0,3.0,6.0,10.0,15.0,21.0,28.0,36.0,45.0};
    BiTree T;
    SecondOptimal(&T,num,sw,1,9);
    if (SearchBST(T,key)/* condition */)
    {
       printf("查找结果是%d(0表示失败,1表示成功)\n",key==(SearchBST(T,key)->data));
    printf("指针最后指向%d\n",SearchBST(T,key)->data); /* code */
    }
    else
    {
        printf("失败");/* code */
    }
    
    
	return 0;
}
