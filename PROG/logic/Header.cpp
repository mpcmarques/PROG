#include "Header.hpp"

vector<string> split(string str, char delimiter) {
  vector<string> toReturn;
  stringstream ss(str); // Transforma a string numa stream
  string info;

  while(getline(ss, info, delimiter)) {
    toReturn.push_back(info);
  }

  return toReturn;
}
