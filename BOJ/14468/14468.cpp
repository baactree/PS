#include <bits/stdc++.h>
using namespace std;
vector<int> arr[26];
string str;
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++)
		arr[str[i]-'A'].push_back(i);
	for(int i=0;i<26;i++)
		sort(arr[i].begin(),arr[i].end());
	int ans=0;
	for(int i=0;i<26;i++){
		int le=arr[i][0];
		int ri=arr[i][1];
		for(int j=i+1;j<26;j++){
			int a=arr[j][0];
			int b=arr[j][1];
			if((le<=a&&a<=ri)&&!(le<=b&&b<=ri))
				ans++;
			if(!(le<=a&&a<=ri)&&(le<=b&&b<=ri))
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}