#include <stdio.h>
#include <assert.h>
int a[]={1,6,4,3,5,5,3,6};
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void qs(int begin,int end,int a[]){
	int key=a[begin];
	int *p=a+begin,*q=a+end-1;
	//~ printf("%ld %ld\n",begin-a,end-a);
	if(begin>=end-1) return;
	assert(begin<end);
	while(p<q){
		while(p<q && *q>=key) q--;
		swap(p,q);
		while(p<q && *p<key) p++;
		swap(p,q);
	}
	*p=key;
	qs(begin,p-a+1,a);
	qs(p-a+1,end,a);
}
int main(){
	int *p,n=sizeof(a)/sizeof(int);
	qs(0,n,a);
	for(p=a;p<a+n;p++)
		printf("%d ",*p);
	return 0;
}
