#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Un videogioco prevede che il proprio avatar venga paracadutato su una mappa.
 * La mappa è divisa in celle a cui è associato un numero indicante l’altitudine. 
 * Un giocatore furbo deve far atterrare il proprio avatar in una cella con 
 * un'altitudine superiore o uguale a quella delle celle adiacenti per 
 * non essere svantaggiato. 
 * Infatti, il giocatore furbo deve poter attaccare dall’alto i giocatori 
 * atterrati su celle con altitudine più bassa o almeno 
 * deve poter fronteggiare gli altri giocatori ad armi pari, cioè a pari altitudine. 
 * Tuttavia, il giocatore deve decidere in fretta dove far atterrare il proprio 
 * avatar, in quanto aprire il paracadute troppo tardi 
 * causerà la morte del proprio avatar e la perdita della partita ancora prima 
 * di iniziarla.
 *
 * Supponi di essere il giocatore e di 
 * rappresentare la mappa nella tua mente come una matrice quadrata 
 * NxN  di numeri positivi, 
 * mentre le locazioni esterne alla mappa sono rappresentate con un numero negativo.
 * Sviluppa un algoritmo divide et impera EFFICIENTE
 * per trovare le coordinate di una cella 
 * che non fornisca uno svantaggio una volta atterrato. 
 * Lo spazio aggiuntivo utilizzabile è O(1).
 *
 * */
int findMaxInColumn(const vector<vector<int>>& matrix, int column, int top, int bottom) {
    int maxRow = top;
    for (int i = top + 1; i <= bottom; i++) {
        if (matrix[i][column] > matrix[maxRow][column]) {
            maxRow = i;
        }
    }
    return maxRow;
}

// Funzione ricorsiva per il divide et impera
pair<int, int> findLandingCell(const vector<vector<int>>& matrix, int left, int right, int top, int bottom) {
    if(left > right || top > bottom) return {-1, -1}; // caso base sono uscito dalla matrice 
    
    int midCol = (left + right) / 2;

    int maxRow = findMaxInColumn(matrix, midCol, top, bottom);

    int current = matrix[maxRow][midCol];
    int leftCurrent = (midCol - 1 >= left) ? matrix[maxRow][midCol - 1] : -1;
    int rightCurrent = (midCol + 1 <= right) ? matrix[maxRow][midCol + 1] : -1;
    int topCurrent = (maxRow - 1 >= top) ? matrix[maxRow - 1][midCol] : -1;
    int bottomCurrent = (maxRow + 1 <= bottom) ? matrix[maxRow + 1][midCol] : -1;
    int topLeftCurrent = (maxRow - 1 >= top && midCol - 1 >= left) ? matrix[maxRow - 1][midCol - 1] : -1;
    int topRightCurrent = (maxRow - 1 >= top && midCol + 1 <= right) ? matrix[maxRow - 1][midCol + 1] : -1;
    int bottomLeftCurrent = (maxRow + 1 <= bottom && midCol - 1 >= left) ? matrix[maxRow + 1][midCol - 1] : -1;
    int bottomRightCurrent = (maxRow + 1 <= bottom && midCol + 1 <= right) ? matrix[maxRow + 1][midCol + 1] : -1;

    if (current < leftCurrent) {
        return findLandingCell(matrix, left, midCol - 1, top, bottom);
    } else if (current < rightCurrent) {
        return findLandingCell(matrix, midCol + 1, right, top, bottom);
    } else if (current < topCurrent) {
        return findLandingCell(matrix, left, right, top, maxRow - 1);
    } else if (current < bottomCurrent) {
        return findLandingCell(matrix, left, right, maxRow + 1, bottom);
    } else if (current < topLeftCurrent) {
        return findLandingCell(matrix, left, midCol - 1, top, maxRow - 1);
    } else if (current < topRightCurrent) {
        return findLandingCell(matrix, midCol + 1, right, top, maxRow - 1);
    } else if (current < bottomLeftCurrent) {
        return findLandingCell(matrix, left, midCol - 1, maxRow + 1, bottom);
    } else if (current < bottomRightCurrent) {
        return findLandingCell(matrix, midCol + 1, right, maxRow + 1, bottom);
    } else {
        return {maxRow, midCol};
    }
}

void findGoodCell(vector<vector<int>>& map, int columns, int& index_row, int& index_column) {
    pair<int, int> result = findLandingCell(map, 0, columns - 1, 0, map.size() - 1);
    index_row = result.first;
    index_column = result.second;
}

vector<vector<int>> read_matrix(int dim_r, int dim_c) {
    vector<vector<int>> res;
    if ((dim_r != 0) && (dim_c != 0)) {
        string delimiter = " ";
        string line;
        for(int i = 0; i < dim_r; i++) {
            getline(cin, line);
            vector<int> row;
            for(int j = 0; j < dim_c; j++) {
                string key_str = line.substr(0, line.find(delimiter));
                int key = stoi(ltrim(rtrim(key_str)));
                row.push_back(key);
                line.erase(0, line.find(delimiter) + delimiter.length());
            }
            res.push_back(row);
        }
    }
    return res;
}

int main() {
    
    int dim_r, dim_c;
    vector<vector<int>> field;
    
    string dim_temp;
    getline(cin, dim_temp);
    dim_r = stoi(ltrim(rtrim(dim_temp)));
    
    getline(cin, dim_temp);
    dim_c = stoi(ltrim(rtrim(dim_temp)));
    
    field = read_matrix(dim_r, dim_c);
    
    int index_row, index_column;
    
    findGoodCell(field, dim_c, index_row, index_column);
    
    cout << index_row << " " << index_column;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
