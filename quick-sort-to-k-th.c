#include <stdio.h>
#include <assert.h>
int a[]={6,5,4,3,2,1};
int n=sizeof(a)/sizeof(int);
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void dispa(int n,int a[]){
	int *p;
	for(p=a;p<a+n;p++)
		printf("%d ",*p);
	putchar('\n');
}
int qs(int begin,int end,int k,int a[]){
	int key=a[begin];
	int p=begin,q=end-1;
	if(begin>=end-1) return a[k];
	assert(begin<end);
	while(p<q){
		while(p<q && a[q]>=key) q--;
		swap(a+p,a+q);
		while(p<q && a[p]<key) p++;
		swap(a+p,a+q);
	}
	a[p]=key;
	printf(">> p: %d a[p]: %d k:%d\n",p,a[p],k);
	dispa(end-begin,a+begin);
	if(p>k) 
		return qs(begin,p+1,k,a);
	else if(p<k)
		return qs(p+1,end,k-p,a);
	return a[p];
}
int main(){
	int k;
	scanf("%d",&k);
	dispa(n,a);
	printf("[ %d ]\n",qs(0,n,k,a));
	dispa(n,a);
	return 0;
}
