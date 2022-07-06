#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <thread>
#include <mutex>

using namespace std;

#define NUM_PRODUCTOR 5

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
        if (buffer.size() == 500)
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

class Productor
{
private:
    Monitor *monitor;
    thread t;
    int item;
    void run_thread()
    {
        int random;
        for (int i = 1; true; i++)
        {
            random = rand() % 26;
            monitor->insertar(item, letras[random]);
        }
    }

public:
    Productor(Monitor *mon, int id)
    {
        monitor = mon;
        item = id;
        t = thread(&Productor::run_thread, this);
    }
    void join_thread()
    {
        t.join(); // START
    }
};

int main()
{
    Productor *productor[NUM_PRODUCTOR];
    Monitor *mo;

    int i;
    for (i = 0; i < NUM_PRODUCTOR; i++)
    {
        int id = i + 1;
        productor[i] = new Productor(mo, id);
    }

    for (i = 0; i < NUM_PRODUCTOR; i++)
    {
        productor[i]->join_thread(); //	START
    }

    return 0;
}
