#include <bits/stdc++.h>
using namespace std;
int n;
int arr[30005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    arr[n]=0x3f3f3f3f;
    int ans=0;
    stack<int> st;
    for(int i=0;i<=n;i++){
        while(!st.empty()&&arr[st.top()]<arr[i]){
            int idx=st.top();
            st.pop();
            ans=max(ans,i-idx-1);
        }
        st.push(i);
    }
    printf("%d\n",ans);
    return 0;
}