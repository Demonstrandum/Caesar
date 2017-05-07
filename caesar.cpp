#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool IsInString(string str, char element) {
  for(unsigned int i = 0; i < str.length(); i++){
     if(str[i] == element){
         return true;
     }
  }
  return false;
}

string rot(int n, string str) {
  if (n > 26 || n < -26) {
    return "\nRotation integer out of range!\nPlease choose a number between -26 and 26!\n";
  }
  if (n < 0) {
    n += 26;
  }
  string alph = "abcdefghijklmnopqrstuvwxyz";
  string ciph = alph;
  rotate(ciph.begin(), ciph.begin() + n, ciph.end());

  string upperAlph = alph;
  string upperCiph = ciph;
  transform(upperAlph.begin(), upperAlph.end(), upperAlph.begin(), ::toupper);
  transform(upperCiph.begin(), upperCiph.end(), upperCiph.begin(), ::toupper);

  unsigned int i = 0;
  unsigned int j = 0;

  while (i < str.length()) {
    if (IsInString(alph, str[i]) || IsInString(upperAlph, str[i])) {
      if (str[i] == alph[j]) {
        str[i] = ciph[j];
        i++;
        j = 0;
      }
      else if (str[i] == upperAlph[j]) {
        str[i] = upperCiph[j];
        i++;
        j = 0;
      }
      else {
        j++;
      }
    }
    else {
      i++;
    }
  }
  return str;
}

int main(int argc, char** argv) {
  if (argc < 4) {
    cout << "Please supply a valid number of arguments." << endl;
    return 1;
  }
  string content;
  string strRotation = argv[1];
  int rotation = atoi(strRotation.c_str());
  if (string(argv[2]) == string("text")) {
    content = string(argv[3]);
  }
  else if (string(argv[2]) == string("file")) {
    string fileName = string(argv[3]);
    ifstream ifs(fileName);
    content.assign( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>()    ) );
  }
  else {
    cout << "Please choose a way of retrieving the input (text or file)." << endl;
    return 1;
  }
  cout << rot(rotation, content);
  return 0;
}
