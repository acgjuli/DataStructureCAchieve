#include <stdio.h>
#include<stdlib.h>
#include<math.h>
# define OK 0;
# define ERROR -1;
#define TRUE 1;
#define FALSE 0;
typedef float Status;
typedef struct BiTNode{
    float data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;
//在二叉排序树中查找元素
BiTree SearchBST1(BiTree T,float key){
if ((!T)||(key==(T->data))/* condition */)
{
    return T;/* code */
}
else{
    if(key<(T->data)){
        return SearchBST1(T->lchild,key);

    }
    else{

        return SearchBST1(T->rchild,key);
    }


}




}
BiTree SearchBST(BiTree T,float key){
if ((!T)||(key==(T->data))/* condition */)
{
    return T;/* code */
}
else{
    if(key<(T->data)){
        if(T->lchild){
            return SearchBST(T->lchild,key);
        }
        else{
            return(T);
        }
    }
    else{
           if(T->rchild){
            return SearchBST(T->rchild,key);
        }
        else{
            return(T);
        } 
    }


}




}
Status InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return OK;
    }
    else {
        InOrderTraverse(T->lchild);
        printf("%f  ", T->data);
        InOrderTraverse(T->rchild);
    }
    return OK;
}
Status InsertBST(BiTree *T,float key){
BiTree    p=SearchBST(*T,key);
if(!SearchBST1(*T,key)){
BiTree s=(BiTree)malloc(sizeof(BiTNode));
s->data=key;
s->lchild=NULL;    
s->rchild=NULL;    
if(!p){
    *T=s;
    }
    else{

        if(key<(p->data)){
            p->lchild=s;
        }
        else{
            p->rchild=s;
        }
    }


return TRUE;}
else{
return FALSE;

}

}


void SecondOptimal(BiTree * T,float R[],float sw[],int low,int high){
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
    float key=10; 
    float num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sw[10]={0.0,1.0,3.0,6.0,10.0,15.0,21.0,28.0,36.0,45.0};
    BiTree T;
    SecondOptimal(&T,num,sw,1,9);
printf("%f\n",InsertBST(&T,5.5));
InOrderTraverse(T);    
    
	return 0;
}
