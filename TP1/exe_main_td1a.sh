
arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/timerLib/timerLib.cpp -I. -o programtd1a -lrt;

chmod +x programtd1a;

scp programtd1a root@192.168.50.52:ROB305/TP1 ;

rm programtd1a;