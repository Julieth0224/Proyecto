#include <iostream>
#include <string>
#include <set>
using namespace std;

bool four(string f){
  int i = 0;
  for(unsigned q = 0; q < f.size(); q++){
    i++;
    if((f[q]==' ' && i <= 5)){
      i = 0;
    }
    else if(i > 4){
      return false;
    }
    else{
      continue;
    }
    if(i > 4){
      return false;
    }
  }
  return true;
}

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
  string d = "aaaaa aa aaaa";
  set <string>::iterator it2;
  set<string> g = Partitions("++++++");
  set<string> n;
  for( it2 = g.begin(); it2!=g.end(); ++it2){
    string h = *it2;
    if(four(h)){
      n.insert(h);
    }
    else{
      g.erase(g.find(h));
    }
  }
  for(auto it3 = n.begin(); it3!=n.end(); ++it3){
    cout << *it3 << endl;
  }
  cout << boolalpha << four(d) << endl;

  return 0;
}
