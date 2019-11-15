#include <iostream>
#include <string>
using namespace std;

int main() {
  string greeting = "Hello, ";
  cout << greeting;

  string firstName = "John ";
  string lastName = "Doe \n";
  string fullName = firstName + lastName;
  cout << fullName;

  string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cout << "The length of the txt string is: " << txt.length() << endl;

  string myString = "Hello";
  cout << myString[0] << endl;

  myString[0] = 'J';
  cout << myString << endl;

  string fullName2;
  cout << "Type your full name: "; 
  getline (cin, fullName2);
  cout << "Your name is: " << fullName2 << endl;



  return 0;
}
