#include "rosbot_control/rosbot_class.h"
#include <iostream>
#include <ros/ros.h>
#include <list>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  
  rosbot.move_forward(4.0);

  list<float> list_coordinates;

  list_coordinates = rosbot.get_position_full();
  for (float coordinate : list_coordinates){

  ROS_INFO_STREAM(coordinate << ", ");
  
  }



  return 0;
}