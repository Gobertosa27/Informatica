#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    
    int num;
    cout<<"Inserisci quanti num primi vuoi vedere: ";
    cin>>num;
    int v[num], n=1, conta, primo;
    for(int k=0; k<num; k=k+1)
    {
        do
        {
            conta=0;
            for(int j=0; j<n; j=j+1)
            {
                if((n)%(j+1)==0)
                    {
                        conta=conta+1;
                    }
            }
            if((conta==1)||(conta==2)) 
            {
                v[k]=n;
                cout<<"v["<<k+1<<"]="<<v[k]<<", ";
            }
            n=n+1;
        }
        while((conta!=1)&&(conta!=2));
        
    }
    cout<<endl;
return 0;
}
