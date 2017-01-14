//#include "bits/stdc++.h"
#include <cstdio>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
//여기에 저장함
char buf[1 << 18];
int number[5000001];
 
//idx 현재 인덱스, nidx 총 몇개 입력 받았는지
int idx, nidx;
//stdin 구간만큼 입력받고 buf배열 저장 -> 리턴은 한 글자만 리턴
static inline char read() {
    if (idx == nidx) {
        nidx = fread(buf, 1, 1 << 18, stdin);
        idx = 0;
    }
    return buf[idx++];
}
static inline int readInt() {
    int sum = 0;
    char now = read();
    bool flag = false;
    while (now == ' ' || now == '\n')
        now = read();
    if (now == '-') {
        flag = true;
        now = read();
    }
    while (now != ' ' && now != '\n') {
        sum *= 10;
        sum += now - '0';
        now = read();
    }
    return flag? -sum: sum;
}
 
int main()
{
    int n = 0;
    n = readInt();
    int k = 0;
    k = readInt();
 
     
    for(int i=0;i<n;i++)
        number[i]=readInt();
 
    nth_element(number, number + k - 1, number + n);
    printf("%d\n", number[k-1]);
 
    return 0;
}