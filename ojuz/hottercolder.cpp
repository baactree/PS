#include "grader.h"
 
int HC(int N){
    int le,ri;
    int st,fi;
    st=1;
    fi=N;
    le=1;
    ri=N;
    
    //int pre=-1000;
 
    int pre=(le*2+ri)/3;
    Guess(pre);
 
    while(true){
        if(le==ri)
            return le;
        int mid=(le+ri)/2;
        int x=2*mid-pre;
        if(x==pre)
            x++;
        else if((x+pre)&1){
            if(x>pre){
                if(x<N)
                    x++;
                else if(x>pre+1&&x>1)
                    x--;
            }
            else{
                if(x>1)
                    x--;
                else if(x+1<pre&&x<N)
                    x++;
            }
        }
        if(x>=st&&x<=fi){
            int k=Guess(x);
            if(k==0)
                return (x+pre)/2;
            else if(k>0){
                if(x<pre){
                    ri=(x+pre)/2-((x+pre)%2==0);
                    pre=x;
                }
                else{
                    le=(x+pre)/2+1;
                    pre=x;
                }
            }
            else{
                if(x<pre){
                    le=(x+pre)/2+1;
                    pre=x;
                }
                else{
                    ri=(x+pre)/2-((x+pre)%2==0);
                    pre=x;
                }
            }
        }
        else{
            if(x<st){
                x=1;
            }
            else{
                x=N;
            }  
            if((x+pre)&1){
                if(x>pre){
                    if(x<N)
                        x++;
                    else if(x>pre+1&&x>1)
                        x--;
                }
                else{
                    if(x>1)
                        x--;
                    else if(x+1<pre&&x<N)
                        x++;
                }
            }
            int k=Guess(x);
            if(k==0)
                return (x+pre)/2;
            else if(k>0){
                if(x<pre){
                    ri=(x+pre)/2-((x+pre)%2==0);
                    pre=x;
                }
                else{
                    le=(x+pre)/2+1;
                    pre=x;
                }
            }
            else{
                if(x<pre){
                    le=(x+pre)/2+1;
                    pre=x;
                }
                else{
                    ri=(x+pre)/2-((x+pre)%2==0);
                    pre=x;
                }
            }
            //x=(le*2+ri)/3;
            //x=le;
            //Guess(x);
            //pre=x;
        }
    }
    return 0;
}