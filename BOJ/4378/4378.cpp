// =====================================================================================
// 
//       Filename:  4378.cpp
//        Created:  2017년 06월 12일 01시 44분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
	while(getline(cin, str)){
		for(int i=0;i<str.size();i++){
			if(str[i]=='=')
				str[i]='-';
			else if(str[i]=='-')
				str[i]='0';
			else if(str[i]>='2'&&str[i]<='9')
				str[i]--;
			else if(str[i]=='0')
				str[i]='9';
			else if(str[i]=='1')
				str[i]='`';
			else if(str[i]=='\\')
				str[i]=']';
			else if(str[i]==']')
				str[i]='[';
			else if(str[i]=='[')
				str[i]='P';
			else if(str[i]=='P')
				str[i]='O';
			else if(str[i]=='O')
				str[i]='I';
			else if(str[i]=='I')
				str[i]='U';
			else if(str[i]=='U')
				str[i]='Y';
			else if(str[i]=='Y')
				str[i]='T';
			else if(str[i]=='T')
				str[i]='R';
			else if(str[i]=='R')
				str[i]='E';
			else if(str[i]=='E')
				str[i]='W';
			else if(str[i]=='W')
				str[i]='Q';
			else if(str[i]=='\'')
				str[i]=';';
			else if(str[i]==';')
				str[i]='L';
			else if(str[i]=='L')
				str[i]='K';
			else if(str[i]=='K')
				str[i]='J';
			else if(str[i]=='J')
				str[i]='H';
			else if(str[i]=='H')
				str[i]='G';
			else if(str[i]=='G')
				str[i]='F';
			else if(str[i]=='F')
				str[i]='D';
			else if(str[i]=='D')
				str[i]='S';
			else if(str[i]=='S')
				str[i]='A';
			else if(str[i]=='/')
				str[i]='.';
			else if(str[i]=='.')
				str[i]=',';
			else if(str[i]==',')
				str[i]='M';
			else if(str[i]=='M')
				str[i]='N';
			else if(str[i]=='N')
				str[i]='B';
			else if(str[i]=='B')
				str[i]='V';
			else if(str[i]=='V')
				str[i]='C';
			else if(str[i]=='C')
				str[i]='X';
			else if(str[i]=='X')
				str[i]='Z';
		}
		cout<<str<<'\n';
	}
	return 0;
}

