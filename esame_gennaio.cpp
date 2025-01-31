#include "lib.h"

using namespace std;


int main()
{
    int conta=0;
    int aut;
    char ident;

    ifstream flussoin;

    flussoin.open("carrelli.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file carrelli!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        if(!(flussoin>>ident)) break;
        flussoin>>aut;
        conta++;
    }

    flussoin.close();

    cout<<"Abbiamo "<<conta<<" carrelli"<<endl;

    carrello *carr=NULL;
    carr=new carrello[conta];

    int conta_car=0;
    float massa;
    int d;

    flussoin.open("carichi.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file carichi!"<<endl;
        return -1;
    }

    while(!flussoin.eof())
    {
        if(!(flussoin>>massa)) break;
        flussoin>>d;
        char *T=NULL;
        T=new char[d];
        for(int k=0; k<d; k++)
        {
            flussoin>>T[k];
        }
        conta_car++;
        delete [] T;
        T=NULL;
    }

    flussoin.close();

    if(conta!=conta_car)
    {
        cout<<"n carrelli!=n carichi! Esco"<<endl;
        return 0;
    }
    else cout<<endl<<"n carrelli=n carichi! Proseguo"<<endl;

    carico *caric=NULL;
    caric=new carico[conta_car];

    flussoin.open("carichi.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file carichi!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        for(int k=0; k<conta_car; k++)
        {
            if(!(flussoin>>caric[k].peso)) break;
            flussoin>>caric[k].nsteps;
            caric[k].T=NULL;
            caric[k].T=new char[caric[k].nsteps];
            for(int j=0; j<caric[k].nsteps; j++)
            {
                flussoin>>caric[k].T[j];
            }
        }
    }

    flussoin.close();


    flussoin.open("carrelli.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file carrelli!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        for(int k=0; k<conta; k++)
        {   
            if(!(flussoin>>carr[k].id)) break;
            flussoin>>carr[k].a;
        }
    }

    flussoin.close();

    flussoin.open("carichi.dat");
    
    if(flussoin.fail())
    {
        cout<<"Errore apertura file carichi!"<<endl;
        return -1;
    }

    while(!flussoin.eof())
    {
        for(int k=0; k<conta; k++)
        {
            if(!(flussoin>>carr[k].c.peso)) break;
            flussoin>>carr[k].c.nsteps;
            carr[k].c.T=NULL;
            carr[k].c.T=new char[carr[k].c.nsteps];
            for(int j=0; j<carr[k].c.nsteps; j++)
            {
                flussoin>>carr[k].c.T[j];
            }
        }
    }

    flussoin.close();

    ofstream flussout;

    flussout.open("risultati.dat");

    if(flussout.fail())
    {
        cout<<"Errore apertura file risultati!"<<endl;
        return -1;
    }
    flussout<<"Abbiamo "<<conta<<" carrelli"<<endl;


    if(conta!=conta_car)
    {
        flussout<<"n carrelli!=n carichi! Esco"<<endl;
        return 0;
    }
    else flussout<<endl<<"n carrelli=n carichi! Proseguo"<<endl;

    cout<<endl<<"I primi 3 carrelli sono: "<<endl;
    flussout<<endl<<"I primi 3 carrelli sono: "<<endl;
    for(int k=0; k<3; k++)
    {
        cout<<"Carrello "<<k<<") id: "<<carr[k].id<<", a="<<carr[k].a<<endl;
        flussout<<"Carrello "<<k<<") id: "<<carr[k].id<<", a="<<carr[k].a<<endl;
    }

    cout<<endl<<"Gli ultimi 3 carrelli sono: "<<endl;
    flussout<<endl<<"Gli ultimi 3 carrelli sono: "<<endl;
    for(int k=23; k<conta; k++)
    {
        cout<<"Carrello "<<k<<") id: "<<carr[k].id<<", a="<<carr[k].a<<endl;
        flussout<<"Carrello "<<k<<") id: "<<carr[k].id<<", a="<<carr[k].a<<endl;
    }

    int carr_noa=0;

    carr_noa=nonAuton(carr, conta, carr_noa);
    
    cout<<endl<<"I carrelli con auton<15 sono N="<<carr_noa<<endl;
    flussout<<endl<<"I carrelli con auton<15 sono N="<<carr_noa<<endl;

    cout<<endl<<"I carichi totali sono "<<conta_car<<endl;
    flussout<<endl<<"I carichi totali sono "<<conta_car<<endl;

    float tot_kg=0;
    tot_kg=totkili(caric, conta_car, tot_kg);

    cout<<endl<<"I kg totali trasportati sono "<<tot_kg<<endl;
    flussout<<endl<<"I kg totali trasportati sono "<<tot_kg<<endl;

    cout<<endl<<"Ordinamento:"<<endl;
    flussout<<"Ordinamento:"<<endl;

    ordinamento(caric, conta_car);

    for(int k=0; k<3; k++)
    {
        cout<<"caric["<<k<<"]: peso="<<caric[k].peso<<", nstep="<<caric[k].nsteps<<" --> ";
        for(int j=0; j<caric[k].nsteps; j++)
        {
                cout<<caric[k].T[j]<<", ";
        }
        cout<<endl;
        flussout<<"caric["<<k<<"]: peso="<<caric[k].peso<<", nstep="<<caric[k].nsteps<<" --> ";
        for(int j=0; j<caric[k].nsteps; j++)
        {
                flussout<<caric[k].T[j]<<", ";
        }
    flussout<<endl;
    }
    cout<<endl;
    flussout<<endl;
    for(int k=23; k<conta_car; k++)
    {
        cout<<"caric["<<k<<"]: peso="<<caric[k].peso<<", nstep="<<caric[k].nsteps<<" --> ";
        for(int j=0; j<caric[k].nsteps; j++)
        {
                cout<<caric[k].T[j]<<", ";
        }
        cout<<endl;
        flussout<<"caric["<<k<<"]: peso="<<caric[k].peso<<", nstep="<<caric[k].nsteps<<" --> ";
        for(int j=0; j<caric[k].nsteps; j++)
        {
                flussout<<caric[k].T[j]<<", ";
        }
        flussout<<endl;
    }

    cout<<endl<<"Assegnamento: "<<endl;
    flussout<<endl<<"Assegnamento: "<<endl;

    assegnamento(carr, caric, conta);

    for(int k=0; k<conta; k++)
    {
        flussout<<"Carrello "<<k<<" ha carico: ";
        carr[k].c=caric[k];
        flussout<<"m="<<carr[k].c.peso<<", nstep="<<carr[k].c.nsteps<<" --> ";
        for(int j=0; j<carr[k].c.nsteps; j++)
        {
            flussout<<carr[k].c.T[j]<<", ";
        }
        flussout<<endl;
    }

    cout<<"Scrematura lista:"<<endl;
    carrello *new_carr=NULL;
    int new_dim;
    new_dim=scrematura(carr, conta, carr_noa);
    new_carr=new carrello[new_dim];

     for(int k=0; k<new_dim; k++)    
    {
        new_carr[k]=carr[k];
        cout<<"Carrello "<<k<<") id: "<<carr[k].id<<", a="<<carr[k].a<<endl;
        flussout<<"Carrello "<<k<<") id: "<<carr[k].id<<", a="<<carr[k].a<<endl;
    }

    delete [] carr;
    carr=NULL;
    flussout.close();

    delete [] new_carr;
    new_carr=NULL;
    delete [] caric;
    caric=NULL;
    return 0;
}

int nonAuton(carrello *C, int d, int noa)
{
    for(int k=0; k<d; k++)
    {
        if(C[k].a<15) noa++;
    }
    return noa;
}

float totkili(carico *C, int d, float tot_kg)
{
    for(int k=0; k<d; k++)
    {
        tot_kg=tot_kg+C[k].peso;
    }
    return tot_kg;
}

void ordinamento(carico *C, int d)
{
    for(int k=0; k<d; k++)
    {
        for(int j=k+1; j<d; j++)
        {
            if(C[k].peso<C[j].peso)
            {
                carico appo;
                appo=C[k];
                C[k]=C[j];
                C[j]=appo;
            }
        }
    }
}

void assegnamento(carrello *C, carico *c, int conta)
{
    for(int k=0; k<conta; k++)
    {
        cout<<"Carrello "<<k<<" ha carico: ";
        C[k].c=c[k];
        cout<<"m="<<C[k].c.peso<<", nstep="<<C[k].c.nsteps<<" --> ";
        for(int j=0; j<C[k].c.nsteps; j++)
        {
            cout<<C[k].c.T[j]<<", ";
        }
        cout<<endl;
    } 
}

int scrematura(carrello *c, int d, int noa)
{
    int new_dim=d, conta=0;
    for(int k=0; k<d; k++)
    {
        while((c[k].a<15)&&(conta<noa))
        {
            conta++;
            new_dim--;
            carrello appo;
            appo=c[k];
            for(int j=k; j<d; j++)
            {
                if(j<d-1) c[j]=c[j+1];
                else c[j]=appo;
            }
        }
    }

    return new_dim;
}

