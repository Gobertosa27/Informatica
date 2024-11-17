#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float lunghezza(float [], float[], int);
float minimo(float [], int);
float massimo(float [], int);
void ordinamento(float[], float[], float [], int);

int main()
{
    int conta=0, npunti;
    float dato;
    ifstream flusso_in; 
    
    flusso_in.open("punti.dat");
    
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
    npunti=conta/2;
    cout<<"Sono presenti "<<npunti<<" punti"<<endl; 

    flusso_in.close();//chiudo per dichiarare il vettore all'infuori del file

    float coordx[npunti], coordy[npunti];

    flusso_in.open("punti.dat");//riapro il file per l'assegnamento
    
    if(flusso_in.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }

    for(int k=0; k<npunti; k=k+1)
    {
        flusso_in>>coordx[k];
        flusso_in>>coordy[k];
    }
    
    flusso_in.close();

    for(int k=0; k<npunti; k=k+1)
    {
        cout<<"p_"<<k<<"=("<<coordx[k]<<", "<<coordy[k]<<")"<<endl; 
    }
    cout<<endl;

    //calcolo distanza punti dall'origine
    float dist[npunti];
    for(int k=0; k<npunti; k=k+1)
    {
        dist[k]=sqrt(pow(coordx[k], 2)+pow(coordy[k], 2));
        cout<<"Distanza p_"<<k<<"="<<dist[k]<<endl;
    }

    //ricerca min
    float min;
    min=minimo(dist, npunti);
   

    //ricerca max
    float max;
    max=massimo(dist, npunti);

    //ordinamento
    cout<<endl<<"Punti ordinati:"<<endl;
    for(int k=0; k<npunti; k=k+1)
    {
        for(int j=k; j<npunti; j=j+1)
        {
            
            if(dist[j]<dist[k])
            {
                float appo;
                
                appo=dist[k];
                dist[k]=dist[j];
                dist[j]=appo;

                appo=coordx[k];
                coordx[k]=coordx[j];
                coordx[j]=appo;

                appo=coordy[k];
                coordy[k]=coordx[j];
                coordy[j]=appo;
                
                
            }
        }
        cout<<endl<<"p_"<<k<<"=("<<coordx[k]<<", "<<coordy[k]<<")="<<dist[k]<<endl;
    }

    ofstream flusso_out;

    flusso_out.open("res_punti.dat");

    if(flusso_out.fail())
    {
        cout<<endl<<"Qualcosa e' andato storto! Esco!"<<endl;
        return -1;
    }

     for(int k=0; k<npunti; k=k+1)
    {
        flusso_out<<coordx[k]<<"   "<<coordy[k]<<"   "<<dist[k]<<endl;
    }

    cout<<"File correttamente sovrascritto nel nuovo file!"<<endl;
    
    flusso_out.close();
    
    return 0;
}

float minimo(float lung[], int n)
{
    float min;
    min=lung[0];
    for(int k=0; k<n; k=k+1)
    {
        if(lung[k]<min) min=lung[k];
    }
    cout<<endl<<"Il minimo e': "<<min<<" ";
    
    int count=0;
    for(int k=0; k<n; k=k+1)
    {
        if(lung[k]==min) 
        {
            if(count==0)
            {    cout<<" del punto p_"<<k;
                count=count+1;
            }
            else cout<<", p_"<<k;
        }   
    }
    return min;
}

float massimo(float lung[], int n)
{
    float max;
    max=lung[0];
    for(int k=0; k<n; k=k+1)
    {
        if(lung[k]>max) max=lung[k];
    }
    cout<<endl<<"Il massimo e': "<<max<<" ";
    
    int count=0;
    for(int k=0; k<n; k=k+1)
    {
        if(lung[k]==max) 
        {
            if(count==0)
            {    cout<<" del punto p_"<<k;
                count=count+1;
            }
            else cout<<", p_"<<k;
        }   
    }
    return max;
}

