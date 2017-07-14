#include <bits/stdc++.h>
using namespace std;
const int shift=1e7;
int k,n;
int a[2000];
int b[2000];
int chk[20000000];
int main(){
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);

    for(int i=0;i<n;i++){
        int sum=b[i];
        set<int> s;
        for(int j=0;j<k;j++){
            sum-=a[j];
            if(s.insert(sum).second)
                chk[sum+shift]++;
        }
    }
    int ans=0;
    for(int i=0;i<20000000;i++)
        if(chk[i]>=n)
            ans++;
    printf("%d\n",ans);
    return 0;
}