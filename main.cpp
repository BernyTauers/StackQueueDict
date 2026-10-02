#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Dictionary.h"
using namespace std;

int main() {
    cout << "STACK" << endl;
    Stack pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.print();
    cout << "Elemento en el top: " << pila.top() << endl;
    cout << "Elemento eliminado con pop: " << pila.pop() << endl;
    pila.print();
    cout << "Tamano: " << pila.size() << endl;

    cout << "\n QUEUE " << endl;
    Queue cola;
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);
    cola.print();
    cout << "Elemento al frente: " << cola.front() << endl;
    cout << "Elemento eliminado con dequeue: " << cola.dequeue() << endl;
    cola.print();
    cout << "Tamano: " << cola.size() << endl;

    cout << "\n DICCIONARIO " << endl;
    Dictionary diccionario;
    diccionario.put("Ana", 90);
    diccionario.put("Luis", 85);
    diccionario.put("Pedro", 100);
    diccionario.print();

    cout << "Valor de Luis: " << diccionario.get("Luis") << endl;

    cout << "Actualizando Luis a 95..." << endl;
    diccionario.put("Luis", 95);
    cout << "Nuevo valor de Luis: " << diccionario.get("Luis") << endl;

    cout << "Eliminando Ana..." << endl;
    diccionario.remove("Ana");
    diccionario.print();

    return 0;
}
