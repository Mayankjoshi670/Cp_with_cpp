#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long 
#define int long long int
const int N = 1e5+10;
//  to optmize we do 2 things 
//  path compression 
// union by size/rank 
 int parent[N] ; 
 int Size[N];
 void make(int v){
     parent[v] = v ;
    Size[v] = 1 ; 
 }
 int find(int v ){
     if(v == parent[v])return v ;
    //  path compression 
     return  parent[v] = find(parent[v]) ; 
 }
 void Union(int a , int b){
    a =  find(a) ; 
    b = find(b) ; 
    //  we consider right tree(a) as smaller tree 
    //  if there is smaller tree on left we just swap them 
    // ie sizeof(a)< sizeof(b) swap 
    if(a!= b ){
        // union by rank 
        if(Size[a]<Size[b]) swap(a,b) ; 
        //  means dont have same parent 
        //  then merge them 
        parent[b] = a ; 
    }
    Size[a]+= Size[b] ; 
 }
int32_t main() {
    fast_io;
    int n , k ; 
    cin>> n >> k ; 
//  to count distinct connected components 
for(int i = 1 ; i<= n ; i++){
    make(i); 
}
while(k--){
    int u , v ; 
    cin>>u>>v ; 
    Union(u , v) ; 
}
int connected_cnt = 0 ; 
//  it is the no of componts who are there own parents 
for(int i= 1 ; i<= n ; i++){
    if(find(i) == i)connected_cnt++ ; 
}
cout<< connected_cnt ; 
}

// time complexcity => O(alpha(n)) 
// where alpha(n) equals to reverse ackerman function 
//  means it's  values increase very slowly
//  alpha of n never exceed then 4 
// meanse constant 



// test case 

// 5
// 3
// 1 2
// 3 4
// 4 5

// output 
// 2 