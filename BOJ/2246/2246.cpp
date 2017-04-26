#include <iostream>
#include <stdio.h>
using namespace std;
int n;
pair<int,int> arr[10000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt1,cnt2,cnt3,cnt4;
        cnt1=cnt2=cnt3=cnt4=0;
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(arr[i].first>arr[j].first){
                cnt1++;
                if(arr[i].second<arr[j].second)
                    cnt2++;
            }
            if(arr[i].second>arr[j].second){
                cnt3++;
                if(arr[i].first<arr[j].first)
                    cnt4++;
            }
        }
        if(cnt1==cnt2&&cnt3==cnt4)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}