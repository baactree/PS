#include <bits/stdc++.h>
using namespace std;
template <class T>
class Sgtree{
public:
    vector<pair<T,T> > tree;
    int n;
    Sgtree(const vector<T> &arr){
        n=arr.size();
        tree=vector<pair<T,T> >(n*4,{0,0});
        init(arr,0,n-1,1);
    }
    void init(const vector<T> &arr,int nodele,int noderi,int node){
        if(nodele==noderi){
            tree[node]={arr[nodele],0};
            return;
        }
        int mid=(nodele+noderi)/2;
        init(arr,nodele,mid,node*2);
        init(arr,mid+1,noderi,node*2+1);
        tree[node].first=tree[node*2].first^tree[node*2+1].first;
    }
    T query(int le,int ri,int nodele,int noderi,int node){
        if(tree[node].second){
            if(nodele!=noderi){
                tree[node*2].second^=tree[node].second;
                tree[node*2+1].second^=tree[node].second;
            }
            if((noderi-nodele)%2==0)
                tree[node].first^=tree[node].second;
            tree[node].second=0;
        }
        if(ri<nodele||noderi<le)
            return 0;
        if(le<=nodele&&noderi<=ri)
            return tree[node].first;
        int mid=(nodele+noderi)/2;
        return query(le,ri,nodele,mid,node*2)^query(le,ri,mid+1,noderi,node*2+1);
    }
    T query(int le,int ri){
        return query(le,ri,0,n-1,1);
    }
    void update(int le,int ri,T val,int nodele,int noderi,int node){
        if(tree[node].second){
            if(nodele!=noderi){
                tree[node*2].second^=tree[node].second;
                tree[node*2+1].second^=tree[node].second;
            }
            if((noderi-nodele)%2==0)
                tree[node].first^=tree[node].second;
            tree[node].second=0;
        }
        if(ri<nodele||noderi<le)
            return;
        if(le<=nodele&&noderi<=ri){
            if((noderi-nodele)%2==0)
                tree[node].first^=val;
            if(nodele!=noderi){
                tree[node*2].second^=val;
                tree[node*2+1].second^=val;
            }
            return;
        }
        int mid=(nodele+noderi)/2;
        update(le,ri,val,nodele,mid,node*2);
        update(le,ri,val,mid+1,noderi,node*2+1);
        tree[node].first=tree[node*2].first^tree[node*2+1].first;
    }
    void update(int le,int ri,T val){
        update(le,ri,val,0,n-1,1);
    }
};
int n,m;
vector<int> arr;
int main(){
    scanf("%d",&n);
    arr.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    Sgtree<int> tree(arr);
    scanf("%d",&m);
    while(m--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a>b)
                swap(a,b);
            tree.update(a,b,c);
        }
        else{
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)
                swap(a,b);
            printf("%d\n",tree.query(a,b));
        }
    }
    return 0;
}