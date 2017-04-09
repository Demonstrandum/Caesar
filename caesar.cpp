#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool IsInArray(string array, char element) {
  for(int i = 0; i < array.length(); i++){
     if(array[i] == element){
         return true;
     }
  }
  return false;
}
string rot(int n, string str) {
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  string alph = "abcdefghijklmnopqrstuvwxyz";
  string ciph = alph;
  rotate(ciph.begin(), ciph.begin() + n, ciph.end());

  int i = 0;
  int j = 0;
  while (i < str.length()) {
    if (IsInArray(alph, str[i])) {
      if (str[i] == alph[j]) {
        str[i] = ciph[j];
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
    cout << "Enter valid arguments." << endl;
  }
  cout << rot(rotation, content);
  return 0;
}
