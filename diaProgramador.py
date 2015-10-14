#!/usr/bin/python
# -*- coding: utf-8
# recibe como primer argumento el año a verificar y el segundo argumento es el dia del año
import sys, datetime
if len(sys.argv) < 3:
	print "Este programa necesita dos argumentos, ejemplo: \n\"python diaProgramador.py 2015 256\""
	exit()
else:
	anio = int(sys.argv[1])
	dia = int(sys.argv[2]) #256
	diasMeses = {	'es':{						'mes':['', 'enero', 'febrero', 'marzo', 'abril', 'mayo', 'junio', 'julio', 'agosto', 'septiembre', 'octubre', 'noviembre', 'diciembre'],						'diaSemana':['lunes', 'martes', 'miercoles', 'jueves', 'viernes', 'sabado', 'domingo']						},					'ru':{						'mes':['', 'январь', 'февраль', 'март', 'апрель', 'май', 'июнь', 'июль', 'август', 'сентябрь', 'октябрь', 'ноябрь', 'декабрь'],						'diaSemana':['понедельник', 'вторник', 'среда', 'четверг', 'пятница', 'суббота', 'воскресенье']					}				}
	inicioAnio = datetime.datetime.strptime('01-01-'+str(anio), '%d-%m-%Y')
	inicioAnioMasDias = inicioAnio + datetime.timedelta(days=dia-1)
	if anio < 2002 :
		print "El dia del programador no existe todavia :("
	elif anio < 2009:
		print 'день Программисты в '+str(anio)+'  году был отмечен '+diasMeses['ru']['diaSemana'][inicioAnioMasDias.weekday()]+' '+inicioAnioMasDias.strftime('%d')+' '+diasMeses['ru']['mes'][inicioAnioMasDias.month]
	elif inicioAnioMasDias.toordinal() < datetime.date.today().toordinal():
		print 'En '+str(anio)+' el dia del programador se celebro el '+diasMeses['es']['diaSemana'][inicioAnioMasDias.weekday()]+' '+inicioAnioMasDias.strftime('%d')+' de '+diasMeses['es']['mes'][inicioAnioMasDias.month]
	elif inicioAnioMasDias.toordinal() == datetime.date.today().toordinal():
		print 'Felicidaes!!! hoy es el dia del programador!'
	else:
		print 'En '+str(anio)+' el dia del programador se celebrará el '+diasMeses['es']['diaSemana'][inicioAnioMasDias.weekday()]+' '+inicioAnioMasDias.strftime('%d')+' de '+diasMeses['es']['mes'][inicioAnioMasDias.month]+' |m|__(>_<)__|m|' 
