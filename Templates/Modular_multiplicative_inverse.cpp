// https://codeforces.com/contest/2008/submission/279248073
#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long 
const int mod = 1e9+7; 
using namespace std;
 
ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void solve() {
    int n; 
    cin >> n; 
    vi arr(n); 
    for(auto &it: arr) cin >> it; 
    
    vi suffix(n); 
    suffix[n-1] = arr[n-1] % mod;
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = (suffix[i+1] + arr[i]) % mod;  
    }
    
    ll result = 0; 
    for(int i = 0; i < n-1; i++) {
        result = (result + (1LL * arr[i] * suffix[i+1]) % mod) % mod; 
    }
    
    ll divBy = (1LL * n * (n-1) / 2) % mod; 
    ll divByInverse = modInverse(divBy, mod);
    
    cout << (result * divByInverse) % mod << '\n';
    return; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    int t; 
    cin >> t; 
    while(t-- > 0) {
        solve(); 
    }
}