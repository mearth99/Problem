target=$1
name=${target:0:-4}

g++ -o $name $target
./$name