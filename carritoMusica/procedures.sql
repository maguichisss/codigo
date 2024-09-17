DELIMITER $$

CREATE PROCEDURE login(in userP varchar(100),in passP varchar(40)) 
BEGIN 
   SELECT * FROM user
   WHERE user=userP
   AND pass=passP; 
END$$



CREATE PROCEDURE registro(in userP varchar(100),in passP varchar(40),in emailP varchar(100)) 
BEGIN 
   INSERT INTO user (user, pass, email)
   VALUES (userP, passP, emailP); 
END$$
DELIMITER ;


SELECT * FROM canciones, artistas, genre, album_artista 
WHERE canciones.id_genero=genre.id_genero 
AND canciones.id_album_artista=album_artista.id_album_artista
AND album_artista.id_artista=artistas.id_artista
ORDER BY visitas DESC LIMIT 6


CALL login('adri', '202cb962ac59075b964b07152d234b70');
CALL registro('lala','202cb962ac59075b964b07152d234b70')


0000000006 	Rihana
0000000007 	Ska-P
0000000008 	Panteon Rococo
0000000009 	Metallica
0000000010 	Coldplay
0000000011 	Linkin Park
 	Editar 	Borrar 	0000000012 	Wolfgang Amadeus Mozart
	Editar 	Borrar 	0000000013 	Ludwig Van Beethoven
	Editar 	Borrar 	0000000014 	Antonio Vivaldi
	Editar 	Borrar 	0000000015 	Eminem
	Editar 	Borrar 	0000000016 	Kanye West
	Editar 	Borrar 	0000000017 	Snoop Dogg
	Editar 	Borrar 	0000000018 	Slipknot
	Editar 	Borrar 	0000000019 	Rammstein
	Editar 	Borrar 	0000000020 	Nightwish
	Editar 	Borrar 	0000000021 	Epica
	Editar 	Borrar 	0000000022 	Dream Theater
	Editar 	Borrar 	0000000023 	Madonna
	Editar 	Borrar 	0000000024 	Britney Spears
	Editar 	Borrar 	0000000025 	Michael Jackson
	Editar 	Borrar 	0000000026 	Lady Gaga
	Editar 	Borrar 	0000000027 	Backstreet Boys
	Editar 	Borrar 	0000000028 	Katy Perry
	Editar 	Borrar 	0000000029 	Shakira
	Editar 	Borrar 	0000000030 	Avril Lavigne

album artistas

INSERT INTO album_artista (album, id_artista) VALUES('A Girl Like Me','6');
INSERT INTO album_artista (album, id_artista) VALUES('Good Girl Gone Bad','6');
INSERT INTO album_artista (album, id_artista) VALUES('Loud','6');
INSERT INTO album_artista (album, id_artista) VALUES('Unapologetic','6');
INSERT INTO album_artista (album, id_artista) VALUES('El vals del obrero','7');
INSERT INTO album_artista (album, id_artista) VALUES('Planeta Eskoria','7');
INSERT INTO album_artista (album, id_artista) VALUES('Eurosis','7');
INSERT INTO album_artista (album, id_artista) VALUES('¡¡Que corra la voz!!','7');
INSERT INTO album_artista (album, id_artista) VALUES('A La Izquierda de la Tierra','8');
INSERT INTO album_artista (album, id_artista) VALUES('Companeros Musicales','8');
INSERT INTO album_artista (album, id_artista) VALUES('Panteon Rococo','8');
INSERT INTO album_artista (album, id_artista) VALUES('Kill Em All','9');
INSERT INTO album_artista (album, id_artista) VALUES('Ride the Lightning','9');
INSERT INTO album_artista (album, id_artista) VALUES('Master of Puppets','9');
INSERT INTO album_artista (album, id_artista) VALUES('...And Justice for All','9');
INSERT INTO album_artista (album, id_artista) VALUES('Parachutes','10');
INSERT INTO album_artista (album, id_artista) VALUES('A Rush of Blood to the Head','10');
INSERT INTO album_artista (album, id_artista) VALUES('X&Y','10');
INSERT INTO album_artista (album, id_artista) VALUES('Hybrid Theory','11');
INSERT INTO album_artista (album, id_artista) VALUES('Meteora','11');
INSERT INTO album_artista (album, id_artista) VALUES('Living Things','12');
INSERT INTO album_artista (album, id_artista) VALUES('Living Things','12');







Canciones









Array ( 
[0] => Holaa 
[1] => Array ( ) 
[2] => Holaa 
[3] => Array ( ) 
[4] => Holaa 
[5] => Array ( ) 
[6] => Holaa 
[7] => Array ( ) 
[8] => Holaa 
[9] => Array ( ) 
[10] => Holaa 
[11] => Array ( ) [12] => Holaa [13] => Array ( ) [14] => 5 [15] => Array ( ) [16] => 3 [17] => Array ( ) [18] => 3 [19] => Array ( ) [20] => 3 [21] => Array ( ) [22] => 3 [23] => Array ( ) [24] => 5 [25] => Array ( ) [26] => 5 [27] => Array ( ) [28] => 5 [29] => Array ( ) [30] => 5 [31] => Array ( ) [32] => 5 )





















