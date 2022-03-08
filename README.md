# Vacuum_Gripper
JWT Robot Controller vacuum gripper control pkg

# Install
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/kimku-0112/vacuum_gripper.git
```
<center><img src="https://user-images.githubusercontent.com/66875200/157189776-234fa3ce-3c86-4cc9-aa95-579cfa94f3a2.gif"  width="960"></center>

# rebuild
```
cd ~/catkin_ws/src/vacuum_gripper
./rebuild.sh
```

<center><img src="https://user-images.githubusercontent.com/66875200/157189797-1b4b7deb-395d-480a-9620-d1423ae00c68.gif"  width="960"></center>

# build
```
cd ~/catkin_ws/src/vacuum_gripper
./build.sh
```

<center><img src="https://user-images.githubusercontent.com/66875200/157189808-277448a4-f1a7-440f-bb6f-7f6e192d6261.gif"  width="960"></center>

# Main launch

## Vacuum gripper control node launch
```
cd ~/catkin_ws/src/vacuum_gripper
./1.suction_and_blow.sh
```

<center><img src="https://user-images.githubusercontent.com/66875200/157189820-eabe1acd-f213-4b7e-b806-a62f22dfd4e4.gif"  width="960"></center>


# publish Test node launch
## Set vaccum gripper Mode (Off = 0 / suction = 1 / blow off = 2)
```
cd ~/catkin_ws/src/vacuum_gripper
./2.pub_suction_and_blow.sh
```

<center><img src="https://user-images.githubusercontent.com/66875200/157189830-537eebd9-81bb-42fb-b9be-68028fd22e91.gif"  width="960"></center>


# demo

<center><img src="https://user-images.githubusercontent.com/66875200/157191868-53f777fd-8483-41e4-902f-3215d69c213e.gif"  width="960"></center>
