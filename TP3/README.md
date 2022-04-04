# [TD-2] Classes pour la gestion du temps

*Author : Nicolas Dimate*

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td3a.cpp src/timerLib/timerLib.cpp src/ChronoLib/ChronoLib.cpp -I. -o programtd3a -lrt;
```

Or run:

```
sh exe_main_td3a.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd3a 
```

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td3b.cpp src/timerLib/timerLib.cpp src/ChronoLib/ChronoLib.cpp src/CounterDown/CounterDown.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Timer/Timer.cpp -I. -o programtd3b -lrt;
```

Or run:

```
sh exe_main_td3b.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd3b <nLoops>
```

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td3c.cpp src/timerLib/timerLib.cpp src/Looper/Looper.cpp src/ChronoLib/ChronoLib.cpp src/Calibrator/Calibrator.cpp src/CounterDown/CounterDown.cpp src/CpuLoop/CpuLoop.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Timer/Timer.cpp -I. -o programtd3c -lrt;
```

Or run:

```
./exe_main_td3c.sh 
```

2. **Execute in the Raspberry Pi**:

```
./programtd3c 
```

------------------


