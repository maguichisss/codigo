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
                                    <h1>Imprimir</h1>
                                    <div class="text">
<script> 
function revisar() { 
if( altas.docente.value=="") { alert('Debes seleccionar un Profesor y un Grupo') ; return false ; } 
}
</script>                                       
<form name="imprimir-mes" method="post" action="pdf/pdf-1.php" onsubmit="return revisar()">
<?php
include("conectar.php");
conectarBaseDeDatos();
$result = mysqli_query($conexionDB, "SELECT a.*, b.*, c.* FROM personal a, incidenciapersonal b, tipoincidencia c where a.idPersonal=b.idPersonal and b.idTipoIncidencia=c.idTipoIncidencia");
echo '<table>';
echo '<tr>';
echo '<td>Nombre</td>';
echo '<td>Apellido P</td>';
echo '<td>Apellido M</td>';
echo '<td>Clave</td>';
echo '<td>Fecha</td>';
while($faltas=mysqli_fetch_array($result))
{    
echo '<tr>';
echo '<td>'.$faltas['nombre'].                          '</td>';
echo '<td>'.$faltas['apPaterno'].                       '</td>';
echo '<td>'.$faltas['apMaterno'].                       '</td>';
echo '<td>'.$faltas['clave'].                           '</td>';
echo '<td>'.substr($faltas['fechaIncidencia'],0,10).    '</td>';
echo '<td><input type="radio" name="uno" value="'.$faltas['idincidenciaPersonal'].'"><td>';
echo '</tr>';
}
echo '</table>';
?>
<input type="submit" name="imprimir" value="Imprimir"></input>   
</form>    

				    </div>                                    
                            </div>                                                                            <div class="designinfo">                                                                                                        </div>                        
                    </div>
                </div>
            </div>                    
        </body>        
    </html>
    