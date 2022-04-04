
arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/timerLib/timerLib.cpp -I. -o programtd1d -lrt -lpthread;

chmod +x programtd1d;

scp programtd1d root@192.168.50.52:ROB305/TP1 ;
 
rm programtd1d;