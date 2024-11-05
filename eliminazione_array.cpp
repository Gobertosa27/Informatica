#include <iostream>
#include <cmath>

using namespace std;

int left_shift( float [], int, int);

int main()
{
    int n;
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
    
    newdim=left_shift(v, n, ind);
    
    float w[newdim];
    cout<<"Nuovo vettore:"<<endl;
    for(int k=0; k<newdim; k=k+1)
    {
        float val;
        val=v[k];
        w[k]=val;
        cout<<"v["<<k<<"]="<<w[k]<<endl;
    }
    cout<<"Dim-1="<<newdim<<endl;
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
