#include <bits/stdc++.h>
using namespace std;
pair<string,int> card[5];
int d_color(){
    map<string,int> color;
    for(int i=0;i<5;i++)
        color[card[i].first]++;
    return color.size();
}
int d_num(){
    int cnt[10]={0,};
    for(int i=0;i<5;i++)
        cnt[card[i].second]++;
    return *(max_element(cnt,cnt+10));
}
bool straight(){
    vector<int> num;
    for(int i=0;i<5;i++)
        num.push_back(card[i].second);
    sort(num.begin(),num.end());
    return num[4]-num[0]==4;
}
int get_max_number(){
    vector<int> num;
    for(int i=0;i<5;i++)
        num.push_back(card[i].second);
    return *max_element(num.begin(),num.end());
}
int get_same_number(int t){
    int cnt[10]={0,};
    for(int i=0;i<5;i++)
        cnt[card[i].second]++;
    for(int i=0;i<10;i++)
        if(cnt[i]==t)
            return i;
    return 0;
}
bool d_case7(){
    int cnt[10]={0,};
    for(int i=0;i<5;i++)
        cnt[card[i].second]++;
    int two=0;
    for(int i=0;i<10;i++)
        if(cnt[i]==2)
            two++;
    return two==2;
}
int c_case7(){
    vector<int> temp;
    int cnt[10]={0,};
    for(int i=0;i<5;i++)
        cnt[card[i].second]++;
    for(int i=0;i<10;i++)
       if(cnt[i]==2)
          temp.push_back(i);
    sort(temp.begin(),temp.end());
    return temp[0]+temp[1]*10; 
}
int distribution(){
    int cnt[10]={0,};
    for(int i=0;i<5;i++)
        cnt[card[i].second]++;
    int d=0;
    for(int i=0;i<10;i++)
        if(cnt[i])
            d++;
    return d;    
}
int solve(){
    int color=d_color();
    int num=d_num();
    int ret=-1;
    if(color==1){
        //case 1
        if(straight()){
            int score=get_max_number();
            ret=max(ret,score+900);
        }
        //case 4
        int score=get_max_number();
        ret=max(ret,score+600);
    }
    if(num==4){
        //case 2
        int score=get_same_number(4);
        ret=max(ret,score+800);
    }
    if(num==3){
        //case 3
        if(distribution()==2){
            int score1=get_same_number(3);
            int score2=get_same_number(2);
            ret=max(ret,score1*10+score2+700);
        }
        //case 6
        int score=get_same_number(3);
        ret=max(ret,score+400);
    }
    //case 5
    if(straight()){
        int score=get_max_number();
        ret=max(ret,score+500);
    }
    if(num==2){
        //case 7
        if(d_case7()){
            int score=c_case7();
            ret=max(ret,score+300);
        }
        //case 8
        int score=get_same_number(2);
        ret=max(ret,score+200);
    }
    //case 9
    int score=get_max_number();
    ret=max(ret,score+100);
    return ret;
}
int main(){
    for(int i=0;i<5;i++)
        cin>>card[i].first>>card[i].second;
    printf("%d\n",solve());
    return 0;
}

