#include <iostream>
 
using namespace std;
 
int main()
{
    int rows = 20;
    int columns = 20;
    string words[] = {"ciao", "word", "apple", "barbabietole", "oshio", "gianni"};
    char empty = ' ';
 
    int wordsLength = sizeof(words) / sizeof(words[0]);
    int contatore = 0;
    char matrix[rows][columns];
 
    // fill matrix with ' '
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = empty;
        }
    }
 
    for (int index = 0; index < wordsLength; index++)
    {
        if (index % 5 == 1)
        { // orizzontale
            if (words[index].length() > columns)
            {
                cout << "word " << words[index] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % rows; // row random
                int y = random() % (columns - words[index].length());
 
                while (matrix[x][y] != empty)
                {
                    x = random() % rows; // row random
                    y = random() % (columns - words[index].length());
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x][y + i] != empty)
                    {
                        x = random() % rows; // row random
                        y = random() % (columns - words[index].length());
                        i = 0;
                    }
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    matrix[x][y + i] = words[index][i];
                    // cout << "index: " << index << " i: " << i << " x: " << x << " y: " << y << endl;
                    // cout << "matrix[" << x << "][" << y + i << "] = " << words[index][i] << endl;
                    // cout << "result: " << matrix[x][y + i] << endl;
                }
            }
        }
        else if (index % 5 == 2)
        { // verticale
            if (words[index].length() > rows)
            {
                cout << "word " << words[index] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length());
                int y = random() % columns;
 
                while (matrix[x][y] != empty)
                {
                    x = random() % (rows - words[index].length());
                    y = random() % columns;
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x + i][y] != empty)
                    {
                        x = random() % (rows - words[index].length());
                        y = random() % columns;
                        i = 0;
                    }
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    matrix[x + i][y] = words[index][i];
                    // cout << "index: " << index << " i: " << i << " x: " << x << " y: " << y << endl;
                    // cout << "matrix[" << x << "][" << y + i << "] = " << words[index][i] << endl;
                    // cout << "result: " << matrix[x][y + i] << endl;
                }
            }
        }
        else if (index % 5 == 3)
        { // diagonale da sopra a sotto
            if (words[index].length() > rows || words[index].length() > columns)
            {
                cout << "word " << words[index] << " is too long" << endl;
                continue;
            }
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length());
                int y = random() % (columns - words[index].length());
 
                while (matrix[x][y] != empty)
                {
                    x = random() % (rows - words[index].length());
                    y = random() % (columns - words[index].length());
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x + i][y + i] != empty)
                    {
                        x = random() % (rows - words[index].length());
                        y = random() % (columns - words[index].length());
                        i = 0;
                    }
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    matrix[x + i][y + i] = words[index][i];
                }
            }
        }
        else if (index % 5 == 4)
        {
            // da sotto verso sopra
            if (words[index].length() > rows)
            {
                cout << "word " << words[index] << " is too long" << endl;
                continue;
            }
 
            else
            {
                contatore++;
                int x = random() % (rows - words[index].length());
                int y = random() % (columns);
 
                while (matrix[x][y] != empty)
                {
                    x = random() % (rows - words[index].length());
                    y = random() % (columns);
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    if (matrix[x - i][y] != empty)
                    {
                        x = random() % (rows - words[index].length());
                        y = random() % (columns);
                        i = 0;
                    }
                }
 
                for (int i = 0; i < words[index].length(); i++)
                {
                    matrix[x - i][y] = words[index][i];
                }
            }
        }
        // // fill the matrix with random char if empty
        // for (int i = 0; i < rows; i++)
        // {
        //     for (int j = 0; j < columns; j++)
        //     {
        //         if (matrix[i][j] == empty)
        //         {
        //             matrix[i][j] = random() % 25 + 97;
        //         }
        //     }
        // }
    }
 
    cout << "devi trovare " << contatore << " parole" << endl;
 
    // print
    cout << "    ";
    for (int i = 0; i < columns; i++)
    {
        if (i < 10)
        {
            cout << " " << i;
        }
        else
        {
            cout << " " << i;
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
 
        if (i < 10)
        {
            cout << "  " << i << " |";
        }
        else
        {
            cout << " " << i << " |";
        }
 
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}