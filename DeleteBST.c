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


Status Delete(BiTree *p);

Status DeleteBST(BiTree *T,int key){
if(!(*T)){

    return FALSE;
    }
else{
    if(key==((*T)->data)){
        printf("%d\n",(*T)->data);
        return Delete(T);

        }
    else{
        if(key<((*T)->data)){
                return DeleteBST(&((*T)->lchild),key);

            }
        else{
                return DeleteBST(&((*T)->rchild),key);

            }
        }

    }



}
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
free(temp);
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
free(temp);

}

Status Delete (BiTree *p){
if(!((*p)->rchild)){
    SetLchildToSelf(p);

    }
else{
    if(!((*p)->lchild)){
        SetRchildToSelf(p);

        }
    else{
        BiTNode* q=*p;
        BiTNode*  s=(*p)->lchild;
        while(s->rchild){
            BiTNode* q=s;
            s=s->rchild;

            }
        (*p)->data=s->data;
        if(q!=(*p)){
            q->rchild=s->lchild;
            }
        else{
            q->lchild=s->lchild;
            }
        Delete(&s);
        }
    
    
    }

return TRUE;
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
DeleteBST(&T,4);
InOrderTraverse(T); 
printf("\n");   
PreOrderTraverse(T);
	return 0;
}
