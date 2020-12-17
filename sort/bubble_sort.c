#include<stdlib.h>
#include<string.h>
#include <stdio.h>
 void bubble_sort(int a[],int n){
     int change;
     int i;
for (i=n-1,change=1.0;i>=1&&change;--i){
	int c;
change=0;
	for(int j=0;j<i;++j){
	if(a[j]>a[j+1]){
	a[j]=a[j]^a[j+1];
	a[j+1]=a[j]^a[j+1]	;
		a[j]=a[j]^a[j+1];
	change=1;
	
	}}


} 
 
 }

int main()
{
int num[10] = {4, 7, 3, 9, 6, 1, 8, 0, 2, 5};
bubble_sort(num,10);
for (int i = 0; i <= 9; i++)
		printf("%d", num[i]);
   return 0;
}
