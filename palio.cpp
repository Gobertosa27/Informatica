#include "lib.h"

using namespace std;

struct giocatore {
int cod; //codice giocatore
bool is_pro; //true per professionista, false per amatore
int tot_punt=0; //punteggio ottenuto al torneo del Palio di Masnago
int nmani=0; //mani giocate al torneo del Palio di Masnago
};

struct mano {
int cod; //codice giocatore
int punti; //punti mano al torneo del Palio/punti classifica nazionale.
};


int main()
{
    ifstream flussoin;
   
    giocatore g;
    int n_g=0;

    flussoin.open("iscritti.dat");

    if(flussoin.fail())
    {
        cout<<"File non aperto correttamente!"<<endl;
        return -1;
    }

    while(!(flussoin.eof()))
    {
        if(!(flussoin>>g.cod)) break;
        n_g++;
    }
    cout<<"Abbiamo "<<n_g<<" giocatori:"<<endl;

    flussoin.close();

    giocatore *gioc=NULL;
    gioc=new giocatore[n_g];
    mano *m=NULL;
    m=new mano[n_g];

    flussoin.open("iscritti.dat");

    if(flussoin.fail())
    {
        cout<<"File non aperto correttamente!"<<endl;
        return -1;
    }

   while(!(flussoin.eof()))
    {
        for(int k=0; k<n_g; k++)
        {    
            if(!(flussoin>>gioc[k].cod)) break;
            if(gioc[k].cod>=1 && gioc[k].cod<=1000)
            {
                gioc[k].is_pro=true;
                cout<<"Giocatore "<<k<<") cod="<<gioc[k].cod<<" professionista: "<<gioc[k].is_pro<<endl;

            }
            else  
            {
                gioc[k].is_pro=false;
                cout<<"Giocatore "<<k<<") cod="<<gioc[k].cod<<" amatoriale"<<endl;
            }
        }
    }

    flussoin.close();

    cout<<endl;

    flussoin.open("punteggi.dat");

    if(flussoin.fail())
    {
        cout<<"File non aperto correttamente!"<<endl;
        return -1;
    }

    int cod;
   while(!(flussoin.eof()))
   {
        int k=0;
        if(!(flussoin>>cod)) break;
        while((gioc[k].cod!=cod)&&(k<n_g)) k++;
        flussoin>>m[k].punti;
        gioc[k].nmani++;
        gioc[k].tot_punt=gioc[k].tot_punt+m[k].punti;
        cout<<"Giocata di giocatore "<<k<<") cod="<<gioc[k].cod<<" con "<<gioc[k].nmani<<" mani: +"<<m[k].punti<<". Punteggio tot. ad ora: "<<gioc[k].tot_punt<<endl;
   }
    cout<<endl;
   for(int k=0; k<n_g; k++)
   {
    gioc[k].tot_punt;
    cout<<"Giocatore "<<k<<") cod="<<gioc[k].cod<<" ha giocato in totale "<<gioc[k].nmani<<" mani con un tot. di "<<gioc[k].tot_punt<<endl;
   }

    flussoin.close();

    cout<<"CLASSIFICA dei singoli giocatori: "<<endl;
    int posto;
    giocatore gioc1;
    for(int k=0; k<n_g; k++)
    {
        for(int j=k; j<n_g; j++)
        {
            if(gioc[k].tot_punt<gioc[j].tot_punt)
            {
                posto=j+1;
                gioc1=gioc[k];
                gioc[k]=gioc[j];
                gioc[j]=gioc1;
            }
        }
    }

    cout<<"CLASSIFICA"<<endl;
    for(int k=0; k<n_g; k++)
    {
        cout<<k+1<<") posto per giocatore cod="<<gioc[k].cod<<" con "<<gioc[k].tot_punt<<" punti"<<endl;
    }

    delete [] gioc;
    gioc=NULL;
    delete [] m;
    m=NULL;

   
    return 0;
}
