#include "RobotControlCenter.hpp"

RobotControlCenter::RobotControlCenter(int capacity) {
  if (capacity < 0) {
    throw RobotException("Capcity cannot be negative!");
  } else {
    robotCollection.reserve(capacity);
    std::cout << "Control centre created" << std::endl;
  }
};

void RobotControlCenter::addRobot(Robot* robot) {
  robotCollection.push_back(robot);
}

void RobotControlCenter::logError(const std::string& errorMessage) noexcept {
  std::cerr << "Error: " << errorMessage << std::endl;
}

void RobotControlCenter::executeAllRobotTasks() {
  try {
    for (Robot* robot : robotCollection) {
      robot -> performTask();
    }
  } catch (BatteryLowException& error) {
    logError(error.what());
  } catch (MechanicalFailureException& error) {
    logError(error.what());
  } catch (const RobotException& error) {
    logError(error.what());
  } catch (...) {
    logError("Unknown robot error");
    throw;
  }
}


