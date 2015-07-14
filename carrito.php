<?php 
include "master.php"; 
?>

<div class="col-xs-7 col-sm-6 bg-info" >
<br>
<table class="table">
<?php
include"conexion.php";
$i=0;
if($_SESSION["estado"] == "loged") {
	if($_SESSION["total"] !=0){
		echo "<th>Tu Carrito!!!</th>";
	
		while($_SESSION["compras"][$i]) {
		$id_cancion = $_SESSION["compras"][$i];
		$q = "SELECT * FROM canciones, artistas, genre, album_artista WHERE canciones.id_genero=genre.id_genero AND canciones.id_album_artista=album_artista.id_album_artista AND album_artista.id_artista=artistas.id_artista AND canciones.id_cancion='$id_cancion' ";
		foreach ($db->query($q) as $row) {
			$id=$row["id_cancion"];
	?>
			<tr>
        	    	<td><iframe align="right" type="text/html" width="320" height="180" src="<?php echo $row['link'] ?>" frameborder="0"></iframe></td>
            		<td>
            			<table align="left" class="tabla_index">
							<tr><td>Cancion: <?php echo $row['nombre']; ?></td></tr>            		
            				<tr><td>Artista: <?php echo $row['artista']; ?></td></tr>            		
            				<tr><td>Album: <?php echo $row['album']; ?></td></tr>            		
            				<tr><td>Genero: <?php echo $row['genero']; ?></td></tr>            		
            				<tr><td>Duracion: <?php echo $row['duracion'] ?></td></tr>
            				<tr><td>Precio: $<?php echo $row['precio'] ?></td></tr>            		            			            		           		            		
	            		</table>       		
    	        	</td>
       		</tr>	
	<?php
		}//fin Foreach
		$i++;
	}//fin while
	
	
	
	
	
	
	}
	else
		echo "<th>Carrito Vacio!!!</th>";
}else 
	echo "<th>Debes Logearte primero!!!</th>";
?>

</table>
</div>


</body>
</html>