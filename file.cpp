#include <iostream>
#include <cmath>
#include <fstream>//ricordati di questo!
using namespace std;

int minimo(int [], int);
int massimo(int [], int);
int min_range(int [], int, int);
void ordinamento(int [], int);
void swap( int [], int, int);


int main ()
{
    int dati[10], dato, conta=0;
    ifstream flusso_in; 
    flusso_in.open("dati_int.dat");
    
    if(flusso_in.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }

    for(int k=0; k<10; k=k+1)
    {
        flusso_in>>dati[k];//sarebbe il cin dei fle. I valori, al posto di essere
        //assegnati da tastiera, vengono assegnati da quelli dei file
    }
    
    flusso_in.close();

    //Riapro file
    flusso_in.open("dati_int.dat");

    flusso_in >> dato;
    
    if(flusso_in.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }
    
    while(!flusso_in.eof())
    {
        flusso_in >> dato;
        conta=conta+1;
    }

    cout<<endl<<"Sono presenti "<<conta<<" dati interi"<<endl;

    int dati_used;
    dati_used=conta;

    cout<<"Vettore ha:";

    for(int k=0; k<dati_used; k=k+1)
    {
        cout<<endl<<dati[k];
    }
    cout<<endl;
    flusso_in.close();

    //ricerca min
    int min;
    min=minimo(dati, dati_used);
    cout<<"Il min e': "<<min<<endl;
    int count=0, posmin;
    for(int k=0; k<dati_used; k=k+1)
    {
       if(dati[k]==min) 
       {
        if(count==0) 
        {
            posmin=k;
            cout<<"In posizione "<<posmin;
            count=count+1;
        }
        else 
        {
            posmin=k;
            cout<<", "<<posmin;
        }  
       }
    }

    cout<<endl;
    //ricerca max
    int max, posmax;
    max=massimo(dati, dati_used);
    cout<<"Il max e': "<<max<<endl;
    count=0;
     for(int k=0; k<dati_used; k=k+1)
    {
       if(dati[k]==max) 
       {
        if(count==0) 
        {
            posmax=k;
            cout<<"In posizione "<<posmax;
            count=count+1;
        }
        else 
        {
            posmax=k;
            cout<<", "<<posmax;
        }  
       }
    }
    cout<<endl;

    //ordinamento
    ordinamento(dati, dati_used);

    //output file
    ofstream flusso_out;
    flusso_out.open("dati_int.dat");

    if(flusso_out.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }
    else cout<<"File correttamente sovrascritto!"<<endl;

    for(int k=0; k<dati_used; k=k+1)
    {
        flusso_out<<dati[k]<<endl;
    }

    flusso_out.close();


    return 0;
}

int minimo(int v[], int dim)
{
    int min;
    min=v[0];
    for(int k=0; k<dim; k=k+1)
    {
       if(v[k]<min) min=v[k]; 
    }
    return min;
}

int min_range(int v[], int j, int dim)
{
    int min;
    min=v[j];
    for(int k=j; k<dim; k=k+1)
    {
       if(v[k]<min) 
       {
            min=v[k];
            swap(v, k, j); 
        }
    }
    return min;
}

int massimo(int v[], int dim)
{
    int max;
    max=v[0];
    for(int k=0; k<dim; k=k+1)
    {
       if(v[k]>max) max=v[k]; 
    }
    return max;
}

void ordinamento(int v[], int dim)
{
    cout<<"Vettore ordinato:"<<endl;
    int min;
    for(int k=0; k<dim; k=k+1)
    {
        min=min_range(v, k, dim);
        v[k]=min;
        cout<<"v["<<k<<"]="<<v[k]<<endl;
    }

}

void swap(int v[], int posmin, int posiniz)
{
    int aus;
    aus=v[posiniz];
    v[posiniz]=v[posmin];
    v[posmin]=aus;
}
