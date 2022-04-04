
arm-linux-g++ -Wall -Wextra -pthread src/main_td2b.cpp src/timerLib/timerLib.cpp -I. -o programtd2b -lrt;

chmod +x programtd2b;

scp programtd2b root@192.168.50.52:ROB305/TP2 ;
rm  programtd2b;