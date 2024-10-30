<!DOCTYPE html>
<html>
<body>
here is the table: 

<?php
$size=(int)$_POST['size']; //takes in value for size from html that calls it
echo "<table border='1'>";

echo "<tr><td></td>"; //corner header cell 
for ($c=1; $c<=$size; $c++) //column headers 
{
    echo "<td><strong>$c</strong></td>"; 
}
echo "</tr>";

for ($i=1; $i<=$size; $i++) {
    echo "<tr>";
    echo "<td><strong>$i</strong></td>"; //row headers 
    for ($j=1; $j<=$size; $j++) {
	$x=$i*$j; 
        echo "<td>$x</td>";
    }
    echo "</tr>";
}

echo "</table>";
?>

</body>
</html>