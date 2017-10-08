#include <iostream>
#include <string>

using namespace std;

string chiffrement (string texte, string cle){
 cout<<"je chiffre"<< endl;

 string crypte;
 int indiceCle = 0;
 
 //principe :
 //on lis le fichier txt
 //repeter la clé au meme taille que les carac
 //on additione a chaques fois les indice %26
 //on écrit le rez dans un txt

 
 //chiffre : texte + cle -'a'-'a'


 
  for (int i = 0; i < texte.length();i++){
   if ((int)texte[i]>= 62 && (int)texte[i]<=90 || (int)texte[i]>=97 && (int)texte[i]<=122){
     crypte += ((int)texte[i]-'a' + cle[indiceCle]-'a')%26  + 'a';
     //  cout<<((int)texte[i]-'a' + cle[indiceCle]-'a')%26  + 'a'<<endl;
	 cout << crypte << endl;
   }

        indiceCle ++;
     
     if(indiceCle == cle.length()){
       indiceCle = 0;
       }
     
 }
  return crypte;

     // cout << crypte << endl;

      /*  cout << "------"<< endl;
	  cout << cle[indiceCle] << endl;*/
     
   }
 /*
  cout << texte << endl;
 cout << " ----------- " <<endl;
 cout << cle << endl;*/


void dechiffrement(string texte, string cle){
  cout << "je dechiffre"<< endl; 
 //principe :
 //on lis le fichier txt
 //repeter la clé au meme taille que les carac
 //on additione a chaques fois les indice %26
 //on écrit le rez dans un txt
  string crypte;
 int indiceCle = 0;
  for (int i = 0; i < texte.length();i++){
   if ((int)texte[i]>= 62 && (int)texte[i]<=90 || (int)texte[i]>=97 && (int)texte[i]<=122){
     crypte += (((int)texte[i]-'a') - (cle[indiceCle]-'a')+26)%26  + 'a';
     //  cout<<((int)texte[i]-'a' + cle[indiceCle]-'a')%26  + 'a'<<endl;
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
  
  /*  comparer chaine de carac en c++
      if(argc<4){
      cout<<"Pas assez d'arguments, utiliser ./TP1.out <option> <texte> <cle>"<<endl;
      }else{
      if((char*)argv[1]=="-c")
      //on chiffre
      chiffrement((char*)argv[2], (char*)argv[3]);
      else if((char*)argv[1] == "-d")
      //on dechiffre
      cout<<"je dechiffre"<< endl;
      else cout << "argument invalide"<< endl;
      }*/

 string crypte =  chiffrement(texte,cle);
  dechiffrement(crypte, cle);
  

  return 0;

}
