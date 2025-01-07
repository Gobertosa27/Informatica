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

punto move(punto start, traiettoria c);

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
    int min, max, lunghezza;
    
    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    int minimo, massimo;
    while(!flussoin.eof())
    {
        if (!(flussoin>>lunghezza))
            break;
        cout<<lunghezza<<": ";

        flussoin>>tr.t;
        lunghezza=tr.t;
        if (conta == 0 || lunghezza > massimo)
            massimo = lunghezza;
        if (conta == 0 || lunghezza < minimo)
            minimo = lunghezza;
        tr.T = new char[lunghezza];
        for(int k=0; k<lunghezza; k++)
        {
            flussoin>>tr.T[k];
            cout<<tr.T[k]<<", ";
        }
        conta++;
        cout<<endl;

        // use tr

        delete[] tr.T; //evito di sovraccaricare l'array
        tr.T=NULL;
    }
    
    cout<<"Abbiamo "<<conta<<" traiettorie ";
    cout<<"con min="<<min<<" e max="<<max<<endl;
    flussoin.close();
    
    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    
    punto.arrivo=move(punto.p0, punto)

    return 0;
}
