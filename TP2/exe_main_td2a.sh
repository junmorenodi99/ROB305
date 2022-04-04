
arm-linux-g++ -Wall -Wextra -pthread src/main_td2a.cpp src/timerLib/timerLib.cpp -I. -o programtd2a -lrt;

chmod +x programtd2a;

scp programtd2a root@192.168.50.52:ROB305/TP2 ;
rm  programtd2a;