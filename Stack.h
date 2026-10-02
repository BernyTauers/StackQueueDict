#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100;
    int datos[MAX];
    int cantidad;

public:
    Stack() {
        cantidad = 0;
    }

    void push(int valor) {
        if (cantidad < MAX) {
            datos[cantidad] = valor;
            cantidad++;
        } else {
            cout << "La pila esta llena" << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "La pila esta vacia" << endl;
            return -1;
        }

        cantidad--;
        return datos[cantidad];
    }

    int top() {
        if (isEmpty()) {
            cout << "La pila esta vacia" << endl;
            return -1;
        }

        return datos[cantidad - 1];
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
        cout << "Stack (tope -> fondo): ";
        for (int i = cantidad - 1; i >= 0; i--) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

#endif
