# Shell
Indicaciones
1.	No debe usar los comandos ya creados ni las funciones de la consola. Usted debe codificar los comandos usando las llamadas al sistema del sistema operativo. No se puede usar la función system().
2.	Para la tubería y el redireccionamiento debe usar las llamadas al sistema pipe(), dup().
3.	Cada estudiante debe programar el 25% del proyecto. No se acepta que el estudiante SOLAMENTE haya investigado. Cada estudiante debe programar mínimo 4 comandos. Se hará una defensa para confirmar su programación. 

Descripción del proyecto
Diseñe la consola mi_sh> de manera que 
1.	lea un comando [comando [opciones]] y valide si existe o no. Si existe ejecute el comando sino imprima “comando no encontrado”. Debe interpretar cada una de las opciones del comando

Mi_sh> ls –l –m –t 

Los comandos GUI los puede correr en el background o en el foreground (&)
Debe implementar la auto-completación del comando.

2.	Se puedan crear tuberías usando la siguiente sintaxis
Comando1 argumentos1 | Comando2 argumentos2 |…| Comandom argumentosm

3.	Se pueda re-direccionar la entrada estándar, la salida estándar y el error estándar a un archivo.
Operadores de redireccionamiento: <, >, >&, >>, 2>&1

4.	Además, debe implementar  los comandos (codificación del comando) y 
a.	mkdir : crea un directorio con ruta absoluta o relativa
b.	cd: cambiar de directorio
c.	chmod: cambia el acceso a un archivo específico. 
d.	rmdir: elimina un directorio si este esta vacío
e.	rmdir -R: elimina un directorio recursivamente
f.	rm: elimina un archivo
g.	cat: imprime los datos de un archivo en la consola o redirecciona la entrada de datos a un archivo. Use también este comando para crear un archivo usando ctrl-d para el EOF. 
h.	ln –s: crea rutas simbólicas y duras
i.	ps –a –u –x -e: imprime la lista de los procesos
j.	uname –a –r  -m -s: muestra información general del sistema
k.	kill -9 process_id (debe usar la llamada al sistema signal())

