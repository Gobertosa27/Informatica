#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    float *diam;
    char *color, scelta;
    int ndati=0;

     
    ifstream flusso_in;
    flusso_in.open("sfere.dat");

    if(flusso_in.fail())
    {
        cout<<"Problema apertura file! Esco!"<<endl;
        return -1;
    }

    float ndiam;
    char ncol;
    while(!flusso_in.eof())
    {
        flusso_in>>ndiam;
        flusso_in>>ncol;
        ndati++;
    }
    
    flusso_in.close(); 
    
    ndati=ndati-1;
    cout<<"Ho "<<ndati<<" sfere!"<<endl;
    
    flusso_in.open("sfere.dat");

    diam=new float[ndati];
    color=new char[ndati];

    if(flusso_in.fail())
    {
        cout<<"Problema apertura file! Esco!"<<endl;
        return -1;
    }

    for(int i=0; i<ndati; i=i+1)
    {
        flusso_in>>diam[i];
        flusso_in>>color[i];
        
        cout<<"Sfera "<<i<<") d="<<diam[i]<<" e colore="<<color[i]<<endl;
    }

    if((diam==NULL)||(color==NULL))
    {
        cout<<"Non c'e' nulla!"<<endl;
        return -1;
    }
    
    flusso_in.close(); 

    cout<<endl<<"Ora conteggio solo quelli di colore scelto (r, g, b): ";
    
    do
    {
        cin>>scelta;
        if ((scelta!='r')&&(scelta!='g')&&(scelta!='b'))
        {
            cout<<"Scegli tra quelli indicati! (r, g, b) : ";
        }
        
    } 
    while ((scelta!='r')&&(scelta!='g')&&(scelta!='b'));
    cout<<endl;   

    int color_right=0;
    

    for(int i=0; i<ndati; i=i+1)
    {
       if(color[i]==scelta)
       {
            color_right++;
       }
    }

    for (int i=0; i<ndati; i=i+1)
    {
        int conta=0, count=0;
        for(int k=i; k<ndati; k++)
        {
            if(color[k]==scelta) conta++;
        }

        if(color[i]==scelta) 
        {
            count++;
        }

        while((color[i]!=scelta)&&(count<conta))
        {
            
            int k=i;
            while(color[k]!=scelta)
            {
                k++;
                if(color[k]==scelta) cout<<"La prossima palla di colore "<<scelta<<" dista a "<<k-i<<" sfere!"<<endl;
            }
            float diametro;
            char colore;
            diametro=diam[i];
            colore=color[i];
            for(int k=i; k<ndati-1; k++)
            {
                diam[k]=diam[k+1];
                color[k]=color[k+1];                    
            }
        
            diam[ndati-1]=diametro;
            color[ndati-1]=colore;

            if(color[i]==scelta)
            {
                cout<<"Presa sfera di colore "<<scelta<<"!"<<endl;
                count++;
            }
        }
    }

    cout<<endl<<"Le sfere di colore "<<scelta<<" sono in totale: ";
    cout<<color_right<<endl;
    for(int i=0; i<color_right; i=i+1)
    {
        cout<<"Sfera "<<i<<") d="<<diam[i]<<" e colore="<<color[i]<<endl;
    }

    cout<<endl<<"Le altre sfere invece: "<<endl;
   for(int i=color_right; i<ndati; i=i+1)
    {
        cout<<"Sfera "<<i<<") d="<<diam[i]<<" e colore="<<color[i]<<endl;
    }

    float media, somma=0;
    for(int i=0; i<color_right; i=i+1)
    {
       somma=somma+diam[i];
    }
    media=somma/color_right;

    float devst, sommaq=0;
    for(int i=0; i<color_right; i=i+1)
    {
       sommaq=sommaq+pow(diam[i]-media, 2);
    }
    
    devst=sqrt((sommaq)/(color_right-1));

    cout<<endl<<"Le sfere di colore "<<scelta<<" hanno media="<<media;
    cout<<" e dev. st.="<<devst<<endl;

    ofstream flusso_out;
    flusso_out.open("sfere_new.dat");
    if(flusso_out.fail())
    {
        cout<<"Problema apertura file! Esco!"<<endl;
        return -1;
    }
   
    for(int i=0; i<color_right; i=i+1)
    {
        flusso_out<<diam[i]<<"\t"<<color[i]<<endl;
    }

    flusso_out<<endl<<media<<"\t"<<devst<<endl;

    flusso_out.close();

    delete [] diam;
    diam=NULL;
    delete [] color;
    color=NULL;

    return 0; 
}

