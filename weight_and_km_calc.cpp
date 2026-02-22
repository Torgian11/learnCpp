#include <iostream>

int main() {

    double itemWeight;
    double weightOnMars;

    std::cout << "What is the weight of your item? ";
    std::cin >> itemWeight;

    weightOnMars = itemWeight * 0.37;

    std::cout << "The weight on Mars would be: " << weightOnMars << "\n";

    std::cout << "Now, what is the distance, in miles, that you need in kilometers? ";

    double miles;
    double km;

    std::cin >> miles;

    km = miles * 1.60934;

    std::cout << "The distance in kilometers would be: " << km << "\n";

    return 0;
}
