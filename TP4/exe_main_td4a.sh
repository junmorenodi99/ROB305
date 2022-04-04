
arm-linux-g++ -Wall -Wextra -pthread src/main_td4a.cpp src/timerLib/timerLib.cpp src/PosixThread/PosixThread.cpp  src/Thread/Thread.cpp src/CounterThread/CounterThread.cpp -I. -o programtd4a -lrt;


chmod +x programtd4a;

scp programtd4a root@192.168.50.52:ROB305/TP4 ; 
rm programtd4a;