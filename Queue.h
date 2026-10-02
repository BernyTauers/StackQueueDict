#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int datos[MAX];
    int cantidad;

public:
    Queue() {
        cantidad = 0;
    }

    void enqueue(int valor) {
        if (cantidad < MAX) {
            datos[cantidad] = valor;
            cantidad++;
        } else {
            cout << "La cola esta llena" << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "La cola esta vacia" << endl;
            return -1;
        }

        int valor = datos[0];

        for (int i = 0; i < cantidad - 1; i++) {
            datos[i] = datos[i + 1];
        }

        cantidad--;
        return valor;
    }

    int front() {
        if (isEmpty()) {
            cout << "La cola esta vacia" << endl;
            return -1;
        }

        return datos[0];
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
        cout << "Queue (frente -> final): ";
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

#endif
