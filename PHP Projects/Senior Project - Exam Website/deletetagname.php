<?php
require 'mysql.php';

// Create connect
$con = mysqli_connect($server, $user, $pass, $db);
// Check connection
if (mysqli_connect_errno())
{
	echo "MySQL Failed: ".mysqli_connect_error();
}

$QUESTION = $_POST['id'];

if (!empty($QUESTION)) {
    mysqli_query($con,"DELETE FROM tags WHERE questionId = $QUESTION;");
}
else {
	echo "<success>0</success>";
}

mysqli_close($con);
?>