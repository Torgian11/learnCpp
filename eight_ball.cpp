#include <iostream>
#include <cstdlib>

int main()
{
  srand(time(NULL));
  int roll = std::rand() % 10;

  std::cout << "MAGIC 8-BALL: ";
  switch(roll){
    case 0:
      std::cout << "It is certain.";
      break;
    case 1:
      std::cout << "Signs point to yes.";
      break;
    case 2:
      std::cout << "Ask again later.";
      break;
    case 3:
      std::cout << "Concentrate and ask again.";
      break;
    case 4:
      std::cout << "My reply is no.";
      break;
    case 5:
      std::cout << "Yes.";
      break;
    case 6:
      std::cout << "Reply hazy, try again.";
      break;
    case 7:
      std::cout << "You may rely on it.";
      break;
    case 8:
      std::cout << "Outlook not so good.";
      break;
    case 9:
      std::cout << "Very doubtful.";
      break;
    default:
      std::cout << "Uncertain.";
  }
  return 0;
}
