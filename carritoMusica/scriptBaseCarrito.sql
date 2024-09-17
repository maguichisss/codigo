-- phpMyAdmin SQL Dump
-- version 2.10.2
-- http://www.phpmyadmin.net
-- 
-- Servidor: localhost
-- Tiempo de generación: 30-05-2013 a las 20:59:30
-- Versión del servidor: 5.0.45
-- Versión de PHP: 5.2.3

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

-- 
-- Base de datos: carrito
-- 
CREATE DATABASE carrito DEFAULT CHARACTER SET utf8 COLLATE utf8_spanish_ci;
USE carrito;

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla album_artista
-- 

CREATE TABLE album_artista (
  id_album_artista int(10) unsigned zerofill NOT NULL auto_increment,
  album varchar(40) collate utf8_spanish_ci NOT NULL,
  id_artista int(10) unsigned zerofill NOT NULL,
  PRIMARY KEY  (id_album_artista),
  KEY id_artista (id_artista)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=173 ;

-- 
-- Volcar la base de datos para la tabla album_artista
-- 

INSERT INTO album_artista VALUES (0000000001, 'Exitos', 0000000014);
INSERT INTO album_artista VALUES (0000000002, 'Let Go', 0000000030);
INSERT INTO album_artista VALUES (0000000003, 'Under My Skin', 0000000030);
INSERT INTO album_artista VALUES (0000000004, 'The Works', 0000000001);
INSERT INTO album_artista VALUES (0000000005, 'A Night At The Opera', 0000000001);
INSERT INTO album_artista VALUES (0000000006, 'News Of The World', 0000000001);
INSERT INTO album_artista VALUES (0000000007, 'The Wall', 0000000002);
INSERT INTO album_artista VALUES (0000000008, 'The Dark Side Of The Moon', 0000000002);
INSERT INTO album_artista VALUES (0000000009, 'Wish You Were Here', 0000000002);
INSERT INTO album_artista VALUES (0000000010, 'Please Please Me', 0000000003);
INSERT INTO album_artista VALUES (0000000011, 'A Hard Day''s Night', 0000000003);
INSERT INTO album_artista VALUES (0000000012, 'The BEATLES', 0000000003);
INSERT INTO album_artista VALUES (0000000013, 'Yellow Submarine', 0000000003);
INSERT INTO album_artista VALUES (0000000014, 'Abbey Road', 0000000003);
INSERT INTO album_artista VALUES (0000000015, 'The Number of the Beast', 0000000004);
INSERT INTO album_artista VALUES (0000000016, 'Fear of the Dark', 0000000004);
INSERT INTO album_artista VALUES (0000000017, 'Seventh Son of a Seventh Son', 0000000004);
INSERT INTO album_artista VALUES (0000000018, 'Origin of Symmetry', 0000000005);
INSERT INTO album_artista VALUES (0000000019, 'Absolution', 0000000005);
INSERT INTO album_artista VALUES (0000000020, 'Black Holes and Revelations', 0000000005);
INSERT INTO album_artista VALUES (0000000021, 'The Resistance', 0000000005);
INSERT INTO album_artista VALUES (0000000022, 'A Girl Like Me', 0000000006);
INSERT INTO album_artista VALUES (0000000023, 'Good Girl Gone Bad', 0000000006);
INSERT INTO album_artista VALUES (0000000024, 'Loud', 0000000006);
INSERT INTO album_artista VALUES (0000000025, 'Unapologetic', 0000000006);
INSERT INTO album_artista VALUES (0000000026, 'El vals del obrero', 0000000007);
INSERT INTO album_artista VALUES (0000000027, 'Planeta Eskoria', 0000000007);
INSERT INTO album_artista VALUES (0000000028, 'Eurosis', 0000000007);
INSERT INTO album_artista VALUES (0000000029, '¡¡Que corra la voz!!', 0000000007);
INSERT INTO album_artista VALUES (0000000030, 'A La Izquierda de la Tierra', 0000000008);
INSERT INTO album_artista VALUES (0000000031, 'Compañeros Musicales', 0000000008);
INSERT INTO album_artista VALUES (0000000032, 'Panteón Rococó', 0000000008);
INSERT INTO album_artista VALUES (0000000033, 'Kill Em All', 0000000009);
INSERT INTO album_artista VALUES (0000000034, 'Ride the Lightning', 0000000009);
INSERT INTO album_artista VALUES (0000000035, 'Master of Puppets', 0000000009);
INSERT INTO album_artista VALUES (0000000036, '...And Justice for All', 0000000009);
INSERT INTO album_artista VALUES (0000000037, 'Parachutes', 0000000010);
INSERT INTO album_artista VALUES (0000000038, 'A Rush of Blood to the Head', 0000000010);
INSERT INTO album_artista VALUES (0000000039, 'X&Y', 0000000010);
INSERT INTO album_artista VALUES (0000000040, 'Hybrid Theory', 0000000011);
INSERT INTO album_artista VALUES (0000000041, 'Meteora', 0000000011);
INSERT INTO album_artista VALUES (0000000042, 'Living Things', 0000000011);
INSERT INTO album_artista VALUES (0000000043, 'Exitos', 0000000013);
INSERT INTO album_artista VALUES (0000000044, 'Exitos', 0000000012);
INSERT INTO album_artista VALUES (0000000045, 'Relapse  ', 0000000015);
INSERT INTO album_artista VALUES (0000000046, 'The Eminem Show ', 0000000015);
INSERT INTO album_artista VALUES (0000000047, '8 Mile Soundtrack ', 0000000015);
INSERT INTO album_artista VALUES (0000000048, 'The College Dropout', 0000000016);
INSERT INTO album_artista VALUES (0000000049, 'Graduation', 0000000016);
INSERT INTO album_artista VALUES (0000000050, 'My Beautiful Dark Twisted Fantasy', 0000000016);
INSERT INTO album_artista VALUES (0000000051, 'The Blue Carpet Treatment ', 0000000017);
INSERT INTO album_artista VALUES (0000000052, ' Tha Doggfather ', 0000000017);
INSERT INTO album_artista VALUES (0000000053, 'Malice n Wonderland ', 0000000017);
INSERT INTO album_artista VALUES (0000000054, 'All Hope Is Gone', 0000000018);
INSERT INTO album_artista VALUES (0000000055, 'Disasterpieces', 0000000018);
INSERT INTO album_artista VALUES (0000000056, 'Vol. 3: (The Subliminal Verses)', 0000000018);
INSERT INTO album_artista VALUES (0000000057, 'Sehnsucht', 0000000019);
INSERT INTO album_artista VALUES (0000000058, 'Reise, Reise', 0000000019);
INSERT INTO album_artista VALUES (0000000059, 'Liebe ist für alle da', 0000000019);
INSERT INTO album_artista VALUES (0000000060, 'Angels Fall First,', 0000000020);
INSERT INTO album_artista VALUES (0000000061, 'Oceanborn ', 0000000020);
INSERT INTO album_artista VALUES (0000000062, 'Century Child', 0000000020);
INSERT INTO album_artista VALUES (0000000063, 'Consign to Oblivion ', 0000000021);
INSERT INTO album_artista VALUES (0000000064, 'The Divine Conspiracy ', 0000000021);
INSERT INTO album_artista VALUES (0000000065, 'Design Your Universe ', 0000000021);
INSERT INTO album_artista VALUES (0000000066, 'Images and Words,', 0000000022);
INSERT INTO album_artista VALUES (0000000067, 'Awake,', 0000000022);
INSERT INTO album_artista VALUES (0000000068, 'Six Degrees of Inner Turbulence', 0000000022);
INSERT INTO album_artista VALUES (0000000069, 'Like a Virgin', 0000000023);
INSERT INTO album_artista VALUES (0000000070, 'Erotica', 0000000023);
INSERT INTO album_artista VALUES (0000000071, 'American Life', 0000000023);
INSERT INTO album_artista VALUES (0000000072, '...Baby One More Time', 0000000024);
INSERT INTO album_artista VALUES (0000000073, ' In the Zone,', 0000000024);
INSERT INTO album_artista VALUES (0000000074, ' Blackout,', 0000000024);
INSERT INTO album_artista VALUES (0000000075, 'Thriller', 0000000025);
INSERT INTO album_artista VALUES (0000000076, 'Off the Wall ', 0000000025);
INSERT INTO album_artista VALUES (0000000077, 'Bad', 0000000025);
INSERT INTO album_artista VALUES (0000000078, 'The Fame', 0000000026);
INSERT INTO album_artista VALUES (0000000079, 'EP The Fame Monster', 0000000026);
INSERT INTO album_artista VALUES (0000000080, 'Born This Way', 0000000026);
INSERT INTO album_artista VALUES (0000000081, 'Backstreet Boys ', 0000000027);
INSERT INTO album_artista VALUES (0000000082, 'Millennium ', 0000000027);
INSERT INTO album_artista VALUES (0000000083, 'Black & Blue ', 0000000027);
INSERT INTO album_artista VALUES (0000000084, 'One of the Boys ', 0000000028);
INSERT INTO album_artista VALUES (0000000085, ' Teenage Dream', 0000000028);
INSERT INTO album_artista VALUES (0000000086, 'Pies descalzos', 0000000029);
INSERT INTO album_artista VALUES (0000000087, 'Oral Fixation Vol. 2', 0000000029);
INSERT INTO album_artista VALUES (0000000088, 'Sale el sol', 0000000029);
INSERT INTO album_artista VALUES (0000000089, 'Ramones', 0000000031);
INSERT INTO album_artista VALUES (0000000090, 'Brain Drain ', 0000000031);
INSERT INTO album_artista VALUES (0000000091, 'Mondo Bizarro ', 0000000031);
INSERT INTO album_artista VALUES (0000000092, 'London Calling ', 0000000032);
INSERT INTO album_artista VALUES (0000000093, 'The Clash', 0000000032);
INSERT INTO album_artista VALUES (0000000094, 'Sandinista!', 0000000032);
INSERT INTO album_artista VALUES (0000000095, 'Dookie,', 0000000033);
INSERT INTO album_artista VALUES (0000000096, 'American Idiot', 0000000033);
INSERT INTO album_artista VALUES (0000000097, '21st Century Breakdown', 0000000033);
INSERT INTO album_artista VALUES (0000000098, 'Cheshire Cat', 0000000034);
INSERT INTO album_artista VALUES (0000000099, 'Dude Ranch', 0000000034);
INSERT INTO album_artista VALUES (0000000100, 'Blink-182', 0000000034);
INSERT INTO album_artista VALUES (0000000101, 'Walk Among Us ', 0000000035);
INSERT INTO album_artista VALUES (0000000102, 'Famous Monsters', 0000000035);
INSERT INTO album_artista VALUES (0000000103, 'he Devil s Rain ', 0000000035);
INSERT INTO album_artista VALUES (0000000104, 'Legend', 0000000036);
INSERT INTO album_artista VALUES (0000000105, 'Sublime', 0000000037);
INSERT INTO album_artista VALUES (0000000106, 'Clandestino', 0000000038);
INSERT INTO album_artista VALUES (0000000107, 'Radio Bemba Sound System', 0000000038);
INSERT INTO album_artista VALUES (0000000108, 'Baionarena', 0000000038);
INSERT INTO album_artista VALUES (0000000109, 'Shake off the dust... arise', 0000000039);
INSERT INTO album_artista VALUES (0000000110, 'No place to be', 0000000039);
INSERT INTO album_artista VALUES (0000000111, 'Spark seeker', 0000000039);
INSERT INTO album_artista VALUES (0000000112, ' Exile on Main St. ', 0000000040);
INSERT INTO album_artista VALUES (0000000113, 'Let It Bleed', 0000000040);
INSERT INTO album_artista VALUES (0000000114, 'Sticky Fingers ', 0000000040);
INSERT INTO album_artista VALUES (0000000115, 'Homework ', 0000000041);
INSERT INTO album_artista VALUES (0000000116, 'Discovery', 0000000041);
INSERT INTO album_artista VALUES (0000000117, 'Alive 2007', 0000000041);
INSERT INTO album_artista VALUES (0000000118, 'Im the supervisor ', 0000000042);
INSERT INTO album_artista VALUES (0000000119, 'Vicious Delicious', 0000000042);
INSERT INTO album_artista VALUES (0000000120, 'BP Empire ', 0000000042);
INSERT INTO album_artista VALUES (0000000121, 'Audio,Video,Disco', 0000000043);
INSERT INTO album_artista VALUES (0000000122, 'Phantom', 0000000043);
INSERT INTO album_artista VALUES (0000000123, 'Planisphere', 0000000043);
INSERT INTO album_artista VALUES (0000000124, 'Chants magnétiques ', 0000000044);
INSERT INTO album_artista VALUES (0000000125, 'The Concerts in China.', 0000000044);
INSERT INTO album_artista VALUES (0000000126, 'Musique pour supermarches ', 0000000044);
INSERT INTO album_artista VALUES (0000000127, 'Until One', 0000000045);
INSERT INTO album_artista VALUES (0000000128, 'Until Now,', 0000000045);
INSERT INTO album_artista VALUES (0000000129, 'Locos & Rucas In Retro ', 0000000046);
INSERT INTO album_artista VALUES (0000000130, 'Secundario del 73 ', 0000000046);
INSERT INTO album_artista VALUES (0000000131, 'Salon Victoria 96-05', 0000000046);
INSERT INTO album_artista VALUES (0000000132, 'A Dos Tiempos de Un Tiempo', 0000000047);
INSERT INTO album_artista VALUES (0000000133, 'Nace Aquí', 0000000047);
INSERT INTO album_artista VALUES (0000000134, 'Sólo Bolero', 0000000047);
INSERT INTO album_artista VALUES (0000000135, 'Sobre el Fuego ', 0000000048);
INSERT INTO album_artista VALUES (0000000136, 'Dicen Que Soy', 0000000048);
INSERT INTO album_artista VALUES (0000000137, 'latin Song Bird: Mi Alma y Corazon ', 0000000048);
INSERT INTO album_artista VALUES (0000000138, 'Metiendo Mano!', 0000000049);
INSERT INTO album_artista VALUES (0000000139, 'Canciones del Solar de los Aburridos ', 0000000049);
INSERT INTO album_artista VALUES (0000000140, 'The Last Fight', 0000000049);
INSERT INTO album_artista VALUES (0000000141, 'Pachanga in New York ', 0000000050);
INSERT INTO album_artista VALUES (0000000142, 'The Legend', 0000000050);
INSERT INTO album_artista VALUES (0000000143, 'El Rey de la Salsa ', 0000000050);
INSERT INTO album_artista VALUES (0000000144, 'Justo a tiempo ', 0000000051);
INSERT INTO album_artista VALUES (0000000145, 'Inconfundible ', 0000000051);
INSERT INTO album_artista VALUES (0000000146, 'Muy personal ', 0000000051);
INSERT INTO album_artista VALUES (0000000147, 'Al Pasito', 0000000052);
INSERT INTO album_artista VALUES (0000000148, 'No Hay Quinto Malo', 0000000052);
INSERT INTO album_artista VALUES (0000000149, 'Huellas del Pasado', 0000000052);
INSERT INTO album_artista VALUES (0000000150, 'Ritmo', 0000000053);
INSERT INTO album_artista VALUES (0000000151, '16 exitos de La Sonora Dinamita', 0000000053);
INSERT INTO album_artista VALUES (0000000152, 'Celebrando con La Sonora Dinamita', 0000000053);
INSERT INTO album_artista VALUES (0000000153, 'Cuando Llega El Amor', 0000000054);
INSERT INTO album_artista VALUES (0000000154, 'Con la Fuerza de un volcán"', 0000000054);
INSERT INTO album_artista VALUES (0000000155, 'Pachanguero', 0000000055);
INSERT INTO album_artista VALUES (0000000156, 'Barrio bravo', 0000000055);
INSERT INTO album_artista VALUES (0000000157, 'Cúmbia de la Paz', 0000000055);
INSERT INTO album_artista VALUES (0000000158, 'Sin Pecado', 0000000056);
INSERT INTO album_artista VALUES (0000000159, '15 Hits', 0000000056);
INSERT INTO album_artista VALUES (0000000160, 'Como Te Voy a Olvidar', 0000000056);
INSERT INTO album_artista VALUES (0000000161, 'Ven conmigo', 0000000057);
INSERT INTO album_artista VALUES (0000000162, 'Amor prohibido', 0000000057);
INSERT INTO album_artista VALUES (0000000163, 'Siempre Selena', 0000000057);
INSERT INTO album_artista VALUES (0000000164, 'El Poder de Nueva York ', 0000000058);
INSERT INTO album_artista VALUES (0000000165, 'Y Sigue el caché ', 0000000058);
INSERT INTO album_artista VALUES (0000000166, 'Best of the Best ', 0000000058);
INSERT INTO album_artista VALUES (0000000167, 'Suavemente', 0000000059);
INSERT INTO album_artista VALUES (0000000168, 'Saboréalo', 0000000059);
INSERT INTO album_artista VALUES (0000000169, 'Wow! Flash', 0000000059);
INSERT INTO album_artista VALUES (0000000170, 'The liberty of Norton Folgate', 0000000060);
INSERT INTO album_artista VALUES (0000000171, 'One Step Beyond... ', 0000000060);
INSERT INTO album_artista VALUES (0000000172, 'The Madness ', 0000000060);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla artistas
-- 

CREATE TABLE artistas (
  id_artista int(10) unsigned zerofill NOT NULL auto_increment,
  artista varchar(40) collate utf8_spanish_ci NOT NULL,
  PRIMARY KEY  (id_artista),
  UNIQUE KEY artista (artista)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=61 ;

-- 
-- Volcar la base de datos para la tabla artistas
-- 

INSERT INTO artistas VALUES (0000000014, 'Antonio Vivaldi');
INSERT INTO artistas VALUES (0000000030, 'Avril Lavigne');
INSERT INTO artistas VALUES (0000000027, 'Backstreet Boys');
INSERT INTO artistas VALUES (0000000034, 'Blink-182');
INSERT INTO artistas VALUES (0000000036, 'Bob Marley');
INSERT INTO artistas VALUES (0000000024, 'Britney Spears');
INSERT INTO artistas VALUES (0000000055, 'Celso Piña');
INSERT INTO artistas VALUES (0000000010, 'Coldplay');
INSERT INTO artistas VALUES (0000000041, 'Daft Punk');
INSERT INTO artistas VALUES (0000000022, 'Dream Theater');
INSERT INTO artistas VALUES (0000000059, 'Elvis Crespo');
INSERT INTO artistas VALUES (0000000015, 'Eminem');
INSERT INTO artistas VALUES (0000000021, 'Epica');
INSERT INTO artistas VALUES (0000000047, 'Gilberto Santa Rosa');
INSERT INTO artistas VALUES (0000000033, 'Green Day');
INSERT INTO artistas VALUES (0000000052, 'Grupo Niche');
INSERT INTO artistas VALUES (0000000042, 'Infected Mushroom');
INSERT INTO artistas VALUES (0000000004, 'Iron Maiden');
INSERT INTO artistas VALUES (0000000044, 'Jean-Michel Jarre');
INSERT INTO artistas VALUES (0000000043, 'Justice');
INSERT INTO artistas VALUES (0000000016, 'Kanye West');
INSERT INTO artistas VALUES (0000000028, 'Katy Perry');
INSERT INTO artistas VALUES (0000000048, 'La India');
INSERT INTO artistas VALUES (0000000026, 'Lady Gaga');
INSERT INTO artistas VALUES (0000000011, 'Linkin Park');
INSERT INTO artistas VALUES (0000000056, 'Los Angeles Azules');
INSERT INTO artistas VALUES (0000000054, 'Los Askis');
INSERT INTO artistas VALUES (0000000013, 'Ludwig Van Beethoven');
INSERT INTO artistas VALUES (0000000060, 'Madness');
INSERT INTO artistas VALUES (0000000023, 'Madonna');
INSERT INTO artistas VALUES (0000000038, 'Manu Chao');
INSERT INTO artistas VALUES (0000000039, 'Matisyahu');
INSERT INTO artistas VALUES (0000000009, 'Metallica');
INSERT INTO artistas VALUES (0000000025, 'Michael Jackson');
INSERT INTO artistas VALUES (0000000035, 'Misfits');
INSERT INTO artistas VALUES (0000000005, 'Muse');
INSERT INTO artistas VALUES (0000000020, 'Nightwish');
INSERT INTO artistas VALUES (0000000058, 'Oro Solido');
INSERT INTO artistas VALUES (0000000008, 'Panteon Rococo');
INSERT INTO artistas VALUES (0000000002, 'Pink Floyd');
INSERT INTO artistas VALUES (0000000001, 'Queen');
INSERT INTO artistas VALUES (0000000019, 'Rammstein');
INSERT INTO artistas VALUES (0000000031, 'Ramones');
INSERT INTO artistas VALUES (0000000006, 'Rihana');
INSERT INTO artistas VALUES (0000000049, 'Ruben Blades');
INSERT INTO artistas VALUES (0000000046, 'Salon Victoria');
INSERT INTO artistas VALUES (0000000057, 'Selena');
INSERT INTO artistas VALUES (0000000029, 'Shakira');
INSERT INTO artistas VALUES (0000000007, 'Ska-P');
INSERT INTO artistas VALUES (0000000018, 'Slipknot');
INSERT INTO artistas VALUES (0000000017, 'Snoop Dogg');
INSERT INTO artistas VALUES (0000000053, 'Sonora Dinamita');
INSERT INTO artistas VALUES (0000000037, 'Sublime');
INSERT INTO artistas VALUES (0000000045, 'Swedish House Mafia');
INSERT INTO artistas VALUES (0000000003, 'The Beatles');
INSERT INTO artistas VALUES (0000000032, 'The Clash');
INSERT INTO artistas VALUES (0000000040, 'The Rolling Stones');
INSERT INTO artistas VALUES (0000000050, 'Tito Puente');
INSERT INTO artistas VALUES (0000000051, 'Victor Manuelle');
INSERT INTO artistas VALUES (0000000012, 'Wolfgang Amadeus Mozart');

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla canciones
-- 

CREATE TABLE canciones (
  id_cancion int(10) unsigned zerofill NOT NULL auto_increment,
  nombre varchar(40) collate utf8_spanish_ci NOT NULL,
  id_album_artista int(10) unsigned zerofill NOT NULL,
  duracion varchar(5) collate utf8_spanish_ci NOT NULL,
  id_genero int(10) unsigned zerofill NOT NULL,
  link varchar(100) collate utf8_spanish_ci NOT NULL,
  precio float NOT NULL,
  visitas int(10) unsigned zerofill NOT NULL,
  PRIMARY KEY  (id_cancion),
  UNIQUE KEY link (link),
  KEY id_genero (id_genero),
  KEY id_album_artista (id_album_artista)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=30 ;

-- 
-- Volcar la base de datos para la tabla canciones
-- 

INSERT INTO canciones VALUES (0000000001, 'Bohemian Rhapsody', 0000000005, '6:07', 0000000001, 'http://www.youtube.com/embed/fJ9rUzIMcZQ', 9.99, 0000000001);
INSERT INTO canciones VALUES (0000000002, 'I Want To Break Free', 0000000004, '4:30', 0000000001, 'http://www.youtube.com/embed/eM8Ss28zjcE', 7.99, 0000000002);
INSERT INTO canciones VALUES (0000000003, 'Complicated', 0000000002, '4:13', 0000000002, 'https://www.youtube.com/embed/5NPBIwQyPWE', 8.99, 0000000002);
INSERT INTO canciones VALUES (0000000004, 'Sk8er Boi', 0000000002, '3:41', 0000000002, 'http://www.youtube.com/embed/TIy3n2b7V9k', 5.99, 0000000001);
INSERT INTO canciones VALUES (0000000005, 'Gato Lopez', 0000000026, '2:44', 0000000004, 'http://www.youtube.com/embed/iKgwV5TZhHo', 2.99, 0000000006);
INSERT INTO canciones VALUES (0000000006, 'Sexo y Religion', 0000000026, '5:0%', 0000000004, 'http://www.youtube.com/embed/3qOP81-RO5c', 4.99, 0000000000);
INSERT INTO canciones VALUES (0000000007, 'Curame', 0000000030, '3:41', 0000000004, 'http://www.youtube.com/embed/cZrLN_CLQlE', 7.99, 0000000004);
INSERT INTO canciones VALUES (0000000008, 'Nada Paso', 0000000030, '4:39', 0000000004, 'http://www.youtube.com/embed/0fIfj3JUMz8', 4.55, 0000000002);
INSERT INTO canciones VALUES (0000000009, 'Fear of the Dark', 0000000016, '7:22', 0000000003, 'http://www.youtube.com/embed/J0N1yY937qg', 6.5, 0000000006);
INSERT INTO canciones VALUES (0000000010, 'The Number of the Beast', 0000000015, '4:48', 0000000003, 'http://www.youtube.com/embed/7mHe6FMs46o', 3, 0000000003);
INSERT INTO canciones VALUES (0000000011, 'Good Girl Gone Bad', 0000000023, '3:37', 0000000002, 'http://www.youtube.com/embed/yb_aa8n2mQE', 6.79, 0000000004);
INSERT INTO canciones VALUES (0000000012, 'Like a Virgin', 0000000069, '3:50', 0000000002, 'http://www.youtube.com/embed/s__rX_WL100', 8.65, 0000000007);
INSERT INTO canciones VALUES (0000000013, 'Death of a Dream', 0000000064, '6:04', 0000000003, 'http://www.youtube.com/embed/BZMDm5Ivj-U', 8.35, 0000000006);
INSERT INTO canciones VALUES (0000000014, 'The Four Seasons', 0000000001, '41:54', 0000000009, 'http://www.youtube.com/embed/ygpf6mxTUeY', 15.99, 0000000003);
INSERT INTO canciones VALUES (0000000015, 'Spring', 0000000001, '9:59', 0000000009, 'http://www.youtube.com/embed/l-dYNttdgl0', 5.75, 0000000004);
INSERT INTO canciones VALUES (0000000016, 'Summer', 0000000001, '5:28', 0000000009, 'http://www.youtube.com/embed/VC3qO2V1AXY', 6.85, 0000000005);
INSERT INTO canciones VALUES (0000000017, 'Requiem', 0000000044, '8:54', 0000000009, 'http://www.youtube.com/embed/Zi8vJ_lMxQI', 7.55, 0000000004);
INSERT INTO canciones VALUES (0000000018, 'Moonlight Sonata', 0000000044, '15:01', 0000000009, 'http://www.youtube.com/embed/4Tr0otuiQuU', 5.99, 0000000004);
INSERT INTO canciones VALUES (0000000019, 'El Baile del Beeper', 0000000166, '5:18', 0000000012, 'http://www.youtube.com/embed/lvw6GCXHlt4', 3.25, 0000000004);
INSERT INTO canciones VALUES (0000000020, 'Mil Horas', 0000000151, '3:46', 0000000008, 'http://www.youtube.com/embed/qEHvsULYj_E', 4.39, 0000000002);
INSERT INTO canciones VALUES (0000000021, 'Mi Cucu', 0000000151, '3:55', 0000000008, 'http://www.youtube.com/embed/hB9Vqf86fr8', 2.99, 0000000004);
INSERT INTO canciones VALUES (0000000022, 'Clandestino', 0000000106, '2:28', 0000000007, 'http://www.youtube.com/embed/rylGaxCyVYY', 5.69, 0000000004);
INSERT INTO canciones VALUES (0000000023, 'Desaparecido', 0000000106, '3:48', 0000000007, 'http://www.youtube.com/embed/H2W4wglPW2c', 4.99, 0000000003);
INSERT INTO canciones VALUES (0000000024, 'Is This Love', 0000000104, '3:57', 0000000007, 'http://www.youtube.com/embed/CHekNnySAfM', 6.89, 0000000003);
INSERT INTO canciones VALUES (0000000025, 'Bufalo Soldier', 0000000104, '4:17', 0000000007, 'http://www.youtube.com/embed/S5FCdx7Dn0o', 4.79, 0000000003);
INSERT INTO canciones VALUES (0000000026, 'I Miss You', 0000000100, '3:51', 0000000006, 'http://www.youtube.com/embed/s1tAYmMjLdY', 7.79, 0000000008);
INSERT INTO canciones VALUES (0000000027, 'Down', 0000000100, '3:17', 0000000006, 'http://www.youtube.com/embed/XrTZT49u0kM', 4.99, 0000000004);
INSERT INTO canciones VALUES (0000000028, 'Les Chants Magnetiques I', 0000000124, '17:58', 0000000005, 'http://www.youtube.com/embed/4pu-f4mDcio', 12.55, 0000000002);
INSERT INTO canciones VALUES (0000000029, 'Around The World', 0000000115, '7:11', 0000000005, 'http://www.youtube.com/embed/yca6UsllwY', 7.99, 0000000007);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla genre
-- 

CREATE TABLE genre (
  id_genero int(10) unsigned zerofill NOT NULL auto_increment,
  genero varchar(40) collate utf8_spanish_ci NOT NULL,
  PRIMARY KEY  (id_genero),
  UNIQUE KEY genre (genero)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=13 ;

-- 
-- Volcar la base de datos para la tabla genre
-- 

INSERT INTO genre VALUES (0000000009, 'Clasica');
INSERT INTO genre VALUES (0000000008, 'Cumbia');
INSERT INTO genre VALUES (0000000005, 'Electronica');
INSERT INTO genre VALUES (0000000010, 'Hip-Hop');
INSERT INTO genre VALUES (0000000012, 'Merengue');
INSERT INTO genre VALUES (0000000003, 'Metal');
INSERT INTO genre VALUES (0000000002, 'Pop');
INSERT INTO genre VALUES (0000000006, 'Punk');
INSERT INTO genre VALUES (0000000007, 'Reggae');
INSERT INTO genre VALUES (0000000001, 'Rock');
INSERT INTO genre VALUES (0000000011, 'Salsa');
INSERT INTO genre VALUES (0000000004, 'Ska');

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla user
-- 

CREATE TABLE user (
  id_user int(10) unsigned zerofill NOT NULL auto_increment,
  user varchar(100) collate utf8_spanish_ci NOT NULL,
  pass varchar(40) collate utf8_spanish_ci NOT NULL,
  email varchar(100) collate utf8_spanish_ci NOT NULL,
  tipo varchar(1) collate utf8_spanish_ci NOT NULL default '2',
  PRIMARY KEY  (id_user),
  UNIQUE KEY user (user)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=8 ;

-- 
-- Volcar la base de datos para la tabla user
-- 

INSERT INTO user VALUES (0000000001, 'adri', '202cb962ac59075b964b07152d234b70', 'adri@gmail.com', '1');
INSERT INTO user VALUES (0000000002, 'mau', '202cb962ac59075b964b07152d234b70', 'mau@gmail.com', '1');
INSERT INTO user VALUES (0000000003, 'lala', '202cb962ac59075b964b07152d234b70', 'lala@gmail.com', '2');
INSERT INTO user VALUES (0000000004, 'popis', '3c130fa28607a8a8ee9f7f708502453f', 'popis@homail.com', '2');
INSERT INTO user VALUES (0000000005, 'borita', '31b0da9e36a87a85e8172e8d57f3d9a5', 'borita@hotmail.com', '2');
INSERT INTO user VALUES (0000000006, 'buuu', '72ed35cba42c605825398937595f445f', 'buuu@hotmail.com', '2');
INSERT INTO user VALUES (0000000007, 'adri2', '7815696ecbf1c96e6894b779456d330e', 'email', '2');

-- 
-- Filtros para las tablas descargadas (dump)
-- 

-- 
-- Filtros para la tabla album_artista
-- 
ALTER TABLE album_artista
  ADD CONSTRAINT album_artista_ibfk_1 FOREIGN KEY (id_artista) REFERENCES artistas (id_artista) ON DELETE CASCADE ON UPDATE CASCADE;

-- 
-- Filtros para la tabla canciones
-- 
ALTER TABLE canciones
  ADD CONSTRAINT canciones_ibfk_1 FOREIGN KEY (id_album_artista) REFERENCES album_artista (id_album_artista) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT canciones_ibfk_2 FOREIGN KEY (id_genero) REFERENCES genre (id_genero) ON DELETE CASCADE ON UPDATE CASCADE;

-- 
-- Procedimientos
-- 
-- 
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
-- 
--
-- Crear usuario 
--
GRANT ALL ON carrito.* TO carrito@localhost identified by '123456';

