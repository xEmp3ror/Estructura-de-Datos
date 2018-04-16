# Estructura de Datos
Todos los apuntes y archivos de la asignatura de Estructura de Datos impartida por _Nicolás Luis Fernández García_ durante el curso 2018.

En este repositorio se encontrarán todas las prácticas resueltas.

## Work in progress.

+ Cambiar todos los `toUnisgned()` para que anuncie el error de que es negativo.

# PRÁCTICA 1: Vectores libres de tres dimensiones.

Entregado: **Lunes, 5 de marzo de 2018 a las 15h11.**

Nota obtenida: 6,5.

## Errores detectados durante la corrección de la práctica:

+ Debería haber incluido alguna opción nueva e "interesante" en el menú.

+ En la función leerVector3D(), debería pedir las componentes una a una.

+ No ha codificado correctamente el producto vectorial.

+ Debería codificar los asertos para comprobar las pre y post condiciones con verdadera "pasión informática".

+ En la función crossProduct, se recomienda devolver una referencia a un objeto de la clase Vector3D para mejorar la eficiencia.

+ En la función angulo(), debe controlar el argumento del arco coseno para que esté en dominio [-1.0,1.0]

        valor = this->dotProduct(v)/(this->modulo()*v.modulo();

        if (valor > 1.0)
                valor = 1.0;
        else if (valor < -1.0)
                valor = -1.0;
        
        valor=acos(valor);

+ Debe revisar y corregir los avisos que genera doxygen.

+ También debe comentar con doxygen los atributos de la clase Vector3D

+ También debe comentar con "entusiasmo" todas las funciones de la clase Vector3D

# PRÁCTICA 2: Provincia compuesta por una lista de municipios.

Entregado: **Lunes, 9 de abril de 2018 a las 15h46.**

Nota obtenida: 6,0.

## Errores detectados durante la corrección de la práctica:

+ Al cargar desde un fichero, no controla el final.
Además, al cargar un fichero, debe comprobar que un municipio no existe antes de insertarlo.

+ Se recomienda "encarecidamente" que las funciones más complejas se codifiquen en el fichero cpp y las elementales en el hpp.

+ Se genera un error de ejecución. No se controla inserción de municipio duplicado.

+ Al insertar un municipio, debe pedir el número de hombres y de mujeres.

+ Debería incluir alguna opción nueva e interesante en el menú.

+ Debe comentar con doxygen todas las funciones y lo debe hacer con "entusiasmo".

+ Debe revisar y corregir todos los avisos de doxygen.

# PRÁCTICA 3: Montículo de mediciones de precipitaciones de lluvia.

Entrega: _Lunes, 7 de mayo de 2018 a las 16h00._

Nota obtenida: TBD.

## Por hacer:

+ Clase `MonticuloMediciones`:

	+ `Medicion getElement(i: Entero)`. **DONE.**
	+ `Void setElement()`.
	+ `Entero getLeftChild(i: Entero)`. **DONE.**
	+ `Entero getRightChild(i: Entero)`. **DONE.**
	+ `Entero getParent(i: Entero)`. **DONE.**
	+ `Void shiftUp(i: Entero)`. **DONE.**
	+ `Void shiftDown(i: Entero)`. **DONE.**
	+ `Bool has(medicion: Medicion)`.


	+ `Bool isEmpty()`. **DONE.**
	+ `Entero size()`. **DONE.**
	+ `Medicion top()`. **DONE.**


	+ `Void insert(medicion: Medicion)`.
	+ `Void remove()`.
	+ `Void removeAll()`.
	+ `Void modify()`.


	+ `MonticuloMediciones operador=(m: MonticuloMediciones)`.


	+ `Void print()`.

## Errores detectados durante la corrección de la práctica:

*La práctica aún no se ha corregido.*