//
// Created by tuan on 31/08/2022.
//
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

template<class T>
void show_2d_vector(vector<vector<T>> a, int nRow, int nCol, int width = 10) {
    for (int i = 0; i <= nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            cerr << setw(width) << a[i][j];
        }
        cerr << endl;
    }
    cerr << endl;
}

template<class T>
void show_1d_vector(vector<T> a) {
    for (const T &x: a) {
        cerr << x << " ";
    }
    cerr << endl;
}