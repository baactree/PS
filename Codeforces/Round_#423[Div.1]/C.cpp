#include <bits/stdc++.h>
using namespace std;
string str;
int q;
int tree[11][4][10][100005];
char trans[300];
void update(int x,int y,int z,int idx, int val){
    while(idx<100005){
        tree[x][y][z][idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int x,int y,int z,int idx){
    int ret=0;
    while(idx){
        ret+=tree[x][y][z][idx];
        idx-=idx&(-idx);
    }
    return ret;
}
int main(){
    trans['A']=0;
    trans['T']=1;
    trans['G']=2;
    trans['C']=3;
    cin>>str>>q;
    for(int i=0;i<str.size();i++){
        int now=trans[str[i]];
        for(int j=1;j<=10;j++){
            int idx=(i+1)%j;
            update(j,now,idx,i+1,1);
        }
    }
    while(q--){
        int a;
        scanf("%d",&a);
        if(a==2){
            int b,c;
            scanf("%d%d",&b,&c);
            string d;
            cin>>d;
            int ans=0;
            for(int i=0;i<d.size();i++){
                int now=trans[d[i]];
                int idx=(b+i)%d.size();
                ans+=query(d.size(),now,idx,c)-query(d.size(),now,idx,b-1);
            }
            printf("%d\n",ans);
        }
        else{
            int b;
            scanf("%d",&b);
            string c;
            cin>>c;
            char k=str[b-1];
            if(k==c[0])
                continue;
            for(int j=1;j<=10;j++){
                int now=trans[k];
                int idx=b%j;
                update(j,now,idx,b,-1);
            }
            k=str[b-1]=c[0];
            for(int j=1;j<=10;j++){
                int now=trans[k];
                int idx=b%j;
                update(j,now,idx,b,1);
            }
        }
    }
    return 0;
}