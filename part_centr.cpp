#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct centro
{
    int x;
    int y;
    float m;
};

struct particella
{
    float x;
    float y;
    float m;
};

void shorter(centro *, particella *, int, int);

int main ()
{
    centro c;
    int n_centri=0;
    
    ifstream flussoin;

    flussoin.open("lab03feb2016_centri.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        if(!(flussoin>>c.x)) break;
        // flussoin>>c.x;
        flussoin>>c.y;
        flussoin>>c.m;
        n_centri++;
    }

    flussoin.close();

    cout<<"Abbiamo "<<n_centri<<" centri di coordinate:"<<endl;

    centro *c_array=NULL;
    c_array=new centro[n_centri];
    
    flussoin.open("lab03feb2016_centri.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        for(int k=0; k<n_centri; k++)
        {    
            if(!(flussoin>>c_array[k].x)) break;
            // flussoin>>c.x;
            cout<<"c["<<k<<"]=("<<c_array[k].x<<", ";
            flussoin>>c_array[k].y;
            cout<<c_array[k].y<<", ";
            flussoin>>c_array[k].m;
            cout<<c_array[k].m<<")"<<endl;
        }
    }

    flussoin.close();
    cout<<endl;

    particella p;
    int n_particelle=0;

    flussoin.open("lab03feb2016_particelle.dat");

      
    if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }
    
    while(!(flussoin.eof()))
    {
        if(!(flussoin>>p.x)) break;
        // flussoin>>c.x;
        flussoin>>p.y;
        flussoin>>p.m;
        n_particelle++;
    }

    flussoin.close();

    cout<<"Abbiamo "<<n_particelle<<" particelle di coordinate:"<<endl;
    
    particella *p_array=NULL;
    p_array=new particella[n_particelle];
    
    flussoin.open("lab03feb2016_particelle.dat");

     if(flussoin.fail())
    {
        cout<<"Errore apertura file!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        for(int k=0; k<n_particelle; k++)
        {    
            if(!(flussoin>>p_array[k].x)) break;
            // flussoin>>c.x;
            cout<<"p["<<k<<"]=("<<p_array[k].x<<", ";
            flussoin>>p_array[k].y;
            cout<<p_array[k].y<<", ";
            flussoin>>p_array[k].m;
            cout<<p_array[k].m<<")"<<endl;
        }
    }

    flussoin.close();
    cout<<endl;

    cout<<"Ricerca (centro, particella) t.c. c e p siano piu vicini!"<<endl;

    shorter(c_array, p_array, n_centri, n_particelle);

    return 0;

}

void shorter(centro *c, particella *p, int n_c, int n_p)
{
    float lunghezza, minimo;
    int c_corrispondente;

    for(int k=0; k<n_p; k++)    
    {
        cout<<"Per particella "<<k<<") il centro piu vicino e' centro: "<<endl;
        for(int j=0; j<n_c; j++)
        {
            lunghezza=sqrt(pow(p[k].x-c[j].x, 2)+pow(p[k].y-c[j].y, 2));
            if(j==0)
            {
                minimo=lunghezza;
                c_corrispondente=j;
            }
            if(lunghezza<minimo) 
            {
                minimo=lunghezza;
                c_corrispondente=j;
            }
            cout<<""
        }
        cout<<c_corrispondente<<")"<<endl;
    }
}