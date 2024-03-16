
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
        <p>Esto debe mostrar el nombre del host de la máquina en la que se está ejecutando el comando.</p>
        <pre><code>./pipex infile.txt "cat" "hostname" "outfile.txt"</code></pre>
        <pre><code>< infile.txt cat | hostname</code></pre>
</div>
</body>
</html>
