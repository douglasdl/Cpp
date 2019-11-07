#include <iostream>
using namespace std;
int fatorial(int n) {
   if(n < 0) {
       return 0;
   } else if(n > 1) {
       return n*fatorial(n-1);
   } else {
       return 1;
   }
}
int main(void) {
   int numero;
   cout<<"Insert a number: ";
   cin>>numero;
   cout<<"Fatorial de "<<numero<<" = "<<fatorial(numero)<<"\n";
}