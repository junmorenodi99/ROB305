# [TD-2] Familiarisation avec l’API multitâches pthread

*Author : Nicolas Dimate*

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -pthread src/main_td2a.cpp src/timerLib/timerLib.cpp -I. -o programtd2a -lrt;
```

Or run:

```
sh exe_main_td2a.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd2a <nLoops> <nTasks>
```

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -pthread src/main_td2b.cpp src/timerLib/timerLib.cpp -I. -o programtd2b -lrt;
```

Or run:

```
sh exe_main_td2b.sh
```

2. **Execute in the Raspberry Pi**:

```
./programtd2b <nLoops> <nTasks> <schedPolicy>
```

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra -pthread src/main_td2c.cpp src/timerLib/timerLib.cpp -I. -o programtd2c -lrt;
```

Or run:

```
./exe_main_td2c.sh 
```

2. **Execute in the Raspberry Pi**:

```
./programtd2c <nLoops> <nTasks> protected
```

------------------


