#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

void segmentation( int* A, int d, int p );

int main()
{
    srand(time(NULL));
    int d;
    d=rand()%20+1;
    cout<<"Array lungo "<<d<<" caselle"<<endl;
    int *A=NULL;
    A=new int [d];
    for(int k=0; k<d; k++)
    {
        A[k]=rand()%100+1;
        cout<<"c["<<k<<"]="<<A[k]<<endl;
    }
    int p;
    p=rand()%10+1;
    cout<<"Tali numeri devono essere multipli di "<<p<<endl;
    segmentation(A, d, p);
    return 0;
}

void segmentation(int *A, int d, int p)
{
    for(int k=0; k<d; k++)
    {
       int j=k;
       while(((A[j]<p)||(A[j]%p!=0))&&(j<d))
       {
        if(A[j]<p) cout<<A[j]<<" e' <"<<p<<endl;
        else
        {
             if(A[j]%p!=0) cout<<A[j]<<" non e' multiplo di "<<p<<endl;
        }
        j++;
       }
       if((A[j]%p==0)&&(A[j]>=p)) 
       {
        cout<<A[j]<<" e' multiplo di "<<p<<endl;
        int appo;
        appo=A[j];
        A[j]=A[k];
        A[k]=appo;
       }
    }
    cout<<"CHECK FINALE: multipli di "<<p<<endl;
     for(int k=0; k<d; k++)
    {
        cout<<"c["<<k<<"]="<<A[k]<<endl;
    }
}
