#include "RobotControlCenter.hpp"
#include "DeliveryRobot.hpp"
#include "MaintenanceRobot.hpp"

int main() {
  try {
    RobotControlCenter controlCenter(5);
    
    DeliveryRobot* dr1 = new DeliveryRobot("DR1", 50);
    DeliveryRobot* dr2 = new DeliveryRobot("DR2", 10);
    MaintenanceRobot* mr1 = new MaintenanceRobot("MR1", 80);
    MaintenanceRobot* mr2 = new MaintenanceRobot("MR2", 20);

    controlCenter.addRobot(dr1);
    controlCenter.addRobot(dr2);
    controlCenter.addRobot(mr1);
    controlCenter.addRobot(mr2);

    try {
      controlCenter.executeAllRobotTasks();
    } catch (...) {
      std::cout << "Unexpected error: shutting down factory" << std::endl;
      std::cout << "Program finished" << std::endl;
      return 0;
    }
  } catch (const RobotException& error) {
    std::cout << "Error: " << error.what() << std::endl;
    return 0;
  }

  return 0;
}
