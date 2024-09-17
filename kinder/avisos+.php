<?php
    include("conectar.php");
    conectarBaseDeDatos();
    
        $fecha = date("Y-m-d H:i:s");
        $aviso = $_POST["aviso"];
        $result=mysqli_query($conexionDB, "INSERT INTO aviso (fecha, aviso) VALUES ('$fecha', '$aviso')" );
        echo "<script>location='avisos.html'</script>";
?>