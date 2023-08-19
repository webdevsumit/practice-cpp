#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;

#define ll long long int
#define pb push_back
#define bg begin()
#define rbg rbegin()
#define ed end()
#define sz size()
#define ff first
#define ss second
#define fon for(i=0;i<n;i++)

//----------------------------------------------------------------

class Solution {
public:
    vector<int> bfs(int node , vector<int> &l){
        int n = l.size();
        vector<int> dis(n , INT32_MAX);
        queue<int> q; q.push(node); dis[node] = 0;
        while(!q.empty()){
            int nn = q.front(); q.pop();
            if(l[nn] == -1) continue;
            if(dis[l[nn]] > dis[nn] + 1){
                dis[l[nn]] = dis[nn] + 1;
                q.push(l[nn]);
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& l, int node1, int node2) {
        vector<int> dis1 = bfs(node1 , l);
        vector<int> dis2 = bfs(node2 , l);
        int ans = -1 , maxi = INT32_MAX;
        for(int i=0;i<l.size();i++){
            if(dis1[i] != INT32_MAX && dis2[i] != INT32_MAX){
                if(maxi > max(dis1[i] , dis2[i])){
                    maxi = max(dis1[i] , dis2[i]);
                    ans = i;
                }
            }
        }
        return ans; 
    }
};