<?php
    include("conectar.php");
    conectarBaseDeDatos();
    if($altasbajascambios==alta)
    {
        $fecha = date("Y-m-d");
        $result=mysqli_query($conexionDB, "INSERT INTO grupodocente (idPersonal, idGrupo, fechainicio) VALUES ('".$_POST["docente"]."', '".$_POST["grupo"]."', '$fecha')" );
        echo "<script>location='altas.php'</script>";
    }
    else if($altasbajascambios==baja)
    {
        $fecha = date("Y-m-d");
        $result=mysqli_query($conexionDB, "INSERT INTO grupodocente (fechafin) VALUES ($fecha') where idPersonal='".$_POST["docente"]."'    " );
        echo "<script>location='altas.php'</script>";
    }
    else if($altasbajascambios==cambio)
    {
        $fecha = date("Y-m-d");
        $result1=mysqli_query($conexionDB, "INSERT INTO grupodocente (fechafin) VALUES ($fecha') where idPersonal='".$_POST["docente1"]."'    " );
        $result2=mysqli_query($conexionDB, "INSERT INTO grupodocente (fechafin) VALUES ($fecha') where idPersonal='".$_POST["docente2"]."'    " );
        $result3=mysqli_query($conexionDB, "INSERT INTO grupodocente (idPersonal, idGrupo, fechainicio) VALUES ('".$_POST["docente1"]."', '".$_POST["grupo1"]."', '$fecha')" );
        $result4=mysqli_query($conexionDB, "INSERT INTO grupodocente (idPersonal, idGrupo, fechainicio) VALUES ('".$_POST["docente2"]."', '".$_POST["grupo2"]."', '$fecha')" );
        echo "<script>location='cambios.php'</script>";
    }
    else
    {

        echo "<script>alert('Error!!!'); location='director-doc.html'</script>";
        
    }
?>