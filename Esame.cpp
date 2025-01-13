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

punto move(punto, traiettoria );
int num_first_quad( punto* , int , traiettoria* );
bool collision( punto p, punto q, traiettoria Cp, traiettoria Cq );

int main()
{
    punto *p=NULL;
    traiettoria tr;
    int n=0, dato, lunghezza;

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

     cout<<"Abbiamo in totale "<<n<<" punti di coordinate:"<<endl;
    for(int k=0; k<n; k=k+1)
    {
        cout<<"Punto "<<k<<") ("<<p[k].x<<","<<p[k].y<<")"<<endl;
    }

    flussoin.close();

    int conta=0;
    
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
        delete [] tr.T;//evito sovraccarichi di array
        tr.T=NULL;
    }

    flussoin.close();
    
    traiettoria *tray=NULL;
    tray=new traiettoria[conta];
    
    int r;
    punto *R=NULL;
    traiettoria *c=NULL;
    int scelta;

    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    cout<<endl<<"Quanti droni hai? ";
    do
    {
        cin>>r;
    }
    while(r<=0);

    R=new punto[r];
    c=new traiettoria[r];

    cout<<"Inserisci le posizioni iniziali dei droni p[0,"<<n-1<<"]: "<<endl;
    for(int k=0; k<r; k++)
    {
        do
        {
            cout<<"Drone "<<k<<") pos=";
            cin>>scelta;
        } 
        while (scelta<0 || scelta>n-1);
        R[k]=p[scelta];
    }

    cout<<endl<<"Abbiamo "<<conta<<" traiettorie ";
    cout<<"con min="<<minimo<<" e max="<<massimo<<": "<<endl;

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

    cout<<endl<<"Inserisci la traiettoria per il tuo drone t[0,"<<k-1<<"]: "<<endl;
    for(int j=0; j<r; j++)
    {
        do
        {
            cout<<"Drone "<<j<<") tray=";
            cin>>scelta;
        } 
        while (scelta<0 || scelta>k-1);
        c[j]=tray[scelta];
    }

    int q;
    bool esito;
    
    q=num_first_quad(R, r, c);
    for(int k=0; k<r; k++)
    {
        punto p0=R[k];
        traiettoria c0=c[k];
        for(int j=k+1; j<r; j++)
        {
            if(j!=r-1)
            {
                punto p1=R[j];
                traiettoria t1=c[j];
                bool esito;
                esito=collision(p0, p1, t0, t1);
            }    
        }
    }
    
    cout<<endl<<"Il numero di droni nel 1-quadr e' "<<q<<endl;

    flussoin.close();
    
    delete [] p;
    p=NULL;
    delete [] tray;
    tray=NULL;
    delete [] R;
    R=NULL;
    delete [] c;
    c=NULL;

    return 0;
}

punto move(punto start, traiettoria c)
{
    punto nuovo_punto;
    nuovo_punto.x=start.x;
    nuovo_punto.y=start.y;
    cout<<"Posizione iniziale: p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
    for (int  k=0; k<c.t; k++)
    {
        if(c.T[k]=='W')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento verso ovest: ";
            nuovo_punto.x=nuovo_punto.x-1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='N')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento verso nord: ";
            nuovo_punto.y=nuovo_punto.y+1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='E')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento verso est: ";
            nuovo_punto.x=nuovo_punto.x+1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='S')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento verso sud: ";
            nuovo_punto.y=nuovo_punto.y-1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if((c.T[k]!='W')&&(c.T[k]!='N')&&(c.T[k]!='E')&&(c.T[k]!='S')) cout<<"Mossa "<<k<<": indicazione non valida!!"<<endl;
    }
    return nuovo_punto;
}

int num_first_quad(punto *R, int r, traiettoria *c)
{
    int conta=0;
    punto p0;
    traiettoria c0;
    for(int k=0; k<r; k++)
    {
        cout<<endl<<"Inizio spostamento per drone "<<k<<")"<<endl;
        p0=R[k];
        c0=c[k];
        R[k]=move(p0, c0);
        if(R[k].x>0 && R[k].y>0) 
        {
            cout<<endl<<"Il drone "<<k<<" finisce nel 1-quadr con p=("<<R[k].x<<","<<R[k].y<<")"<<endl;
            conta++;
        }
        else cout<<endl<<"Il drone "<<k<<" NON puo' finire nel 1-quadr con p=("<<R[k].x<<","<<R[k].y<<")"<<endl;
    }
    return conta;
}
