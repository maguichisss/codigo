    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
        <head>
            <title>Jard&iacuten de ni&ntildeos "Joaquin Fern&aacutendez de Lizardi"</title>
            <meta http-equiv="content-type" content="text/html;charset=utf-8" />
            <link rel="stylesheet" type="text/css" href="basic.css" />
        </head>

        <body>

            <div id="first_container">
                <div id="second_container">
                    <div id="third_container">
                    

                    
                        <ul id="menu">
			    <li><a href="director-doc.html">Salir</a></li>

			   
                          
			    <li><span id="menuselected">Control</span></li>
			    
                        </ul> 

                        <div class="border">
                            <div class="content">
                                    <h1>Cambios</h1>
                                    <div class="text">
<script> 
function revisar() { 
if( (cambios.docente1.value == "" || cambios.docente2.value == "") || (cambios.grupo1.value == "" || cambios.grupo2.value == "")) { alert('Debes seleccionar Docentes o Grupos') ; return false ; } 
} 
</script> 
Seleccione los docentes o los grupos                                       
<form name="cambios" method="post" action="cambios+.php" onsubmit="return revisar()">
<?php
include("conectar.php");
conectarBaseDeDatos();
//Consulta para seleccionar lo deseado.
$result=mysqli_query($conexionDB, "SELECT nombre,apPaterno,apMaterno,idPersonal FROM personal");
//Docente 1
echo 'Docente 1:';
//Mostramos por un echo la etiqueta del select con su nombre y su id
echo '<select name="docente1" id="docente1">';
echo '<option value="">- Seleccione -</option>';
//Realizamos un Bucle wile para recorrer la tabla
while ($row=mysqli_fetch_array($result))
{//Por otro echo mostramos en cada option del select lo seleccionado por la consulta 
    echo '<option value="'.$row['idPersonal'].'">'  .$row['nombre'].  " "  .$row['apPaterno'].  " "  .$row['apMaterno'].  '</option>';
}
echo '</select>';
//Docente 2
$result=mysqli_query($conexionDB, "SELECT nombre,apPaterno,apMaterno,idPersonal FROM personal");
echo '<br>Docente 2:';
echo '<select name="docente2" id="docente2">';
echo '<option value="">- Seleccione -</option>';
while ($row=mysqli_fetch_array($result))
{//Por otro echo mostramos en cada option del select lo seleccionado por la consulta 
    echo '<option value="'.$row['idPersonal'].'">'  .$row['nombre'].  " "  .$row['apPaterno'].  " "  .$row['apMaterno'].  '</option>';
}
echo '</select>';
//Grupo 1
$result1 = mysqli_query($conexionDB, "SELECT * FROM grupo");
echo '<br>Grupo 1:';
echo "<select name='grupo1' id='grupo1'>";
echo '<option value="">- Seleccione -</option>';
while ($row1=mysqli_fetch_array($result1))
    echo '<option value="'.$row1['idGrupo'].'">'  .$row1['grado'].  "&deg "   .$row1['grupo'].   '</option>';
echo '</select>';
//Grupo 1
$result1 = mysqli_query($conexionDB, "SELECT * FROM grupo");
echo '<br>Grupo 2:';
echo "<select name='grupo2' id='grupo2'>";
echo '<option value="">- Seleccione -</option>';
while ($row1=mysqli_fetch_array($result1))
    echo '<option value="'.$row1['idGrupo'].'">'  .$row1['grado'].  "&deg "   .$row1['grupo'].   '</option>';
echo '</select>';
//Cerramos el PHP**
?>
<br>
<input type="submit" name="cambiar" value="Cambiar"></input>    
</form>
                                        
                                        
                                        
				    </div>
                                    
                            </div>
                        </div>

			<ul id="submenu">

			   	    
			    
                        </ul>
                        
                        
                        <div class="designinfo">
                            
                        </div>
                        
                    </div>
                </div>
            </div>
                    
        </body>
        
    </html>
    