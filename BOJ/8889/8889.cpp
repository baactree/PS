#include <bits/stdc++.h>
using namespace std;
struct Line{
    int x1,x2,y;
    bool mode;
    bool operator < (const Line &rhs)const{
        if(y==rhs.y)
            return x1<rhs.x1;
        return y<rhs.y;
    }
};
pair<int,int> tree[8000000];
int n;
vector<Line> line;
vector<int> xidx;
void update(int le,int ri,int val, int nodele,int noderi,int node){
    if(le>noderi||ri<nodele)
        return;
    if(le<=nodele&&noderi<=ri){
        tree[node].first+=val;
        tree[node].second=tree[node].first;
        if(nodele!=noderi)
            tree[node].second=max(tree[node*2].second,tree[node*2+1].second)+tree[node].first;
        return;
    }
    int mid=(nodele+noderi)/2;
    update(le,ri,val,nodele,mid,node*2);
    update(le,ri,val,mid+1,noderi,node*2+1);
    tree[node].second=max(tree[node*2].second,tree[node*2+1].second)+tree[node].first;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        memset(tree,0,sizeof(tree));
        xidx.clear();
        line.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int k;
            scanf("%d",&k);
            vector<pair<int,int> > vec;
            int min_x=0x3f3f3f3f;
            int max_x=-0x3f3f3f3f;
            int st=-1;
            for(int j=0;j<k;j++){
                int x,y;
                scanf("%d%d",&x,&y);
                xidx.push_back(x);
                vec.push_back({x,y});
                min_x=min(min_x,x);
                if(max_x<x){
                    max_x=x;
                    st=j;
                }    
            }
            if(vec[st].first==vec[(st+1)%k].first)
                st++;
            bool flag=false;
            for(int j=0;j<k;j+=2){
                if(vec[(st+j)%k].first==min_x)
                    flag=true;
                if(!flag){
                    int y=vec[(st+j)%k].second;
                    int x1=vec[(st+j)%k].first;
                    int x2=vec[(st+j+1)%k].first;
                    if(x1>x2)
                        swap(x1,x2);
                    line.push_back({x1,x2,y,flag});
                }
                else{
                    int y=vec[(st+j)%k].second;
                    int x1=vec[(st+j)%k].first;
                    int x2=vec[(st+j+1)%k].first;
                    if(x1>x2)
                        swap(x1,x2);
                    line.push_back({x1,x2,y,flag});
                }
            }
        }

        sort(xidx.begin(),xidx.end());
        xidx.erase(unique(xidx.begin(),xidx.end()),xidx.end());
        sort(line.begin(),line.end());
        int ans=0;
        for(int i=0;i<line.size();i++){
            int x1=lower_bound(xidx.begin(),xidx.end(),line[i].x1)-xidx.begin();
            int x2=lower_bound(xidx.begin(),xidx.end(),line[i].x2)-xidx.begin();
            bool mode=line[i].mode;
            update(x1,x2-1,mode?1:-1,0,xidx.size()-1,1);
            ans=max(ans,tree[1].second);
        } 
        printf("%d\n",ans); 
    }
    return 0;
}