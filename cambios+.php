<?php
    include("conectar.php");
    conectarBaseDeDatos();
    
        $fecha = date("Y-m-d");
        $result1 = mysqli_query($conexionDB, "UPDATE grupodocente SET idGrupo=NULL, fechafin='$fecha' WHERE idPersonal = '".$_POST["docente1"]."'  " );
        $result2 = mysqli_query($conexionDB, "UPDATE grupodocente SET idGrupo=NULL, fechafin='$fecha' WHERE idPersonal = '".$_POST["docente2"]."'  " );
        
        $result3=mysqli_query($conexionDB, "INSERT INTO grupodocente (idPersonal, idGrupo, fechainicio) VALUES ('".$_POST["docente1"]."', '".$_POST["grupo2"]."', '$fecha')" );
        $result4=mysqli_query($conexionDB, "INSERT INTO grupodocente (idPersonal, idGrupo, fechainicio) VALUES ('".$_POST["docente2"]."', '".$_POST["grupo1"]."', '$fecha')" );
    	echo "<script>location='cambios.php'</script>";
?>