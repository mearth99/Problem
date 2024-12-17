target=$1
name=${target:0:-4}

g++ -o $name $target
./$name

dos2unix ./output.txt
if diff .//output.txt ./myoutput.txt 1>/dev/null;then echo "예제정답과 일치합니다.";else echo "예제정답과 일치하지 않습니다.";fi