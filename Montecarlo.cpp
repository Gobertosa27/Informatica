#include "libcas.h"
#include <iostream>

using namespace std;

bool insidecircle(double , double);
int countWithin(int, double);

struct Punto
{
    double *x;
    double *y;
};


int main()
{
    srand(time(NULL));
    Punto punto;

    double lato=1; 
    double r;
    r=lato;

    int n, k;
    n=rand()%50;
    cout<<"Ora estraggo "<<n<<" coordinate:"<<endl;
    k=countWithin(n, r);
    cout<<"I punti interni sono "<<k<<"/"<<n<<endl;
    return 0;
}

int countWithin(int n, double r)
{
    double *p_x; 
    double *p_y;
    double pquadr;
    p_x=new double[n];
    p_y=new double[n];

    for(int k=0; k<n; k=k+1)
    {
          do
        {
            p_x[k]=(double)(rand()/RAND_MAX);
            p_y[k]=(double)(rand()/RAND_MAX);
        } 
        while((p_x[k]<0 || p_y[k]<0)||(p_x[k]>2*r || p_y[k]>2*r));
        cout<<"p_x["<<k<<"]="<<p_x[k]<<endl;
        cout<<"p_y["<<k<<"]="<<p_y[k]<<endl;
    }
    
    int i=0;
     for(int k=0; k<n; k=k+1)
    {
        bool esito;
        pquadr=pow(p_x[k], 2)+pow(p_y[k], 2);
        esito=insidecircle(pquadr, r);
        if(esito=='0') i++;
    }
    return i;
}

bool insidecircle(double p, double r)
{
    cout<<p<<"<"<<pow(r, 2)<<"?"<<endl;
    if(p<pow(r, 2)) return true;
    else return false;
}
    
