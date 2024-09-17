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
                                    <h1>Bajas</h1>
                                    <div class="text">
<script> 
function revisar() { 
if( bajas.docente.value=="" ) { alert('Debes seleccionar un Profesor') ; return false ; } 
}
</script>                                        
<form name="bajas" method="post" action="bajas+.php" onsubmit="return revisar()">
<?php
include("conectar.php");
conectarBaseDeDatos();
echo '<br>Docente a dar de baja:';
//Consulta para seleccionar lo deseado.
$result=mysqli_query($conexionDB, "SELECT nombre,apPaterno,apMaterno,idPersonal FROM personal");
//Mostramos por un echo la etiqueta del select con su nombre y su id
echo '<select name="docente" id="docente">';
echo '<option value="">- Seleccione -</option>';
//Realizamos un Bucle wile para recorrer la tabla
while ($row=mysqli_fetch_array($result))
{//Por otro echo mostramos en cada option del select lo seleccionado por la consulta 
    echo '<option value="'.$row['idPersonal'].'">'  .$row['nombre'].  " "  .$row['apPaterno'].  " "  .$row['apMaterno'].  '</option>';
}
echo '</select>';
//Cerramos el PHP**
?>
<br><br>
<input type="submit" name="bajar" value="Dar de baja">  
</form>
   

				    </div>                                    
                            </div>                                                                            <div class="designinfo">                                                                                                        </div>                        
                    </div>
                </div>
            </div>                    
        </body>        
    </html>
    