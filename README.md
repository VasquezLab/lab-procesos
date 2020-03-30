# PRÁCTICA 1 - PROCESOS #

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
    R//Antes del llamado de fork() se inicializo la variable x en 100. Al ejecutarse el proceso hijo el valor de la variable es 100. 
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
   R//En el proceso hijo se aumento la variable x en 1, por lo que la variable x quedo en el proceso con un valor de 101. En el proceso padre se aumento la variable x en 2, por lo que la variable x quedo en el proceso con un valor de 102.

2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
  R// Si, debido luego de utilizar una función fork() intentamos acceder al file descriptor y en ambos casos se pudo hacer uso de el, lo que significa que el alcance de "fd" es para padre e hijo.
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
      R// Se puso a prueba la escritura dentro del archivo con un ciclo "for", y no presentó ningún problema por lo tanto, no hay incoveniente.

3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
  R//Si es posible que se ejecute el proceso hijo de primero sin llamar a la funcion wait(), esto es posible mendiante el uso de la funcion sleep() en la cual podemos suspender el proceso padre unos segundos garantizando que el  proceso hijo se ejecute primero

4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
    R// Las variaciones que tiene la llamada exec() existen para cuando se desconocen los argumentos, o variables, o por el contrario si se necesita algún argumento o variable, existe una variación que nos permite esto.

5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. 

¿Cuál es el valor de retorno de la función ```wait()```?,
    R// el valor retornado contiene el PID del proceso hijo que finalizó o -1 si no se crearon hijos o si ya no hay hijos por los cuales esperar.

 ¿Qué pasa si usted usa la función ```wait``` en el hijo?
    R// El proceso padre es ejecutado primero, por lo que es igual que no tener el wait() dentro del código, aunque depende el procesador entonces ya va en que lo normal es que el procesador ejecute primero el padre, entonces en dicho caso, tener o no tener el wait() dentro del hijo es igual.

6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?
  R// cuando estamos manejando una gran cantidad de hijos y queremos obtener el estado de cada uno de ellos, esta función nos da una mayor variedad de estados que nos permiten tener más información.

7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
  R//Al cerrar la salida estandar en el proceso hijo y posterior a este llamar un printf(), entonces el resultado  es que no se genera la salida.

8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```


