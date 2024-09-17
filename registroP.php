<?php
session_start(); 
include "database.php";
$user=$_POST["user"];
$pass=md5($_POST["pass"]);
$email=$_POST["email"];
$proced = $db->prepare("CALL registro('$user','$pass','email')");
if($proced->execute()){
	$_SESSION["estado"]="loged";
	echo "Su registro fue satisfactorio...";

}else {
	echo "error...";

}
?>