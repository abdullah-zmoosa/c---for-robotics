#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <math.h>
#include <string>

using namespace std;

class RobotMove{

public:
    RosbotClass rosbot;
    void get_out();
    float calc_distance(float x0, float y0, float x1, float y1);
}; // DEFINE YOUR CLASS HERE


void RobotMove::get_out() {
    rosbot.move_forward(1);
    while (rosbot.get_laser(0) > 1.75) {
    ROS_INFO_STREAM("Moving forward because laser only detected at" << "" << rosbot.get_laser(0));
    rosbot.move_forward(1);
    }

    rosbot.turn("clockwise", 3);
    rosbot.move_forward(2);
    rosbot.turn("counterclockwise", 3);

    float x0 = rosbot.get_position(1);
    float y0 = rosbot.get_position(2);
    float x1 = x0;
    float y1 = y0;
    float distance_moved = calc_distance(x0, y0, x1, y1);

    while (distance_moved < 8.0) {
    rosbot.move_forward(1);
    x1 = rosbot.get_position(1);
    y1 = rosbot.get_position(2);
    distance_moved = calc_distance(x0, y0, x1, y1);
    ROS_INFO_STREAM("Distance moved is" << "" << distance_moved);


    }
  ROS_INFO_STREAM("escaped");
}
float RobotMove::calc_distance(float x0, float y0, float x1, float y1){

return sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "Rosbot_move_node");
  RobotMove movement;
  movement.get_out();

}