// City and Flood
// link
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define ll long long 
#define int long long int
const int N = 1e5+10;
     int Parent[N+1]; 
    int Size[N+1] ;
void make (int v ){
    Parent[v] = v ; 
    Size[v] = 1; 
}
int find(int v ){
    if(Parent[v] == v) return v ; 
    return Parent[v] = find(Parent[v]) ; 
}
void Union(int a, int b){
   a = find(a) ; 
   b = find(b) ; 
   if(a!= b ){
       if(Size[a]<Size[b])swap(a,b);
       Parent[b] = a; 
   }
   Size[a]+= Size[b];
}
int32_t main() {
    fast_io;
    int n , k ; 
    cin>> n >> k ;
for(int i = 1 ; i<= n ;i++ ){
    make(i);
    }
    
    while(k--){
        int a, b ; 
        cin>>a >> b ; 
        Union(a  ,b) ; 
    }
    int connected_cnt = 0 ; 
//  it is the no of componts who are there own Parents 
for(int i= 1 ; i<= n ; i++){
    if(find(i) == i)connected_cnt++ ; 
}
cout<< connected_cnt<<'\n' ; 

}

 