/**
 * Author:              Brandon Williams
 * Assignment Number:   Lab Exercise 15
 * File Name:           S9_L15_WILLIAMS.cpp
 * Course/Section:      COSC 1320 44669
 * Due Date:            May 12, 2012
 * Instructor:          Prof Paul Thayer
 *
 * This program encrypts and decrypts a file (specified by user) using
 * and key also specified by user.
 *
 * Source code modified from code in
 *
 * Starting Out With C++
 * Early Objects, Seventh Edition
 * Tony Gaddis, Judy Walters, Godfrey Muganda
 * Publisher Addison-Wesley
 *
 * Copyright Respective Owners
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Abstract Encryption Class
class Encryption {
  protected:
    ifstream inFile;
    ofstream outFile;   
  public:
    Encryption(string inFileName, string outFileName);
    ~Encryption();
    virtual char transform(unsigned char ch) = 0;
    void encrypt();
};

// Encryption subclass to encrypt and decrypt a file with a key
class KeyEncryption : public Encryption {
  private:
    int key;
  public:
    char transform(unsigned char);
    void decrypt();
    KeyEncryption(string inFileName, string outFileName, int key)
    : Encryption(inFileName, outFileName),
    key(key) {}
};

int main() {
  string fileName, encFileName, decFileName;
  int key;
  
  cout << "Enter name of file to encrypt: ";
  cin >> fileName;
  
  encFileName = fileName + "Encrypted.txt";
  decFileName = fileName + "Decrypted.txt";

  cout << "Entery a integer encryption key: ";
  cin >> key;
  
  cout << endl << "Encrypting contents of " << fileName << ".txt and saving to " << encFileName << endl;
  cout << "Then decrypting contents of " << encFileName << " and saving to " << decFileName << endl;
  
  KeyEncryption obfuscate(fileName.append(".txt"), encFileName, key);
  obfuscate.encrypt();
  
  cout << endl;
  
  // Now decrypt what we just encrypted
  KeyEncryption deobfuscate(encFileName, decFileName, key);
  deobfuscate.decrypt();
  
  system("pause");
  return 0;
}

char KeyEncryption::transform(unsigned char ch) {
  /* Useful debugging
  cout << setw(4)
       << static_cast<int>(ch) << ":" << static_cast<char>(ch)
       << " " << this->key << " "
       << static_cast<int>(ch + this->key) << ":" << static_cast<char>(ch + this->key)
       << endl;
  */
  return ch + this->key;
}

void KeyEncryption::decrypt() {
  this->key = this->key * -1;
  this->encrypt();
}

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(string inFileName, string outFileName) {
  inFile.open(inFileName.data());
  outFile.open(outFileName.data());
  if (!inFile) {
    cout <<  "The file " << inFileName 
         << " cannot be opened.";
    system("pause");
    exit(1);
  }
  
  if (!outFile) {
    cout << "The file " << outFileName
         << " cannot be opened.";
    system("pause");
    exit(1);
  }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption() {
  inFile.close();
  outFile.close(); 
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//***************************************************** 
void Encryption::encrypt() {
  char ch;
  char transCh;
  inFile.get(ch);
  while (!inFile.fail()) {
    transCh = transform(ch);
    outFile.put(transCh);
    inFile.get(ch);
  }
  outFile.flush();
}

/*
 Sample Output

Enter name of file to encrypt: input
Entery a integer encryption key: 140

Encrypting contents of input.txt and saving to inputEncrypted.txt
Then decrypting contents of inputEncrypted.txt and saving to inputDecrypted.txt

Press any key to continue . . .

input.txt
---------
This is a test

inputEncrypted.txt
------------------
ΰτυÿ¬υÿ¬ν¬ ρÿ –

inputDecrypted.txt
------------------
This is a test


*/

