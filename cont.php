<?php
    
    $pass = $_POST["pass"];
    if (!mysqli_connect("localhost", "jardin", "$pass", "sci") ) 
        echo "<script> alert('Contraseņa incorrecta')  </script>";
    else
        echo "<script>location='registro.html'</script>";
    
?>