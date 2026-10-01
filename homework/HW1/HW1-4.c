#include<stdio.h>
#define ll long long

int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    ll value[n];
    int nxt[n];
    ll num = 0,ans = 0;
    for(int i=0;i<n;i++) scanf("%lld",value+i);
    for(int i=0;i<n;i++) scanf("%d",nxt+i);
    while(s!=-1){
        ans+=value[s];
        s = nxt[s];
        num++;
    }
    printf("%lld %lld\n",num,ans);
    return 0;
}