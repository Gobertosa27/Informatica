#include <iostream>
#include <cmath>

using namespace std;

void Merge(float *, int, int);

int main ()
{
    int dim, centro;
    float *v;

    cout<<"Inserisci un num di elementi: ";
    cin>>dim;

    v=new float[dim];

    cout<<"Inserisci "<<dim<<" elementi:"<<endl;
    for(int k=0; k<dim; k++)
    {
        cout<<"v["<<k<<"]=";
        cin>>v[k];
    }
    centro=dim;
    cout<<"Algoritmo merge:"<<endl;
    Merge(v, centro, dim);

    return 0;
}

void Merge(float *v, int centro, int dim)
{
    dim=centro;
    if(dim>1)
    {
        if(dim%2==0)  centro=dim/2;
        else centro=(dim+1)/2;
        for(int k=0; k<centro; k++)
        {
              cout<<"v["<<k<<"]="<<v[k]<<", ";
        }
        cout<<endl;
        Merge(v, centro, dim);
    }
}
