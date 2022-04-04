
arm-linux-g++ -Wall -Wextra -pthread src/main_td2c.cpp src/timerLib/timerLib.cpp -I. -o programtd2c -lrt;

chmod +x programtd2c;

scp programtd2c root@192.168.50.52:ROB305/TP2 ;
rm  programtd2c;