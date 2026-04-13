#include <iostream>
#include <string>
#include <vector>

namespace Sales {
  class Team {
    private:
      std::string teamName;
      std::vector<std::string> teamMembers;
      std::string teamLocation;
    public:
      Team(std::string name, std::vector<std::string> members, std::string location) : teamName(name), teamMembers(members), teamLocation(location) {};
      std::string getTeamName() {
        return teamName;
      };
      std::vector<std::string> getMembers() {
        return teamMembers;
      };
      void addMember(std::string member) {
        teamMembers.push_back(member);
      };
      std::string getLocation() {
        return teamLocation;
      };
      void setLocation(const std::string& location) {
        teamLocation = location;
      };
      void printTeamDetails() {
        std::cout << "Sales Team Name: " << teamName << "\n" << "Location: " << teamLocation << "\n" << "Members: " << std::endl;

        for (int i = 0; i < teamMembers.size() - 1; ++i) {
          std::cout << teamMembers[i] << ", ";
        }
        std::cout << teamMembers[teamMembers.size() - 1] << std::endl;
      };
  };
}
