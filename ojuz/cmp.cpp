#include "cmp.h"
//4+3+3=10
void remember(int n) {
    int ri=10240;
    bit_set(ri-n);
    ri-=4096;
    bit_set(ri-n/64);
    ri-=64;
    int a,b;
    a=n/64;
    bit_set(ri-a/8);
    ri-=8;
    b=n%64;
    bit_set(ri-b/8);
}
 
int compare(int b) {
    //일치하는 경우 제외
    int ri=10240;
    if(bit_get(ri-b))
        return 0;
    ri-=4096;
    int k=b/64;
    //일치함 따라서 뒤 6비트 봐야함
    if(bit_get(ri-k)){
        ri-=64;
        ri-=8;
        int p=b%64;
        //일치함 뒤 3비트로 확인해야함 3번 구간
        if(bit_get(ri-p/8)){
            int r=0;
            int t=7<<r;
            int q=(b&t)>>r;
            int w=b&(~t);
            if(q<4){
                //0 1 2
                for(int i=0;i<q;i++){
                    int now=w+(i<<r);
                    if(bit_get(10240-now))
                        return 1;
                }
                return -1;
            }
            else{
                //5 6 7
                for(int i=q+1;i<8;i++){
                    int now=w+(i<<r);
                    if(bit_get(10240-now))
                        return -1;
                }
                return 1;
            }
        }
        //불일치함 앞 3비트로 확인해야함 2번 구간
        else{
            int r=3;
            int t=7<<r;
            int q=(b&t)>>r;
            int w=b&(~t);
            if(q<4){
                //0 1 2
                for(int i=0;i<q;i++){
                    int now=i;
                    if(bit_get(10240-4096-64-8-now))
                        return 1;
                }
                return -1;
            }
            else{
                //5 6 7
                for(int i=q+1;i<8;i++){
                    int now=i;
                    if(bit_get(10240-4096-64-8-now))
                        return -1;
                }
                return 1;
            }
        }
    }
    //불일치함 따라서 앞 6비트 봐야함
    else{
        ri-=64;
        int p=b/64;
        //일치함 뒤 3비트로 확인해야함 1번 구간
        if(bit_get(ri-p/8)){
            int r=0;
            int t=7<<r;
            int q=(p&t)>>r;
            int w=p&(~t);
            if(q<4){
                //0 1 2
                for(int i=0;i<q;i++){
                    int now=w+(i<<r);
                    if(bit_get(10240-4096-now))
                        return 1;
                }
                return -1;
            }
            else{
                //5 6 7
                for(int i=q+1;i<8;i++){
                    int now=w+(i<<r);
                    if(bit_get(10240-4096-now))
                        return -1;
                }
                return 1;
            }
        }
        //불일치함 앞 3비트로 확인해야함 0번 구간
        else{
            int r=9;
            int t=7<<r;
            int q=(b&t)>>r;
            int w=b&(~t);
            if(q<4){
                //0 1 2
                for(int i=0;i<q;i++){
                    int now=i;
                    if(bit_get(10240-4096-64-now))
                        return 1;
                }
                return -1;
            }
            else{
                //5 6 7
                for(int i=q+1;i<8;i++){
                    int now=i;
                    if(bit_get(10240-4096-64-now))
                        return -1;
                }
                return 1;
            }
        }
    }
}