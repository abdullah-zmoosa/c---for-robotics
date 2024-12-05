#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

#include <string>

using namespace std;

class RobotMove{

public:

    RobotMove(string a){

    direction = a;
    
    
    }

    string direction;
    RosbotClass rosbot;

    void change_direction();
}; // DEFINE YOUR CLASS HERE


void RobotMove::change_direction() {
    rosbot.move_forward(1);
    
    
    while (rosbot.get_laser(0) > 2.0) {
    ROS_INFO_STREAM("Moving forward because laser only detected at" << "" << rosbot.get_laser(0));
    rosbot.move_forward(1);
    }

    if (direction == "left"){

    rosbot.turn("counterclockwise", 2);
    
    }

    else if (direction == "right") {
    rosbot.turn("clockwise", 2);
    }

    else {
    ROS_INFO_STREAM("error no direction defined");
    }
}


int main(int argc, char **argv) {
  ros::init(argc, argv, "Rosbot_move_node");

  RobotMove movement("right");
  movement.change_direction();

}