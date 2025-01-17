#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct centro
{
    int x;
    int y;
    float m;
    int count=0;
};

struct particella
{
    float x;
    float y;
    float m;
    float minimo;
    int corr;//corrispondenza sfera
};

void shorter(centro *, particella *, int, int);

int cdm(centro *, int );

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

    int 

    delete [] c_array;
    c_array=NULL;
    delete [] p_array;
    p_array=NULL;
    return 0;

}

void shorter(centro *c, particella *p, int n_c, int n_p)
{
    float lunghezza;

    for(int k=0; k<n_p; k++)    
    {   
        cout<<"Per particella "<<k<<") il centro piu vicino e' centro: ";
        
        for(int j=0; j<n_c; j++)
        {
            lunghezza=sqrt(pow(p[k].x-c[j].x, 2)+pow(p[k].y-c[j].y, 2));
            cout<<"c["<<j<<"]="<<lunghezza<<endl;
            if(j==0)
            {
                p[k].minimo=lunghezza;
                p[k].corr=j;
            }
            if(lunghezza<p[k].minimo) 
            {
                p[k].minimo=lunghezza;
                p[k].corr=j;
            }
             
        }
        c[p[k].corr].count=c[p[k].corr].count+1;
        cout<<"--> c["<<p[k].corr<<"]="<<p[k].minimo<<endl;
    }

    cout<<endl;

    for(int k=0; k<n_c; k++)
    {
        cout<<endl<<"Centro "<<k<<": ("<<c[k].x<<", "<<c[k].y<<", "<<c[k].m<<") ";
        int count=c[k].count;
        cout<<"con "<<count<<" occorrenze"<<endl;
        for(int j=0; j<n_p; j++)
        {
            if(p[j].corr==k) 
            {
                cout<<"Particella "<<j<<": ("<<p[j].x<<", "<<p[j].y<<", "<<p[j].m<<", "<<p[j].minimo<<")"<<endl;
            }
        }
    }

    int max=0, k_max;
    for(int k=0; k<n_c; k++)
    {
        if(k==0 || c[k].count>max) 
        {
            max=c[k].count;
            k_max=k;
        }
    }
    cout<<"Il centro con piu particelle e' c["<<k_max<<"] con "<<max<<" parti."<<endl;
}

int cdm(centro *c, int n_c)
{

}
