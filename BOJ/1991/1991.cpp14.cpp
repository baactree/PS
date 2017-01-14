#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <deque>
#include <utility>
using namespace std;

int N;
struct Node
{
	int left;
	int right;
};

Node Map[26];

void search_pre(int v)
{
	printf("%c",v+65);
	if(Map[v].left!=-1)
		search_pre(Map[v].left);
	if(Map[v].right!=-1)
		search_pre(Map[v].right);
}

void search_mid(int v)
{

	if(Map[v].left!=-1)
		search_mid(Map[v].left);
		printf("%c",v+65);
	if(Map[v].right!=-1)
		search_mid(Map[v].right);
}

void search_last(int v)
{

	if(Map[v].left!=-1)
		search_last(Map[v].left);
	if(Map[v].right!=-1)
		search_last(Map[v].right);
	
		printf("%c",v+65);
}

int main()
{

//	freopen("sample.txt","r",stdin);
	cin>>N;
	char input[3][2];
	for(int i=0;i<N;i++)
	{
		scanf("%s%s%s",input[0],input[1],input[2]);
		if(input[1][0]!='.')
	
			Map[input[0][0]-65].left=input[1][0]-65;		
		else
			Map[input[0][0]-65].left=-1;
		if(input[2][0]!='.')
			Map[input[0][0]-65].right=input[2][0]-65;
		else
			Map[input[0][0]-65].right=-1;
		
	
	}
	search_pre(0);
	printf("\n");
	search_mid(0);
	printf("\n");
	search_last(0);
//	while(true);

    return 0;
}

	
