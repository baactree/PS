#include <stdio.h>
int main()
{


    int a;
    if(((long long int)&a/10)%2==0)
        printf("Yonsei\n");
    else
        printf("Korea\n");
    return 0;

}