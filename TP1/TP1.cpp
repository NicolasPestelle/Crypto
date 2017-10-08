#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string chiffrement (string texte, string cle){
 cout<<"je chiffre"<< endl;


 int indiceCle = 0;

 string crypte;
 
  for (int i = 0; i < texte.length();i++){
   if ((int)texte[i]>= 62 && (int)texte[i]<=90 || (int)texte[i]>=97 && (int)texte[i]<=122){
     crypte += ((int)texte[i]-'a' + cle[indiceCle]-'a')%26  + 'a';
	 cout << crypte << endl;
   }

        indiceCle ++;
     
     if(indiceCle == cle.length()){
       indiceCle = 0;
       }
     
 }
  return crypte;
     
   }


void dechiffrement(string texte, string cle){
  cout << "je dechiffre"<< endl; 
  string crypte;
 int indiceCle = 0;
  for (int i = 0; i < texte.length();i++){
   if ((int)texte[i]>= 62 && (int)texte[i]<=90 || (int)texte[i]>=97 && (int)texte[i]<=122){
     crypte += (((int)texte[i]-'a') - (cle[indiceCle]-'a')+26)%26  + 'a';
	 cout << crypte << endl;
   }

        indiceCle ++;
     
     if(indiceCle == cle.length()){
       indiceCle = 0;
       }
     
 }
}

int main(int argc,char** argv){

  string texte = argv[2];
  string cle = argv[3];


  
  ifstream fichier(argv[2], ios::in);  // on ouvre en lecture
 
  if(fichier)  // si l'ouverture a fonctionné
    {
      string ligne;

      while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"

        {

	  cout << ligne << endl;  // on l'affiche

        }
    }
  else
    cerr << "Impossible d'ouvrir le fichier !" << endl;


  

  //  comparer chaine de carac en c++
  if(argc<4){
    cout<<"Pas assez d'arguments, utiliser ./TP1.out <option> <texte> <cle>"<<endl;
  }else{
    if(argv[1] == string("-c"))
      //on chiffre
      chiffrement((char*)argv[2], (char*)argv[3]);
    else if(argv[1] == string("-d"))
      //on dechiffre
      cout<<"je dechiffre"<< endl;
    else cout << "argument invalide"<< endl;
  }

  /*string crypte =  chiffrement(texte,cle);
    dechiffrement(crypte, cle);*/
  

  return 0;

}
