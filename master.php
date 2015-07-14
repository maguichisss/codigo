<?php 
session_start(); 
include "database.php";
$q = "SELECT * FROM genre ORDER BY id_genero ASC";
$query = $db->query($q);
$generos = "";

while ($row = $query->fetch(PDO::FETCH_ASSOC)) {
	$generos .= 
		"<li>
			<a href='musica.php?g=".(int)$row["id_genero"]."'>"
				.$row["genero"]."
			</a>
		</li> ";
}









?>
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="css/bootstrap.min.css" />
<link rel="stylesheet" type="text/css" href="css/bootstrap-theme.min.css" />
<link rel="stylesheet" type="text/css" href="css/style.css" />

<script src="js/bootstrap.min.js"></script>
<script src="js/jquery-2.1.4.min.js"></script>

</head>
<body>
<div class="container">
	<nav class="navbar navbar-default">
		<div class="container-fluid">
			<!-- Brand and toggle get grouped for better mobile display -->
			<div class="navbar-header">
				<a class="navbar-brand" href="index.php">M&uacutesica</a>
			</div>
			<!-- Collect the nav links, forms, and other content for toggling -->
			<div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
				<ul class="nav navbar-nav">
				<?php
					echo $generos;
				?>					
				</ul>
			</div><!-- /.navbar-collapse -->
		</div><!-- /.container-fluid -->
	</nav>

	<?php
		if($_SESSION["estado"] != "loged") {
	?>
	<div class="col-sm-3 bg-info div_login" >
		<form name="login" action="login.php" method="post" class="navbar-form navbar-left">
			<div class="form-group">
			<table class="table borderless">
				<tr><br></tr>
				<tr>Usuario:<br></tr>
				<tr>
					<input class="form-control" name="user" placeholder="Usuario"/>
				</tr>
				<tr>Contrase&ntilde;a:<br></tr>
				<tr>
					<input class="form-control" type="password" name="pass" placeholder="Contrase&ntilde;a"/>
					<br><br>
				</tr>
				<tr><input type="submit" class="btn btn-default" value="Entrar" /></tr>		
			</div>
			</table>					
		</form>
		<br>Nuevo? <a href="registro.php" >Registrate!!!</a>
	</div></div>
	<?php  
	} //acaba el if 
	?>
	<?php
	if($_SESSION["estado"] == "loged") {
	?>
	<div class="col-sm-3 bg-success div_login">
		<br>
		<table class="table borderless">
			<tr>
				<td> Bienvenido <?php echo ucwords($_SESSION["user"]);?>
				</td>
			</tr>
			<tr><td>Loged</td></tr>
			<form name="logout" action="logout.php" method="post">
				<tr><td><input class="submit" type="submit" name="logout" value="Salir" /></td></tr>
			</form>
		</table>
		<br>
		<table class="table borderless">
			<tr><td><img src="http://www.saiwireless.com/img/blanca/ecomercio.png" alt="" width="50" height="50"></img></td></tr>
			<tr><td>Total: $<?php echo $_SESSION["total"];  ?></td></tr>
			<tr><td><form action="carrito.php" method="post"><button name="carrito" type="submit">Ver Carrito</button></form></td></tr>
			<tr><td><form action="vaciar.php" method="post"><button name="vaciar" type="submit">Vaciar Carrito</button></form></td></tr>
			<tr><td><form action="comprar.php" method="post"><button name="comprar" type="submit">Comprar</button></form></td></tr>
		</table>	
	</div>	
	<?php
	} //acaba el if 
	?>

