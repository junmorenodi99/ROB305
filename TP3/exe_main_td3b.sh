arm-linux-g++ -Wall -Wextra src/main_td3b.cpp src/timerLib/timerLib.cpp src/ChronoLib/ChronoLib.cpp src/CounterDown/CounterDown.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Timer/Timer.cpp -I. -o programtd3b -lrt;

chmod +x programtd3b;

scp programtd3b root@192.168.50.52:ROB305/TP3 ; 
rm programtd3b;