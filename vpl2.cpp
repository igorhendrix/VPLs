#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    string proib[10];
    int cont[10]={0};
    int n, x=0;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> proib[i];
    }
    cin.ignore();
    
    string frase;
    getline(cin, frase);
    
    string palavra;
    stringstream ss(frase);
    vector<string> palavras;

    while(ss >> palavra){
        palavras.push_back(palavra);
        x++;
    }

    for(int i=0; i<palavras.size(); i++){
        for(int j=0;j<n; j++){
            if (palavras[i] == proib[j]){
            cont[j]++;
            palavras[i] = string(palavras[i].size(), '*');
            break;
            }
        }
    }

    for(int i=0; i<x; i++){
        cout << palavras[i] << " ";
    }

    puts("\n");

    for(int i=0; i<n; i++){
        cout << "Palavra " << proib[i] << " substituida " << cont[i] << " vez(es)." << endl;
    }

return 0;
}


/*
1 PEGAR O NUMERO DE PALAVRAS PROIBIDAS
    - salvar para percorrer em loop
2 PEGAR AS PALAVRAS PROIBIDAS
    - a cada loop, salvar uma palavra
3 PEGAR A FRASE ESCRITA
    - salvar com getline
4 COMPARAR CADA PALAVRA DA FRASE COM CADA PALAVRA PROIBIDA
    - desmembrar a frase em palavras a serem salvas
    - salvar cada palavra da frase
    - loop para comparar tudo
5 SUBSTITUIR AS PROIBIDAS POR "*"
    - se igual, pegar a quantidade de letras e escrever os "*"
6 DIGITAR A FRASE COM AS PALAVRAS ALTERADAS
    - cout em loop das palavras

*/