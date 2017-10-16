#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string clear(string texte){
  string res ="";

  for(int i = 0; i < texte.length();i++){
    if('a' <= texte[i] && texte[i] <= 'z'){
      res += texte[i]; 
    }else if ('A' <= texte[i] && texte[i] <= 'Z'){
      res += (char)(texte[i]+('a'-'A'));
    }
  }
  return res;
}

int trouverTailleCle(string texte){

  double maxIC = 0.0;
  int tailleCle = 0;


  for (int i =1; i<16;i++){
  double tailleTexte = 0.0;
  double tabOccurence [26];
  double ic = 0.0;

      for(int j = 0; j <26;j++){
	tabOccurence[j] = 0;
    }
      
    for(int j = 0; j <texte.length();j += i){
      tailleTexte ++;
      tabOccurence[texte[j] - 'a'] ++;
    }
    for(int k = 0 ; k < 26; k++){
      ic += (tabOccurence[k]/tailleTexte)*((tabOccurence[k]-1)/(tailleTexte-1));
    }

    if( ic > maxIC){
      maxIC = ic;
      tailleCle = i;
    }
      
  }
  return tailleCle;
}

string chiffrement (string texte, string cle){

  int indiceCle = 0;

  string crypte;
 
  for (int i = 0; i < texte.length();i++){
    if ((int)texte[i]>= 62 && (int)texte[i]<=90 || (int)texte[i]>=97 && (int)texte[i]<=122){
      crypte += ((int)texte[i]-'a' + cle[indiceCle]-'a')%26  + 'a';
    }else{
      crypte += texte[i];
    }

    indiceCle ++;
     
    if(indiceCle == cle.length()){
      indiceCle = 0;
    }
     
  }
  return crypte;
     
}

string trouverCle(string texte){

  string cle = "";
  string txt = clear(texte);
  int taillecle = trouverTailleCle(txt);

  vector<string> tab(taillecle);
 
  for(int j = 0; j< txt.length();j++)
    {
      tab[j%taillecle] += txt[j];
    }
  for(int i = 0; i < taillecle;i++)
    {   
      //do something
    }
  return cle;
}

string dechiffrement(string texte, string cle){
 string decrypte;
 int indiceCle = 0;
  for (int i = 0; i < texte.length();i++){
   if ((int)texte[i]>= 62 && (int)texte[i]<=90 || (int)texte[i]>=97 && (int)texte[i]<=122){
     decrypte += (((int)texte[i]-'a') - (cle[indiceCle]-'a')+26)%26  + 'a';
   }else{
      decrypte += texte[i];
    }

        indiceCle ++;
     
     if(indiceCle == cle.length()){
       indiceCle = 0;
       }     
 }
  return decrypte;
}

int main(int argc,char** argv){

  string texte = argv[1];

  string d = "";
  double resultat = 0.0;
  string clearLine ="";

  
  if(argc<2){
    cout<<"Pas assez d'arguments, utiliser ./casseVigenerre.out <texte>"<<endl;
  }else{
    
      std::ifstream ifs(argv[1]);
      std::string line;

      while (std::getline(ifs, line)) { 
	d += line;
      }

      cout << trouverCle(d);
    }

  return 0;

}
