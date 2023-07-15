for((i=1; ; i++)){
    echo $i
    ./gen $i > int
    diff -w <(./test < int) <(./brute < int) || break
}

