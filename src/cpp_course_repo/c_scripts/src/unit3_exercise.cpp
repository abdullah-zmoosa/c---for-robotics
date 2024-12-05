#include "rosbot_control/rosbot_class.h"
#include <iostream>
#include <list>
#include <ros/ros.h>

using namespace std;

void turn(RosbotClass rosbot, string clock, int n_secs) {
rosbot.turn(clock, n_secs);

}

int main(int argc, char **argv) {
 ros::init(argc, argv, "rosbot_turn_node");
 RosbotClass rosbot;
 turn(rosbot, "clockwise", 2);
 turn(rosbot, "counterclockwise", 3);

  return 0;
}