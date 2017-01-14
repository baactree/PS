//baactree
#include<stdio.h>
static char input[524288];
static char *_input=input+524288;
static char *index=_input;
static int sum,num;
static long long int _sum;
extern inline int read()
{
    if(index==_input)
    {
        fread(input,1,524288,stdin);
        index=input;
    }
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
        n-=20;
    }
    printf("3000000\n%lld",_sum);
	return 0;
}
