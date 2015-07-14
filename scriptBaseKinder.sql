-- phpMyAdmin SQL Dump
-- version 2.10.2
-- http://www.phpmyadmin.net
-- 
-- Servidor: localhost
-- Tiempo de generación: 06-12-2012 a las 01:11:50
-- Versión del servidor: 5.5.24
-- Versión de PHP: 5.2.3

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

-- 
-- Base de datos: `kinder`
-- 
CREATE DATABASE kinder DEFAULT CHARACTER SET utf8 COLLATE utf8_spanish_ci;
USE kinder;

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `alumno`
-- 

CREATE TABLE `alumno` (
  `idalumno` int(11) NOT NULL,
  `apPaterno` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `apMaterno` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `nombre` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `sexo` bit(1) DEFAULT NULL,
  `fechaNacimiento` datetime DEFAULT NULL,
  `codigoPostal` int(11) DEFAULT NULL,
  `curp` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `idGrupo` int(11) DEFAULT NULL,
  PRIMARY KEY (`idalumno`),
  KEY `grupo` (`idGrupo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `alumno`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `aviso`
-- 

CREATE TABLE `aviso` (
  `idAviso` int(11) NOT NULL AUTO_INCREMENT,
  `aviso` varchar(80) COLLATE utf8_spanish_ci NOT NULL,
  `fecha` datetime NOT NULL,
  PRIMARY KEY (`idAviso`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=4 ;

-- 
-- Volcar la base de datos para la tabla `aviso`
-- 

INSERT INTO `aviso` VALUES (1, 'buuu', '2012-12-05 00:00:00');
INSERT INTO `aviso` VALUES (2, 'Por fin funciona esta cosa...', '2012-12-05 04:52:51');
INSERT INTO `aviso` VALUES (3, 'vhgvv jb', '2012-12-05 11:15:01');
INSERT INTO `aviso` VALUES (4, 'Por fin en Github, despues de mil anios XD', '2015-07-14 00:18:32');

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `colonia`
-- 

CREATE TABLE `colonia` (
  `idcolonia` int(11) NOT NULL,
  `nombre` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  PRIMARY KEY (`idcolonia`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `colonia`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `escuela`
-- 

CREATE TABLE `escuela` (
  `idEscuela` int(11) NOT NULL,
  `nombre` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `clave` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `sector` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `zona` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `turno` bit(1) DEFAULT NULL,
  `idPersonal` int(11) DEFAULT NULL,
  `telefono` int(11) DEFAULT NULL,
  PRIMARY KEY (`idEscuela`),
  KEY `personal1` (`idPersonal`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `escuela`
-- 

INSERT INTO `escuela` VALUES (1, 'JOAQUIN FERNANDEZ DE LIZARDI', '15DJN0432X', '11', '85', NULL, NULL, NULL);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `grupo`
-- 

CREATE TABLE `grupo` (
  `idGrupo` int(11) NOT NULL AUTO_INCREMENT,
  `grupo` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `grado` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  `idPersonal` int(11) DEFAULT NULL,
  PRIMARY KEY (`idGrupo`),
  KEY `personal2` (`idPersonal`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=6 ;

-- 
-- Volcar la base de datos para la tabla `grupo`
-- 

INSERT INTO `grupo` VALUES (1, 'A', '1', NULL);
INSERT INTO `grupo` VALUES (2, 'A', '2', NULL);
INSERT INTO `grupo` VALUES (3, 'B', '2', NULL);
INSERT INTO `grupo` VALUES (4, 'A', '3', NULL);
INSERT INTO `grupo` VALUES (5, 'B', '3', NULL);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `grupodocente`
-- 

CREATE TABLE `grupodocente` (
  `idGrupoDocente` int(11) NOT NULL AUTO_INCREMENT,
  `idPersonal` int(11) NOT NULL,
  `idGrupo` int(11) DEFAULT NULL,
  `fechainicio` date NOT NULL,
  `fechafin` date DEFAULT NULL,
  PRIMARY KEY (`idGrupoDocente`),
  UNIQUE KEY `idGrupo` (`idGrupo`),
  KEY `docentegrupo` (`idPersonal`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=21 ;

-- 
-- Volcar la base de datos para la tabla `grupodocente`
-- 

INSERT INTO `grupodocente` VALUES (5, 23, 5, '2012-12-05', NULL);
INSERT INTO `grupodocente` VALUES (6, 20, NULL, '2012-12-05', '2012-12-05');
INSERT INTO `grupodocente` VALUES (7, 21, NULL, '2012-12-05', '2012-12-05');
INSERT INTO `grupodocente` VALUES (8, 22, 4, '2012-12-05', NULL);
INSERT INTO `grupodocente` VALUES (9, 19, NULL, '2012-12-05', '2012-12-05');
INSERT INTO `grupodocente` VALUES (11, 19, NULL, '2012-12-05', '2012-12-05');
INSERT INTO `grupodocente` VALUES (13, 19, NULL, '2012-12-05', '2012-12-05');
INSERT INTO `grupodocente` VALUES (14, 20, NULL, '2012-12-05', '2012-12-05');
INSERT INTO `grupodocente` VALUES (19, 20, 3, '2012-12-05', NULL);
INSERT INTO `grupodocente` VALUES (20, 21, 1, '2012-12-05', NULL);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `incidenciaalumno`
-- 

CREATE TABLE `incidenciaalumno` (
  `idincidenciaAlumno` int(11) NOT NULL,
  `fechaIncidencia` datetime DEFAULT NULL,
  `idAlumno` int(11) DEFAULT NULL,
  `idTipoIncidencia` int(11) DEFAULT NULL,
  PRIMARY KEY (`idincidenciaAlumno`),
  KEY `alumno` (`idAlumno`),
  KEY `tipoIncidenciaA` (`idTipoIncidencia`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `incidenciaalumno`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `incidenciapersonal`
-- 

CREATE TABLE `incidenciapersonal` (
  `idincidenciaPersonal` int(11) NOT NULL AUTO_INCREMENT,
  `fechaIncidencia` datetime NOT NULL,
  `idPersonal` int(11) DEFAULT NULL,
  `idTipoIncidencia` int(11) DEFAULT NULL,
  PRIMARY KEY (`idincidenciaPersonal`),
  KEY `personalIn` (`idPersonal`),
  KEY `tipoIncidenciaP` (`idTipoIncidencia`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=8 ;

-- 
-- Volcar la base de datos para la tabla `incidenciapersonal`
-- 

INSERT INTO `incidenciapersonal` VALUES (1, '2012-12-03 04:04:05', 19, 1);
INSERT INTO `incidenciapersonal` VALUES (2, '2012-12-04 04:20:00', 19, 2);
INSERT INTO `incidenciapersonal` VALUES (3, '2012-12-13 04:20:00', 23, 11);
INSERT INTO `incidenciapersonal` VALUES (4, '2012-12-04 04:25:00', 25, 4);
INSERT INTO `incidenciapersonal` VALUES (5, '2012-12-11 04:25:29', 21, 8);
INSERT INTO `incidenciapersonal` VALUES (6, '2012-12-03 11:10:37', 21, 12);
INSERT INTO `incidenciapersonal` VALUES (7, '2012-12-03 00:50:07', 20, 15);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `municipio`
-- 

CREATE TABLE `municipio` (
  `idmunicipio` int(11) NOT NULL,
  `nombre` varchar(45) COLLATE utf8_spanish_ci DEFAULT NULL,
  PRIMARY KEY (`idmunicipio`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `municipio`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `personal`
-- 

CREATE TABLE `personal` (
  `idPersonal` int(11) NOT NULL AUTO_INCREMENT,
  `apPaterno` varchar(45) COLLATE utf8_spanish_ci NOT NULL,
  `apMaterno` varchar(45) COLLATE utf8_spanish_ci NOT NULL,
  `nombre` varchar(45) COLLATE utf8_spanish_ci NOT NULL,
  `sexo` binary(1) NOT NULL,
  `fechaNacimiento` date NOT NULL,
  `curp` varchar(18) COLLATE utf8_spanish_ci NOT NULL,
  `telefono` int(10) DEFAULT NULL,
  `celular` int(10) DEFAULT NULL,
  `codigoPostal` int(5) DEFAULT NULL,
  `idPuesto` int(1) NOT NULL,
  `clavePresupuestal` varchar(13) COLLATE utf8_spanish_ci NOT NULL,
  `numeroFiliacion` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `idMunicipio` int(11) DEFAULT NULL,
  `idColonia` int(11) DEFAULT NULL,
  PRIMARY KEY (`idPersonal`),
  KEY `puesto` (`idPuesto`),
  KEY `coloniaP` (`idColonia`),
  KEY `municipioP` (`idMunicipio`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=31 ;

-- 
-- Volcar la base de datos para la tabla `personal`
-- 

INSERT INTO `personal` VALUES (18, 'k', 'k', 'goku', 0x30, '2012-12-02', 'gokukk120254ouhh00', 5555555, 1111111, 90875, 1, '1234567890', '0987654321', NULL, NULL);
INSERT INTO `personal` VALUES (19, 'Garces', 'qwerty', 'Mauricio', 0x30, '1979-02-15', 'gaqm123456hycrgr04', 1234567890, 987654321, 50260, 2, '2343424', '2323232323', NULL, NULL);
INSERT INTO `personal` VALUES (20, 'Yoli', 'Prado', 'Adriana', 0x31, '1992-02-16', 'yaju900819mtmdth08', 1234567890, 987654321, 90740, 2, '9o09i8u', '4r5t6y7', NULL, NULL);
INSERT INTO `personal` VALUES (21, 'dominguez', 'tovar', 'edgar', 0x30, '1992-08-15', '', 35446676, 4254678, 65436, 2, 'uyt', 'tyu', NULL, NULL);
INSERT INTO `personal` VALUES (22, '   qwe', '             regert', 'q', 0x30, '1900-01-01', '123456789012345678', 321, 321, 321, 2, '87687', 'uygut7', NULL, NULL);
INSERT INTO `personal` VALUES (23, '1', '1', '1', 0x30, '1234-01-10', '123', 12, 1, 1, 2, '1', '1', NULL, NULL);
INSERT INTO `personal` VALUES (24, 'jose', 'jose', '       pepe', 0x30, '1900-01-01', '13', 123, 1231, 12314, 2, 'ibi', 'bib', NULL, NULL);
INSERT INTO `personal` VALUES (25, 'jose', 'b', '       pepe', 0x30, '1234-01-01', '123456789012345678', 987, 8798, 76565, 2, 'n987h9', 'm08hn0', NULL, NULL);
INSERT INTO `personal` VALUES (26, 'a', 'a', 'pepe', 0x30, '1234-01-01', 'q', 234, 445, 234, 2, 'c43r4', 'd34r4', NULL, NULL);
INSERT INTO `personal` VALUES (27, 'Garcia', 'Bueno', 'Moctezuma', 0x30, '1989-01-01', '1234567890oiuytrew', 1233, 1234567890, 50260, 2, '171edgdvgb', '81631tgbdbef', NULL, NULL);
INSERT INTO `personal` VALUES (28, 'gomez', 'ortiz', 'juan', 0x31, '1980-01-01', '123456789012345678', 123456789, 123456789, 1234, 2, 'njhjguhu8', 'yey2d277', NULL, NULL);
INSERT INTO `personal` VALUES (29, 'o', 'o', 'o', 0x30, '9087-01-01', 'uiuii0887rftvnbjmn', 1234567890, 1234567890, 12345, 2, '09765r6fvu', '8675rfgyukh', NULL, NULL);
INSERT INTO `personal` VALUES (30, 'chapo', 'guzman', 'joaquin', 0x30, '1990-09-24', 'asdfghjki654321234', 23456789, 234567, 23456, 2, '1234', '54321', NULL, NULL);

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `puesto`
-- 

CREATE TABLE `puesto` (
  `idPuesto` int(1) NOT NULL,
  `funcion` varchar(45) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`idPuesto`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `puesto`
-- 

INSERT INTO `puesto` VALUES (1, 'Director');
INSERT INTO `puesto` VALUES (2, 'Docente');

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `tipoincidencia`
-- 

CREATE TABLE `tipoincidencia` (
  `idtipoIncidencia` int(11) NOT NULL AUTO_INCREMENT,
  `clave` varchar(2) COLLATE utf8_spanish_ci NOT NULL,
  `incidencia` varchar(80) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`idtipoIncidencia`),
  UNIQUE KEY `clave` (`clave`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=26 ;

-- 
-- Volcar la base de datos para la tabla `tipoincidencia`
-- 

INSERT INTO `tipoincidencia` VALUES (1, 'RA', 'RETARDO A');
INSERT INTO `tipoincidencia` VALUES (2, 'RB', 'RETARDO B');
INSERT INTO `tipoincidencia` VALUES (3, 'RJ', 'RETARDO JUSTIFICADO');
INSERT INTO `tipoincidencia` VALUES (4, 'FI', 'FALTA INJUSTIFICADA');
INSERT INTO `tipoincidencia` VALUES (5, 'FS', 'FALTA POR SUSPENSION');
INSERT INTO `tipoincidencia` VALUES (6, 'DE', 'DIA ECONOMICO');
INSERT INTO `tipoincidencia` VALUES (7, 'LM', 'LICENCIA MEDICA');
INSERT INTO `tipoincidencia` VALUES (8, 'LG', 'LICENCIA DE GRAVIDEZ');
INSERT INTO `tipoincidencia` VALUES (9, 'CT', 'CONSTANCIAS DE TIEMPO');
INSERT INTO `tipoincidencia` VALUES (10, 'CO', 'COMISION OFICIAL');
INSERT INTO `tipoincidencia` VALUES (11, 'MF', 'CUIDADOS MATERNOS Y  FAMILIARES');
INSERT INTO `tipoincidencia` VALUES (12, 'V', 'VACACIONES');
INSERT INTO `tipoincidencia` VALUES (13, 'RE', 'RECESO ESCOLAR');
INSERT INTO `tipoincidencia` VALUES (14, 'SL', 'SUSPENSION DE LABORES DOCENTES DE ACUERDO AL CALENDARIO ESCOLAR OFICIAL');
INSERT INTO `tipoincidencia` VALUES (15, 'BC', 'BECA COMISION');
INSERT INTO `tipoincidencia` VALUES (16, 'AP', 'ACUERDO PRESIDENCIAL');
INSERT INTO `tipoincidencia` VALUES (17, 'RD', 'REPOSICION DE DIAS');
INSERT INTO `tipoincidencia` VALUES (18, 'PN', 'PERMISO POR NUPCIAS');
INSERT INTO `tipoincidencia` VALUES (19, 'PE', 'PERMISO POR EXAMEN PROFESIONAL');
INSERT INTO `tipoincidencia` VALUES (20, 'PD', 'PERMISO POR DEFUNCION');
INSERT INTO `tipoincidencia` VALUES (21, 'PL', 'PERIODO DE LACTANCIA');
INSERT INTO `tipoincidencia` VALUES (22, 'LA', 'LICENCIA POR ASUNTOS PARTICULARES');
INSERT INTO `tipoincidencia` VALUES (23, 'LP', 'LICENCIA PREJUBILATORIA');
INSERT INTO `tipoincidencia` VALUES (24, 'CS', 'COMISION SINDICAL');

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `usuario`
-- 

CREATE TABLE `usuario` (
  `nombre` varchar(45) COLLATE utf8_spanish_ci NOT NULL,
  `clave` varchar(45) COLLATE utf8_spanish_ci NOT NULL,
  `idPersonal` int(11) NOT NULL,
  PRIMARY KEY (`nombre`),
  KEY `personal` (`idPersonal`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

-- 
-- Volcar la base de datos para la tabla `usuario`
-- 

INSERT INTO `usuario` VALUES ('      toÃ±o', '123', 26);
INSERT INTO `usuario` VALUES ('1', '1', 23);
INSERT INTO `usuario` VALUES ('321', '321', 22);
INSERT INTO `usuario` VALUES ('adrii', '8a', 20);
INSERT INTO `usuario` VALUES ('bebe', '123', 27);
INSERT INTO `usuario` VALUES ('dos', 'dos', 25);
INSERT INTO `usuario` VALUES ('edgar', '1234', 21);
INSERT INTO `usuario` VALUES ('eR', 'r', 28);
INSERT INTO `usuario` VALUES ('gama', '54321', 30);
INSERT INTO `usuario` VALUES ('goku', '123', 18);
INSERT INTO `usuario` VALUES ('mau', '321', 19);
INSERT INTO `usuario` VALUES ('po', 'po', 29);
INSERT INTO `usuario` VALUES ('uno', 'uno', 24);

-- 
-- Filtros para las tablas descargadas (dump)
-- 

-- 
-- Filtros para la tabla `alumno`
-- 
ALTER TABLE `alumno`
  ADD CONSTRAINT `grupo` FOREIGN KEY (`idGrupo`) REFERENCES `grupo` (`idGrupo`);

-- 
-- Filtros para la tabla `escuela`
-- 
ALTER TABLE `escuela`
  ADD CONSTRAINT `personal1` FOREIGN KEY (`idPersonal`) REFERENCES `personal` (`idPersonal`);

-- 
-- Filtros para la tabla `grupo`
-- 
ALTER TABLE `grupo`
  ADD CONSTRAINT `personal2` FOREIGN KEY (`idPersonal`) REFERENCES `personal` (`idPersonal`);

-- 
-- Filtros para la tabla `incidenciaalumno`
-- 
ALTER TABLE `incidenciaalumno`
  ADD CONSTRAINT `alumno` FOREIGN KEY (`idAlumno`) REFERENCES `alumno` (`idalumno`),
  ADD CONSTRAINT `tipoIncidenciaA` FOREIGN KEY (`idTipoIncidencia`) REFERENCES `tipoincidencia` (`idtipoIncidencia`);

-- 
-- Filtros para la tabla `incidenciapersonal`
-- 
ALTER TABLE `incidenciapersonal`
  ADD CONSTRAINT `personalIn` FOREIGN KEY (`idPersonal`) REFERENCES `personal` (`idPersonal`),
  ADD CONSTRAINT `tipoIncidenciaP` FOREIGN KEY (`idTipoIncidencia`) REFERENCES `tipoincidencia` (`idtipoIncidencia`);

-- 
-- Filtros para la tabla `personal`
-- 
ALTER TABLE `personal`
  ADD CONSTRAINT `coloniaP` FOREIGN KEY (`idColonia`) REFERENCES `colonia` (`idcolonia`),
  ADD CONSTRAINT `municipioP` FOREIGN KEY (`idMunicipio`) REFERENCES `municipio` (`idmunicipio`),
  ADD CONSTRAINT `puesto` FOREIGN KEY (`idPuesto`) REFERENCES `puesto` (`idPuesto`);

-- 
-- Filtros para la tabla `usuario`
-- 
ALTER TABLE `usuario`
  ADD CONSTRAINT `personal` FOREIGN KEY (`idPersonal`) REFERENCES `personal` (`idPersonal`);
--
--
-- Crear usuario 
--
GRANT ALL ON kinder.* TO kinder@localhost identified by '123456';

