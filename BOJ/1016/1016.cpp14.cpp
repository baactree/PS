#include<stdio.h>
#include<vector>
 
using namespace std;
 
bool check[5000001]; // min + i가 제곱수인지 아닌지
 
int main()
{
    vector<long long int> zegop;
     
    long long int min, max;
    scanf("%lld %lld", &min, &max);
    for (long long int i = 2;; i++)
    {
        if (i*i > max) break;
        zegop.push_back(i*i);
    }
    long long int answer = 0;
    int size = zegop.size();
    for (int i = 0; i < size; i++)
    {
        for (long long int j = (min / zegop[i])*zegop[i]  ;j<=max; j += zegop[i])
        {
            if (j - min < 0) continue;
            if (check[j - min] == 0)
            {
                check[j - min] = 1;
                answer++;
            }
        }
    }
    printf("%lld\n",max-min-answer+1);
    return 0;
}