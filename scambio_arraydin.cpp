#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void scambiafloat(float *, float *);
void scambiaint(int *, int *);
void ordinamentoint(int *, int*);

int main()
{
   int *p1, *p2;//puntatore = contenuto dell'indirizzo a cui il puntatore punta
   
   int n;
   cout<<"Inserire numero di el. da inserire: ";
   cin>>n;

   cout<<"Inserire vettori di "<<n<<" el. interi:"<<endl;
   p1=new int[n]; /*n*sizeof(float) restituisce l'indirizzo a cui è allocato dinamicamente l'array e, poi,
   p1 ne legge il valore nella cella*/
   p2=new int[n];
    int i=0;
    while(i<=n)
    {
        cout<<"p1["<<i<<"]=";
        cout<<"("<<&p1[i]<<")";
        cin>>p1[i];
       
        cout<<"p2["<<i<<"]=";
        cout<<"("<<&p2[i]<<")";
        cin>>p2[i];
        
        i=i+1;
    }

    scambiaint(p1, p2);
    i=0;
    cout<<endl<<"Scambio el. dei 2 vettori:"<<endl;
    while(i<=n)
    {
        cout<<"p1["<<i<<"]=";
        cout<<p1[i]<<endl;

        cout<<"p2["<<i<<"]=";
        cout<<p2[i]<<endl;

        i=i+1;
    }



    delete [] p1, p2;
    p1=NULL;
    p2=NULL;
    return 0;
}

void scambiaint(int *p1, int *p2)
{
    int appo;
    appo=*p1;
    *p1=*p2;
    *p2=appo;
}

void ordinamento (int *p1, int *p2)
{
    
}
