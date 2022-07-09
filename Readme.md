<div align="center">
<table>
    <theader>
        <tr>
            <th><img src="https://github.com/rescobedoulasalle/git_github/blob/main/ulasalle.png?raw=true" alt="EPIS" style="width:50%; height:auto"/></th>
            <th>
                <span style="font-weight:bold;">UNIVERSIDAD LA SALLE</span><br />
                <span style="font-weight:bold;">FACULTAD DE INGENIERÍAS</span><br />
                <span style="font-weight:bold;">DEPARTAMENTO DE INGENIERÍA Y MATEMÁTICAS</span><br />
                <span style="font-weight:bold;">CARRERA PROFESIONAL DE INGENIERÍA DE SOFTWARE</span>
            </th>            
        </tr>
    </theader>
    
</table>
</div>
 

<table>
    <theader>
        <tr><th colspan="2">EXÀMEN FINAL</th></tr>
    </theader>
<tbody>

<tr><td>EJERCICIO:</td><td>Productores-COnsumidores</td></tr>
<tr><td colspan="2">RECURSOS:
    <ul>
        <li>https://github.com/rescobedoulasalle/so/</li>
        <li>http://cotana.informatica.edu.bo/downloads/Sistemas%20Operativos.pdf</li>
    </ul>
</td>
</<tr>
<tr><td colspan="2">DOCENTE:
    <ul>
        <li>Richart Smith Escobedo Quispe  - r.escobedo@ulasalle.edu.pe</li>
    </ul>
</td>


<tr><td colspan="2">ALUMNA:
    <ul>
        <li>Sharmelyn Violeta Bautista Luque  - sbautistal@ulasalle.edu.pe</li>
    </ul>
</td>
</<tr>
</tdbody>
</table>



# Productores Consumidores

  
 [![Git][Git]][git-site]
[![GitHub][GitHub]][github-site]
 
#
 
## CONTENIDO 
- Introducción
- Código Productores y Consumidores
- Ejecución

### Introducción

 Uno de los problemas màs comunes en programación concurrente es el de: productores-consumidores. Existe uno o más procesos generando letras del alfabeto e ingresándolos a un buffer. Existe uno o más consumidores que consume las letras del alfabeto. Es decir que solo los productores o los consumidores, no ambos al mismo tiempo, pueden acceder al buffer en un momento dado. 
La resolución del ejercicio se realizó en el lenguaje de programación C++ y con el paradigma POO, creando clases para los productores, consumidores y para el monitor. Se hizo uso de la librería ``` <thread> ```, que ejecutará en forma paralela el programa. La librería ``` <stdio.h> ```,  nos permite la manipulaciòn de las funciones de entradas y salidas. La librerìa ```<stdlib.h> ``` es una librería estándar de C++. La librerìa ```<mutex> ```para los estados lock o unlocked, esto funciona   como un candado para el monitor. La librerìa ```<queue> ```para generar una cola de entrada y salida de los caracteres del alfabeto.
  
### Código Productores y Consumidores

<<<<<<< HEAD
=======
###  Código Productores y Consumidores


>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d
#### Clase Monitor
 
Los productores y consumidores se comunican con el monitor. Se creó un método (insertar) mediante el cual el productor activará una operación que es insertar. Con una estructura similar se creó un método (extraer) mediante el cual el consumidor activará una operación que es extraer.  

Se asignó una cantidad de 2000 al buffer, la cual es el límite del buffer. Cuando llegue a 2000, se lanzará un mensaje indicando que se está creando letras de más, las cuales se identifican como el sobrante.

Un proceso puede entrar en el monitor, el otro proceso se añadirà a la cola de espera, debido a que la entrada y salida estàn protegidas. El monitor tiene un candado, que se abre o se cierra, porque existen los métodos que insertan o extraen. Al momento de insertar o extraer tienen estos candados, lock o unlock, según corresponda. Una vez que un mètodo se esté ejecutando en el monitor, el monitor, temporalmente se bloquea a sí mismo.

El método pantalla, muestra el comportamiento de los productores y consumidores.
 



``` c++

class Monitor
{
public:
    void insertar(char alpha, int item)
    {
        flag.lock();
        if (buffer.size() == 100)
        {
            sobra += 1;
<<<<<<< HEAD
            cout << "Hay sobra" << endl;
=======
            cout << "Hay sobrante" << endl;
>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d
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
            pantalla(alpha, "consumidor", item);
        }
        flag.unlock();
    }

    void pantalla(char alpha, string personaje, int item)
    {
        if (personaje == "productor")
        {
            cout << personaje << item << " produjo: "
<<<<<<< HEAD
                 << alpha << "\tEn elbuffer hay: "
                 << buffer.size() << " elementos."
=======
                 << alpha << "\tEs el elemento: " << buffer.size()
>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d
                 << "\tLa sobra es: " << sobra << endl;
        }
        else
        {
            cout << personaje << item << " consume: "
<<<<<<< HEAD
                 << alpha << "\tEn elbuffer hay: "
                 << buffer.size() << " elementos."
=======
                 << alpha << "\tEs el elemento : " << buffer.size()
>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d
                 << "\tLa sobra es: " << sobra << endl;
        }
    }
};
```



#### Clase Productor

La clase productor solo puede añadir caracteres al buffer mediante el método insertar. Este método escoge de manera aleatoria los caracteres a ingresarse en el buffer. Se comprueba si hay espacio disponible en el buffer, sino el monitor bloqueará la entrada y lanzará un mensaje diciendo que hay demás, es decir que sobra producto. Cuando el buffer esté vacío el proceso que se encuentra en la cola retomará su actividad y seguirá añadiendo caracteres. El mètodo run_thread(), se invoca a sí mismo, mientras el método join_thread() dará inicio a la ejecución.

``` c++
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
<<<<<<< HEAD
            sleep(2);
=======
            sleep(1);
>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d
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

```

#### Clase Consumidor

La clase consumidor solo puede extraer caracteres del buffer mediante el método extraer. Este método escoge de manera aleatoria los caracteres a extraerse del buffer. Se comprueba si hay elementos en el buffer e irá consumiendo aleatoriamente hasta que el buffer esté vacío. Cuando el buffer esté lleno el proceso que se encuentra en la cola retomará su actividad y seguirá extrayendo caracteres. El mètodo run_thread(), se invoca a sí mismo, mientras el método join_thread() dará inicio a la ejecución.

``` c++
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
<<<<<<< HEAD
            sleep(2);
=======
            sleep(1);

>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d
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

```
<<<<<<< HEAD

#### Main


### Ejecución

     ![alt text](https://github.com/SharmelynVioleta/Patron_Builder/blob/master/imagenes/patron_builder_estructura.JPG)
=======
 

#### Main

En el main se llama a las clases principales Productor, Consumidor y Monitor. 

``` c++

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
        productor[i]->join_thread(); //	START
    }

    for (i = 0; i < NUM_CONSUMIDOR; i++)
    {
        productor[i]->join_thread(); //	START
    }

    return 0;
}

```


### Ejecución

>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d



## REFERENCIAS
<<<<<<< HEAD
-   William Stallings. Sistemas Operativos_Aspectos interos y principios de diseño. Pearson Educación S.A. (2005)
=======
-   William Stallings. Sistemas Operativos - Aspectos internos y principios de diseño. Pearson Educación S.A. (2005)
>>>>>>> 54e27c6a16d96b6923718c6e69841d733e4f920d

#

 

  
[Git]: https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white
[git-site]: https://git-scm.com/

[GitHub]: https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white
[github-site]: https://github.com/

 
 [![Git][Git]][git-site]
[![GitHub][GitHub]][github-site]
 