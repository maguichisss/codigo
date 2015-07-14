<?php
    include("conectar.php");
    conectarBaseDeDatos();
    
    $fecha = $_POST["fecha"].date(":s");
    $docente = $_POST["docente"];
    $tipo = $_POST["tipoincidencia"];
    $result=mysqli_query($conexionDB, "INSERT INTO incidenciapersonal (fechaIncidencia, idPersonal, idTipoIncidencia) VALUES ('$fecha', '$docente', '$tipo')" );
    echo "<script>location='incidencias-doc.php'</script>";
?>