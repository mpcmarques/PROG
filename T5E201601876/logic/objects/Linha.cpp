#include "Linha.hpp"

int Linha::calcularTempoTotalEntreParagens(int posPrimeiraParagem, int posSegundaParagem) {
    int tempoTotal = 0;

    if (posPrimeiraParagem == posSegundaParagem) return 0;

    else if (posPrimeiraParagem < posSegundaParagem) {
        for (int j = posPrimeiraParagem; j <= posSegundaParagem; j++) {
            tempoTotal += getTempos()[j - 1];
        }
    } else if (posPrimeiraParagem > posSegundaParagem) {
        for (int j = posPrimeiraParagem; j >= posSegundaParagem; j--) {
            tempoTotal += getTempos()[j - 1];
        }
    }
    return tempoTotal;
}

const int Linha::getPosParagem(string nome) {
    int toRet = -1;
    for (int i = 0; i < getParagens().size(); ++i) {
        if (paragens[i].getNome() == nome) {
            toRet = i;
        }
    }
    return toRet;
}

vector<Paragem> stringToParagens(std::vector<string> stringParagens){
  vector<Paragem> newParagens;
  //  loop atraves das virgulas
  for(string paragemString: stringParagens){
    Paragem newParagem = Paragem(trimString(paragemString));
    newParagens.push_back(newParagem);
  }
  return newParagens;
}

const int Linha::getNumeroAutocarrosNecessarios(){
  // tempo de ida e volta = 2x tempo total
  int tempo_ida_e_volta = getTempoPercurso() * 2;
  // calculo do numero
  int n = (int) ((double) tempo_ida_e_volta / getFreq() + 1.0);
  return n;
}

const int Linha::getTempoPercurso(){
  int valorFinal = 0;
  for(int valor: this->getTempos()){
    valorFinal += valor;
  }
  return valorFinal;
}

const int Linha::getUid(){
  return this->uid;
}

vector<Paragem> Linha::getParagens() const {
  return this->paragens;
}

Linha::Linha(int uid, int freq, std::vector<Paragem> paragens, std::vector<int> tempos){
  this->uid = uid;
  this->freq = freq;
  this->paragens = paragens;
  this->tempos = tempos;
}

const int Linha::getFreq(){
  return this->freq;
}

vector<int> stringsToInt(vector<string> newTemposString){
  std::vector<int> newVector;
  for(string tempoString: newTemposString){
    newVector.push_back(stoi(tempoString));
  }
  return newVector;
}

vector<int> Linha::getTempos() const {
  return this->tempos;
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

    //  configurar paragens
    vector<string> stringParagens = split(data[2],',');
    linha.paragens = stringToParagens(stringParagens);

    //  configurar tempos
    vector<string> newTemposString = split(data[3], ',');
    linha.tempos = stringsToInt(newTemposString);
  }

  return is;
}

ostream& operator<< (ostream &os, Linha &linha){

  os << linha.uid;
  os << " ; ";
  os << linha.freq;
  os << " ;";

  //  paragens
  for (unsigned int i = 0; i < linha.paragens.size(); i++) {
    if (i < linha.paragens.size()-1){
      os << " " << linha.paragens[i].getNome() << ',';
    } else {
      os << " " << linha.paragens[i].getNome() << ';';
    }
  }

  //  tempos
  for (unsigned int i = 0; i < linha.tempos.size(); i++) {
    if (i < linha.tempos.size()-1){
      os << " " << linha.tempos[i] << ',';
    } else {
      os << " " << linha.tempos[i];
    }
  }

  return os;
}
