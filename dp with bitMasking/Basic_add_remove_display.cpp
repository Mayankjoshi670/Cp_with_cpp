#include<bits/stdc++.h>
using namespace std ;
void display(int subSet){
    for(int bitno = 0 ; bitno<=9 ; bitno++){
        if(subSet & (1<< bitno)){
            cout <<  bitno+1<<" ";
        }
    }
    cout << '\n' ; 
}
void remove(int& subSet , int x){
subSet =     subSet^(1<<(x-1)) ; 
}
void add(int & subSet , int x){
    subSet = subSet^(1<<(x-1)) ; 
}
int main(){
    int set = 15 ; 
    display(set) ; 
    //  set for val 15 is {1 , 2 , 3,4 }
     remove(set , 3) ;
      display(set) ;
      add(set , 5) ; 
      display(set);
      
}