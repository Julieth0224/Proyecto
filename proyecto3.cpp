#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

template <typename dataType>
void m_find(map<char, dataType> &mp1, dataType n){ //Encuentra la decodificacion
  typename map<char, dataType> :: iterator it;
  for(it = mp1.begin(); it!=mp1.end(); ++it){
    if(n == it->second){
      cout << it->first;
    }
  }
}

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

set<string> print_partitions(string s){
  set<string> set_1 = Partitions(s);
  set<string> final_set;
  for(auto it = set_1.begin(); it!=set_1.end(); ++it){
    string n = *it;
    if(four(n)){
      final_set.insert(n);
    }
    else{
      set_1.erase(set_1.find(n));
    }
  }
  return final_set;
}

int main(){
  map<char, string> map_magic; //map de decodificaciones de dos a cuatro simbolos
  map_magic['A'] = "++";
  map_magic['C'] = "+-+";
  map_magic['D'] = "--";
  map_magic['E'] = "+++";
  map_magic['F'] = "+-+-";
  map_magic['G'] = "----";
  map_magic['H'] = "--+-";
  map_magic['I'] = "-+" ;
  map_magic['J'] = "-+-+";
  map_magic['K'] = "+--+";
  map_magic['L'] = "---";
  map_magic['M'] = "++-+";
  map_magic['N'] = "++-";
  map_magic['O'] = "-++";
  map_magic['P'] = "+-++";
  map_magic['Q'] = "+---";
  map_magic['R'] = "+-";
  map_magic['T'] = "-+-";
  map_magic['U'] = "++--";
  map_magic['V'] = "-+--";
  map_magic['W'] = "-+++";
  map_magic['X'] = "--+";
  map_magic['Y'] = "+++-";
  map_magic['Z'] = "---+";
  map_magic['.'] = "+--";
  map_magic['#'] = "++++";
  map_magic['!'] = "-++-";
  map_magic['?'] = "--++";
  map_magic['B'] = "-";
  map_magic['S'] = "+";

  map<char, char> map_char; // map de decodificaciones de un simbolo
  map_char['B'] = '-';
  map_char['S'] = '+';

  string x;
  cin >> x;
  set<string> g = print_partitions(x);

  for (auto it = g.begin(); it!=g.end(); ++it){ // imprime el set de particiones
      cout << *it << endl;
  }

  return 0;
}
