#include <iostream>


using namespace std;

const int dimensioneMax=100;

//prototipi
void caricaVettori(string codice[], string nomi[], string casa[], string classe[], float prezzo[], int n);
void cercaProdottoCodice(string codice[], string nomi[], string casa[], string classe[], float prezzo[], int n);
void ordinamentoAlfabetico(string nomi[], int n, string classe[], string vAlpha[]);
void aggiornaPrezzo(string codice[], float prezzo[], float prezzo1[]);
float media(string classe[], float prezzo[], int n, float prezziClasse[], int &d);
void fasciaPrezzo(string codice[], string nomi[], string casa[], float prezzo[], string classe[], int n);
void stampaMassimo(string nomi[], float prezzo[], int n, string classe[], string casa[], string codice[]);
int Menu();


int main() {
    int N;
    string CODICE[dimensioneMax];
    string NOME[dimensioneMax];
    string CASA[dimensioneMax];
    string CLASSE[dimensioneMax];
    float PREZZO[dimensioneMax];
    string Nomi_Alfabetico[dimensioneMax];
    string codiciDaAggiornare[dimensioneMax];
    float prezziDaAggiornare[dimensioneMax];
    int d=0;
    float prezziClasse[dimensioneMax];
    float m=0.00;
    int scelta;

    do {
        scelta=Menu();
        switch(scelta) {
            case 1:
              cout<<"Inserisci il numero di prodotti da inserire: ";
              cin>>N;
              caricaVettori(CODICE,NOME,CASA,CLASSE,PREZZO,N);
            break;
            case 2:
              stampaMassimo(NOME,PREZZO,N,CLASSE,CASA,CODICE);
            break;
            case 3:
              cercaProdottoCodice(CODICE,NOME,CASA,CLASSE,PREZZO,N);
            break;
            case 4:
              ordinamentoAlfabetico(NOME,N,CLASSE,Nomi_Alfabetico);
            break;
            case 5:
              aggiornaPrezzo(CODICE,PREZZO,prezziDaAggiornare);
            break;
            case 6:
              m=media(CLASSE,PREZZO,N,prezziClasse,d);
              cout<<"La media dei prezzi dei prodotti della classe inserita e' : "<<m<<endl;
            break;
            case 7:
              fasciaPrezzo(CODICE,NOME,CASA,PREZZO,CLASSE,N);
            break;
            case 0:
             cout<<"Esci"<<endl;
            break;
            default:
             cout<<"Attenzione, scelta sbagliata!"<<endl;
            break;
        }
    }while(scelta!=0);

    return 0;
}


int Menu () {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Inserisci prodotti"<<endl;
  cout<<"2-Stampa il prodotto con prezzo maggiore appartenente ad una determinata classe"<<endl;
  cout<<"3-Ricerca prodotto dato il codice"<<endl;
  cout<<"4-Stampa prodotti in ordine alfabetico data una classe"<<endl;
  cout<<"5-Aggiorna prezzi"<<endl;
  cout<<"6-Stampare la media dei prodotti di una determinata categoria"<<endl;
  cout<<"7-Stampare i dati di un prodotto che rientra in una determinata fascia di prezzo"<<endl;

  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}



void caricaVettori(string codice[], string nomi[], string casa[], string classe[], float prezzo[], int n) {
  for(int i=0; i<n; i++) {
    cout<<"Inserisci il codice, il nome, la casa produttrice, la categoria e il prezzo del prodotto: ";
    cin>>codice[i]>>nomi[i]>>casa[i]>>classe[i]>>prezzo[i];
  }
}


void cercaProdottoCodice(string codice[], string nomi[], string casa[], string classe[], float prezzo[], int n) {
  string codiceProdotto;
  int i=0;


  cout<<endl;

  cout<<"Inserisci il codice del prodotto: ";
  cin>>codiceProdotto;
  while(i<n&&codice[i]!=codiceProdotto) {
      i=i+1;
  }

  if(i>=n) {
      cout<<codiceProdotto<<" non e' presente nei prodotti"<<endl;
  } else {
      cout<<"il prodotto con codice "<<codiceProdotto<<" e' presente nei prodotti"<<endl;
      cout<<"il nome del prodotto e': "<<nomi[i]<<endl;
      cout<<"la casa produttrice del prodotto e': "<<casa[i]<<endl;
      cout<<"la categoria del prodotto e': "<<classe[i]<<endl;
      cout<<"il prezzo del prodotto e': "<<prezzo[i]<<endl;
  }

  cout<<endl;
}


void ordinamentoAlfabetico(string nomi[], int n, string classe[], string vAlpha[]) {

  string classeProdotto;
  string temp;
  
  cout<<"Inserisci la classe dei prodotti da ordinare: ";
  cin>>classeProdotto;
  for(int i=0; i<n; i++) {
    if(classeProdotto==classe[i]) {
      vAlpha[i]=nomi[i];
    }
  }

  for(int i=0; i<n-1; i++) {
    for(int j=i+1; j<n; j++) {
      if(vAlpha[i]>vAlpha[j]) {
        temp=vAlpha[i];
        vAlpha[i]=vAlpha[j];
        vAlpha[j]=temp;
      }
    }
  }

  cout<<"I prodotti della classe "<<classeProdotto<<" in ordine alfabetico sono: "<<endl;
  for(int i=0; i<n; i++) {
    cout<<vAlpha[i]<<endl;
  }
  
}

void aggiornaPrezzo(string codice[], float prezzo[], float prezzo1[]) {
    
  int nProdotti=0;
  
  cout<<"Quanti prodottti vuoi aggiornare ? : ";
  cin>>nProdotti;
    
  for(int i=0; i<nProdotti; i++) {
    cout<<"Inserisci il codice del prodotto da aggiornare e il nuovoi prezzo: ";
    cin>>codice[i]>>prezzo1[i];
  }

  for(int i=0; i<nProdotti; i++) {
    prezzo[i]=prezzo1[i];
  }
  
  
}


float media(string classe[], float prezzo[], int n, float prezziClasse[], int &d) {
  float somma=0.00;
  float m=0.00;
  string classeProdotto;
  
  cout<<"Inserisci la categoria del prodotto: ";
  cin>>classeProdotto;


  
  
  for(int i=0; i<n; i++) {
    if(classeProdotto==classe[i]) {
      d=d+1;
      prezziClasse[i]=prezzo[i];
    }
  }

  for(int j=0; j<d; j++) {
    somma=somma+prezziClasse[j];
  }

  m=somma/d;


  return m;
  
}



void fasciaPrezzo(string codice[], string nomi[], string casa[], float prezzo[], string classe[], int n) {

  float prezzoMin;
  float prezzoMaggiore;

  cout<<"Inserisci il prezzo massimo che puoi spendere: ";
  cin>>prezzoMaggiore;
  cout<<"Inserisci il prezzo minimo che puoi spendere: ";
  cin>>prezzoMin;

  for(int i=0; i<n; i++) {
    if(prezzo[i]>prezzoMin&&prezzo[i]<prezzoMaggiore) {
      cout<<endl;
      cout<<"Codice prodotto: "<<codice[i]<<endl;
      cout<<"Nome prodotto: "<<nomi[i]<<endl;
      cout<<"Casa produttrice del prodotto: "<<casa[i]<<endl;
      cout<<"Categoria prodotto: "<<classe[i]<<endl;
      cout<<"Prezzo prodotto: "<<prezzo[i]<<endl;
      cout<<endl;
    }
  }
  
}


void stampaMassimo(string nomi[], float prezzo[], int n, string classe[], string casa[], string codice[]) {
  string classeProdotto;
  int prezzoMax=0;
  int pos=0;

  for(int i=0; i<n; i++) {
    if(prezzo[i]>prezzoMax) {
      prezzoMax=prezzo[i];
      pos=i;
    }
  }

  cout<<"Il codice del prodotto e' : "<<codice[pos]<<endl;
  cout<<"Il nome del prodotto e' : "<<nomi[pos]<<endl;
  cout<<"La casa produttrice del prodotto e' : "<<casa[pos]<<endl;
  cout<<"La categoria del prodotto e' : "<<classe[pos]<<endl;
  cout<<"Il prezzo del prodotto e' : "<<prezzo[pos]<<endl;



  
}
