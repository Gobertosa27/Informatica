#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main ()
{
    int dati[10], dato, conta=0;
    ifstream flusso_in; 
    flusso_in.open("dati_int.dat");
    
    if(flusso_in.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }

    for(int k=0; k<10; k=k+1)
    {
        flusso_in>>dati[k];
    }
    
    flusso_in.close();

    //Riapro file
    flusso_in.open("dati_int.dat");

    flusso_in >> dato;
    
    if(flusso_in.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }
    
    while(!flusso_in.eof())
    {
      conta=conta+1;

      flusso_in >> dato;
    }

    cout<<endl<<"Sono presenti "<<conta<<" dati interi"<<endl;

    int dati_used;
    dati_used=conta;

    cout<<"Vettore ha:";

    for(int k=0; k<dati_used; k=k+1)
    {
        cout<<endl<<dati[k];
    }
    cout<<endl;
    flusso_in.close();

    return 0;
}
