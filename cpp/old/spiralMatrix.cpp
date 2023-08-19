#include<iostream>
#include<vector>

using namespace std;

// vector<int> spiralOrder(vector<vector<int>>& matrix) {
//     int count = matrix.size()*matrix[0].size();
//     int i = 0;
//     int j = 0;
//     int maxI = matrix.size()-1;
//     int maxJ = matrix[0].size()-1;
//     int level = 0;
//     int iPlus = 0;
//     int jPlus = 1;
    
//     vector<int> ans;
    
//     while(count--){
//         ans.push_back(matrix[i][j]);
//         i += iPlus;
//         j += jPlus;
//         if(i==level && j==maxJ-level && level!=maxJ-level ){
//             iPlus = 1;
//             jPlus = 0;
//         }else if(i==maxI-level && j==maxJ-level && level!=maxJ-level){
//             iPlus = 0;
//             jPlus = -1;
//         }else if(i==maxI-level && j==level && level!=maxI-level){
//             iPlus = -1;
//             jPlus = 0;
//         }else if(i==level && j==level && level!=maxJ-level){
//             level++;
//             i = level;
//             j = level;
//         }
//     }
//     return ans;
// }


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int count = m*n;
    vector<int> ans;
    if(m == 0 ) return ans;
    vector<vector<bool>> seen(m, vector<bool>(n, false));

    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int x = 0, y = 0, di = 0;
    
    while(count>0){
        ans.push_back(matrix[x][y]);
        seen[x][y] = true;
        int newX = x+dr[di], newY = y+dc[di];

        if(newX>=0 && newX<m && newY>=0 && newY<n && !seen[newX][newY]){
            x = newX;
            y = newY;
        }else{
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
        count--;
    }
    return ans;
}

int main(){

    vector<vector<int>>matrix = {{1,2,3},
                                 {4,5,6},
                                 {7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    
    for(auto it:ans){
        cout<<it<<"->";
    }

    return 0;
}