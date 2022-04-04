
arm-linux-g++ -Wall -Wextra src/main_td1b.cpp src/timerLib/timerLib.cpp -I. -o programtd1b -lrt;

chmod +x programtd1b;

scp programtd1b root@192.168.50.52:ROB305/TP1 ;
 
rm programtd1b;