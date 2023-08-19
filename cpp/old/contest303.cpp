#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>

using namespace std;


class Solution {
    
    int setBits(int n){
        int ans = 0;
        while(n){
            if(n&1){
                ans++;
            }
            n = n>>1;
        }
        return ans;
    }
public:
    typedef long long ll;
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> v;
        
        for(auto& i :s){
            int x = setBits(i);
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        
        ll ans = 0;
        for(auto i:v){
            auto it = lower_bound(v.begin(), v.end(), k-i);
            ans += v.end()-it;
        }
        return ans;
    }
};

char repeatedCharacter(string s) {
        
    map<char, int> mmap;

    for(int i=0; i<s.length(); i++){

        if(mmap[s[i]]){
            mmap[s[i]] += 1;

            if(mmap[s[i]]==2){
                return s[i];
            }

        }else{
            mmap[s[i]] = 1;
        }

    }
    return s[0];
}


int main(){

    string s = "abccbaacz";

    cout<<repeatedCharacter(s)<<endl;

    return 0;
}