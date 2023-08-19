#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include <cstring>
// #include "Hero.cpp"

using namespace std;

    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string s = "11";
        string newS;
        int count;
        char nn;
            
        for(int j=3; j<=n; j++){
            newS = "";
            count=1;
            for(int i=1; i<s.length();i++){

                if(s[i]==s[i-1]) count++;
                else {
                    newS += to_string(count);
                    newS.push_back(s[i-1]);
                    count = 1;
                }

            }
            newS += to_string(count);
            newS.push_back(s[s.length()-1]);
            s = newS;
        }
        return s;
    }

int main(){
    string s = countAndSay(5);
    cout<< "ANS : " << s  <<endl;
    return 0;
}