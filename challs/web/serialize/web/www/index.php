<?php
    if (isset($_POST["conv"])) $convert = $_POST["conv"]; else $convert = NULL;
    if (isset($_POST["number"])) $number = $_POST["number"]; else $number = NULL;

    $result = 0;
    if ($convert && $number) {
        $result = $convert($number);
    }
?>

<!DOCTYPE HTML>
<html lang="en">
<head>
    <meta charset="utf-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"/>

    <title>Converter</title>
</head>

<body>
    <h2> Amazing converter</h2>

    <form method="post">

        <select name="conv">
            <option value="dechex">to hex</option>
            <option value="decoct">to oct</option>
            <option value="decbin">to bin</option>
        </select>
        <input type="text" name="number", placeholder="0"/>
        <input type="submit" value="Convert!">
    </form>
    <?php if ($result != 0) { ?>
        <br/>
        <h3>
            <span> Result = <?php echo($result); ?> </span>
        </h3>
    <?php } ?>

</body>
</html>