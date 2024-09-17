<?php
session_start();
include"database.php";

$id=$_GET["id"];
array_push($_SESSION["compras"], $id);

$q = "SELECT * FROM canciones WHERE id_cancion='$id'";
foreach ($db->query($q) as $row) 
	$precio = $row["precio"];

$_SESSION["total"] += $precio;

header("location:index.php");

?>