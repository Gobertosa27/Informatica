#include <iostream>
#include <cmath>

using namespace std;

int left_shift( float [], int, int);
int swap(float [], int, int);
void ordinamento(float [], int);

int main()
{
    int n;
    char scelta;
    do
    {
        cout<<"Inserire una dim per il vettore: ";
        cin>>n;
        if(n<0) cout<<"dim>0, per cortesia!"<<endl;
    }
    while(n<0);
    
    float v[n];
    cout<<"Ora Inserisci gli el. del vettore:"<<endl;
    for(int k=0; k<n; k=k+1)
    {
        cout<<"v["<<k<<"]=";
        cin>>v[k];
    }

    int newdim, ind;
    cout<<"Scegli la posizione dell'el. da cui far partire lo spostamento: ind=";
    cin>>ind;
    
   do
   {
   cout<<"Eliminazione el. tramite L.S.(l) oppure Swap(s)? ";
    cin>>scelta;
    if((scelta!='l')&&(scelta!='s')) cout<<"Ho detto o 'l' o 's' "<<endl;
   }
    while((scelta!='l')&&(scelta!='s'));
   
    if(scelta=='l')
    {
        newdim=left_shift(v, n, ind);
    }
   
    if(scelta=='s')
    {
        newdim=swap(v, n, ind);
    }

    cout<<"Nuovo vettore:"<<endl;
    for(int i=0; i<newdim; i++)
    {
        cout<<"v["<<i<<"]="<<v[i]<<endl;
    }

    cout<<"...ordinato:"<<endl;
    ordinamento(v, newdim);

    return 0;
}

int left_shift(float v[], int dim, int ind)
{
    if((ind<0)&&(ind>=dim)) return -1;
    else
    {
        for(int i=ind; i<dim-1; i=i+1) //es.: dim=4; 0, 1, 2, 3; new dim=3: 0, 1, 2.
        {
            v[i]=v[i+1]; //il valore corrente e' uguale a quello successivo;
        }
    }
    int newdim=dim-1;
    return newdim;
}

int swap(float v[], int dim, int ind)
{
    if((ind<0)&&(ind>=dim)) return -1;
    v[ind]=v[dim-1];
    int newdim=dim-1;
    return newdim;
}

void ordinamento(float v[], int dim)
{
    for(int k=0; k<dim; k=k+1)
    {
        for(int j=k; j<dim; j=j+1)
        {
            if(v[j]<v[k]) 
            {
                float val;
                val=v[k];
                v[k]=v[j];
                v[j]=val;
            }
        }
        cout<<"v["<<k<<"]="<<v[k]<<endl;
    }
}
