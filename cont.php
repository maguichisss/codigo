<?php
    
    $pass = $_POST["pass"];
    if (!mysqli_connect("localhost", "jardin", "$pass", "sci") ) 
        echo "<script> alert('Contrase�a incorrecta')  </script>";
    else
        echo "<script>location='registro.html'</script>";
    
?>