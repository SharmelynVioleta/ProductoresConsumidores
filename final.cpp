#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

#define NUM_PRODUCTOR 3
#define NUM_CONSUMIDOR 2

int cont = 0;
int sobra = 0;
mutex flag;

const char letras[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
queue<char> buffer;

class Monitor
{
public:
    void insertar(char alpha, int item)
    {
        flag.lock();
        if (buffer.size() == 100)
        {
            sobra += 1;
            cout << "Hay sobra" << endl;
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
            cout << "Estoy sin nada" << endl;
        }
        else
        {
            buffer.pop();
            pantalla(alpha, "consumidor", item);
        }
        flag.unlock();
    }

    void pantalla(char alpha, string personaje, int item)
    {
        if (personaje == "productor")
        {
            cout << personaje << item << " produjo: "
                 << alpha << "\tEn elbuffer hay: "
                 << buffer.size() << " elementos."
                 << "\tLa sobra es: " << sobra << endl;
        }
        else
        {
            cout << personaje << item << " consume: "
                 << alpha << "\tEn elbuffer hay: "
                 << buffer.size() << " elementos."
                 << "\tLa sobra es: " << sobra << endl;
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
            sleep(2);
            random = rand() % 26;
            monitor->insertar(letras[random], item);
        }
    }

public:
    Productor(int id, Monitor *monit)
    {
        monitor = monit;
        item = id;
        t = thread(&Productor::run_thread, this);
    }
    void join_thread()
    {
        t.join();
    }
};

class Consumidor
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
            sleep(2);
            random = rand() % 26;
            monitor->extraer(letras[random], item);
        }
    }

public:
    Consumidor(int id, Monitor *monit)
    {
        monitor = monit;
        item = id;
        t = thread(&Consumidor::run_thread, this);
    }
    void join_thread()
    {
        t.join(); // START
    }
};

int main()
{
    Productor *productor[NUM_PRODUCTOR];
    Consumidor *consume[NUM_PRODUCTOR];

    Monitor *monit;

    int i;
    for (i = 0; i < NUM_PRODUCTOR; i++)
    {
        int id = i + 1;
        productor[i] = new Productor(id, monit);
    }

    for (i = 0; i < NUM_CONSUMIDOR; i++)
    {
        int id = i + 1;
        consume[i] = new Consumidor(id, monit);
    }

    for (i = 0; i < NUM_PRODUCTOR; i++)
    {
        productor[i]->join_thread();
    }

    for (i = 0; i < NUM_CONSUMIDOR; i++)
    {
        productor[i]->join_thread();
    }

    return 0;
}
