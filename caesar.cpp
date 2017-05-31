#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

bool IsInString(string str, char element) {
  for(unsigned int i = 0; i < str.length(); i++) {
     if(str[i] == element){
         return true;
     }
  }
  return false;
}

string rot(int n, string str) {
  if (n > 26 || n < -26)
    return "\nRotation integer out of range!\nPlease choose a number between -26 and 26!\n";

  if (n < 0)
    n += 26;

  string alph = "abcdefghijklmnopqrstuvwxyz";
  string ciph = alph;
  rotate(ciph.begin(), ciph.begin() + n, ciph.end());

  string upperAlph = alph;
  string upperCiph = ciph;
  transform(upperAlph.begin(), upperAlph.end(), upperAlph.begin(), ::toupper);
  transform(upperCiph.begin(), upperCiph.end(), upperCiph.begin(), ::toupper); // or alph.upcase in Ruby or alph.upper() in Python...

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

  if (string(argv[2]) == "text") {
    content = string(argv[3]);
  }
  else if (string(argv[2]) == "file") {
    string fileName = string(argv[3]);
    ifstream ifs(fileName);
    content.assign( (istreambuf_iterator<char>(ifs) ),
                    (istreambuf_iterator<char>()    ) );
  }
  else {
    cout << "Please choose a way of retrieving the input (text or file)." << endl;
    return 1;
  }

  string strRotation = argv[1];
  if (strRotation == "bruteforce" || strRotation == "brute" || strRotation == "force") {
    for (unsigned int i = 25; i >= 1; i--) {
      stringstream list;
      list << setfill('0') << setw(2) << -(i - 26); // Adds padding with '0's, e.g. {5 => 05, 14 => 14} etc...
      cout << list.str() << " => " << rot(i, content) << endl; // ^^^ (i - 26) * -1 to reverse the numbers because brute force decrypts, showing the encryption number as opposed to the decryption number
    }
    return 0;
  }

  int rotation = atoi(strRotation.c_str());
  cout << rot(rotation, content);
  return 0;
}
