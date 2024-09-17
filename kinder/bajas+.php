<?php
    include("conectar.php");
    conectarBaseDeDatos();
    
        $fecha = date("Y-m-d");
        $result=mysqli_query($conexionDB, "UPDATE grupodocente SET idGrupo=NULL, fechafin='$fecha' WHERE idPersonal = '".$_POST["docente"]."'" );
        echo "<script>location='bajas.php'</script>";
    
?>