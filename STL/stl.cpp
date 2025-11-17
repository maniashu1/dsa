#include<iostream>
#include<utility>
#include<vector>
#include<list>
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

   ls.emplace_front(); {7 , 9};

   // rest function same as vector
   // begin , end , rbegin , clear , insert , size , swap etc...

}



int main(){

 // explainPair();

 // explainVector();

 // explainList();


    return 0;
}

