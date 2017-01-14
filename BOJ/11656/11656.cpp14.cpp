#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include <deque>

using namespace std;
char input[1001];
vector<string> store;
int main()
{
//	freopen("sample.txt","r",stdin);

	cin>>input;
	int len=strlen(input);
	string temp;
	for(int i=0;i<len;i++)
	{
		temp.assign(input,i,len-i);
		store.push_back(temp);
	}
	sort(store.begin(),store.end());
	
	int size=store.size();
	for(int i=0;i<size;i++)
		cout<<store[i]<<"\n";

    return 0;
}
