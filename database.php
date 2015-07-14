<?php

try {
	$db = new PDO(
			"mysql:dbname=carrito;
				host=localhost",
			"carrito",
			"123456");
	//echo "se establecio la conexion";

}catch(PDOException $e){
	print "Error:" . $e->getMessage()."<br>";
	die();
}

/*
// Create connection
$conexion=mysqli_connect("localhost","carrito","c4rr1t0","carrito");
// Check connection

if (mysqli_connect_errno($conexion))
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }
*/
?>
