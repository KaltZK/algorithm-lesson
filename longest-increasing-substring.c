#include <stdio.h>
#include <limits.h>
#include <assert.h>
#define MAXN 100005
int max(int a,int b){
    return a>b ? a:b;
}
int min(int a,int b){
    return a<b ? a:b;
}
int binsearch(int n,int a[],int m){
    int key,mid,l=1,r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]<m)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main(){
    int n,i,j,k,ans=0,len=0;
    /*
    POJ 3903
    O(nlogn)
    http://chhaj5236.blog.163.com/blog/static/1128810812013332417789/
    */
    static int a[MAXN],f[MAXN]={0};
    static int set[MAXN];
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        set[0]=INT_MIN;
        for(i=1;i<=n;i++){
            if(set[len]<a[i]){
                set[++len]=a[i];
                f[i]=len;
            }
            else{
                j=binsearch(len,set,a[i]);
                set[j]=a[i];
                f[i]=j;
            }
            f[i]=j;
            ans=max(ans,f[i]);
        }
        printf("%d\n",len);
    }
    return 0;
}
