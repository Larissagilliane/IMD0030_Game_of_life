#ifndef _LIFE_H_
#define _LIFE_H_

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>

using namespace std;

/**
 * @file
 * @author  Larissa Moura
 * @version 1.0
 *
 *
 * @section DESCRIPTION
 *
 * A classe Life representa a forma como o jogo segue, aplicando as regras e conferindo a o status da configuração
 */

class Life
{
    int width, height;
    bool** size ;



public:
	 /**
       * Um construtor.
       * Recebe o tamanho da matriz e a matriz gerado pelo arquivo.
       */
    Life(int, int, bool**);
	
	/**
       * Um membro normal sem argumentos e com retorno void.
       * O jogo é atulizado com as regras definidas
       * @see Life()
       * @see print()
       * @see setAlive()
       * @see extinct()
       * @see stable()
       * @see operator=()
       */

    void update();

    /**
       * Um membro normal sem argumentos e com retorno void.
       * A matriz é impressa atualizada.
       */

    void print();

    /**
       * Um membro sem retorno com um argumento.
       * @param um ponteiro para ponteiro, que referencia a matriz recebida no construtor
       */

    void setAlive(bool**);

    /**
       * Um membro normal sem argumentos e retornando um boleano.
       * Confere o status da matriz se está extinto.
       */

    bool extinct();

    /**
       * Um membro normal com retorno boleano, e com um argumento.
       * @param um ponteiro para ponteiro, que referencia a matriz recebida no setalive.
       */

    bool stable( bool**);
    /**
       * Um membro normal com retorno vazio, e com um argumento.
       * @param matriz passada por referência
       */
    void operator=( Life & matrix ) const;


};

#endif
