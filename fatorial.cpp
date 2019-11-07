#include <iostream>
using namespace std;
int fatorial(int n) {
    int result = 1;
    if(n < 0) {
        result = 0;
    } else if(n == 0) {
        result = 1;
    } else {
        for(int i = 1; i <= n; i++) {
            result *= i;
        }
    }
    return result;
}

int main(void) {
    int numero;
    cout<<"Insert a number: ";
    cin>>numero;
    cout<<"Fatorial de "<<numero<<" = "<<fatorial(numero)<<"\n";
}
