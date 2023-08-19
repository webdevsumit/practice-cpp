#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int count(int n){
    return (n*(n+1))/2;
}

 int candy(vector<int>& ratings) {
    if(ratings.size()<=1) return ratings.size();
    int ans = 0;
    int up = 0;
    int down = 0;
    int oldSlope = 0;
    for(int i=1; i<ratings.size(); i++){
        int newSlope;
        if(ratings[i]>ratings[i-1]) newSlope = 1;
        else if(ratings[i]==ratings[i-1]) newSlope = 0;
        else newSlope = -1;

        if((oldSlope>0 && newSlope==0) || (oldSlope<0 && newSlope>=0)){
            ans += count(up)+count(down)+max(up, down);
            up = 0;
            down = 0;
        }
        if(newSlope>0){
            up++;
        }else if(newSlope<0){
            down++;
        }else{
            ans++;
        }
        oldSlope = newSlope;
    }
    ans += count(up)+count(down)+max(up, down) + 1;
    return ans;
}

int main(){

    vector<int> h;
    h.push_back(1);
    h.push_back(2);
    h.push_back(3);
    h.push_back(2);
    h.push_back(2);
    h.push_back(1);
    // h.push_back(3);
    // h.push_back(1);
    // h.push_back(2);
    // h.push_back(1);
    // h.push_back(2);
    // h.push_back(1);

    cout<<candy(h)<<endl;

    return 0;
}