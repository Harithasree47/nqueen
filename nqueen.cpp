// nqueen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<vector>
using namespace std;
void placequeens(vector<vector<int>>& v, int n) {
    int i = 0, j, k;
    int size;
    srand(time(NULL));
    //0 for an empty space
    //1 for position being placed
    //2 for the position where the queen attacks
    while (i < n) {
        vector<int> v1;
        for (k = 0; k < n; k++) {
            if (v[i][k] == 0) {
                //push the position into the empty slot
                //previously you have entered value at the current position...
                //you should insert the position in the vector...
                v1.push_back(k);
            }
        }
        size = v1.size();
        if (size == 0) {
            //no empty spaces are available for a qqueen to be placed
            //so reset the board
            for (k = 0; k < n; k++) {
                for (j = 0; j < n; j++) {
                    v[k][j] = 0;
                }
            }
            i = 0;
            continue;
        }
        int r = v1[rand() % size];
        //make the randomly selected position of the queen as 1
        v[i][r] = 1;
        // make the current row except r as attacked i.e 0's
        for (j = 0; j < n; j++) {
            if (j != r) {
                v[i][j] = 2;
            }
        }
        //make the current column as
        for (k = i + 1; k < n; k++) {
            v[k][r] = 2;
        }
        j = i + 1;
        //right diagonal
        for (k = r + 1; k < n && j < n; k++) {
            v[j][k] = 2;
            j++;
        }
        j = i + 1;
        //left diagonal
        for (k = r - 1; k >= 0 && j < n; k--) {
            v[j][k] = 2;
            j++;
        }
        i++;
    }
    return;
}
int main()
{
    srand(time(NULL));
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    placequeens(v, n);

    for (auto i : v) {
        for (auto k : i) {
            if (k == 1) {
                cout << 1 << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

