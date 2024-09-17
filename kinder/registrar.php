<?php
    $mysqli = mysqli_connect("localhost", "jardin", "jardin123", "sci");
    $paterno = trim($_POST["apeP"]);
    $materno = trim($_POST["apeM"]);
    $nombre = trim($_POST["nombre"]);
    $fecha_nacimiento =$_POST["anio"]."-".$_POST["mes"]."-".$_POST["dia"];
    $sexo = $_POST["sexo"];
    $curp = $_POST["curp"];
    $telefono = trim($_POST["telefono"]);
    $celular = trim($_POST["celular"]);
    $CP = $_POST["CP"];
    $clavepres = trim($_POST["clavepres"]);
    $nofil = trim($_POST["nofil"]);
    $user = trim($_POST["user"]);
    $pass = trim($_POST["pass"]);

    $sql = "INSERT INTO personal (apPaterno, apMaterno, nombre, fechaNacimiento, curp, telefono, idPuesto, celular, codigoPostal, clavePresupuestal, numeroFiliacion, sexo) VALUES ('$paterno', '$materno', '$nombre', '$fecha_nacimiento', '$curp', '$telefono', '2', '$celular', '$CP', '$clavepres', '$nofil', '$sexo')";
    $resultado= mysqli_query($mysqli, $sql) or die(mysqli_error($mysqli));
    $id = mysqli_insert_id($mysqli);
    $sql = "INSERT INTO usuario (nombre, clave, idPersonal) VALUES ('$user', '$pass', '$id')";
    $resultado= mysqli_query($mysqli, $sql) or die(mysqli_error($mysqli));
    echo "<script>location='registro.html'</script>";
?>