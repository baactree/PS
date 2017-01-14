#include <stdio.h>
#define MAXN 1000006
#define MOD 1000000009
typedef long long lld;
int N,K,D[7],E[7],ans;
int main()
{
int i,j;
//freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
scanf("%d%d",&N,&K);
E[0] = 1;
for (i=1;i<=N;i++){
D[0] = ((lld)E[0]*(K-1)%MOD + (lld)E[1]*(K-2)%MOD +
(lld)E[2]*(K-2)%MOD + (lld)E[3]*(K-2)%MOD + (lld)E[4]*(K-2)%MOD +
(lld)E[5]*(K-2)%MOD + (lld)E[6]*(K-2)%MOD)%MOD;
D[1] = ((lld)E[0] + E[1] + E[3] + E[5] + E[6])%MOD;
D[2] = E[1];
D[3] = (E[2]+E[4])%MOD;
D[4] = E[3];
D[5] = E[2];
D[6] = E[5];
for (j=0;j<7;j++) E[j] = D[j];
}
for (i=0;i<7;i++) ans = (ans+D[i])%MOD;
printf("%d\n",ans);
}