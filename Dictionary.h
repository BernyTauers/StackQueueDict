#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
using namespace std;

class Dictionary {
private:
    static const int MAX = 100;
    string claves[MAX];
    int valores[MAX];
    int cantidad;

public:
    Dictionary() {
        cantidad = 0;
    }

    void put(string clave, int valor) {
        for (int i = 0; i < cantidad; i++) {
            if (claves[i] == clave) {
                valores[i] = valor;
                return;
            }
        }

        if (cantidad < MAX) {
            claves[cantidad] = clave;
            valores[cantidad] = valor;
            cantidad++;
        } else {
            cout << "El diccionario esta lleno" << endl;
        }
    }

    int get(string clave) {
        for (int i = 0; i < cantidad; i++) {
            if (claves[i] == clave) {
                return valores[i];
            }
        }

        cout << "La clave no existe" << endl;
        return -1;
    }

    bool contains(string clave) {
        for (int i = 0; i < cantidad; i++) {
            if (claves[i] == clave) {
                return true;
            }
        }
        return false;
    }

    bool remove(string clave) {
        for (int i = 0; i < cantidad; i++) {
            if (claves[i] == clave) {
                for (int j = i; j < cantidad - 1; j++) {
                    claves[j] = claves[j + 1];
                    valores[j] = valores[j + 1];
                }

                cantidad--;
                return true;
            }
        }

        return false;
    }

    bool isEmpty() {
        return cantidad == 0;
    }

    int size() {
        return cantidad;
    }

    void clear() {
        cantidad = 0;
    }

    void print() {
        cout << "Dictionary:" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "  " << claves[i] << " -> " << valores[i] << endl;
        }
    }
};

#endif
