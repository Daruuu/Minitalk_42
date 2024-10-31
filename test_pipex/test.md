### 10 Casos de Éxito (funcionamiento correcto):

1. **Filtro de texto con `grep` y conteo de palabras con `wc`**:
    - **Comando**: `./pipex infile "grep palabra" "wc -w" outfile`
    - **Equivalente Bash**: `< infile grep palabra | wc -w > outfile`
    - **Verificación**: `outfile` debe contener el número de palabras que contienen "palabra".
2. **Comando con un script de shell**:
    1. **Caso básico con `ls` y `wc`**:
        - **Comando**: `./pipex infile "ls -l" "wc -l" outfile`
        - **Equivalente Bash**: `< infile ls -l | wc -l > outfile`
        - **Verificación**: El archivo `outfile` debe contener el número de líneas de la salida de `ls -l`.
    - **Comando**: `./pipex infile "./script.sh" "wc -l" outfile`
    - **Equivalente Bash**: `< infile ./script.sh | wc -l > outfile`
    - **Verificación**: El archivo `outfile` debe contener la salida del script y el número de líneas.
3. **Comando con `cat` y `wc -c` (conteo de caracteres)**:
    - **Comando**: `./pipex infile "cat" "wc -c" outfile`
    - **Equivalente Bash**: `< infile cat | wc -c > outfile`
    - **Verificación**: El archivo `outfile` debe contener el número de caracteres en `infile`.
4. **Comando con redirección a `/dev/null`**:
    - **Comando**: `./pipex infile "cat" "wc -l" /dev/null`
    - **Equivalente Bash**: `< infile cat | wc -l > /dev/null`
    - **Verificación**: No debe haber salida en la terminal ni en archivos, pero el programa debe ejecutarse sin errores.
5. **Concatenación de archivos**:
    - **Comando**: `./pipex infile1 "cat" "cat" outfile`
    - **Equivalente Bash**: `< infile1 cat | cat > outfile`
    - **Verificación**: `outfile` debe contener el contenido completo de `infile1`.
6. **Comando que ejecuta un archivo binario (usando `hexdump`)**:
    - **Comando**: `./pipex infile "hexdump" "wc -l" outfile`
    - **Equivalente Bash**: `< infile hexdump | wc -l > outfile`
    - **Verificación**: El archivo `outfile` debe contener el número de líneas de la salida de `hexdump`.
7. **Uso de `head` y `tail`**:
    - **Comando**: `./pipex infile "head -n 5" "tail -n 3" outfile`
    - **Equivalente Bash**: `< infile head -n 5 | tail -n 3 > outfile`
    - **Verificación**: `outfile` debe contener las últimas 3 líneas de las primeras 5 líneas de `infile`.
8. **Uso de rutas absolutas**:
    - **Comando**: `./pipex infile "/bin/ls -l" "/usr/bin/wc -l" outfile`
    - **Equivalente Bash**: `< infile /bin/ls -l | /usr/bin/wc -l > outfile`
    - **Verificación**: `outfile` debe contener el número de líneas de la salida de `ls`.

1. **Uso de múltiples espacios en los argumentos**:
    - **Comando**: `./pipex infile " ls -l " " wc -l " outfile`
    - **Equivalente Bash**: `< infile ls -l | wc -l > outfile`
    - **Verificación**: `outfile` debe contener el número de líneas de la salida de `ls`.

---

### 5 Casos de Error (gestión de errores):

1. **Archivo de entrada inexistente**:
    - **Comando**: `./pipex nofile "ls -l" "wc -l" outfile`
    - **Equivalente Bash**: `< nofile ls -l | wc -l > outfile`
    - **Esperado**: Un mensaje de error como `Error: Cannot open INPUT file` debe aparecer, y `outfile` no debe crearse.
2. **Comando inexistente**:
    - **Comando**: `./pipex infile "invalidcommand" "wc -l" outfile`
    - **Equivalente Bash**: `< infile invalidcommand | wc -l > outfile`
    - **Esperado**: Un mensaje de error como `Error: Command not found` debe aparecer y `outfile` no debe crearse.
3. **Permisos denegados para archivo de salida**:
    - **Preparación**: Crea un archivo `outfile` y cambia sus permisos:
        
        ```bash
        touch outfile
        chmod 444 outfile
        
        ```
        
    - **Comando**: `./pipex infile "ls -l" "wc -l" outfile`
    - **Equivalente Bash**: `< infile ls -l | wc -l > outfile`
    - **Esperado**: Un mensaje de error como `Error: Cannot write to OUTPUT file` debe aparecer porque `outfile` no es escribible.
4. **Pipe entre comandos inválidos**:
    - **Comando**: `./pipex infile "invalidcommand" "invalidcommand2" outfile`
    - **Equivalente Bash**: `< infile invalidcommand | invalidcommand2 > outfile`
    - **Esperado**: Se deben mostrar dos mensajes de error indicando que ambos comandos no fueron encontrados, y `outfile` no debe crearse.
5. **Archivo de entrada vacío**:
    - **Preparación**: Crea un archivo vacío:
        
        ```bash
        touch emptyfile
        
        ```
        
    - **Comando**: `./pipex emptyfile "cat" "wc -l" outfile`
    - **Equivalente Bash**: `< emptyfile cat | wc -l > outfile`
    - **Esperado**: `outfile` debe contener "0", ya que no hay líneas en el archivo vacío.

