#include <cstdio>
int n; // 사탕의 수
int m; // 소지금액
int c[5001]; // c[i] = i번 사탕의 칼로리
int p[5001]; // p[i] = i번 사탕의 가격
int d[10001]; // d[i] = i원으로 구입할 수 있는 사탕의 최대 칼로리
int max2(int a, int b){ return a>b?a:b; }
int main(void){
 
    int m1,m2;
    // 입력
    while(scanf("%d %d.%d",&n,&m1,&m2)==3){
        m=m1*100+m2;
        if(n==0 && m==0) break;
        for(int i=1; i<=n; i++){
            int p1,p2;
            scanf("%d %d.%d",&c[i],&p1,&p2);
            p[i]=p1*100+p2;
        }
 
        // DP 테이블 초기화
        for(int i=0; i<=m; i++) d[i]=0;
 
        for(int i=1; i<=n; i++) // i번째 iteration을 마쳤을 때, m보다 작은 모든 소지금의 경우에 대해 1~i번 사탕으로 얻을 수 있는 최대 칼로리를 계산하게 됨
            for(int j=p[i]; j<=m; j++) // i번 사탕을 사기 위해서는 적어도 p[i] 이상의 소지금이 필요함
                d[j]=max2(d[j],d[j-p[i]]+c[i]);
        // 답 계산
        int ans=0;
        for(int i=0; i<=m; i++) ans=max2(ans,d[i]);
        printf("%d\n",ans);
    }
    return 0;
}
