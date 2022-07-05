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
    <li>Oscar J Blancarte Iturralde. Introducción a los patrones de diseño. Un enfoque práctico (Spanish Edition. CreateSpace Independent Publishing Platform (2016)</li>
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


<table>
    <theader>
        <tr><th colspan="2">EXAMEN FINAL</th></tr>
    </theader>
<tbody>

<tr><td>Ejercicio:</td><td>Productores-COnsumidores</td></tr>
<tr><td colspan="2">RECURSOS:
    <ul>
        <li>https://github.com/rescobedoulasalle/git_github/</li>
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
        <li>Sharmelyn  - correo@ulasalle.edu.pe</li>
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

- Uno de los problemas màs comunes en programación concurrente es el de: productores-consumidores. Existe uno o más procesos generando letras del alfabeto e ingresándolos a un buffer. Existe uno o más consumidores que consume las letras del alfabeto. Es decir que solo los productores o los consumidores, no ambos al mismo tiempo, pueden acceder al buffer en un momento dado. 
La resolución del ejercicio se realizó en el lenguaje de programación C++ y con el paradigma POO, creando clases para los productores, consumidores y para el monitor. Se hizo uso de la librería ``` <thread> ```, que ejecutará en forma paralela el programa. La librería ``` <stdio.h> ```,  nos permite la manipulaciòn de las funciones de entradas y salidas. La librerìa <stdlib.h>  es una librería estándar de C++. La librerìa <mutex> para los estados lock o unlocked, esto funciona   como un candado para el monitor. La librerìa <queue> para generar una cola de entrada y salida de los caracteres del alfabeto.
 

### Clase Monitor

Los productores y consumidores se comunican con el monitor. Se creó un método (insertar) mediante el cual el productor activará una operación que es insertar. Con una estructura similar se creó un método (extraer) mediante el cual el consumidor activará una operación que es extraer.  

Se asignó una cantidad de 2000 al buffer, la cual es el límite del buffer. Cuando llegue a 2000, se lanzará un mensaje indicando que se está creando letras de más, las cuales se identifican como el sobrante.

El monitor tiene un candado, que se abre o se cierra, porque existen los métodos que insertan o extraen. Al momento de insertar o extraer tienen estos candados, lock o unlock, según corresponda.

El método pantalla, muestra el comportamiento de los productores y consumidores.

``` c++

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
```



### Clase Productor

``` c++
class Productor
{
private:
	thread t;
	int k;
	void run_thread()
	{
		int aleatorio;
		for (int i = 1; true; i++)
		{
			aleatorio = rand() % 26;
			printf("(%d) Productor-%d estoy produciendo : %c \n", i, k, letras[aleatorio]);
		}
	}

public:
	Productor(int id)
	{
		k = id;
		t = thread(&Productor::run_thread, this);
		// t.join();
	}
	void join_thread()
	{
		t.join();
	}
};

```


 
## REFERENCIAS
-   Oscar J Blancarte Iturralde. Introducción a los patrones de diseño_ Un enfoque práctico (Spanish Edition. CreateSpace Independent Publishing Platform (2016)

#

 

  
[Git]: https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white
[git-site]: https://git-scm.com/

[GitHub]: https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white
[github-site]: https://github.com/

 
 [![Git][Git]][git-site]
[![GitHub][GitHub]][github-site]
 