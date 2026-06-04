// Leetcode 386 ( Lexicographical Numbers ) medium
// topic trie, recursion,

#include<iostream>
#include<vector>
using namespace std;
/*

fun(0,n) = fun(10*i+j,n) , [0->9] -> if ( i != 0 )
           fun(10*i+j,n) , [1->9] -> if ( i == 0 )
 
*/
class Solution {
public:
    vector<int> ans;
    void fun(int i, int n){
        if(i > n) return;
        if(i <= n && i != 0) {
            ans.push_back(i);
        }
        if( i != 0){
            for(int j=0; j<=9; j++){
                fun(10*i+j,n);
            }
        } else {
            for(int j=1; j<=9; j++){
                fun(10*i+j,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        fun(0,n);
        return ans;
    }
};


int main(){

    return 0;
}