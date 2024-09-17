<?php
session_start();
unset($_SESSION["compras"]);
$_SESSION["total"]=0;
$_SESSION["compras"]=array();
header("location:index.php");
?>