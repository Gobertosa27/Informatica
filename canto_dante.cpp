#include <iostream>
#include <fstream>

#define NCHARS 256
using namespace std;

// Questa funzione restituisce la posizione del massimo in un vettore di interi v contenente used elementi.
int findMax(int v[], int used);

// Questa funzione restituisce la posizione del massimo in un vettore di interi v nel range di indici [ind_min, ..., ind_max].
int findMaxRange(int v[], int ind_min, int ind_max);

int main() {
    // Ricordiamo che i caratteri sono codificati su 8 bit (1 byte).
    // Ci sono quindi 2^8 = 256 caratteri.
    int counts[NCHARS] = {0};  // Inizializza direttamente a zero
    int counts_size = NCHARS;
    int counts_used = counts_size;
    int pos_max_occ;
    char appo;
    int total = 0;

    ifstream file_in;

    // Apro il file di input
    file_in.open("canto_dante.txt");
    if (file_in.fail()) {
        cout << endl << "Problema apertura file! Esco";
        return -1;
    }

    // Inizializzo i contatori dei caratteri a zero
    // (L'inizializzazione è già fatta sopra con l'array counts)

    // Inizio il conteggio dei caratteri.
    // Leggo il primo carattere
    appo = file_in.get();
    while (!file_in.eof()) {
        counts[(unsigned char) appo]++;  // Incremento il contatore del carattere
        appo = file_in.get();  // Leggo il carattere successivo
    }

    // Stampa le occorrenze dei caratteri (compreso spazio e caratteri speciali)
    cout << "Occorrenze dei caratteri (ASCII 32-255):" << endl;
    for (int i = 32; i < counts_size; i++) {
        cout << "\t" << (char)i << ": " << counts[i];
        if (i % 10 == 0) cout << endl;
    }
    cout << endl;

    // Trova e stampa il carattere con il numero massimo di occorrenze
    pos_max_occ = findMax(counts, counts_used);
    cout << endl << "Il carattere con maggiori occorrenze è: " 
         << (char)pos_max_occ << " con " << counts[pos_max_occ] << " occorrenze" << endl;

    // Trova e stampa il carattere alfabetico con il numero massimo di occorrenze
    pos_max_occ = findMaxRange(counts, 65, 122); // Range delle lettere alfabetiche (A-Z, a-z)
    cout << endl << "Il carattere alfabetico con maggiori occorrenze è: " 
         << (char)pos_max_occ << " con " << counts[pos_max_occ] << " occorrenze" << endl;

    // Occorrenze di ritorno a capo e line-feed
    cout << endl << "Occorrenze ritorno a capo (carattere ASCII 13): " << counts[13] << endl;
    cout << endl << "Occorrenze line-feed (carattere ASCII 10): " << counts[10] << endl;

    // Calcolo il numero totale di caratteri letti
    for (int i = 0; i < NCHARS; i++) total += counts[i];

    cout << endl << "Numero di caratteri letti: " << total << endl;

    return 0;
}

/* Definizione funzioni */

// Trova la posizione del massimo in un array v con 'used' elementi
int findMax(int v[], int used) {
    int posMax = 0;
    int max = v[0];

    for (int i = 1; i < used; i++) {
        if (v[i] > max) {
            max = v[i];
            posMax = i;
        }
    }
    return posMax;
}

// Trova la posizione del massimo in un array v nel range di indici [ind_min, ind_max]
int findMaxRange(int v[], int ind_min, int ind_max) {
    int posMax = ind_min;
    int max = v[ind_min];

    for (int i = ind_min + 1; i <= ind_max; i++) {
        if (v[i] > max) {
            max = v[i];
            posMax = i;
        }
    }
    return posMax;
}

/*La scelta di usare `unsigned char` anziché `char` in un contesto come `counts[(unsigned char) appo]++` dipende dal fatto che il tipo `char` può essere sia **signed** che **unsigned** 
a seconda della piattaforma o del compilatore, e questo potrebbe causare comportamenti imprevisti quando si lavora con valori numerici, come gli indici di un array.

Ecco il motivo principale per cui si usa `unsigned char`:

1. **Valori negativi con `char`**: In alcune piattaforme, `char` è interpretato come un tipo **signed**. Questo significa che il suo valore può variare da -128 a 127 (per un `char` a 8 bit), e
 quindi, se il valore di `appo` è negativo, la conversione di `appo` in `char` potrebbe dare risultati non desiderati, come un indice negativo. Gli indici di un array, invece, devono essere sempre numeri non negativi.

2. **Range di valori con `unsigned char`**: Il tipo `unsigned char` è garantito essere senza segno, con valori che vanno da 0 a 255 (per un `unsigned char` a 8 bit). Questo è utile se l'intento è trattare `appo` come una variabile 
che può rappresentare qualsiasi valore all'interno di questo intervallo, come ad esempio un byte che potrebbe rappresentare un carattere ASCII, una sequenza di byte, o un valore di una tabella di contatori.

Usando `(unsigned char) appo`, forzi il compilatore a trattare il valore di `appo` come un numero positivo (compreso tra 0 e 255), eliminando la possibilità di indici negativi che potrebbero causare accessi a posizioni 
non valide nell'array `counts`.

In sintesi, usare `unsigned char` è una misura di sicurezza per garantire che l'indice dell'array sia sempre valido e positivo, specialmente quando si lavora con valori di byte o quando si è incerti sul comportamento del tipo `char` nella piattaforma di destinazione.*/
