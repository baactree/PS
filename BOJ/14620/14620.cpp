#include <bits/stdc++.h>
using namespace std;
int n;
int mat[10][10];
int cnt[10][10];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    int ans=0x3f3f3f3f;
    for(int x1=1;x1<n-1;x1++)
        for(int y1=1;y1<n-1;y1++){
            int now=0;
            cnt[x1][y1]++;
            cnt[x1-1][y1]++;
            cnt[x1+1][y1]++;
            cnt[x1][y1-1]++;
            cnt[x1][y1+1]++;
            now+=mat[x1][y1];
            now+=mat[x1-1][y1];
            now+=mat[x1+1][y1];
            now+=mat[x1][y1-1];
            now+=mat[x1][y1+1];
            for(int x2=1;x2<n-1;x2++)
                for(int y2=1;y2<n-1;y2++){
                    bool flag=false;
                    if(cnt[x2][y2])
                        flag=true;
                    cnt[x2][y2]++;
                    if(cnt[x2-1][y2])
                        flag=true;
                    cnt[x2-1][y2]++;
                    if(cnt[x2+1][y2])
                        flag=true;
                    cnt[x2+1][y2]++;
                    if(cnt[x2][y2-1])
                        flag=true;
                    cnt[x2][y2-1]++;
                    if(cnt[x2][y2+1])
                        flag=true;
                    cnt[x2][y2+1]++;
                    now+=mat[x2][y2];
                    now+=mat[x2-1][y2];
                    now+=mat[x2+1][y2];
                    now+=mat[x2][y2-1];
                    now+=mat[x2][y2+1];
                    if(!flag){ 
                        for(int x3=1;x3<n-1;x3++)
                            for(int y3=1;y3<n-1;y3++){
                                bool flag2=false;
                                if(cnt[x3][y3])
                                    flag2=true;
                                cnt[x3][y3]++;
                                if(cnt[x3-1][y3])
                                    flag2=true;
                                cnt[x3-1][y3]++;
                                if(cnt[x3+1][y3])
                                    flag2=true;
                                cnt[x3+1][y3]++;
                                if(cnt[x3][y3-1])
                                    flag2=true;
                                cnt[x3][y3-1]++;
                                if(cnt[x3][y3+1])
                                    flag2=true;
                                cnt[x3][y3+1]++;
                                now+=mat[x3][y3];
                                now+=mat[x3-1][y3];
                                now+=mat[x3+1][y3];
                                now+=mat[x3][y3-1];
                                now+=mat[x3][y3+1];
                                if(!flag2){
                                    ans=min(ans,now);
                                }   
                                cnt[x3][y3]--;
                                cnt[x3-1][y3]--;
                                cnt[x3+1][y3]--;
                                cnt[x3][y3-1]--;
                                cnt[x3][y3+1]--;
                                now-=mat[x3][y3];
                                now-=mat[x3-1][y3];
                                now-=mat[x3+1][y3];
                                now-=mat[x3][y3-1];
                                now-=mat[x3][y3+1];
                            }
                    }
                    cnt[x2][y2]--;
                    cnt[x2-1][y2]--;
                    cnt[x2+1][y2]--;
                    cnt[x2][y2-1]--;
                    cnt[x2][y2+1]--;
                    now-=mat[x2][y2];
                    now-=mat[x2-1][y2];
                    now-=mat[x2+1][y2];
                    now-=mat[x2][y2-1];
                    now-=mat[x2][y2+1];
                }
            cnt[x1][y1]--;
            cnt[x1-1][y1]--;
            cnt[x1+1][y1]--;
            cnt[x1][y1-1]--;
            cnt[x1][y1+1]--;
        }
    printf("%d\n",ans);
    return 0;
}