#include <bits/stdc++.h>
using namespace std;
int n;
int mat[105][105];
int arr[105];
vector<int> xidx;
vector<int> yidx;
void paint(int x,int y){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            mat[x+i][y+j]=1;
}
int calc(){
    stack<int> st;
    int ret=0;
    for(int i=0;i<101;i++){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            int temp=st.top();
            st.pop();
            int w=-1;
            if(st.empty())
                w=i;
            else
                w=i-st.top()-1;
            ret=max(ret,arr[temp]*w);
        }
        st.push(i);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        paint(x,y);
    }
    int ans=0;
    for(int i=0;i<100;i++){
        if(i==0){
            for(int j=0;j<100;j++){
                arr[j]=mat[i][j];
            }
        }
        else{
            for(int j=0;j<100;j++){
                if(mat[i][j]==0)
                    arr[j]=0;
                else
                    arr[j]++;
            }
        }
        ans=max(ans,calc());
    }
    printf("%d\n",ans);
    return 0;
}