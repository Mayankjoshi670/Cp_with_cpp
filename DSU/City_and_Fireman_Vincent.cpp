// City and Fireman Vincent
// link
//  https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/
#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long 
#define int long long int
const int mod = 1e9 + 7;

class DSU {
    vector<int> parent, Size;
public:
    DSU(int n) {
        parent.resize(n+1);
        Size.resize(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);   
    }
    
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (Size[a] < Size[b]) swap(a, b);  
            parent[b] = a;
            Size[a] += Size[b];
        }
    }
};

int32_t main() {
    fast_io;
    
    int n, k;
    cin >> n;
    
    DSU dsu(n);
    vi arr(n+1);
     
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        dsu.Union(a, b);
    }
    
    unordered_map<int, vector<int>> mpp;
    for (int i = 1; i <= n; i++) {
        int root = dsu.find(i);
        mpp[root].push_back(i);
    }
    
    int ways = 1;
    for (auto& it : mpp) {
        vector<int>& compo = it.second;
        int cnt = 0;
        int mini = LLONG_MAX;
         
        for (auto& city : compo) {
            if (arr[city] < mini) {
                mini = arr[city];
                cnt = 1;   
            } else if (arr[city] == mini) {
                cnt++;
            }
        }
        
        ways = (ways * cnt) % mod;
    }
    
    cout << ways << '\n';
    
    return 0;
}
