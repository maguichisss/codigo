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
		<table>
			<tr>
				<td></td>
				<td>Registro</td>			
			</tr>
			<tr>
				<td width="30%" align="right" >Usuario: </td>
				<td><input class="text" type="text" name="user" value=""/></td>
			</tr>
			<tr>
				<td width="30%" align="right" >Contraseña: </td>
				<td><input class="text" type="text" name="pass" value="" /></td>
			</tr>
			<tr>
				<td width="30%" align="right" >E-mail:</td>
				<td><input class="text" type="text" name="email" /></td>
			</tr>
			<tr>
				<td></td>			
				<td><input class="submit" type="submit" name="registro" value="Registrarse" /></td>
			</tr>
		</table>	
	</form>
<br><br>
</div>

</body>
</html>