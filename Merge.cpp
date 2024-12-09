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
        cout<<"v["<<k<<"]="<<v[k]<<endl;
    }
    centro=dim/2;

    cout<<"Algoritmo merge:"<<endl;
    Merge(v, )

    return 0;
}
