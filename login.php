<?php 
include "master.php";

$user=$_POST["user"];
$pass=md5($_POST["pass"]);

$proced = $db->prepare("CALL login('$user','$pass')");
$proced->execute();
if($proced->rowCount() == 1) {
	$_SESSION["estado"]="loged";
	$_SESSION["user"]=$user;
	$_SESSION["compras"]=array();
	$_SESSION["total"]=0;
	$_SESSION["otro"]=0;
	header("Location: musica.php?g=1");
	die();

}else{
	$backgd="danger";
	header("Location: index.php?mensaje=".$backgd);
	die();

}	
?>