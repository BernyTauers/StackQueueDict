#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Dictionary.h"
using namespace std;

int aprobadas = 0;
int fallidas = 0;

void comprobar(bool condicion, string nombre) {
    if (condicion) {
        cout << "Ok " << nombre << endl;
        aprobadas++;
    } else {
        cout << "Error " << nombre << endl;
        fallidas++;
    }
}

void probarStack() {
    cout << "\n Pruebas Stack " << endl;

    Stack pila;
    comprobar(pila.isEmpty(), "S1: pila nueva esta vacia");
    comprobar(pila.size() == 0, "S2: pila nueva tiene tamano 0");

    pila.push(10);
    pila.push(20);
    pila.push(30);
    comprobar(pila.size() == 3, "S3: push aumenta el tamano");
    comprobar(pila.top() == 30, "S4: top devuelve el ultimo elemento agregado");
    comprobar(pila.pop() == 30, "S5: pop respeta orden LIFO");
    comprobar(pila.pop() == 20, "S6: segundo pop devuelve 20");

    pila.clear();
    comprobar(pila.isEmpty(), "S7: clear vacia la pila");
}

void probarQueue() {
    cout << "\nPruebas Queue" << endl;

    Queue cola;
    comprobar(cola.isEmpty(), "Q1: cola nueva esta vacia");
    comprobar(cola.size() == 0, "Q2: cola nueva tiene tamano 0");

    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);
    comprobar(cola.size() == 3, "Q3: enqueue aumenta el tamano");
    comprobar(cola.front() == 10, "Q4: front devuelve el primer elemento agregado");
    comprobar(cola.dequeue() == 10, "Q5: dequeue respeta orden FIFO");
    comprobar(cola.dequeue() == 20, "Q6: segundo dequeue devuelve 20");

    cola.clear();
    comprobar(cola.isEmpty(), "Q7: clear vacia la cola");
}

void probarDictionary() {
    cout << "\nPruebas Dictionary" << endl;

    Dictionary diccionario;
    comprobar(diccionario.isEmpty(), "D1: diccionario nuevo esta vacio");

    diccionario.put("Ana", 90);
    diccionario.put("Luis", 85);
    comprobar(diccionario.size() == 2, "D2: put agrega elementos");
    comprobar(diccionario.get("Ana") == 90, "D3: get recupera el valor correcto");
    comprobar(diccionario.contains("Luis"), "D4: contains encuentra una clave existente");
    comprobar(!diccionario.contains("Pedro"), "D5: contains es false para clave inexistente");

    diccionario.put("Luis", 95);
    comprobar(diccionario.get("Luis") == 95, "D6: put actualiza una clave existente");
    comprobar(diccionario.size() == 2, "D7: actualizar una clave no aumenta el tamano");

    comprobar(diccionario.remove("Ana"), "D8: remove elimina una clave existente");
    comprobar(!diccionario.contains("Ana"), "D9: la clave eliminada ya no existe");

    diccionario.clear();
    comprobar(diccionario.isEmpty(), "D10: clear vacia el diccionario");
}

int main() {
    probarStack();
    probarQueue();
    probarDictionary();

    cout << "Pruebas aprobadas: " << aprobadas << endl;
    cout << "Pruebas fallidas: " << fallidas << endl;

    if (fallidas == 0) {
        cout << "Todas las pruebas pasaron correctamente." << endl;
        return 0;
    }

    return 1;
}
