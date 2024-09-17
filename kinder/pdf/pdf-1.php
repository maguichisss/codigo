<?php
require('fpdf.php');
$pdf = new FPDF('P','mm','Letter');
$pdf->AddPage();
$pdf->SetMargins(18, 4.43,18);
$pdf->SetFont('Arial','B',12);
$conexionDB = mysqli_connect("localhost", "jardin", "jardin123", "sci");
$idincidenciapersonal = $_POST["uno"];
$result = mysqli_query($conexionDB, 
        "SELECT a.*, b.*, c.* 
        FROM personal a, incidenciapersonal b, tipoincidencia c 
        WHERE a.idPersonal=b.idPersonal 
        and b.idTipoIncidencia=c.idTipoIncidencia 
        and b.idincidenciaPersonal='$idincidenciapersonal'");
$persona=mysqli_fetch_array($result);
$result = mysqli_query($conexionDB,"SELECT * FROM escuela");
$director=mysqli_fetch_array($result);
$pdf->Image('imagenes/header-all.jpg',0, 0, 220, 60);
$pdf->Ln(35);
$pdf->MultiCell(180,10,'N° / '.$idincidenciapersonal.' / '.date("Y").'.',0,'R');
$pdf->MultiCell(180,10,'Naucalpan México, a '.date("j").' de '.date("m").' de '.date("Y").'.' ,0,'R');
$pdf->MultiCell(180,6,
'PROFRA. 
LETICIA BARRAZA ACOSTA                 ' ,0,'L');
$pdf->SetFont('Arial','',12);
$pdf->MultiCell(180,6,
'JEFE DEL DEPARTAMENTO DE EDUCACIÓN
PREESCOLAR VALLE DE MÉXICO
P  R  E  S  E  N  T  E                 ' ,0,'L');
$pdf->Ln(5);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(180,6,'                   La (El) que suscribe, C. PROFR. (A)________(jefe inmediato)____, director de la Institución '.$director['nombre'].' zona '.$director['zona'].' sector '.$director['sector']. ', remite a Usted, Licencia Médica No_(número de folio)__, expedida por el ISSSTE, de la C. Profr.(a) '.$persona['nombre'].' '.$persona['apPaterno'].' '.$persona['apMaterno'].', R.F.C. '.substr($persona['curp'],0,10).', Clave(s) '.$persona['clavePresupuestal'].', faltó a sus labores en (los) día (s) '.substr($persona['fechaIncidencia'],0,10).', reanudando oportunamente el __(día, mes y año)__.
                                       ' ,0,'J');
$pdf->MultiCell(180,6,'                     NOTA: La Original se entrego (Solo en el caso que se haga entrega en el turno matutino), '.$director['nombre'].' zona '.$director['zona'].' sector '.$director['sector'].'.
                                       ' ,0,'J');
$pdf->MultiCell(180,6,'                 Lo anterior se informa para los fines a que haya lugar.
                                       ' ,0,'J');
$pdf->MultiCell(180,6,'A T E N T A M E N T E 
          Director                      ' ,0,'L');
$pdf->MultiCell(180,6,'C. PROFRA. __(jefe inmediato, firma y sello)__' ,0,'L');
$pdf->Ln(10);
$pdf->SetFont('Arial','',8);
$pdf->MultiCell(180,6,'c.c.p. Archivo					
c.c.p. Minutario      ' ,0,'L');
$pdf->Image('imagenes/footer-all.jpg',0, 220, 220, 60);
$pdf->Output();
?>