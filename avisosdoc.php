    <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
        <head>
            <title>Jard&iacuten de ni&ntildeos "Joaquin Fern&aacutendez de Lizardi"</title>
            <meta http-equiv="content-type" content="text/html;charset=utf-8" />
            <link rel="stylesheet" type="text/css" href="basic.css" />
        </head>

        <body>

            <div id="first_container">
                <div id="second_container">
                    <div id="third_container">
                    

                    
                        <ul id="menu">
			    <li><a href="index.html">Salir</a></li>

			    <li><span id="menuselected">Avisos</span></li>

			    <li><a href="docente.html">Alumno</a></li>
                          
			    
                        </ul> 

                        <div class="border">
                            <div class="content">
                                    <h1>Avisos</h1>
                                    <div class="text">
<br>
Avisos al docente:
<?php
include("conectar.php");
conectarBaseDeDatos();
$consulta = mysqli_query($conexionDB, "SELECT * FROM aviso");
while($aviso=mysqli_fetch_array($consulta))
{    
echo '<br>'.substr($aviso['fecha'],0,10)." - ".$aviso['aviso'];
}

?>
<br>


				    </div>
                                    
                            </div>
                        </div>

			<ul id="submenu">

			   	    
			    
                        </ul>
                        
                        
                        <div class="designinfo">
                            
                        </div>
                        
                    </div>
                </div>
            </div>
                    
        </body>
        
    </html>
    