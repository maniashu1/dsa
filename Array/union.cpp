#include<iostream>
#include<vector>
using namespace std;

 vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0;
        int j = 0;
        vector<int> ans;
       while (i < len1 && j < len2) {
        if (nums1[i] < nums2[j]) {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
        }
        else if (nums2[j] < nums1[i]) {
            if (ans.empty() || ans.back() != nums2[j])
                ans.push_back(nums2[j]);
            j++;
        }
        else {  // nums1[i] == nums2[j]
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
        // nums2 get exhausted
        while(i < len1){
            ans.push_back(nums1[i]);
            i++;
        }
        // nums 1 get exhausted
        while(j < len2){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }

    void Display(vector<int>& v){
       for(int i=0; i<v.size() ; i++){
        cout << v[i] << " ";
       }
    }

int main(){
    int n1;
    cout << "Enter the size of the first array :";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the element of the second array : ";
    for(int i=0; i<n1; i++){
        cin >> nums1[i];
    }

    int n2;
    cout << "Ente the size of the second array : ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the element of the second array : ";
    for(int i=0; i<n2; i++){
        cin >> nums2[i];
    }
    
    vector<int> result = unionArray(nums1 , nums2);
    Display(result);

    return 0;
}
