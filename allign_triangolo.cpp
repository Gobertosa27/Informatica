#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>

using namespace std;

struct punto 
{ 
    float x, y; 
};

bool aligned( punto p, punto q, punto r );

int main()
{
    srand(time(NULL));
    punto p1;
    punto p2;
    punto p3;
    cout<<"Inserisci punti trangolo:"<<endl;
    cout<<"p1_x=";
    cin>>p1.x;
    cout<<"p1_y=";
    cin>>p1.y;
    
    cout<<endl<<"p2_x=";
    cin>>p2.x;
    cout<<"p2_y=";
    cin>>p2.y;
    
    cout<<endl<<"p3_x=";
    cin>>p3.x;
    cout<<"p3_y=";
    cin>>p3.y;

    bool esito;
    esito=aligned(p1, p2, p3);
    if(esito==true) cout<<"I tre punti sono allineati!"<<endl;
    else cout<<"I tre punti NON sono allineati!"<<endl;

    cout<<"Vettore di 100 punti"<<endl;
    int d=100;
    punto *p=NULL;
    p=new punto[d];
    for(int k=0; k<d; k++)
    {
        p[k].x=(rand()%201-100)/10.f;
        p[k].y=(rand()%201-100)/10.f;
        cout<<"p["<<k<<"]=("<<p[k].x<<", "<<p[k].y<<")"<<endl;
    }

    for(int k=0; k<d; k++)
    {
        for(int j=k+1; j<d; j++)
        {
            for(int l=j+1; l<d; l++)
            {
                p1=p[k];
                p2=p[j];
                p3=p[l];
                esito=aligned(p1, p2, p3);
                if(esito==true) 
                {
                    cout<<"I tre punti k="<<k<<", j="<<j<<", l="<<l<<" sono allineati!"<<endl;
                    {
                        cout<<"p["<<k<<"]=("<<p[k].x<<", "<<p[k].y<<")"<<endl;
                        cout<<"p["<<j<<"]=("<<p[j].x<<", "<<p[j].y<<")"<<endl;  
                        cout<<"p["<<l<<"]=("<<p[l].x<<", "<<p[l].y<<")"<<endl; 
                    }           
                }
            }
        }
    }

   delete [] p;
   p=NULL;
    return 0;
}

bool aligned( punto p, punto q, punto r )
{
    float a=sqrt(pow(p.x-q.x, 2)+pow(p.y-q.y, 2));
    float b=sqrt(pow(p.x-r.x, 2)+pow(p.y-r.y, 2));
    float c=sqrt(pow(q.x-r.x, 2)+pow(q.y-r.y, 2));
    float pm=(a+b+c)/2;
    float A=sqrt(pm*(pm-a)*(pm-b)*(pm-c));
    if(A==0) 
    {
        cout<<endl<<"a="<<a<<", b="<<b<<", c="<<c<<endl;
        cout<<"mezzo perimetro="<<pm<<endl;
        cout<<"Area="<<A<<endl;
        return true;
    }
    else return false;
}
