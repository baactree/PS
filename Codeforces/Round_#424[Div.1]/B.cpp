#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
priority_queue<int> pq;
vector<int> deci[100005];
int tree[100005];
pair<int,int> itree[400005];
int sz;
void iupdate(int idx,pair<int,int> val){
    idx+=sz;
    itree[idx]=val;
    idx/=2;
    while(idx){
        itree[idx]=min(itree[idx*2],itree[idx*2+1]);
        idx/=2;
    }
}
pair<int,int> iquery(int a,int b){
    pair<int,int> ret={0x3f3f3f3f,0x3f3f3f3f};
    a+=sz;
    b+=sz;
    while(a<=b){
        if(a&1)
            ret=min(ret,itree[a++]);
        if(!(b&1))
            ret=min(ret,itree[b--]);
        a/=2;
        b/=2;
    }
    return ret;
}
void update(int idx,int val){
    idx++;
    while(idx<100005){
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    idx++;
    int ret=0;
    while(idx){
        ret+=tree[idx];
        idx-=idx&(-idx);
    }
    return ret;
}
const int inf=0x3f3f3f3f;
int main(){
    memset(itree,0x3f,sizeof(itree));

    scanf("%d",&n);
    sz=1;
    while(sz<n)
        sz*=2;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        pq.push(-arr[i]);
        update(i,1);
        iupdate(i,{arr[i],i});
    }
    typedef long long ll;
    ll ans=1;
    int idx=0;
    int cnt=0;
    while(true){
        if(arr[idx]==-pq.top()){
            cnt++;
            pq.pop();
            update(idx,-1);
            iupdate(idx,{inf,inf});
            if(cnt==n)
                break;
        }
        //idx+1 -> n-1
        auto k=iquery(idx+1,n-1);
        if(k.first==-pq.top()){
            ans+=query(k.second)-query(idx);
            idx=k.second;
        }
        //0->idx
        else{
            ans+=query(n-1)-query(idx);
            auto k=iquery(0,idx-1);
            ans+=query(k.second);
            idx=k.second;
        }
    }
    printf("%lld\n",ans);

    return 0;
}