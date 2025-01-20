#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void sort_odd( int *A, int d );

int main()
{
    srand(time(NULL));
    int d;
    d=rand()%11+10;
    int *A=NULL;
    A=new int [d];
    for(int k=0; k<d; k++)
    {
        A[k]=rand()%101;
        cout<<"c["<<k<<"]="<<A[k]<<endl;
    }
    sort_odd(A, d);
    cout<<endl<<"Array ordinato:"<<endl;
    for(int k=0; k<d; k++)
    {
        cout<<"c["<<k<<"]="<<A[k]<<endl;
    }
    return 0;
}

void sort_odd(int *A, int d)
{
    int n_pari=0;
    
    for(int k=0; k<d; k++)
    {
        if(A[k]%2==0)
        {
            n_pari++;
            for(int j=k+1; j<d; j++)
            {
                
                if((A[j]%2==0)&&(A[j]<A[k]))
                {
                    int appo;
                    appo=A[j];
                    A[j]=A[k];
                    A[k]=appo;
                }
            }
        }
        
    }
    cout<<"Ci sono "<<n_pari<<" num. pari!"<<endl;
}
