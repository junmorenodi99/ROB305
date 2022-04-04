# [TD-4] Classes de base pour la programmation multitâches

*Author : Nicolas Dimate*

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -pthread src/main_td4a.cpp src/timerLib/timerLib.cpp src/PosixThread/PosixThread.cpp  src/Thread/Thread.cpp src/CounterThread/CounterThread.cpp -I. -o programtd4a -lrt;
```

Or run:

```
sh exe_main_td4a.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd4a <nLoops> <nTasks> <Sched Policy>
```

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -pthread src/main_td4b.cpp src/CounterMutex/CounterMutex.cpp src/Lock/Lock.cpp src/Mutex/Mutex.cpp src/timerLib/timerLib.cpp src/CounterThread/CounterThread.cpp src/Monitor/Monitor.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp -I. -o programtd4b -lrt;
```

Or run:

```
sh exe_main_td4b.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd4b <nLoops> <nTasks> <Sched Policy>
```

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td4c.cpp src/Semaphore/Semaphore.cpp src/SemaphoreConsumer/SemaphoreConsumer.cpp src/SemaphoreProducer/SemaphoreProducer.cpp src/CounterMutex/CounterMutex.cpp src/Lock/Lock.cpp src/Mutex/Mutex.cpp src/timerLib/timerLib.cpp src/CounterThread/CounterThread.cpp src/Monitor/Monitor.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp -I. -o programtd4c -lrt -lpthread;
```

Or run:

```
./exe_main_td4c.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd1c <nProd> <nCons> <nItems>
```

------------------


## d)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -lpthread src/main_td4d.cpp src/Fifo/Fifo.hpp src/FifoProducer/FifoProducer.hpp src/FifoConsumer/FifoConsumer.hpp src/Semaphore/Semaphore.cpp src/SemaphoreConsumer/SemaphoreConsumer.cpp src/SemaphoreProducer/SemaphoreProducer.cpp src/CounterMutex/CounterMutex.cpp src/Lock/Lock.cpp src/Mutex/Mutex.cpp src/timerLib/timerLib.cpp src/CounterThread/CounterThread.cpp src/Monitor/Monitor.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp -I. -o programtd4d -lrt;
```

Or run:
```
./compile_main_td4d.sh 
```

2. **Execute in the Raspberry Pi**:

```
./main_td4d <nProd> <nCons> <nItems>
```
