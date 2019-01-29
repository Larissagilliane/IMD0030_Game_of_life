#include "../include/life.h"

Life::Life(int a, int b, bool** size)
{
    height = a;
    width = b;

    this->setAlive(size);

}

void Life::setAlive(bool** matrix )
{
    this->size=matrix;
}

bool Life::stable( bool** matrix ) 
{
    for(int i=0; i<width; i++)
        for (int j = 0; j < height; ++j)
        {

            if(this->size[i][j] != matrix[i][j])
            {
                return false;
            }
        }

    if(!extinct())
    {
        return true;
    }

    return false;

}

bool Life::extinct( ) 
{

    for(int i=0; i<width; i++)
        for (int j = 0; j < height; ++j)
        {
            if (size[i][j])
                return false;
        }
    return true;

}

void Life::operator=( Life & matrix ) const
{

    if(width != matrix.width  && height != matrix.height)
    {
        cout << "ERRO AO COPIAR" << endl;
    }

    for(int i=0; i<width; i++)
        for (int j = 0; j < height; ++j)
        {
            size[i][j] = matrix.size[i][j];
        }
}

void Life::update()
{

    int Surrounding = 0; /**< Variavel inteira. Contabiliza quantas células ao redor */
    bool **tempsize; /**< Matriz boleana. É uma matriz temporária que atualiza de acodo com as células mortas e vivas */
    tempsize = new bool *[height];
    for(int i = 0; i < height; i++)
        tempsize[i] = new bool[width];

    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            if ( (i+1) < height && size[i + 1][j] == true )
            {
                Surrounding++;
            }
            if ( (i-1) >= 0 && size[i - 1][j] == true )
            {
                Surrounding++;
            }
            if ( (j+1) < width && size[i][j+1] == true )
            {
                Surrounding++;
            }
            if ( (j-1) >= 0 && size[i][j-1] == true )
            {
                Surrounding++;
            }
            if ( (i+1) < height && (j+1) < width && size[i+1][j+1] == true )
            {
                Surrounding++;
            }
            if ( (i+1) < height && (j-1) >= 0 && size[i+1][j-1] == true )
            {
                Surrounding++;
            }
            if ( (i-1) >= 0 && (j+1) < width && size[i-1][j+1] == true )
            {
                Surrounding++;
            }
            if ( (i-1) >= 0 && (j-1) >= 0 && size[i-1][j-1] == true )
            {
                Surrounding++;
            }

            if (Surrounding <= 1 || Surrounding > 3) //MORRE
            {
                tempsize[i][j] = false;
            }
            else if (Surrounding == 2 ) //CONTINUA COMO ESTA
            {
                tempsize[i][j] = size[i][j];
            }
            else if (Surrounding == 3) //NASCE
            {
                tempsize[i][j] = true;
            }

            Surrounding = 0;

        }
    }

    if(stable(tempsize))
    {
        cout << "CONFIGURACAO ESTAVEL" << endl;
    }

    for (int i = 0 ; i < height ; i++ )
    {
        for (int j = 0 ; j < width ; j++ )
        {
            size[i][j] = tempsize[i][j];
        }
    }

    if(extinct())
    {
        cout << "CELULAS EXTINTAS" << endl;
    }

    for(int i = 0; i <height; i++)
    {
        delete[] tempsize[i];
    }
    delete[] tempsize;


}

void Life::print()
{
    std::ofstream arquivo( "saida.txt");
    for (int i = 0; i < height ; i++ )
    {
        for (int j = 0 ; j < width ; j++ )
        {
            if ( size[i][j] == true )
            {
                cout << "*";
                arquivo <<"*";
            }
            else
            {
                cout << "-";
                arquivo <<"-";
            }

            if ( (j + 1) >= width )
            {
                cout << endl;
                 arquivo << endl;
            }
        }
    }
    arquivo.close();
}