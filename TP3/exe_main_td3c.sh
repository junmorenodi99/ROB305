arm-linux-g++ -Wall -Wextra src/main_td3c.cpp src/timerLib/timerLib.cpp src/Looper/Looper.cpp src/ChronoLib/ChronoLib.cpp src/Calibrator/Calibrator.cpp src/CounterDown/CounterDown.cpp src/CpuLoop/CpuLoop.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Timer/Timer.cpp -I. -o programtd3c -lrt;

chmod +x programtd3c;

scp programtd3c root@192.168.50.52:ROB305/TP3 ; 
rm programtd3c;

