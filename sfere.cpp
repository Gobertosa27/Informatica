#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    float *diam;
    char *color;
    int ndati=0;

     
    ifstream flusso_in;
    flusso_in.open("sfere.dat");

    if(flusso_in.fail())
    {
        cout<<"Problema apertura file! Esco!"<<endl;
        return -1;
    }

    float ndiam;
    char ncol;
    while(!flusso_in.eof())
    {
        flusso_in>>ndiam;
        flusso_in>>ncol;
        ndati++;
    }
    
    flusso_in.close(); 
    
    ndati=ndati-1;
    cout<<"Ho "<<ndati<<" dati"<<endl;
    
    flusso_in.open("sfere.dat");

    diam=new float[ndati];
    color=new char[ndati];

    if(flusso_in.fail())
    {
        cout<<"Problema apertura file! Esco!"<<endl;
        return -1;
    }

    for(int i=0; i<ndati; i=i+1)
    {
        flusso_in>>diam[i];
        flusso_in>>color[i];
        
        cout<<"Sfera "<<i<<") d="<<diam[i]<<" e colore="<<color[i]<<endl;
    }

    if((diam==NULL)||(color==NULL))
    {
        cout<<"Non c'e' nulla!"<<endl;
        return -1;
    }
    
    flusso_in.close(); 

    return 0; 
}
