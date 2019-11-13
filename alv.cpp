#include <iostream>
#include <string>
#include <set>
using namespace std;
/*
bool four(string &f){
  int i = 0;
  string n = f;
  while(n[0]!=' '){
    i++;
    n.erase(n.begin());
    cout << n << endl;
  }
  if(i > 4){
    return false;
  }
  else{
    return four(n);
  }

}*/

set<string> Partitions(string s) {
  set <string> sub;
  if(s.size()<=1){
    sub.insert(s);
    return sub;
  }
  else{
    int x = s.size();
    for(int q = 0; q < x; q++){
      string first = s.substr(0,q+1), n = s;
      n.erase(0,q+1);
      set<string> b = Partitions(n);
      first += ' ';
      for(auto it = b.begin(); it!=b.end(); ++it){
        string f = first + *it;
        sub.insert(f);
      }
    }
    return sub;
  }
}
int main(){
  set <string>::iterator it2;
  set<string> g = Partitions("abcdefgh");
  for( it2 = g.begin(); it2!=g.end(); ++it2){
    cout << *it2 << endl;
  }

  return 0;
}
