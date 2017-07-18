#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100],b[100];
int num[205];
int bnum[205];
int main(){
    scanf("%d%d",&n,&k);
    int cnt=0;
    int pre=-1;
    bool flag=false;
    int idx=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        num[a[i]]++;
        if(a[i]==0){
            cnt++;
            idx=i;
        }
        else if(pre<a[i])
            pre=a[i];
        else
            flag=true;
    }
    int cnt2=0;
    for(int i=0;i<k;i++){
        scanf("%d",&b[i]);
        if(num[b[i]]==0){
            cnt2++;
        }
    }
    if(cnt2<cnt||(cnt==0&&!flag))
        printf("No\n");
    else if(cnt==1&&!flag){
        if(idx>0){
            bool ok=false;
            for(int i=0;i<k;i++){
                if(num[b[i]]==0){
                    if(a[idx-1]>=b[i])
                        ok=true;
                }
            }
            if(ok){
                printf("Yes\n");
                return 0;
            }
        }
        if(idx+1<n){
            bool ok=false;
            for(int i=0;i<k;i++){
                if(num[b[i]]==0){
                    if(a[idx+1]<=b[i])
                        ok=true;
                }
            }
            if(ok){
                printf("Yes\n");
                return 0;
            }
        }
        printf("No\n");
    }
    else
        printf("Yes\n");
    return 0;
}