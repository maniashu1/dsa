#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> &v ,int x){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    int lb = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(v[mid] == x)  {
            lb = v[mid-1];
            return lb;
        }
        if(v[mid] > x){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    } 
    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the element of the array : ";

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int x;
    cout << "Enter the element for which you want to find its lowerbound : ";
    cin >> x;
    int res = lowerBound(v,x);

    cout << "The lower bound is :" << res;

    return 0;
}