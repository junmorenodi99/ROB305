
arm-linux-g++ -Wall -Wextra -pthread src/main_td4b.cpp src/CounterMutex/CounterMutex.cpp src/Lock/Lock.cpp src/Mutex/Mutex.cpp src/timerLib/timerLib.cpp src/CounterThread/CounterThread.cpp src/Monitor/Monitor.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp -I. -o programtd4b -lrt;


chmod +x programtd4b;

scp programtd4b root@192.168.50.52:ROB305/TP4; 
rm programtd4b;