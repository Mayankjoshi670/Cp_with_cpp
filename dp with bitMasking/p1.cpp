/* Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20

*/

#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int dp[21][21];

int findAns(int i, int mask, vector<vector<int>>& arr) {
    if (i == arr.size()) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];
    int ans = INT_MAX;
    for (int j = 0; j < arr.size(); j++) {
        if (mask & (1 << j)) {
            // It means we can take jth bit because the AND operation is one 
            ans = min(ans, arr[j][i] + findAns(i + 1, mask ^ (1 << j), arr));
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
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));   
        cout << findAns(0, (1 << n) - 1, arr) << "\n";
    }
}
