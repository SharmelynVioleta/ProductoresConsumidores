#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <thread>
#include <mutex>

using namespace std;

#define NUM_HILOS 10

int cont = 0;
int sobra = 0;
mutex flag;

queue<char> buffer;
const char letras[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

class Monitor
{
public:
    void insertar(char alpha, int item)
    {
        flag.lock();
        if (buffer.size() == 2000)
        {
            sobra += 1;
            cout << "Soy el sobrante" << endl;
        }
        else
        {
            buffer.push(alpha);
            pantalla(alpha, "productor", item);
        }
        flag.unlock();
    }

    void extraer(char alpha, int item)
    {
        flag.lock();
        if (buffer.empty())
        {
            sobra += 1;
            cout << "Estoy sin nada" << endl;
        }
        else
        {
            buffer.pop();
            pantalla(alpha, "productor", item);
        }
        flag.unlock();
    }

    void pantalla(char alpha, string personaje, int item)
    {
        if (personaje == "productor")
        {
            cout << personaje << item << " produjo: "
                 << alpha << "\tCola: " << buffer.size()
                 << "L a sobra es: " << sobra << endl;
        }
        else
        {
            cout << personaje << item << " consume: "
                 << alpha << "\tCola: " << buffer.size()
                 << "L a sobra es: " << sobra << endl;
        }
    }
};

class Hilo
{
private:
    Monitor *monitor;
    thread t;
    void run_thread()
    {
        monitor->insertar(char alpha, int item); //	RUN
    }

public:
    Hilo(Monitor *mon)
    {
        monitor = mon;
        t = thread(&Hilo::run_thread, this);
    }
    void join_thread()
    {
        t.join(); // START
    }
};

int main()
{

    Hilo *hilos[NUM_HILOS];
    Monitor *mo;

    int i;
    for (i = 0; i < NUM_HILOS; i++)
    {
        hilos[i] = new Hilo(mo);
    }

    for (i = 0; i < NUM_HILOS; i++)
    {
        hilos[i]->join_thread(); //	START
    }

    return 0;
}
