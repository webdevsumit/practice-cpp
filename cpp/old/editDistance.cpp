#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int minOf(int x, int y, int z){
    return min(x, min(y, z));
}

int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(2, vector<int>(n+1, 0));
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0){
                dp[i%2][j] = j;
            }else if(j==0){
                dp[i%2][j] = i;
            }else if(word1[i-1]==word2[j-1]){
                dp[i%2][j] = dp[(i-1)%2][j-1];
            }else{
                dp[i%2][j] = 1 + minOf(dp[i%2][j-1],dp[(i-1)%2][j],dp[(i-1)%2][j-1]);
            }
        }    
    }
    return dp[m%2][n];
}

int main(){

    for(int i=1; i<=7; ++i) cout<<i<<endl;

    return 0;
}