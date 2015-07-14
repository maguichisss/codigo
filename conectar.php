<?php
function conectarBaseDeDatos(){
	global $conexionDB;
	global $altasbajascambios;
	$conexionDB = mysqli_connect("localhost", "jardin", "jardin123", "sci");

	
	if (mysqli_connect_errno()) {
		printf("Error en la conexi&oacute;n: %s\n", mysqli_connect_error());
		exit();
	}
}
?>    