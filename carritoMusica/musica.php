<?php 
include "master.php";
$id_genero = $_GET["g"];
$q = "SELECT * FROM canciones, artistas, genre, album_artista 
            WHERE canciones.id_genero=genre.id_genero 
            AND canciones.id_album_artista=album_artista.id_album_artista 
            AND album_artista.id_artista=artistas.id_artista 
            AND canciones.id_genero='$id_genero' 
            ORDER BY visitas DESC";
$query = $db->query($q);	

$tablaCanciones="";
while ($row = $query->fetch(PDO::FETCH_ASSOC)) {
    $id=$row["id_cancion"];
    $tablaCanciones .=
        '<tr>
            <td>
                <iframe align="right" type="text/html" width="320" height="180" 
                src="'.$row['link'].'" 
                frameborder="0">
                </iframe>
            </td>
            <td>
                <table align="left">
                    <tr><td>Cancion:    '.$row['nombre'].'</td></tr>                    
                    <tr><td>Artista:    '.$row['artista'].'</td></tr>                   
                    <tr><td>Album:      '.$row['album'].'</td></tr>                   
                    <tr><td>Genero:     '.$row['genero'].'</td></tr>                 
                    <tr><td>Duracion:   '.$row['duracion'].'</td></tr>
                    <tr><td>Precio:    $'.$row['precio'].'</td></tr>';

                if($_SESSION["estado"] == "loged") {
                    $tablaCanciones .= ' 
                    <form action="agregar.php?id='.$id.'" method="post">                
                        <tr>
                            <td>
                                <button name="comprar" type="submit">
                                    Agregar al Carrito
                                </button>
                            </td>
                        </tr>
                    </form>';
                }
    $tablaCanciones .=
                '</table>            
            </td>
        </tr>';
}









?>

<div class="col-xs-7 col-sm-6 bg-info" >
<br>
<table class="table borderless">
<th>Musica!!!</th>
<?php
   echo $tablaCanciones
?>
</table>
</div>



</body>
</html>