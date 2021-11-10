# sbc_GPIO
vacuum gripper control pkg

# Install
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/kimku-0112/sbc_GPIO.git
```
# rebuild
```
cd ~/catkin_ws/src/sbc_gpio
./rebuild.sh
```

# build
```
cd ~/catkin_ws/src/sbc_gpio
./build.sh
```

# launch

## suction blow Main
New Terminal
```
cd ~/catkin_ws/src/sbc_gpio
./1.suction_and_blow.sh
```


## Set vaccum gripper Mode
New Terminal
```
cd ~/catkin_ws/src/sbc_gpio
./2.pub_suction_and_blow.sh
```

# warning
이 package는 WU310Z3A PC ubuntu 16.04 ros kinetic 환경에서 동작합니다. 

(그외의 환경에서는 작동하지 않습니다.)
