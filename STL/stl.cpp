#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<math.h>
#include<algorithm>
using namespace std;

// pair -> it lies inside the utility library

void explainPair(){

  pair<int ,int> p = {1 , 3};
  cout << p.first << " " << p.second << endl;

  pair<int, pair<int , int>> p2 = {1 , {3 , 4}};
  cout << p2.first << " " << p2.second.first << " " << p2.second.second ;
  cout << endl;

  pair<int, int> arr[] = { {1 , 2} , {3 , 4} , {5 , 7} };
  cout << arr[1].second ;

}

// it lies inside the vector library
// vector -> it inside the vector library
// it is container which is dynamic in nature

void explainVector(){
   
  vector<int> v;

  v.push_back(1);
  v.push_back(5);
  v.push_back(4);
  v.push_back(2);
  v.push_back(7);
  v.push_back(9);
  v.push_back(3);

  // v.emplace_back(4); // similar to push_back , it dynamically insreases its size and insert at back , generally it is faster than push_back

  // creating vector of pair
  // vector<pair <int , int>> vec;
  
  // vec.push_back({1 , 3});
  // vec.emplace_back(4 , 5);

  // vector<int> v(5 , 100) ; // it contain 5 instances of 100 or 5 times 100 

  // vector<int> v3(5) ; // 5 instances of zero or size of the vector is 5 , we can also increase the size, because it is dynamic in nature 

  // vector<int , int> v4(6 , 20); // {20 , 20, 20, 20, 20, 20}

  // vector<int> v5(v3) ; // we can copy the container inside the another container

  // // iteration in vector

  vector<int>::iterator it = v.begin();

  it++;
  cout << *(it) << " "; // it will give 5

  it = it + 2 ;

  cout << *(it) << " "; // it will print 2

  // other iterator

  vector<int>::iterator itr = v.end() ; // end pointed the memory location just right after the location of last elememnt and when we do it-- the it will pointibng towards the last location
  
  // vector<int>::iterator it = v.rend() ; 

  // vector<int>::iterator it = v.rbegin();

  cout << endl;

  cout << v[0] << " " << v.at(0) << endl ;

  cout << v.back() << " ";
  cout << endl;

  for(vector<int>::iterator i = v.begin(); i != v.end() ; i++){ // printing the element of the vector using for loop
    cout << *(i) << " " ;
  }
   
  cout << endl ;

  for(auto i = v.begin(); i != v.end() ; i++){ // here we use auto keyword ehich automatically assign the data type
    cout << *(i) << " " ;
  }
  cout << endl; 
  for(auto itr : v){
    cout << itr << " ";  // it iterator on the data type
  }

  // deletion of the vector

  v.erase(v.begin()+1); // it will delete the second element from the begning
  cout << endl ;

  for(auto itr : v){
    cout << itr << " ";  // it iterator on the data type
  }
  
  v.erase(v.begin()+2 , v.begin()+4); // start is included but end is not included i.e [ _ _ _ ) ;
  cout << endl ;

  for(auto itr : v){
    cout << itr << " ";  // it iterator on the data type
  }
  cout << endl;
  // insert function of vector
  
  v.insert(v.begin() , 300);
  v.insert(v.begin() + 2 , 4 , 200);

  for(auto itr : v){
    cout << itr << " ";  
  }

  cout <<endl ;

  // copy
  vector<int> copy(2, 50); // {50 , 50}

  // size 

  cout << v.size();
  
  // pop_back function 
  v.pop_back(); // it will pop out the last element form the vector

  // swap function
  // v1 {10 , 20}  and v2 {30 , 40}
  // v1.swap(v2) ;  v1 -> {30 , 40} and v2 -> {10 , 20} 

  // clear() function -> it will erase the entire vector
  // v.clear();

}

// it lies inside the list library
// list is exactly similar to the vector 
// but the only difference is it will give you the front operation as well 
// it is also dynamic in nature

void explainList(){
   list<int> ls;
   
   ls.push_back(2);
   ls.emplace_back(5);

   ls.push_front(7);

   //ls.emplace_front(); {7 , 9};

   // rest function same as vector
   // begin , end , rbegin , clear , insert , size , swap etc...

}

void explainDeque(){

  deque<int> dq;
  dq.push_back(3);
  dq.emplace_back(4);
  dq.push_front(4);
  dq.emplace_front(9);

  dq.back();
  dq.front();
  // rest function same as vector
  // begin , rbegin , rend , clear , insert , size , swap etc .... 

  for (auto el : dq){
    cout << dq[el] << " ";
  }
}

void explainStack(){  // it is LIFO -> i.e last in first out 
   stack<int> st;
   st.push(5);
   st.push(7);
   st.push(8);
   st.push(4);
   st.push(2);
   st.push(9);
   st.emplace(6);

   cout << st.top() ; // it print 6 which is top odf the stack "** st[2] is invalid **"

   st.pop();  // it wil pop the top element from the stack 

   cout << st.top() ;  // it will print 9

   cout << st.size() ; // it will print the size of the stack

   cout << st.empty() ; // it will return true if stack is empty else it will return true 

   stack<int> st1 , st2;
   st1.swap(st2);    // swap st1 with st2
}

void explainQueue(){   // it is FIFO -> i.e first in first out ...
queue<int> q;
q.push(1); // {1}
q.push(2) ; // {1, 2}
q.emplace(4); // {1, 2, 4}

q.back() += 5 ; // 5 will get added into the 4 and makes it 9

cout << q.back(); // it will prints 9

// now q is containing {1, 2, 9}

cout << q.front() ; // it will print 1

q.pop() ; // it will pop 1 from the queue and rmaining queue will be {2, 9}

cout << q.front(); // it will print 2

// all other function like swap, size, etc same as above..
 

}


// Largest value always stay on the top 

void explainPriorityQueue(){
  priority_queue<int> pq;

  pq.push(5); // {5}
  pq.push(2); // {5 , 2}
  pq.push(8); // {8 , 5 , 2}
  pq.emplace(10); // {10, 8, 5, 2}

  cout << pq.top(); // prints 10

  pq.pop(); // it will pop out 10 and remaining element {8, 5, 2}

  cout << pq.top(); // now it will print 8

  // size , swap, empty etc... function same as others

  // minimum heap

  priority_queue<int, vector<int>, greater<int>> prq; // it kept minimum element at the top generally ii is also known as min heap
  prq.push(5); // {5}
  prq.push(2); // {2, 5}
  prq.push(8); // {2, 5, 8}
  prq.emplace(10); // {2, 5, 8, 10}

  cout << prq.top(); // it will print 2

}

// set container conatin everything in sorted order and every elemnt is unique and everything happen in logn time complexity

void explainSet(){
  set<int> s;
  s.insert(1);  // {1}
  s.emplace(2);  // {1, 2}
  s.insert(2);   // {1, 2}
  s.insert(4);  // {1, 2, 4}
  s.insert(3);  // {1, 2, 3, 4}

  // functionality of insert in vector can be used also, they only increases effiency
  // begin() , end() , rbegin() , rend() , size() , empty() , swap(). function are same as above

  auto it = s.find(3); // it returns an iteraton which point on the 3 basically it rerturns the address of 3 

  auto it = s.find(6); // if element is not in the set it will always return s.end() i.e the iterator which points to the end 

  s.erase(3) ; // it erases 3 from the set and it will take logarithmic time 

  int cnt = s.count(1); // if it exists it will give 1 otherwise it give 0

  auto it = s.find(3);
  s.erase(it) ; // it will take constant time // we can also do that s.erase(s1 , s2);

  // lower_bound() and upper_bound() function works in the same way as in vector it does 

  auto it = s.lower_bound(2);

  auto it = s.upper_bound(3);
  
}

// Multiset is similar to set it also contain element in sorted manner but not unique i.e duplicate is may present in the set

void explainMultiset(){

  multiset<int> ms;
  ms.insert(1); // {1}
  ms.insert(1);  // {1, 1}
  ms.insert(1); // {1, 1, 1}
  ms.erase(1); // all 1's erased...

  int cnt = ms.count(1) ; // count the no of 1's present in the multiset 

  ms.erase(ms.find(1)) ; // it will erase only one 1's by finding and erasing on the only particular addresses

  // ms.erase(ms.find(1) , ms.find(1)+2); // it will erase 2 ones..

  // rest all function same as set

}

// Unordered set i.e element is stored in randomised ordered 
// lower_bound and upper_bound function doesn't work here 
// rest all function are same as above
// it does not stores in any particular order it has a better complexity than set in most cases except when collisons happen
// time complexity is O(1) // but in worst case it will goes O(n)

void explainUnorderedset(){
  unordered_set<int> us;
  
}


// map
// it stores data in the key value pair form 
// it can store any data type like integer , double float etyc...

void explainMap(){
  map<int , int> mpp;
  
  map<int, pair<int , int>> mpp;

  map<pair<int,int>, int> mpp;

  mpp[1] = 2; // it eill store like key 1 value 2

 // mpp.emplace({3 , 1}); // it will store like key as 3 and value at 3 is 1

  mpp.insert({2,4}) ; // it will also stored in the same manner 

  mpp[{2,3}] = 10; 

  // {
  //   {1,2}
  //   {2,4}
  //   {3,1}
  // }
  
  for(auto it : mpp) {
    cout << it.first << " " << it.second << endl ; // if something is not exit it will print either 0 or null
  }

  cout << mpp[1];
  cout << mpp[5];

  // auto it = mpp.find(3);
  // cout << *(it).second;

  auto it = mpp.find(5);
  
  auto it = mpp.lower_bound(2);
  auto it = mpp.upper_bound(3);
  // all other function are same as above 
}

// multimap

void explainMultimap(){
  // everything is similar to map, only thing it can stor multiple keys
  // only mpp[key] can not be used here

}
// unorderd_map same as set and unorderd_set but not in sorted and have unique keys and tc is constant
// comp function
bool comp(pair<int, int> p1 , pair<int , int> p2){
  if(p1.second < p2.second) return true;
  if(p1.second > p2.second) return false; // then it will do the internal swapping
  // if they are same i.e p1.second == p2.second 
  if(p1.first > p2.first) return true;
  return false; // please swap it 
}

void explainExtra(){
    // sort(a , a + n);
    // sort(v.begin() , v.end()) ;
    // sort(a+2, a+4);
    // sort(a , a+n, greater<int>) ; // it will sort them in descending order

    pair<int , int> a[] = {{1,2}, {2,1}, {4,1}};
    // sort it according to second element 
    // if secod element is same , then sort according to first element but in descinding

   //  sort(a , a+n , comp);
   

   int num = 7;  //7 means 00000111 -> in binary 
   //int cnt = __builtin_popcount(); // it count 3 bits of 1 it count no of set bits 

   long long num = 65657215471254721;
  // int cnt = __builtin_popcountll(); 

  // string

  string s = "1234";
  sort(s.begin() , s.end());

  do{
    cout << s << endl;
  } while(next_permutation(s.begin() , s.end()));
  
  // int maxi = *max_element(a,a+n);

   
}



int main(){

 // explainPair();

 // explainVector();

 // explainList();

  // explainDeque();

 //  explainStack();

  // explainQueue();

   // explainPriorityQueue();

   // explainSet();

   // explainMultiset();
   
   // explainUnorderedset();

   // explainMap();
    return 0;
}

