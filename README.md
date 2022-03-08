# Vacuum_Gripper
JWT Robot Controller vacuum gripper control pkg

# Install
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/kimku-0112/vacuum_gripper.git
```
<center><img src="./Image/install.gif"  width="960"></center>

# rebuild
```
cd ~/catkin_ws/src/vacuum_gripper
./rebuild.sh
```

<center><img src="./Image/rebuild.gif"  width="960"></center>

# build
```
cd ~/catkin_ws/src/vacuum_gripper
./build.sh
```

<center><img src="./Image/build.gif"  width="960"></center>

# Main launch

## Vacuum gripper control node launch
```
cd ~/catkin_ws/src/vacuum_gripper
./1.suction_and_blow.sh
```

<center><img src="./Image/main.gif"  width="960"></center>


# publish Test node launch
## Set vaccum gripper Mode (Off = 0 / suction = 1 / blow off = 2)
```
cd ~/catkin_ws/src/vacuum_gripper
./2.pub_suction_and_blow.sh
```

<center><img src="./Image/test.gif"  width="960"></center>


# demo

<center><img src="./Image/demo.gif"  width="960"></center>
