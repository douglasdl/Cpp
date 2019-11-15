#include <iostream>
using namespace std;

// This is a comment

/* This is
a comment too */
int main() {
  cout << "Hello World! \n";
  cout << "Hello World!" << endl;

  //int myNum = 15;
  int myNumber;
  myNumber = 15;
  cout << myNumber << endl;

  const int myConst = 15;  // myNum will always be 15
  
  int myNum = 5;               // Integer (whole number without decimals)
  double myFloatNum = 5.99;    // Floating point number (with decimals)
  char myLetter = 'D';         // Character
  string myText = "Hello";     // String (text)
  bool myBoolean = true;       // Boolean (true or false)

  int myAge = 35;
  cout << "I am " << myAge << " years old." << endl;

  int x = 5;
  int y = 6;
  int sum = x + y;
  cout << sum << endl;
  

  return 0;
}