#include<iostream>

using namespace std;

int minFlips(int a, int b, int c) {
    int ans = 0;
    while(c!=0){
        cout<<"a : "<<(!(a&1 == 1))<<" b : "<<(b&1 == 1)<<" c : "<<(c&1 == 1)<<endl;
        cout<<ans<<endl;
        if((c&1 == 1) && !(a&1 == 1) && !(b&1 == 1)) ans++;
        if(!(c&1 == 1) && (a&1 == 1)) ans++;
        if(!(c&1 == 1) && (b&1 == 1)) ans++;
        a = a>>1;
        b = b>>1;
        c = c>>1;
    }
    while(a!=0){
        if(a&1==1) ans++;
        a = a>>1;
    }
    while(b!=0){
        if(b&1==1) ans++;
        b = b>>1;
    }
    return ans;
}

int main(){
    cout<<minFlips(10,9,1)<<endl;
    return 0;
}