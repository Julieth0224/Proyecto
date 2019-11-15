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

void base_case1234(map<char, char> &mp1, map<char, string> &mp2, string str){//Maximo 4 simbolos
  if(str=="+"){ // Si solo hay un simbolo
    char letra = '+';
    m_find(mp1, letra);
    cout << endl;
  }
  else if(str =="-"){ // Si solo hay un simbolo
    char letra = '-';
    m_find(mp1, letra);
    cout << endl;
  }
  else if(str.size()==2){ // Si hay dos simbolos
    char sim1 = str[0], sim2 = str[1];
    m_find(mp2, str);
    cout << endl;
    m_find(mp1, sim1);
    m_find(mp1, sim2);
  }
  else if(str.size()==3){ // Si hay tres simbolos
    char sim1 = str[0], sim2 = str[1], sim3 = str[2];
    string cop1 = str, cop2 = str;
    m_find(mp2, str);
    cout << endl;
    cop1.erase(cop1.begin());
    m_find(mp1, sim1);
    m_find(mp2, cop1);
    cout << endl;
    cop2.pop_back();
    m_find(mp2, cop2);
    m_find(mp1, sim3);
    cout << endl;
    m_find(mp1, sim1);
    m_find(mp1, sim2);
    m_find(mp1, sim3);
    cout << endl;
  }
  else if(str.size()==4){ // Si hay cuatro simbolos
    char sim1 = str[0], sim2 = str[1], sim3 = str[2], sim4 = str[3];
    string cop1 = str, cop2 = str, cop3 = str, cop4 = str, cop5 = str;
    m_find(mp2, str);
    cout << endl;
    cop1.pop_back();
    m_find(mp2, cop1);
    m_find(mp1, sim4);
    cout << endl;
    cop3.erase(2,4);
    cop4.erase(0,2);
    m_find(mp2, cop3);
    m_find(mp2, cop4);
    cout << endl;
    cop2.erase(cop2.begin());
    m_find(mp1, sim1);
    m_find(mp2, cop2);
    cout << endl;
    m_find(mp2, cop3);
    m_find(mp1, sim3);
    m_find(mp1, sim4);
    cout << endl;
    cop5.erase(cop5.begin());
    cop5.pop_back();
    m_find(mp1, sim1);
    m_find(mp2, cop5);
    m_find(mp1, sim4);
    cout << endl;
    m_find(mp1, sim1);
    m_find(mp1, sim2);
    m_find(mp2, cop4);
    cout << endl;
    m_find(mp1, sim1);
    m_find(mp1, sim2);
    m_find(mp1, sim3);
    m_find(mp1, sim4);
    cout << endl;
  }
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

  map<char, char> map_char; // map de decodificaciones de un simbolo
  map_char['B'] = '-';
  map_char['S'] = '+';

  string x;
  cin >> x;
  base_case1234(map_char, map_magic, x); // Prueba

  return 0;
}
