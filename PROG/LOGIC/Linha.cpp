#include "Linha.hpp"


vector<string> split(string str, char delimiter) {
  vector<string> toReturn;
  stringstream ss(str); // Transforma a string numa stream
  string info;

  while(getline(ss, info, delimiter)) {
    toReturn.push_back(info);
  }

  return toReturn;
}


istream& operator>> (istream &is, Linha &linha){
  string line;

  getline(is, line);

  if (!line.empty()) {
    //  dividir a linha de acordo com ';'
    vector<string> data = split(line, ';');

    //  configurar objecto
    linha.uid = stoi(data[0]);
    linha.freq = stoi(data[1]);
  }

  cout << linha << endl;

  return is;
}

ostream& operator<< (ostream &os, Linha &linha){

  os << linha.uid;
  os << " ; ";
  os << linha.freq;
  os << " ; ";


  return os;
}
