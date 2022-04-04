
arm-linux-g++ -Wall -Wextra src/main_td1c.cpp src/timerLib/timerLib.cpp -I. -o programtd1c -lrt -lpthread;


chmod +x programtd1c;

scp programtd1c root@192.168.50.52:ROB305/TP1 ;
 
rm programtd1c;