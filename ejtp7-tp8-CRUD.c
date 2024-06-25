/* Ejercicio extra entre tp7 y tp8 - CRUD de Personas en Arreglo
Ejercicio adicional para practicar.

El ejercicio 15 de la tp7 al cual le agregan un inciso que sea una modificación,
 y de esa forma logran un ABML o CRUD.
Y que los elementos sean un registro con datos: nombre, apellido, DNI (dato único) y teléfono.
TPersona = < nombre E cadena, apellido E cadena, dni E cadena, telefono E Z >
donde el campo dni es único, no existen dos personas en el arreglo que tengan el mismo dni.
Si este ejercicio completo lo hacen sin problemas, lo entienden, entonces vienen bien.

a) Una función llamada Vacia que reciba como parámetro el registro (con el arreglo de personas
 y la cantidad de nombres cargados), y devuelva Verdadero si la lista está vacía y sino debe
 devolver Falso.

b) Una función llamada Llena que reciba como parámetro el registro (con el arreglo de personas
 y la cantidad de nombres cargados), y devuelva Verdadero si el arreglo está completamente lleno
 (es decir si ya tiene 1000 nombres cargados) y sino debe devolver Falso.

c) Una acción que permita insertar una persona en el arreglo. Para ello se pasará como parámetros
 el registro (con el arreglo de nombres y la cantidad de nombres cargados), y el nuevo TPersona a 
 insertar. El nuevo elemento se inserta siempre al final de la lista. Después de ejecutada 
 la acción, la cantidad debe quedar incrementada en una unidad. 
 Tener en cuenta que no debe haber otra persona en la lista con mismo DNI.

d) Una acción que permita suprimir al primer apellido de la lista, no importa cuál es. 
 Simplemente suprime el primero cada vez que la acción es ejecutada. El parámetro que debe recibir
 es el registro (con el arreglo de nombres y la cantidad de nombres cargados) y el apellido de la
 persona a eliminar. Después de ejecutada la acción, la cantidad debe quedar decrementada en una unidad.

e) Una acción que permita suprimir a una persona de la lista. Los parámetros que debe recibir es el
 registro (con el arreglo de nombres y la cantidad de nombres cargados) y el dni de la persona a eliminar.
 Después de ejecutada la acción, si existe la persona con ese dni, la cantidad debe quedar
 decrementada en una unidad y se deben realizar el reacomodo del arreglo, dejando con campos
 en blanco el elemento eliminado.

f) Una acción que permita mostrar todos los datos de las personas de la lista. Los parámetros
 que debe recibir son: el arreglo y la cantidad de nombres que tiene cargados. 

g) Una acción Modificar que permita modificar el nombre, apellido y telefono de una persona. 
  Los parámetros que debe recibir son: el arreglo con la cantidad de nombres que tiene cargados 
  (TData) y un TPersona, La acción debe modificar los datos de la persona si lo encuentran, 
  es decir, si el dni del TPersona pasado como parametro se encuentra en el TData se debe actualizar
  el nombre, apellido y teléfono que se encuentran en el TPersona sino dar un mensaje de que ese
  dni no se encuentra.

*/
