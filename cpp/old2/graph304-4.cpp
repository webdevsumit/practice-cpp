#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<set>
#include<queue>

using namespace std;

#define pb push_back
#define ve vector

const int N = 1e5 + 10;
int q[N * 2];
int vis[N], sta[N];
ve<int> g[N];
int res = -1;

void dfs(int root, int d) {
    vis[root] = 1;
    sta[root] = d;
    for(int& c : g[root]) {
        if(vis[c]) if(sta[c]) res = max(res, d - sta[c] + 1);
        else dfs(c, d + 1);
    }
    sta[root] = 0;
}

class Solution {
public:
    int longestCycle(vector<int>& e) {
        int n = e.size();
        res = -1;
        for(int i = 0; i < n; i++) {
            g[i].clear();
            if(e[i] == -1) continue;
            g[i].pb(e[i]);
            vis[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, 1);
        }
        return res;
    }
};