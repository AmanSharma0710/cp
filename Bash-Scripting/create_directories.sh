#/bin/bash
for((i=1; i<=25; i++)){
if (( $i<10 ))
then
mkdir -p "Day 0$i"
else
mkdir -p "Day $i"
fi
}
for file in *-*
{
var=${file%%-*}
if (( $var<10 ))
then
cp $file "Day 0$var/"
else
cp $file "Day $var/"
fi
rm -f $file
}