#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    
    int n;
    cout<<"Inserisci num da cui vedere tutti i numeri primi: ";
    cin>>n;
    int conta=0, count=0;
    for(int k=0; k<n; k=k+1)
    {
        for(int j=0; j<=k; j=j+1)
        {
            if((k+1)%(j+1)==0) conta=conta+1;
        }
        cout<<endl<<"conta per "<<k+1<<"="<<conta<<endl;
    if((conta==2)||(conta==1)) 
    {
        count=count+1;
        conta=0;
    }
    else conta=0;
    }
    int v[count], y=0;
    cout<<"I numeri primi di "<<n<<" sono: ";
    for(int k=0; k<n; k=k+1)
    {
        for(int j=0; j<=k; j=j+1)
        {
            if((k+1)%(j+1)==0) conta=conta+1;
        }
        if((conta==2)||(conta==1)) 
        {
            v[y]=k+1;
            cout<<v[y]<<", ";
            y=y+1;
            conta=0;
        }
        else conta=0;
    }
    cout<<endl;
return 0;
}
