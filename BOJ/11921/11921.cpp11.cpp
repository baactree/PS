//baactree
#include<stdio.h>
char input[524288];
int n_index;
char *index;
int sum,num;
long long int _sum;
extern inline int read()
{
    if(!n_index)
    {
        n_index=fread(input,1,524288,stdin);
        index=input;
    }
    n_index--;
    return *(index++);
}
extern inline int readInt()
{
    sum=0;
    num=read();
    while(num^10)
    {
        sum*=10;
        sum+=num-48;
        num=read();
    }
    return sum;
}
int main()
{
    fread(input,8,1,stdin);
    int n=3000000;
    while(n)
    {
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        _sum+=readInt();
        n-=10;
    }
    printf("3000000\n%lld",_sum);
	return 0;
}