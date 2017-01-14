#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> pq;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        pq.push(-temp);
    }
    int ret=0;
    while(pq.size()!=1){
        int a=-pq.top();
        pq.pop();
        int b=-pq.top();
        pq.pop();
        ret+=a+b;
        pq.push(-(a+b));
    }
    printf("%d\n",ret);
    return 0;
}
