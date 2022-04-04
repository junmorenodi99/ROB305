
arm-linux-g++ -Wall -Wextra src/main_td3a.cpp src/timerLib/timerLib.cpp src/ChronoLib/ChronoLib.cpp -I. -o programtd3a -lrt;

chmod +x programtd3a;

scp programtd3a root@192.168.50.52:ROB305/TP3 ; 
rm programtd3a;