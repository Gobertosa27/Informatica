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

    int conta=0;
    int lunghezza;
    
    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    int minimo=0, massimo=0;
    while(!flussoin.eof())//conta tray
    {
        flussoin>>lunghezza;
        if (flussoin.fail())
            break;
        tr.t=lunghezza;
        tr.T=new char[tr.t];
        if (conta == 0 || lunghezza > massimo)
            massimo = lunghezza;
        if (conta == 0 || lunghezza < minimo)
            minimo = lunghezza;
        // tr.T = new char[tr.t];
        for(int k=0; k<lunghezza; k++)
        {
            flussoin>>tr.T[k];
        }
        conta++;
        delete [] tr.T;
        tr.T=NULL;
    }
    
    cout<<"Abbiamo "<<conta<<" traiettorie ";
    cout<<"con min="<<minimo<<" e max="<<massimo<<endl;
    flussoin.close();
    
    traiettoria *tray=NULL;
    tray=new traiettoria[conta];

    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    int scelta;
    punto p0;
    traiettoria c;
    do
    {
        cout<<"Inserisci il punto che ti interessa p[0,"<<n-1<<"]: ";
        cin>>scelta;
    } while (scelta<0 || scelta>n-1);
    p0=p[scelta];

    int k=0;
    while(!flussoin.eof())
    {
        
         flussoin>>lunghezza;
        if (flussoin.fail())
            break;
        cout<<"Traiettroia "<<k<<") "<<lunghezza<<": ";

        tr.t=lunghezza;
        tray[k].t=tr.t;
        tray[k].T = new char[lunghezza];
        for(int j=0; j<lunghezza; j++)
        {
            flussoin>>tray[k].T[j];
            cout<<tray[k].T[j]<<", ";
        }
        cout<<endl;
        k++;
    }

     do
    {
        cout<<"Inserisci la traiettoria che ti interessa t[0,"<<k-1<<"]: ";
        cin>>scelta;
    } while (scelta<0 || scelta>k-1);
    c=tray[scelta];
    
    punto arrivo=move(p0, c);
    

    flussoin.close();
    delete [] p;
    p=NULL;
    delete [] tray;
    tray=NULL;
    return 0;
}

punto move(punto start, traiettoria c)
{
    punto nuovo_punto;
    nuovo_punto.x=start.x;
    nuovo_punto.y=start.y;
    cout<<"Punto iniziale: p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
    for (int  k=0; k<c.t; k++)
    {
        if(c.T[k]=='W')
        {
            cout<<"Spostamento verso ovest: ";
            nuovo_punto.x=nuovo_punto.x-1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='N')
        {
            cout<<"Spostamento verso nord: ";
            nuovo_punto.y=nuovo_punto.y+1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='E')
        {
            cout<<"Spostamento verso est: ";
            nuovo_punto.x=nuovo_punto.x+1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='S')
        {
            cout<<"Spostamento verso sud: ";
            nuovo_punto.y=nuovo_punto.y-1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if((c.T[k]!='W')&&(c.T[k]!='N')&&(c.T[k]!='E')&&(c.T[k]!='S')) cout<<"Indicazione non valida!!"<<endl;
    }
    return nuovo_punto;
}
