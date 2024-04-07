
# Guía de Aprendizaje para el Proyecto Minitalk de 42 Network

Esta guía proporciona una explicación detallada de los conceptos clave necesarios para el proyecto Minitalk de 42 Network, junto con ejemplos prácticos.

## 1. Programación en C

### Punteros
- **Definición**: Un puntero es una variable que almacena la dirección de memoria de otra variable.
- **Ejemplo**:
  ```c
  int var = 20;      // Declaración de una variable.
  int *ptr = &var;   // Declaración de un puntero que apunta a var.
  ```

### Gestión de Memoria
- **malloc** y **free**: Se utilizan para asignar y liberar memoria dinámicamente.
- **Ejemplo**:
  ```c
  int *ptr = malloc(sizeof(int) * 10); // Asigna memoria para un array de 10 enteros.
  free(ptr);                           // Libera la memoria.
  ```

## 2. Comunicación entre Procesos (IPC)

### Señales
- **Definición**: Mecanismo utilizado para enviar notificaciones a procesos.
- **Ejemplo**:
  ```c
  #include <signal.h>
  #include <stdio.h>
  #include <unistd.h>

  void signal_handler(int signal) {
      printf("Señal recibida: %d
", signal);
  }

  int main() {
      signal(SIGINT, signal_handler); // SIGINT es la señal enviada al presionar Ctrl+C.
      while(1) {
          sleep(1); // Ciclo infinito, esperando la señal.
      }
      return 0;
  }
  ```

## 3. Manejo de Errores

### errno y perror
- **Definición**: `errno` es una variable global que almacena el código de error de la última función que falló. `perror` muestra un mensaje relacionado con el valor actual de `errno`.
- **Ejemplo**:
  ```c
  #include <stdio.h>
  #include <errno.h>
  #include <stdlib.h>

  int main() {
      FILE *file = fopen("no_existe.txt", "r");
      if (file == NULL) {
          perror("Error al abrir el archivo");
          exit(EXIT_FAILURE);
      }
      fclose(file);
      return 0;
  }
  ```

## 4. Sistemas de Numeración

### Binario, Decimal, Hexadecimal
- **Ejemplo de Conversión**:
  - Decimal 15 es Binario 1111 y Hexadecimal F.

## 5. Herramientas de Desarrollo en C

### GCC, Makefiles, GDB
- **GCC**: Compilador de C.
  ```bash
  gcc programa.c -o programa
  ```
- **Makefiles**: Automatizan la compilación.
  ```Makefile
  all: programa.c
      gcc programa.c -o programa
  ```
- **GDB**: Herramienta de depuración.
  ```bash
  gdb programa
  ```

Esta guía ofrece una base sobre la cual puedes construir tu conocimiento y habilidades para el proyecto Minitalk. La práctica y la experimentación con estos conceptos te ayudarán a consolidar tu aprendizaje.
