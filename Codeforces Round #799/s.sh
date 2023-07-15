for((i=1; ; i++)){
    echo $i
    ./gen $i > int
    diff -w <(./A < int) <(./brute < int) || break
}

