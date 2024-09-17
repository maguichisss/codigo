    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
        <head>
            <title>Jard&iacuten de ni&ntildeos "Joaquin Fern&aacutendez de Lizardi"</title>
            <meta http-equiv="content-type" content="text/html;charset=utf-8" />
            <link rel="stylesheet" type="text/css" href="basic.css" />
            <link rel="stylesheet" type="text/css" href="basic.css" />
            <link rel="stylesheet" type="text/css" href="JSCal2-1.9/src/css/jscal2.css" />
            <link rel="stylesheet" type="text/css" href="JSCal2-1.9/src/css/border-radius.css" />
            <link rel="stylesheet" type="text/css" href="JSCal2-1.9/src/css/steel/steel.css" />
            <script src="JSCal2-1.9/src/js/jscal2.js"></script>
            <script src="JSCal2-1.9/src/js/lang/es.js"></script>
        </head>

        <body>

            <div id="first_container">
                <div id="second_container">
                    <div id="third_container">
                    

                    
                        <ul id="menu">
			    <li><a href="director-doc.html">Salir</a></li>

			    <li><a href="incidencias-alu.html">Alumno</a></li>
                          
			    <li><span id="menuselected">Docente</span></li>
			    
                        </ul> 

                        <div class="border">
                            <div class="content">
                                    <h1>Incidencias Docente</h1>
                                    <div class="text">
<script> 
function revisar() { 
if (incidencias.docente.value        == "")  { alert('Debes seleccionar un Docente') ; return false ; } 
if (incidencias.tipoincidencia.value == "")  { alert('Debes seleccionar un Tipo de Incidencia') ; return false ; } 
if (incidencias.fecha.value          == "")  { alert('Debes seleccionar una Fecha') ; return false ; }
} 
</script> 
Agregar una Incidencia                                       
<form name="incidencias" method="post" action="incidencias+.php" onsubmit="return revisar()">
<?php
include("conectar.php");
conectarBaseDeDatos();
$result=mysqli_query($conexionDB, "SELECT nombre,apPaterno,apMaterno,idPersonal FROM personal");
echo 'Docente:';
echo '<select name="docente" id="docente">';
echo '<option value="">- Seleccione -</option>';
while ($row=mysqli_fetch_array($result))
    echo '<option value="'.$row['idPersonal'].'">'  .$row['nombre'].  " "  .$row['apPaterno'].  " "  .$row['apMaterno'].  '</option>';
echo '</select>';
//incidencias
$result=mysqli_query($conexionDB, "SELECT * FROM tipoincidencia");
echo '<br>Incidencia:';
echo '<select name="tipoincidencia" id="tipoincidencia" >';
echo '<option value="">- Seleccione -</option>';
while ($row=mysqli_fetch_array($result))
{
    $nombre=substr($row['nombre'], 0, 20);
    echo '<option value="'.$row['idtipoIncidencia'].'  "    maxlength="20">'  .$row['clave'].  " - "  .$nombre.   '</option>';
}
echo '</select>';
echo '<br>Fecha:
<input size="30" name="fecha" id="f_date1" placeholder="Seleccionar..." value=""/>        
        <script type="text/javascript">//<![CDATA[
      Calendar.setup({
        inputField : "f_date1",
        trigger    : "f_date1",
        onSelect   : function() { this.hide() },
        showTime   : 12,
        dateFormat : "%Y-%m-%d %H:%M"
      });
    //]]></script> </input> ';
?>
<br>
<input type="submit" name="agregarincidencia" value="Agregar Incidencia"></input>
<br>
</form>
<a href="imprimir-mes.php"><button><font color="#cc0000">Ir a imprimir</font></button></a>


                   
            
</html>