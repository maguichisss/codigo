#!/usr/bin/python
# -*- coding: utf-8
# recibe como primer argumento el año a verificar y el segundo argumento es el dia del año
import sys, datetime

if len(sys.argv) >= 1:
    anio = int(sys.argv[1])
    dia = 256
    daysMonths = {
        'es':{
            'mes':['', 'enero', 'febrero', 'marzo', 'abril', 'mayo', 'junio', 'julio', 'agosto', 'septiembre', 'octubre', 'noviembre', 'diciembre'],
            'diaSemana':['lunes', 'martes', 'miercoles', 'jueves', 'viernes', 'sabado', 'domingo']},
        'ru':{
            'mes':['', 'январь', 'февраль', 'март', 'апрель', 'май', 'июнь', 'июль', 'август', 'сентябрь', 'октябрь', 'ноябрь', 'декабрь'],
            'diaSemana':['понедельник', 'вторник', 'среда', 'четверг', 'пятница', 'суббота', 'воскресенье']},
    }
    inicioAnio = datetime.datetime.strptime('01-01-'+str(anio), '%d-%m-%Y')
    diaProg = inicioAnio + datetime.timedelta(days=dia-1)
    diaSemana = daysMonths['es']['diaSemana'][diaProg.weekday()]
    diaMes = diaProg.strftime('%d')
    mes = daysMonths['es']['mes'][diaProg.month]

    if anio < 2002 :
        print("El dia del programador no existe todavia :(")
    elif anio < 2009:
        ruDay = daysMonths['ru']['diaSemana'][diaProg.weekday()]
        ruMonth = daysMonths['ru']['mes'][diaProg.month]
        print(f'день Программисты в {anio} году был отмечен {ruDay} {diaMes} {ruMonth}')
    elif diaProg.toordinal() < datetime.date.today().toordinal():
        print(f'En {anio} el dia del programador se celebro el {diaSemana} {diaMes} de {mes}')
    elif diaProg.toordinal() == datetime.date.today().toordinal():
        print('Felicidaes!!! hoy es el dia del programador!')
    else:
        print(f'En {anio} el dia del programador se celebrará el {diaSemana} {diaMes} de {mes} |m|__(>_<)__|m|' )
else:
    print("Este programa necesita dos argumentos, ejemplo: \n\"python diaProgramador.py 2015 256\"")
    exit()
