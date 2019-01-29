#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>

#include "../include/life.h"


 /**
 * @file
 * @brief Função main
 * @param argc um contador inteiro, das linhas de comando
 * @param argc um vetor como argumento das linhas de comando
 * @return um inteiro 0 exit_success
 */

int main (int argc, char** argv)
{

    std::ifstream file(argv[1], std::ifstream::in);
    std::ofstream arquivo( "saida.txt");
    unsigned lines; /**< Variavel sem sinal. Recebe as linhas da matriz */
    file >> lines;
    cout << "LINHAS: "<< lines << endl;

    unsigned columns; /**< Variavel sem sinal. Recebe as colunas da matriz */
    file >> columns;
    cout <<  "columns: " << columns << endl;

    char carc; /**< Valor do caracter. Recebe o caracter do documento */
    file >> carc;
    cout << "CELULAS VIVAS: " <<  carc << endl << endl;

    bool **m; /**< Ponteiro para ponteiro. Matriz criada por alocação dinâmica */
    m = new bool *[lines];
    for(unsigned i = 0; i <lines; i++)
        m[i] = new bool[columns];


    for (unsigned i = 0; i < lines; ++i)
    {
        for (unsigned j = 0; j < columns; ++j)
        {
            char aux;
            file >> aux ;
            if (aux == carc)
            {
                m[i][j] = true ;
            }
            else
            {
                m[i][j] = false;
            }
        }
    }

    if (!file)
    {
        
        cout << "Linhas ?" << endl;
        cin >> lines;
        cout << "columns ?" << endl;
        cin >> columns;
    }

    if(!arquivo ) 
    {  
		cout << " Erro ao abrir arquivo de saida\n";
	}

    Life life(lines, columns, m);
    life.print();
    cout << endl;


    string kbd;
    do
    {
        kbd = "";
        cout << "Digite \"y\" para prosseguir e \"n\" para parar ";
        cin >> kbd;
        cout << endl;

        life.update();
        life.print();

        cout << endl;
    }
    while (kbd == "y");
    

    cout << "ACABOU !!" << endl;

    for(unsigned i = 0; i <lines; i++)
    {
        delete[] m[i];
    }
    delete[] m;

    file.close();

    return EXIT_SUCCESS; 
}
