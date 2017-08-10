#include <bits/stdc++.h>
using namespace std;

///
char buf[1 << 17];
int idx, nidx;
extern inline char read() {
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
extern inline int readInt() {
	int sum = 0;
	char now = read();
    while(now==' '||now=='\n')
        now=read();
	while (now != ' '&&now != '\n') {
		sum = sum * 10 + now - '0';
		now = read();
	}
	return sum;
}
///


int n,m;
int arr[100005];
map<int,int> tree[100005];
void update(int idx,int val){
    if(val==1)
        return;
    ++idx;
    while(idx<n+5){
        int t=idx&(-idx);
        if(t>2)
            tree[idx][val]++;
        idx+=t;
    }
}
int query(int idx,int val){
    if(val==1)
        return idx+1;
    ++idx;
    int ret=0;
    while(idx){
        int t=idx&(-idx);
        if(t<=2){
            for(int i=0;i<t;++i)
                if(arr[idx-1-i]%val==0)
                    ++ret;
        }
        else if(tree[idx].count(val)!=0)
            ret+=tree[idx][val];
        idx-=t;
    }
    return ret;
}
vector<int> p;
typedef long long ll;
vector<int> calc(int x){
    vector<pair<int,int> > pd;
    for(int i=0;i<p.size()&&(ll)p[i]*p[i]<=x;i++){
        int cnt=0;
        while(x%p[i]==0){
            cnt++;
            x/=p[i];
        }
        if(cnt>0)
            pd.push_back({p[i],cnt});
    }
    if(x!=1)
        pd.push_back({x,1});
    vector<int> ret;
    ret.push_back(1);
    for(int i=0;i<pd.size();i++){
        int r=pd[i].first;
        int sz=ret.size();
        for(int j=0;j<pd[i].second;j++){
            for(int k=0;k<sz;k++){
                ret.push_back(ret[k]*r);
            }
            r*=pd[i].first;
        }
    }
    return ret;
}
bool prime[1000005];
int main(){
    for(int i=2;i<1000005;i++){
        if(!prime[i]){
            p.push_back(i);
            for(int j=i+i;j<1000005;j+=i)
                prime[j]=true;
        }
    }
    setbuf(stdout,NULL);
    int testcase;
    //scanf("%d",&testcase);
    testcase=readInt();
    for(int tc=1;tc<=testcase;tc++){
        //scanf("%d%d",&n,&m);
        n=readInt();
        m=readInt();
        for(int i=0;i<n+5;i++)
            tree[i].clear();
        for(int i=0;i<n;i++){
            //scanf("%d",&arr[i]);
            arr[i]=readInt();
            //if(n<=1000){
            vector<int> div=calc(arr[i]);
            for(int j=0;j<div.size();j++){
                update(i,div[j]);
            }
            //}
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int b,l,r;
            //scanf("%d%d%d",&b,&l,&r);
            b=readInt();
            l=readInt();
            r=readInt();
            //if(n<=1000){
            vector<int> div=calc(b);
            for(int j=0;j<div.size();j++){
                if(query(r-1,div[j])==query(l-2,div[j]))
                    ans++;
            }
            //}
        }
        printf("Case #%d\n%d\n",tc,ans);
    }
    return 0;
}
