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

# Patrón Composite

  
 [![Git][Git]][git-site]
[![GitHub][GitHub]][github-site]
 
#
 
## CONTENIDO 
- Introducción
- Código Productores y Consumidores
- Ejecución

### Introducción

-   Patrón composite
    -   Si ud. quiere crear estructuras complejas a partir de estructuras simples. Este patrón puede ayudarlo.

 

### Clase Productor

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




 
## REFERENCIAS
-   Oscar J Blancarte Iturralde. Introducción a los patrones de diseño_ Un enfoque práctico (Spanish Edition. CreateSpace Independent Publishing Platform (2016)

#

 

  
[Git]: https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white
[git-site]: https://git-scm.com/

[GitHub]: https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white
[github-site]: https://github.com/

 
 [![Git][Git]][git-site]
[![GitHub][GitHub]][github-site]
 