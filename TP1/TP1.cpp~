#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

  string texte = argv[2];
  string cle = argv[3];
  string result;
  
  if(argc<4){
    cout<<"Pas assez d'arguments, utiliser ./TP1.out <option> <texte> <cle>"<<endl;
  }else{
    if(argv[1] == string("-c")){
      
      std::ifstream ifs(argv[2]);
      std::string line;
      std::ofstream ofs("texteChiffre.txt");
      
      while (std::getline(ifs, line)) { 
	 ofs << chiffrement(line, (char*)argv[3]);
      }
      
    }else if(argv[1] == string("-d")){
      
      std::ifstream ifs(argv[2]);
      std::string line;
      std::ofstream ofs("texteDechiffre.txt");

      while (std::getline(ifs, line)) { 
	ofs << dechiffrement(line, (char*)argv[3]);
      }
      
    }else{
      
      cout << "argument invalide"<< endl;
      
    }
  }

  return 0;

}
