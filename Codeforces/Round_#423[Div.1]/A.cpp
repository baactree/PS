#include <bits/stdc++.h>
using namespace std;
struct Node{
    int le,ri;
    int idx;
    Node(){}
    Node(int le,int ri,int idx):le(le),ri(ri),dx(idx){}
    bool operator < (const Node &rhs)const{
        return le<rhs.le;
    }
};
int n;
vector<Node> vec;
string arr[100005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            x--;
            vec.push_back(Node(x,x+arr[i].size()-1,i));
        }
    }
    sort(vec.begin(),vec.end());
    int fi=-1;
    string ans="";
    for(int i=0;i<vec.size();i++){
        while(fi+1<vec[i].le){
            ans+="a";
            fi++;
        }
        while(fi<vec[i].ri){
            int p=vec[i].ri-fi;
            int idx=vec[i].idx;
            ans+=arr[idx][arr[idx].size()-p];
            fi++;
        }
    }
    cout<<ans<<endl;
    return 0;
}