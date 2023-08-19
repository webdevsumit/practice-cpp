#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int ptr1 = 0;
    while(ptr1<wordDict.size()){
        
        string w = wordDict[ptr1];
        vector<string> filteredS;
        int ptrS = 0;
        
        while(ptrS<s.length()){
            if(s.substr(ptrS, w.length())==w){
                string temp = s;
                temp.erase(ptrS, w.length());
            }else{
                ptrS++;
            }
            cout<<"s2 : "<<s<<endl;
        }
        ptr1++;
    }
    if(s.length()==0) return true;
    return false;
}

int countPrimes(int n) {
    vector<bool> dp(n, true);
    dp[0] = false;
    dp[1] = false;
    if(n<=2) return 0;
    int ans = 0;
    for(int i=2; i<n; i++){
        cout<<"i : "<<i<<endl;
        if(dp[i]){
            ans++;
            cout<<"i inside : "<<i<<endl;
            for(int j=2*i; j<n; j+=i){
                cout<<"j false : "<<j<<endl;
                dp[j]=false;
            }
        }
    }
    return ans;
}

int main(){

    string s = "cars";
    vector<string> wordDict = {"car", "ca", "rs"};
    // cout<<wordBreak(s, wordDict)<<endl;

    cout<<countPrimes(10)<<endl;


    return 0;
}