<?php
    
    $pass = $_POST["pass"];
    if ($pass != "olakase" ) 
        echo "<script> alert('Contrase�a incorrecta')</script>";
    else
        echo "<script>location='registro.html'</script>";
    
?>