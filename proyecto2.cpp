#include <iostream>
#include <map>
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

string resta(string a, string b){
  while(!b.empty()){
    if(a[a.size()-1]==b[b.size()-1]){
      a.pop_back();
      b.pop_back();
    }
  }
  return a;
}

void part(map<char, char> &mp1, map<char, string> &mp2, string n){
  unsigned i;
  if(n.size() >= 4){
    i = 4;
  }
  else if(n.size() < 4){
    i = n.size();
  }
  /*string p2 = n.substr(0,1);
  m_find( mp2, p2);*/
  for(unsigned j = 0; j < i; j++){
    string p1 = n.substr(0, j+1);
    m_find(mp2, p1);
    string res = n.substr(j+1, n.size());

    part(mp1, mp2, res);

  }
  cout << endl;

}
/*
void base_case1234(map<char, char> &mp1, map<char, string> &mp2, string str, string str2){//Maximo 4 simbolos
  string g = resta(str2, str);
  if(str.size()<=4){
    if(str=="+"){ // Si solo hay un simbolo
      m_find(mp2, g);
      char letra = '+';
      m_find(mp1, letra);
      cout << endl;
    }
    else if(str =="-"){ // Si solo hay un simbolo
      m_find(mp2, g);
      char letra = '-';
      m_find(mp1, letra);
      cout << endl;
    }
    else if(str.size()==2){ // Si hay dos simbolos
      char sim1 = str[0], sim2 = str[1];
      m_find(mp2, g);
      m_find(mp2, str);
      cout << endl;
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp1, sim2);
      cout << endl;
    }
    else if(str.size()==3){ // Si hay tres simbolos
      char sim1 = str[0], sim2 = str[1], sim3 = str[2];
      string cop1 = str, cop2 = str;
      m_find(mp2, g);
      m_find(mp2, str);
      cout << endl;
      cop1.erase(cop1.begin());
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp2, cop1);
      cout << endl;
      cop2.pop_back();
      m_find(mp2, g);
      m_find(mp2, cop2);
      m_find(mp1, sim3);
      cout << endl;
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp1, sim2);
      m_find(mp1, sim3);
      cout << endl;
    }
    else if(str.size()==4){ // Si hay cuatro simbolos
      char sim1 = str[0], sim2 = str[1], sim3 = str[2], sim4 = str[3];
      string cop1 = str, cop2 = str, cop3 = str, cop4 = str, cop5 = str;
      m_find(mp2, g);
      m_find(mp2, str);
      cout << endl;
      cop1.pop_back();
      m_find(mp2, g);
      m_find(mp2, cop1);
      m_find(mp1, sim4);
      cout << endl;
      cop3.erase(2,4);
      cop4.erase(0,2);
      m_find(mp2, g);
      m_find(mp2, cop3);
      m_find(mp2, cop4);
      cout << endl;
      cop2.erase(cop2.begin());
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp2, cop2);
      cout << endl;
      m_find(mp2, g);
      m_find(mp2, cop3);
      m_find(mp1, sim3);
      m_find(mp1, sim4);
      cout << endl;
      cop5.erase(cop5.begin());
      cop5.pop_back();
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp2, cop5);
      m_find(mp1, sim4);
      cout << endl;
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp1, sim2);
      m_find(mp2, cop4);int
      cout << endl;
      m_find(mp2, g);
      m_find(mp1, sim1);
      m_find(mp1, sim2);
      m_find(mp1, sim3);
      m_find(mp1, sim4);
      cout << endl;
    }
  }
  else{
    string g = resta(str2, str);
    m_find(mp2, g);
    for(int q = 0; q < 4; q++){
      string n = str, s = str;
      n.erase(q+1, str.size());
      m_find(mp2, n);
      //cout << n << " nnn" << endl;
      s.erase(0, q+1);int
      //cout << s << " sss" << endl;
      base_case1234(mp1, mp2, s, str);
    }
  }
}
*/

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
  part(map_char, map_magic, x);

  return 0;
}
