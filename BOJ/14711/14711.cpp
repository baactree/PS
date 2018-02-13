#include <bits/stdc++.h>
using namespace std;
int n;
char mat[1005][1005];
bool check[1005][1005];
bool safe(int x,int y){
	return min(x,y)>=0&&max(x,y)<n;
}
void paint(int x,int y){
	if(!safe(x,y))
		return;
	mat[x][y]=((mat[x][y]=='#')?'.':'#');
}
int main(){
	string str;
	cin>>n>>str;
	for(int i=0;i<n;i++)
		if(str[i]=='#'){
			paint(0,i-1);
			paint(0,i+1);
			paint(1,i);
			check[0][i]=true;
		}
	for(int i=1;i<n;i++)
		for(int j=0;j<n;j++){
			if(mat[i-1][j]=='#'){
				check[i][j]=true;
				paint(i,j-1);
				paint(i,j+1);
				paint(i+1,j);
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(check[i][j])
				mat[i][j]='#';
			else
				mat[i][j]='.';
	for(int i=0;i<n;i++)
		printf("%s\n",mat[i]);
	return 0;
}