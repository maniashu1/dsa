// leetcode 253 ( Meeting room ii) medium

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minMeetingsRooms(vector<vector<int>>& intervals){
    vector<int> start;
    vector<int> ending;

    for(auto ele : intervals){
        start.push_back(ele[0]);
        ending.push_back(ele[1]);
    }
    // sort the starting and ending time
    sort(start.begin(),start.end());
    sort(ending.begin(),ending.end());

    int ans = 0;
    int room = 0;
    int i = 0;
    int j = 0;

    while(i < start.size() && j < ending.size()){
        if(start[i] < ending[j]){                    // new room taken
            room++;
            ans++;
            i++;
        } else if(start[i] == ending[j]){           // room vacent and can be reused
            room--;
            i++;
            j++;
        } else {                                    // vacent room available 
            room--;
            j++;
        }
    }
    return ans;

}

int main(){

    vector<vector<int>> intervals = { {1,10} ,{2,7} ,{3,19},{8,12},{10,20},{11,30} };
    
    int result = minMeetingsRooms(intervals);

    cout << result;

    return 0;
}