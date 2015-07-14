<?php
$mysqli = mysqli_connect("localhost", "jardin", "jardin123", "sci");

$sql = "SELECT * FROM usuario WHERE nombre = '".$_POST["user"]."' AND clave = '".$_POST["pass"]."'";
$res_usu = mysqli_query($mysqli, $sql) or die(mysqli_error($mysqli));

$sqlmio= "SELECT * FROM personal";
$res_per= mysqli_query($mysqli, $sqlmio) or die(mysqli_error($mysqli));

$qrypuesto = "SELECT * FROM puesto";
$res_pue= mysqli_query($mysqli, $qrypuesto) or die(mysqli_error($mysqli));

$usuario = mysqli_fetch_array($res_usu);
$usuario_id = $usuario['idPersonal'];

if (mysqli_num_rows($res_usu) == 1) 
{	
	do
	{
		$puesto = mysqli_fetch_array($res_pue);
		$puesto_id = $puesto['idPuesto'];
		$puesto_funcion = $puesto['funcion'];		
		
		$personal = mysqli_fetch_array($res_per);
		$personal_id = $personal['idPersonal'];
		$personal_nombre = $personal['nombre']; 
		$personal_apepa = $personal['apPaterno'];
		$personal_puesto = $personal['idPuesto'];
		
	}while($personal_id != $usuario_id);
	echo "<p><h1><center> Bienvenido ".$personal_puesto."@  ".$personal_nombre." ".$personal_apepa."</h1></p></center>";
}
else
{
	echo"<p><h1><center>Error!!!  El nombre de usuario o contraseña no coinciden</h1></center></p>";	
} 
switch ($personal_puesto)
{
    case 1:
        echo "<script>location='director-doc.html'</script>";
        break;
    case 2:
        echo "<script>location='docente.html'</script>";
        break;
    default:
        echo"<p><h1><center>Error!!!</h1></center></p>";
        break;  
}

?>




