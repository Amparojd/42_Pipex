
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <div class="container">
        <p align = "center">
         <img src=./pipex_1.gif width="800"/></p>
        <p align = "center">Proyecto de 42 Madrid</p>
        <h2>Índice</h2>
        <ul>
            <li><a href="#intro">Introducción</a></li>
            <li><a href="#instalacion">Instalación</a></li>
            <li><a href="#tester">Pruebas</a></li>
            <!-- Agrega más enlaces a otras secciones si es necesario -->
        </ul>
        <h2 id="intro">Introducción</h2>
        <p>Pipex es un proyecto diseñado para explorar el funcionamiento interno de los pipes en sistemas Unix y Linux, así como para familiarizarse con la redirección de entrada y salida estándar en el entorno de la línea de comandos.

El objetivo principal de Pipex es implementar un programa en lenguaje C que replique el funcionamiento básico de la línea de comandos pipe en un sistema Unix. En Pipex, se aprenden conceptos como la creación de procesos, la redirección de entrada y salida estándar, la comunicación entre procesos mediante pipes y la gestión adecuada de errores.</p>
        <h2 id="instalacion">Instalación</h2>
        <p>Clona el repositorio:</p>
        <pre><code>git clone git@github.com:Amparojd/42_Pipex.git pipex</code></pre>
        <br>
        <p>Una vez dentro del directorio clonado, escribe "make" en terminal. Con esto se compilarán todos los archivos y se creará un ejecutable llamado "pipex".</p>
        <br>
        <h2 id="tester">Pruebas</h2>
        <p>*Esto debe mostrar el nombre del host de la máquina en la que se está ejecutando el comando.</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "cat" "hostname" "outfile.txt"</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt cat | hostname</code></pre>
        <br>
        <p>*cuenta el número de palabras en esas líneas que contienen "a1" en el archivo "infile.txt"</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "grep a1" "wc -w" outfile.txt</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt grep a1 | wc -w</code></pre>
        <br>
        <p>*Cuenta el número de líneas de la salida generada por el comando "ls -l" en el directorio actual</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "ls -l" "wc -l" outfile.txt</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt ls -l | wc -l </code></pre>
         <br>
        <p>*Mostrará en la salida estándar el resultado de ejecutar "ls -l" en el directorio actual</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "ls -l" "cat" outfile.txt</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt ls -l | cat </code></pre>
        <br>
        <p>*Busca líneas que contienen la palabra "hola" en el archivo "infile.txt" y luego muestra estas líneas utilizando el comando "/bin/cat"</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "grep hola" "/bin/cat" outfile.txt</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt grep hola | /bin/cat</code></pre>
        <br>
        <p>*Este comando busca las primeras dos líneas que contienen la palabra "hola" en el archivo "infile.txt"</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "grep hola" "head -2" "outfile.txt"</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt grep hola | head -2</code></pre>
         <br>
        <p>*busca líneas que contienen la palabra "Now" en el archivo "infile.txt" y luego las muestra</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "grep hola" "cat" "outfile.txt"</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt grep hola | cat</code></pre>
         <br>
        <p>*buscará líneas que contengan la palabra "hola" en el archivo "infile.txt" y luego ejecutará el resultado utilizando el comando "cat". El "$(which cat)" es una forma de asegurarse de que se use el comando "cat" del sistema, incluso si su ubicación no está en la ruta predeterminada</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "grep hola" "$which cat" "outfile.txt"</code></pre>
        <p>Original:</p>
        <pre><code>< infile.txt grep hola | $(which cat)</code></pre>
        <p>* crea un script awk para contar las ocurrencias de un patrón específico en un archivo, y luego lo utiliza para contar las ocurrencias de "hola" en el archivo infile.txt.</p>
        <p>Pipex:</p>
        <pre><code>./pipex "infile.txt" "grep hola" "awk -f script.awk" "outfile.txt"</code></pre>
        <p>Original:</p>
        <pre><code>+++ CREATE in repo a file script.awk with inside: {count++} END {printf "%s", count}</code></pre>
        <pre><code>< infile.txt grep Hello | awk '{count++} END {print count}'</code></pre>
         <p>*Este comando no funcionará correctamente como se espera.</p>
        <p>Pipex:</p>
        <pre><code>./pipex "/dev/random" "grep hola" "cat" outfile.txt</code></pre>
        <p>Original:</p>
        <pre><code>< /dev/random grep hola | cat > outfile.txt</code></pre>
        <br><br>
        <p>Comandos que no deberían funcionar</p>
         <p>Faltan argumentos, deben ser 5 "./pipex infile cmd1 cmd2 outfile</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "grep a1" "wc -w"</code></pre>
         <p>Infile SÍ debe existir</p>
        <p>Pipex:</p>
        <pre><code>./pipex incorrectfile "grep a1" "wc -w" outfile.txt</code></pre>
          <p>Si los comandos no son válidos no funcionará</p>
        <p>Pipex:</p>
        <pre><code>./pipex infile.txt "nonexistant" "nonexistant" outfile.txt</code></pre>
        
        
        
        
</div>
</body>
</html>
