#include<iostream>
using namespace std;

int fun(int n){
    if(n == 0 ) return 0;
    if(n == 1) return 1;
    return fun(n-1) + fun(n-2);
}

int main(){
    
    cout << fun(6);
    
    return 0;
}