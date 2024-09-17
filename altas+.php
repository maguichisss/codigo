<?php
    include("conectar.php");
    conectarBaseDeDatos();
    
        $fecha = date("Y-m-d");
        $result=mysqli_query($conexionDB, "INSERT INTO grupodocente (idPersonal, idGrupo, fechainicio) VALUES ('".$_POST["docente"]."', '".$_POST["grupo"]."', '$fecha')" );
        echo "<script>location='altas.php'</script>";
?>