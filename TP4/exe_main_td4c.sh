
arm-linux-g++ -Wall -Wextra src/main_td4c.cpp src/Semaphore/Semaphore.cpp src/SemaphoreConsumer/SemaphoreConsumer.cpp src/SemaphoreProducer/SemaphoreProducer.cpp src/CounterMutex/CounterMutex.cpp src/Lock/Lock.cpp src/Mutex/Mutex.cpp src/timerLib/timerLib.cpp src/CounterThread/CounterThread.cpp src/Monitor/Monitor.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp -I. -o programtd4c -lrt -lpthread;

chmod +x programtd4c;

scp programtd4c root@192.168.50.52:ROB305/TP4 ; 
rm programtd4c;