#include <iostream>
#include <cmath>

using namespace std;

int numero_valori(float [], float, float, int, int);
float leggi_dato(float, float);

int main()
{
    int max, size;
    
    do
    {
        cout<<"Inserisci il numero max di valori che vuoi inserire: ";
        cin>>max;
        if(max<=0) cout<<"Ma vaffanculo va!"<<endl;
    }
    while(max<=0);
    float valori[max], a, b;

    cout<<"Inserisci estremi [a,b]:"<<endl;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    if(b<a)
    {
        float val;
        val=b;
        b=a;
        a=val;
    }
    
    int usati=0;
    
    size=numero_valori(valori, a, b, max, usati);

    cout<<"Hai immesso "<<size<<" numeri!"<<endl;
    


    return 0;
}

int numero_valori(float valori[], float a, float b, int max, int usati)
{
    float dato;
    char scelta;
    do
    {
        dato=leggi_dato(a, b);
        valori[usati]=dato;
        cout<<"Hai immesso v["<<usati<<"]="<<valori[usati]<<endl;
        usati=usati+1;

        cout<<"Continuare? (y per si) ";
        cin>>scelta;
    }
    while((scelta=='y')&&(usati<max));
    if(usati==max) cout<<"Ops, valore max RAGGIUNTO!"<<endl;
    
    return usati; 
}

float leggi_dato(float min, float max)
{
    float dato;
    do 
    {
        cout<<"Inserisci dato ["<<min<<","<<max<<"] :";
        cin>>dato;
        if((dato<min) || (dato>max)) cout<<"Rileggi la condizione!"<<endl;
    }
    while((dato<min)||(dato>max));

    return dato;
}


