#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void scambiafloat(float *, float *);
void scambiaint(int *, int *);
void ordinamentoint(int *, int*, int);

int main()
{
   int *p1, *p2;//puntatore = valore dell'indirizzo della cella che viene selezionato dal puntatore
   
   int n;
   cout<<"Inserire numero di el. da inserire: ";
   cin>>n;

   cout<<"Inserire vettori di "<<n<<" el. interi:"<<endl;
   p1=new int[n]; /*n*sizeof(float) restituisce l'indirizzo a cui è allocato dinamicamente l'array e, poi,
   p1 ne legge il valore nella cella (perche è variabile puntatore)*/
   p2=new int[n];
    int i=0;
    while(i<=n)
    {
        cout<<"p1["<<i<<"]";
        cout<<"("<<&p1[i]<<")=";
        cin>>p1[i];
       
        cout<<"p2["<<i<<"]";
        cout<<"("<<&p2[i]<<")=";
        cin>>p2[i];
        
        cout<<endl;
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

        cout<<endl;
        i=i+1;
    }

    ordinamentoint(p1, p2, n);

    delete [] p1;
    delete [] p2;
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

void ordinamentoint(int *p1, int *p2, int n)
{
    cout<<"Ordinamento p1:"<<endl;
    for (int i = 0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(p1[i]>p1[j])
            {
                int appo;
                appo=p1[i];
                p1[i]=p1[j];
                p1[j]=appo;
            } 
        }
        cout<<"p1["<<i<<"]="<<p1[i]<<endl;
    }
    
    cout<<"Ordinamento p2:"<<endl;
    for (int i = 0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(p2[i]>p2[j])
            {
                int appo;
                appo=p2[i];
                p2[i]=p2[j];
                p2[j]=appo;
            } 
        }
        cout<<"p2["<<i<<"]="<<p2[i]<<endl;
    }
}
