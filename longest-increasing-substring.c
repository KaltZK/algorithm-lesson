#include <stdio.h>
#define MAXN 100005
int max(int a,int b){
    return a>b ? a:b;
}
int main(){
    int n,i,j,ans=0;
    static int a[MAXN],f[MAXN]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            f[i]=max(f[i],a[j]<=a[i] ? f[j]+1 : 1);
            ans=max(ans,f[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
