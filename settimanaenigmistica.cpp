#include <iostream>
 
using namespace std;
 
int main()
{
    int righe = 10;
    int colonne = 10;
    string parola[] = {"ciao", "word", "apple", "barbabietole", "oshio"};
    char vuoto = ' ';
 
 
    int parolaLength = sizeof(parola) / sizeof(parola[0]);
    int contatore = 0;
    char matrix[righe][colonne];
 
    // fill matrix with ' '
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrix[i][j] = vuoto;
        }
    }
 
    for (int indice = 0; indice < parolaLength; indice++)
    {
        if (indice % 3 == 0)
        { // orizzontale
            if (parola[indice].length() > colonne)
            {
                cout << "word " << parola[indice] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % righe; // row random
                int y = random() % (colonne - parola[indice].length());
 
                while (matrix[x][y] != vuoto)
                {
                    x = random() % righe; // row random
                    y = random() % (colonne - parola[indice].length());
                }
 
                for (int i = 0; i < parola[indice].length(); i++)
                {
                    if (matrix[x][y + i] != vuoto)
                    {
                        x = random() % righe; // row random
                        y = random() % (colonne - parola[indice].length());
                        i = 0;
                    }
                }
 
                for (int i = 0; i < parola[indice].length(); i++)
                {
                    matrix[x][y + i] = parola[indice][i];
                    // cout << "indice: " << indice << " i: " << i << " x: " << x << " y: " << y << endl;
                    // cout << "matrix[" << x << "][" << y + i << "] = " << parola[indice][i] << endl;
                    // cout << "result: " << matrix[x][y + i] << endl;
                }
            }
        }
        else if (indice % 3 == 1)
        { // verticale
            if (parola[indice].length() > righe)
            {
                cout << "word " << parola[indice] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (righe - parola[indice].length());
                int y = random() % colonne;
 
                while (matrix[x][y] != vuoto)
                {
                    x = random() % (righe - parola[indice].length());
                    y = random() % colonne;
                }
 
                for (int i = 0; i < parola[indice].length(); i++)
                {
                    if (matrix[x + i][y] != vuoto)
                    {
                        x = random() % (righe - parola[indice].length());
                        y = random() % colonne;
                        i = 0;
                    }
                }
 
                for (int i = 0; i < parola[indice].length(); i++)
                {
                    matrix[x + i][y] = parola[indice][i];
                    // cout << "indice: " << indice << " i: " << i << " x: " << x << " y: " << y << endl;
                    // cout << "matrix[" << x << "][" << y + i << "] = " << parola[indice][i] << endl;
                    // cout << "result: " << matrix[x][y + i] << endl;
                }
            }
        }
        else
        {
            // cout << "diagonale" << endl;
        }
    }
 
 
    // // fill the matrix with random char if vuoto
    // for (int i = 0; i < righe; i++)
    // {
    //     for (int j = 0; j < colonne; j++)
    //     {
    //         if (matrix[i][j] == vuoto)
    //         {
    //             matrix[i][j] = random() % 25 + 97;
    //         }
    //     }
    // }
 
    cout << "devi trovare " << contatore << " parole" << endl;
 
    // print
    cout << "    ";
    for (int i = 0; i < colonne; i++)
    {
        if(i < 10){
            cout << " " << i;
        }
        else{
            cout << " " << i;
        }
        
    }
    cout << endl;
    for (int i = 0; i < righe; i++)
    {
        
        if(i < 10){
            cout << "  " << i << " |";
        }
        else{
            cout << " " << i << " |";
        }
        
        for (int j = 0; j < colonne; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}