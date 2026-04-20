#include "Logger.hpp"
using namespace std;

TIME_POINT Logger::startTime;

void Logger::logLocation(const std::string& message,
                         const std::string& file,
                         int line,
                         const std::string& function) {
                          std::cout << "[LOG] " << file << ":" << line << " (" << function << ") " << "- " << message << std::endl;
}

void Logger::startTimer() {
  startTime = NOW;
}

void Logger::stopTimer(const std::string& function) {
  auto endTime = NOW;
  auto duration = DURATION(endTime, startTime);
  std::cout << "[TIMER] (" << function << ") - Duration: " << duration << " µs" << std::endl;
}

void Logger::printCompileInfo() {
  std::cout << "Date: " << __DATE__ << std::endl;
  std::cout << "Time: " << __TIME__ << std::endl;

  #ifdef GCC
    std::cout << "Compiler: " << __GNUC__ << " " << __GNUC_MAJOR__ << "." << __GNUC_MINOR__  << std::endl;
  #elif defined(Clang)
    std::cout << "Compiler: " << "Clang" << " " << __clang_major__ << "." << __clang_minor__  << std::endl;
  #elif defined(MSVC)
    std::cout << "Compiler: " << "MSVC" << " " << _MSC_VER << std::endl;
  #endif

  std::cout << "Platform: " << PLATFORM << std::endl;
}   
