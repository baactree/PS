#include <bits/stdc++.h>
using namespace std;
string mat[5];
char num[10][5][4]={
	{
		"***",
		"* *",
		"* *",
		"* *",
		"***"
	},
	{
		"  *",
		"  *",
		"  *",
		"  *",
		"  *"	
	},
	{
		"***",
		"  *",
		"***",
		"*  ",
		"***"
	},
	{
		"***",
		"  *",
		"***",
		"  *",
		"***"
	},
	{
		"* *",
		"* *",
		"***",
		"  *",
		"  *"
	},
	{
		"***",
		"*  ",
		"***",
		"  *",
		"***"
	},
	{
		"***",
		"*  ",
		"***",
		"* *",
		"***"
	},
	{
		"***",
		"  *",
		"  *",
		"  *",
		"  *"
	},
	{
		"***",
		"* *",
		"***",
		"* *",
		"***"
	},
	{
		"***",
		"* *",
		"***",
		"  *",
		"***"
	}
};
bool possi(int n,int x){
	for(int i=0;i<5;i++)
		for(int j=0;j<3;j++)
			if(num[n][i][j]!=mat[i][j+x])
				return false;
	return true;
}
int calc(int x){
	for(int i=0;i<10;i++)
		if(possi(i,x))
			return i;
	return -1;
}
int main(){
	for(int i=0;i<5;i++)
		getline(cin,mat[i]);
	int ans=0;
	for(int i=0;i<mat[0].size();i+=4){
		int now=calc(i);
		if(now==-1)
			return !printf("BOOM!!");
		ans=ans*10+now;
	}
	printf("%s\n",ans%6==0?"BEER!!":"BOOM!!");
	return 0;
}