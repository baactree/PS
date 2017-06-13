#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    if(n%2==0){
        printf("I LOVE CBNU\n");
        return 0;
    }
    int le,ri;
    le=ri=n/2;
    for(int i=0;i<n;i++)
        printf("*");
    printf("\n");
    while(true){
       for(int i=0;i<ri;i++){
            if(i==le)
                    printf("*");
            else
                printf(" ");
        }
        printf("*\n");
        ri++;
        le--;
        if(le==-1)
            break;
    }
    return 0;
}