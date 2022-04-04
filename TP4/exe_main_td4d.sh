
arm-linux-g++ -Wall -Wextra -lpthread src/main_td4d.cpp src/Fifo/Fifo.hpp src/FifoProducer/FifoProducer.hpp src/FifoConsumer/FifoConsumer.hpp src/Semaphore/Semaphore.cpp src/SemaphoreConsumer/SemaphoreConsumer.cpp src/SemaphoreProducer/SemaphoreProducer.cpp src/CounterMutex/CounterMutex.cpp src/Lock/Lock.cpp src/Mutex/Mutex.cpp src/timerLib/timerLib.cpp src/CounterThread/CounterThread.cpp src/Monitor/Monitor.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp -I. -o programtd4d -lrt;

chmod +x programtd4d;

scp programtd4d root@192.168.50.52:ROB305/TP4 ; 
rm programtd4d;