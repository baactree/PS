#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> st;
int main(){
    scanf("%d",&n);
    long long ans=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(!st.empty()&&st.top()<=x)
            st.pop();
        ans+=st.size();
        st.push(x);
    }
    printf("%lld\n",ans);
    return 0;
}