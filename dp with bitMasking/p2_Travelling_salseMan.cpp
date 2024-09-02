#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int dp[21][1<<16];

int findAns(vector<vector<int>>& cost, int i, int mask, int n) {
    if(mask == 0){
        return cost[i][0];
    }
    
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }
    
    int ans = INT_MAX;
    for(int j = 0; j < n ; j++){
        if(mask & 1 << j){
            ans = min(ans, cost[i][j] + findAns(cost , j, mask ^ (1 << j), n));
        }
    }
    
    return dp[i][mask] = ans;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));   
        cout << findAns(cost , 0 , ((1 << n) - 2) , n) << "\n";
    }
}
