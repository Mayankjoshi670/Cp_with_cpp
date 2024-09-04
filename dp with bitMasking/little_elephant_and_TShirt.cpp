// problem link :) https://www.codechef.com/problems/TSHIRTS

// video link :)  https://www.youtube.com/watch?v=Smem2tVQQXU&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=6

#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define itn int 
#define ll long long 
#define mod 1000000007
bool people[11][101];

void input(int n)
{
    string s;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        stringstream in(s);
        int a;
        while(in >> a)
        {
            people[i+1][a] = 1;
        }
    }
}

ll dp[101][1025]; 
// mask = 3 (binary 11), it means the first and second persons have already been assigned shirts.
int findAns(int shirt, int mask, int n) {
    if(mask == ((1<<n)-1)) return 1;
// All people have been assigned shirts, so return 1. 
    if(shirt > 100) return 0;
    if(dp[shirt][mask] != -1) return dp[shirt][mask];
    //  it is dp 
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        //  we iterate over  each person 
        if((mask & (1<<(i-1))) != 0) {
        //  If person i has already been assigned a shirt (mask & (1<<(i-1)) != 0), skip to the next person.
            continue;
        }
        if(people[i][shirt]){
            //  if that person has that shirt we can use it 
            // If person i have  the current shirt (people[i][shirt]), update the mask to reflect that person i has been assigned this shirt (temp_mask = (mask |(1<<(i-1)))), and recursively calculate the number of ways for the remaining shirts.
            int temp_mask = (mask |(1<<(i-1)));
            ans = (ans + findAns(shirt+1, temp_mask, n)) % mod;
        }
    }
    ans = (ans + findAns(shirt+1, mask, n)) % mod;
    return dp[shirt][mask] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
          memset(people, 0, sizeof people);
        memset(dp, -1, sizeof dp);
        cin >> n; 
        input(n);
        // we will start form first shirt and fo ahead till 100  and 
        cout << findAns(1, 0, n) << "\n";
    }
}
