# [TD-1] Mesure de temps et échantillonnage en temps

*Author : Nicolas Dimate*

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/timerLib/timerLib.cpp -I. -o programtd1a -lrt;
```

Or run:

```
sh exe_main_td1a.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd1a
```

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1b.cpp src/timerLib/timerLib.cpp -I. -o programtd1b -lrt;
```

Or run:

```
sh exe_main_td1b.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd1b
```

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1c.cpp src/timerLib/timerLib.cpp -I. -o programtd1c -lrt -lpthread;
```

Or run:

```
./exe_main_td1c.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd1c <nLoops>
```

------------------


## d)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/TimerLib/TimerLib.cpp -o main_td1d -lrt -lpthread
```

Or run:
```
./compile_main_td1d.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td1d
```
