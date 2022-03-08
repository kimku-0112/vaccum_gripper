# Vacuum_Gripper
JWT Robot Controller vacuum gripper control pkg

# Install
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/kimku-0112/vacuum_gripper.git
```
<img src="./Image/install.gif"  width="1280" height="540">

# rebuild
```
cd ~/catkin_ws/src/vacuum_gripper
./rebuild.sh
```

<img src="./Image/rebuild.gif"  width="1280" height="540">

# build
```
cd ~/catkin_ws/src/vacuum_gripper
./build.sh
```

<img src="./Image/build.gif"  width="1280" height="540">

# Main launch

## Vacuum gripper control node launch
```
cd ~/catkin_ws/src/vacuum_gripper
./1.suction_and_blow.sh
```

<img src="./Image/main.gif"  width="1280" height="540">


# publish Test node launch
## Set vaccum gripper Mode (Off = 0 / suction = 1 / blow off = 2)
```
cd ~/catkin_ws/src/vacuum_gripper
./2.pub_suction_and_blow.sh
```

<img src="./Image/test.gif"  width="1280" height="540">


# demo

<img src="./Image/demo.gif"  width="1280" height="540">
