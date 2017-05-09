#include "Utility.hpp"

vector<string> split(string str, char delimiter) {
  vector<string> toReturn;
  stringstream ss(str); // Transforma a string numa stream
  string info;

  while(getline(ss, info, delimiter)) {
    toReturn.push_back(info);
  }

  return toReturn;
}

string trimString(const string& str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
