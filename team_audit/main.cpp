#include <iostream>
#include "Marketing.hpp"
#include "Sales.hpp"


int main() {
 std::vector<std::string> marketingMembers = {"John", "Sally"};
 std::vector<std::string> salesMembers = {"Alex", "Tim"};

 Marketing::Team marketingTeam = Marketing::Team("Stellar Corp", marketingMembers, 500000);

 Sales::Team salesTeam = Sales::Team("Stellar Corp", salesMembers, "London");

 salesTeam.printTeamDetails();
 salesTeam.setLocation("New York");
 salesTeam.printTeamDetails();

 namespace audit = Marketing::Support;

 audit::auditTeam(marketingTeam);
 return 0;
}
