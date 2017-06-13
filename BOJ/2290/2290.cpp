#include <bits/stdc++.h>
using namespace std;
int s;
string str;
char mat[50][50*20];
void p(int x,int y,int k){
    if(k==0){
        for(int i=0;i<s;i++)
            mat[x][y+1+i]='-';
    }
    else if(k==1){
        for(int i=0;i<s;i++)
            mat[x+1+i][y+s+1]='|';
    }
    else if(k==2){
        for(int i=0;i<s;i++)
            mat[x+s+1][y+1+i]='-';
    }
    else if(k==3){
        for(int i=0;i<s;i++)
            mat[x+1+i][y]='|';
    }
    else if(k==4){
        for(int i=0;i<s;i++)
            mat[x+2+s+i][y+s+1]='|';
    }
    else if(k==5){
        for(int i=0;i<s;i++)
            mat[x+2*s+2][y+1+i]='-';
    }
    else if(k==6){
        for(int i=0;i<s;i++)
            mat[x+2+s+i][y]='|';
    }
}
void paint(int x,int y,int k){
    if(k==1){
        p(x,y,1);
        p(x,y,4);
    }
    else if(k==2){
        p(x,y,0);
        p(x,y,1);
        p(x,y,2);
        p(x,y,5);
        p(x,y,6);
    }
    else if(k==3){
        p(x,y,0);
        p(x,y,1);
        p(x,y,2);
        p(x,y,4);
        p(x,y,5);
    }
    else if(k==4){
        p(x,y,1);
        p(x,y,2);
        p(x,y,3);
        p(x,y,4);
    }
    else if(k==5){
        p(x,y,0);
        p(x,y,2);
        p(x,y,3);
        p(x,y,4);
        p(x,y,5);
    }
    else if(k==6){
        p(x,y,0);
        p(x,y,2);
        p(x,y,3);
        p(x,y,4);
        p(x,y,5);
        p(x,y,6);
    }
    else if(k==7){
        p(x,y,0);
        p(x,y,1);
        p(x,y,4);
    }
    else if(k==8){
        p(x,y,0);
        p(x,y,1);
        p(x,y,2);
        p(x,y,3);
        p(x,y,4);
        p(x,y,5);
        p(x,y,6);
    }
    else if(k==9){
        p(x,y,0);
        p(x,y,1);
        p(x,y,2);
        p(x,y,3);
        p(x,y,4);
        p(x,y,5);
    }
    else if(k==0){
        p(x,y,0);
        p(x,y,1);
        p(x,y,3);
        p(x,y,4);
        p(x,y,5);
        p(x,y,6);
    }
}
int main(){
    cin>>s>>str;
    for(int i=0;i<2*s+3;i++)
        for(int j=0;j<(s+3)*str.size();j++)
            mat[i][j]=' ';
    for(int i=0,k=0;k<str.size();i+=s+3,k++)
        paint(0,i,str[k]-'0');
    for(int i=0;i<2*s+3;i++)
        printf("%s\n",mat[i]);
    return 0;
}