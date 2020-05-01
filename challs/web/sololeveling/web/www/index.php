<?php

    function encrypt($string) {
        if (is_numeric($string)) {
            $string = (string)((int)$string + 1);
            return base64_encode($string);
        }
        else
            return (encrypt(0));
    }

    function decrypt($string) {
        $ret = base64_decode($string);
        if (is_numeric($ret)) {
            $ret = number_format($ret, 0, "", "");
            return($ret);
        }
        else
            return (decrypt(encrypt(0)));
    }

    if (!isset($_COOKIE["leveliterator"])) {
        setcookie("leveliterator", encrypt(0));
    }
    if (isset($_POST["levelup"])) {
        setcookie("leveliterator", encrypt(decrypt($_COOKIE["leveliterator"])));
    }
    $level = decrypt($_COOKIE["leveliterator"]);
    if ($level == "")
        $level = "1";
?>

<!DOCTYPE HTML>
<html lang="en" xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="utf-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"/>

    <title>Solo Leveling</title>
</head>

<body background="https://atm-subs.fr/wp-content/uploads/2019/09/solo-leveling.png">


    <form method="post">
        <h2>
            <span style="color:white"> You are level: <?php echo(number_format($level, 0, "", "")); ?></span>
        </h2>
        <input type="hidden" name="levelup"/>
        <input type="submit" value="Level up">
    </form>
    <?php if ($level >= 2000000000) { ?>
        <br/>
        <h3>
            <span style='color:white'>Wow! He is S rank! epiCTF{c00ki3s_aR3_F0r_[Tr4ck1nG]}</span>
        </h3>
    <?php } ?>

</body>
</html>