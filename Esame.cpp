#include <iostream>
#include <fstream>
#include <cmath>

struct punto //definisce un nuovo tipo di variabile (del tipo int, float ecc..)
{
    int x, y;
};

struct traiettoria
{
    int t; //lunghezza traiettoria
    char *T; //array di t-comandi di movim
};

using namespace std;

int main()
{
    punto *p=NULL;
    traiettoria tr;
    int n=0, dato;
    ifstream flussoin;   
    flussoin.open("punti.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    while(!flussoin.eof())
    {
        flussoin>>dato;
        n++;
    }

    flussoin.close();
    n=n/2;
    p=new punto[n];

    flussoin.open("punti.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    for(int k=0; k<n; k=k+1)
    {
        flussoin>>p[k].x;
        flussoin>>p[k].y;
    }

    flussoin.close();

    cout<<"Abbiamo in totale "<<n<<" punti di coordinate:"<<endl;
    for(int k=0; k<n; k=k+1)
    {
        cout<<"Punto "<<k<<") ("<<p[k].x<<","<<p[k].y<<")"<<endl;
    }

    cout<<endl<<"Caricamento traiettorie"<<endl;
    int conta=0;
    
    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    while(!flussoin.eof())
    {
        flussoin>>tr.t;
        cout<<tr.t<<": ";
        tr.T=new char[tr.t];
        for(int k=0; k<tr.t; k++)
        {
            flussoin>>tr.T[k];
            cout<<tr.T[k]<<", ";
        }
        conta++;
        cout<<endl;
    }
    conta=conta-1; //eof conta un el. in piu
    
    cout<<"Abbiamo "<<conta<<" traiettorie"<<endl;
    flussoin.close();

    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    traiettoria *tray;
    tray=new traiettoria[conta];
    for(int k=0; k<conta; k++)
    {
        flussoin>>tray[k].t;
        cout<<tray[k].t<<": ";
        tray[k].T=new traiettoria[k]
        for(int j=0; j<tray[k].t ; j++)
        {
            flussoin>>tray[k].T[j];
            cout<<tray[k].T[j]<<", ";
        }
        cout<<endl;
    }
    flussoin.close();


}
