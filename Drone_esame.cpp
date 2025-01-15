#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h>

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
    srand(time(NULL));
    
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
    
    int *select;
    punto *R=NULL;
    traiettoria *c=NULL;

    flussoin.open("traiettorie.dat");

    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    cout<<endl<<"Quanti droni hai? ";
    cout<<n<<endl;

    R=new punto[n];
    c=new traiettoria[n];
    select=new int[n];

    cout<<"Inserisci le posizioni iniziali dei droni p[0,"<<n-1<<"]: "<<endl;
    for(int k=0; k<n; k++)
    {
        R[k]=p[k];
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
    for(int j=0; j<n; j++)
    {
        int m=k-1;
        int scelta;
        cout<<"Drone "<<j<<") tray=";
        scelta=rand()%m;
        cout<<scelta<<endl; 
        select[j]=scelta;
        c[j]=tray[scelta];
    }

    int q;
    
    q=num_first_quad(R, n, c);
    cout<<endl<<"IN TOTALE il numero di droni nel 1-quadr e' "<<q<<endl;
    cout<<endl;
    
    bool esito;
    int count=0;
    for(int k=0; k<n; k++)
    {
        punto p0=R[k];
        traiettoria c0=c[k];
        for(int j=k+1; j<n; j++)
        {
            
            cout<<endl<<"Drone "<<k<<" (tray "<<select[k]<<") collide con drone "<<j<<" (tray"<<select[j]<<")?"<<endl;
            punto p1=R[j];
            traiettoria c1=c[j];
            bool esito;
            esito=collision(p0, p1, c0, c1);
            if(esito==true) 
            {
                cout<<endl<<"Yes, drone "<<k<<" collide con drone "<<j<<"!!"<<endl;
                count++;
            }
            else cout<<endl<<"No, drone "<<k<<" NON collide con drone "<<j<<"!!"<<endl;    
        }
    }

    flussoin.close();

    ofstream flussout;

    flussout.open("risultati.dat");

    if(flussout.fail())
    {
        cout<<"errore apertura file!"<<endl;
        return -1;
    }

    flussout<<"Numero di droni:"<<n<<endl;
    flussout<<"Numero di droni sul primo quadr.:"<<q<<endl;
    flussout<<"Traiettorie num:"<<conta<<endl;
    flussout<<"Num collisioni:"<<count<<endl;

    flussout.close();

    
    delete [] p;
    p=NULL;
    delete [] tray;
    tray=NULL;
    delete [] R;
    R=NULL;
    delete [] c;
    c=NULL;
    delete [] select;
    select=NULL;

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
            cout<<"Spostamento W: ";
            nuovo_punto.x=nuovo_punto.x-1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='N')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento N: ";
            nuovo_punto.y=nuovo_punto.y+1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='E')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento E: ";
            nuovo_punto.x=nuovo_punto.x+1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if(c.T[k]=='S')
        {
            cout<<"Mossa "<<k<<": ";
            cout<<"Spostamento S: ";
            nuovo_punto.y=nuovo_punto.y-1;
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
        if((c.T[k]!='W')&&(c.T[k]!='N')&&(c.T[k]!='E')&&(c.T[k]!='S')) 
        {
            cout<<"Mossa "<<k<<" errata: ";
            cout<<"p=("<<nuovo_punto.x<<","<<nuovo_punto.y<<")"<<endl;
        }
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
        cout<<endl<<"Inizio spostamento per drone "<<k<<" con ";
        p0=R[k];
        c0=c[k];
        cout<<c0.t<<" spostamenti"<<endl;
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

bool collision( punto p, punto q, traiettoria Cp, traiettoria Cq )
{
    int k=0, j=0;
    cout<<"p0=("<<p.x<<","<<p.y<<") ";
    cout<<"con "<<Cp.t<<" spostamenti"<<endl;
    cout<<"q0=("<<q.x<<","<<q.y<<") ";
    cout<<"con "<<Cq.t<<" spostamenti"<<endl;
    if((p.x==q.x)&&(p.y==q.y)) 
    {
        cout<<"Collisione immediata!"<<endl;
        return true;
    }
    while(k<Cp.t || j<Cq.t)
    {
        cout<<endl;
        if(k<Cp.t)
        {
            cout<<k<<") ";
            if(Cp.T[k]=='W') 
                {
                    p.x=p.x-1;
                    cout<<"W: ";
                    cout<<"p=("<<p.x<<","<<p.y<<")"<<endl;
                }
            
            if(Cp.T[k]=='N') 
                {
                    p.y=p.y+1;
                    cout<<"N: ";
                    cout<<"p=("<<p.x<<","<<p.y<<")"<<endl;
                }
            if(Cp.T[k]=='E') 
                {
                    p.x=p.x+1;
                    cout<<"E: ";
                    cout<<"p=("<<p.x<<","<<p.y<<")"<<endl;
                }
            if(Cp.T[k]=='S') 
                {
                    p.y=p.y-1;
                    cout<<"S: ";
                    cout<<"p=("<<p.x<<","<<p.y<<")"<<endl;
                }
            if((Cp.T[k]!='W')&&(Cp.T[k]!='N')&&(Cp.T[k]!='E')&&(Cp.T[k]!='S'))
            {
                cout<<"Error: ";
                cout<<"p=("<<p.x<<","<<p.y<<")"<<endl;
            }
            k++;
        }
        else cout<<"fine) p=("<<p.x<<","<<p.y<<")"<<endl;
        
        if(j<Cq.t)
        {
            cout<<j<<") ";
            if(Cq.T[j]=='W') 
                {
                    q.x=q.x-1;
                    cout<<"W: ";
                    cout<<"q=("<<q.x<<","<<q.y<<")"<<endl;
                }
            
            if(Cq.T[j]=='N') 
                {
                    q.y=q.y+1;
                    cout<<"N: ";
                    cout<<"q=("<<q.x<<","<<q.y<<")"<<endl;
                }
            if(Cq.T[j]=='E') 
                {
                    q.x=q.x+1;
                    cout<<"E: ";
                    cout<<"q=("<<q.x<<","<<q.y<<")"<<endl;
                }
            if(Cq.T[j]=='S') 
                {
                    q.y=q.y-1;
                    cout<<"S: ";
                    cout<<"q=("<<q.x<<","<<q.y<<")"<<endl;
                }
            if((Cq.T[j]!='W')&&(Cq.T[j]!='N')&&(Cq.T[j]!='E')&&(Cq.T[j]!='S'))
                {
                    cout<<"Error: ";
                    cout<<"q=("<<q.x<<","<<q.y<<")"<<endl;
                }
            j++;
        }
        else cout<<"fine) q=("<<q.x<<","<<q.y<<")"<<endl;
        
        if((p.x==q.x)&&(p.y==q.y)) 
            {
                cout<<"Collisione dopo "<<k<<" spost. del primo drone e "<<j<<" spost. del secondo"<<endl;
                return true;
            }
    }
    cout<<endl<<"Niente da segn."<<endl;
    return false;
}
