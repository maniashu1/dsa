#include<iostream>
#include<unordered_set>
using namespace std;

// it stores only unique element
int main(){
   unordered_set<int> s;

   s.insert(1);
   s.insert(2);
   s.insert(3);
   s.insert(4);
   
   cout << s.size() << endl ;

   // printing using for each loop

   for(int ele : s){
    cout << ele << " ";
   }

   // finding an element which is present in the set

   // s.find() -> it searches the target element in the set and if it is not present in the set it returns the last element 

   int target = 5;

   if(s.find(target) != s.end()){
    cout << "Target exists "<< endl;
   } else {
    cout << "Target does not exists " << endl;
   }
    return 0;
}