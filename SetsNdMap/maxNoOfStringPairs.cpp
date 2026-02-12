// Leetcode 2744 ( maximum number of stirng pair)

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string> s;
        int count = 0;
        for(int i=0; i<n; i++){
           string rev = words[i]; 
           reverse(rev.begin() , rev.end());
           if(s.find(rev) != s.end()){
            count++;
           } else {
            s.insert(words[i]);
           }
        }
        return count;
    }

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<string> s(n);

    cout << "Ente the element if the array : ";

    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    int result = maximumNumberOfStringPairs(s);

    cout << "The maximum no of string pairs is : " << result ;
    
    return 0;
}