#include <bits/stdc++.h>
using namespace std;
int k,n;
pair<int,int> arr[1000005];
int check[1000005];
int main(){
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    int st,fi,min_value,ans,cnt;
    min_value=2e9+5;
    ans=2e9+5;
    st=0;
    fi=0;
    // [st,fi)
    // check  k타입에 따른 각각의 수
    // 서로 다른 종류의 수
    cnt=0;
    while(st<=fi&&st<n){
        //cout<<st<<" "<<fi<<" "<<cnt<<endl;
        //system("PAUSE");
        if(cnt>=k){
            assert(st!=fi);
            int le=arr[st].first;
            int ri=arr[fi-1].first;
            int len=(ri-le+1)/2;
            int mid=le+(ri-le)/2;
            if(len<min_value){
                min_value=len;
                ans=mid;
            }
            int idx=st;
            while(idx<n){
                check[arr[idx].second]--;
                if(check[arr[idx].second]==0)
                    cnt--;
                idx++;
                if(idx==n||arr[idx].first!=arr[idx-1].first)
                    break;
            }
            st=idx;
        }
        else if(fi<n){
            int idx=fi;
            while(idx<n){
                check[arr[idx].second]++;
                if(check[arr[idx].second]==1)
                    cnt++;
                idx++;
                if(idx==n||arr[idx].first!=arr[idx-1].first)
                    break;
            }
            fi=idx;
        }
        else{
            int idx=st;
            while(idx<n){
                check[arr[idx].second]--;
                if(check[arr[idx].second]==0)
                    cnt--;
                idx++;
                if(idx==n||arr[idx].first!=arr[idx-1].first)
                    break;
            }
            st=idx;
        }
    }
    assert(ans!=2e9+5);
    printf("%d\n",ans);
    return 0;
}