#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
    
  unordered_map<string,int> m;
  pair<string,int> p1;
  p1.first = "ashutosh";
  p1.second = 20;

  pair<string,int> p2;
  p2.first = "Ashish";
  p2.second = 25;

  pair<string,int> p3;
  p3.first = "rahul";
  p3.second = 27;

  m.insert(p1);
  m.insert(p2);
  m.insert(p3);

  for(auto p : m){
    cout << p.first << " " << p.second << endl;
  }

  

    return 0;
}