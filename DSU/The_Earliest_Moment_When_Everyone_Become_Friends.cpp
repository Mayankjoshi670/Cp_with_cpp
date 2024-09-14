// link   https://www.geeksforgeeks.org/the-earliest-moment-when-everyone-become-friends/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5 + 10;
int parent[N];
int Size[N];

void make(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

int Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return 0  ; 
    if (a != b) {
        if (Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
    return 1 ; 
    
}

int earliestAcq(vector<vector<int>>& logs, int n) {
    for (int i = 0; i < n; i++) {
        make(i);
    }
    int groups = n ; 
    sort(logs.begin(), logs.end());
    
    for (auto& log : logs) {
        int t = log[0];
        int a = log[1];
        int b = log[2];
        groups-= Union(a , b ) ; 
        if(groups== 1 ) return t ; 
    }
    
    return -1;
}

int32_t main() {
    vector<vector<int>> logs;

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        logs.push_back({c, a, b});  
    }
    
    int n;
    cin >> n;
    
    cout << earliestAcq(logs, n) << '\n';

    return 0;
}
