#include <iostream>

using namespace std;

void funzione(int);

int main()
{
    int n;
    cout<<"Inserisci un numero int: ";
    cin>>n;

    funzione(n);
    return 0;
}

void funzione(int n)
{
    if(n>1) 
    {
         cout<<"Inizio funzione con n="<<n<<endl;

        funzione(n-1);
        funzione(n-2);

        cout<<"Fine funzione con n="<<n<<endl;
    }
    else 
    {
        cout<<"Finito con n="<<n<<endl;
        return;
    }

   
}
