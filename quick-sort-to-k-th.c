#include <stdio.h>
#include <assert.h>
int a[305];
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
	if(begin>=end-1){
                assert(begin==k);
                return a[begin];
        }
	assert(begin<end);
	while(p<q){
		while(p<q && a[q]>=key) q--;
		swap(a+p,a+q);
		while(p<q && a[p]<=key) p++;
		swap(a+p,a+q);
	}
	a[p]=key;
	//~ printf(">> p: %d a[p]: %d k: %d\n",p,a[p],k);
	//~ dispa(end-begin,a+begin);
	if(p>k)
		return qs(begin,p+1,k,a);
	else if(p<k)
		return qs(p+1,end,k,a);
	return a[p];
}
int main(){
	int n,k,i;
	scanf("%d",&n);
        for(i=0;i<n;i++)
                scanf("%d",a+i);
	scanf("%d",&k);
	printf("%d\n",qs(0,n,k,a));
	return 0;
}
