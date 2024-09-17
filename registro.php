<?php include"master.php";?>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8" />
<title></title>
</head>
<body>
<div>
<br><br>
	<form action="registroP.php" method="post">
		<div class="form-group">
		<table>
			<tr>
				<td></td>
				<td>Registro</td>			
			</tr>
			<tr>
				<td width="30%" align="right" >Usuario: </td>
				<td><input required class="form-control" type="text" name="user" value=""/></td>
			</tr>
			<tr>
				<td width="30%" align="right" >Contraseña: </td>
				<td><input required class="form-control" type="password" name="pass" value="" /></td>
			</tr>
			<tr>
				<td width="30%" align="right" >E-mail:</td>
				<td><input class="form-control" type="text" name="email" /></td>
			</tr>
			<tr>
				<td></td>			
				<td><input class="btn btn-default" type="submit" name="registro" value="Registrarse" /></td>
			</tr>
		</table>
		</div>
	</form>
<br><br>
</div>

</body>
</html>