cmake_minimum_required(VERSION 3.0.2)
project(vacuum_gripper)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES sbc_gpio
  CATKIN_DEPENDS roscpp rospy
  DEPENDS system_lib
)

set(SUCTION_AND_BLOW_SOURCES
  src/suction_blow.cpp
)

set(PUB_SUCTION_AND_BLOW_SOURCES
  src/pub_suction_blow.cpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}  
)

add_executable(suction_and_blow ${SUCTION_AND_BLOW_SOURCES})
target_link_libraries(suction_and_blow  ${catkin_LIBRARIES})
add_dependencies(suction_and_blow ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(pub_suction_and_blow ${PUB_SUCTION_AND_BLOW_SOURCES})
target_link_libraries(pub_suction_and_blow  ${catkin_LIBRARIES})
add_dependencies(pub_suction_and_blow ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

