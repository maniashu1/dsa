// Leetcode 1700  ( Number of students unable to eat lunch). 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int st = students.size();
        queue<int> q;
        int count = 0;
        int i = 0; // for treversing in sandwiches
        for(int i=0; i<st; i++){
            q.push(students[i]);
        }
        while(q.size()>0 && count != q.size()){
            if(q.front() == sandwiches[i]){
                count = 0;   // if eaten then count should be zero
                i++;
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
                count++;   // if not eaten then ififnite loop  
            }
        }
        return count;

    }

int main(){

    return 0;
}