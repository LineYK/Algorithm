<?php
fscanf(STDIN, "%d\n", $n);

$arr = array();

for ($i = 1; $i <= $n; $i++) {
    fscanf(STDIN, "%d\n", $num);
    array_push($arr, $num);
}

sort($arr);

foreach ($arr as &$val) {
    fprintf(STDOUT, "%d\n", $val);
}
?>