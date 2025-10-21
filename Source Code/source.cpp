#include <iostream>
#include <ctime>
#include <cstdlib>

inline void startingmsg();
inline int weathergen();
inline bool obstacle();
inline bool malfunction();

void main() {
    srand(time(0));

    startingmsg();

    std::cout << "---Delivery to location A---\n";



}

inline void startingmsg() {
    std::cout << "---------------Delivery Drone---------------" << std::endl;
    std::cout << "Good Morning!" << std::endl;
    std::cout << "Let's start the day. \n\n" << std::endl;
}

inline int weathergen() {
    return rand() % 6 + 1;
}

inline bool obstacle() {
    return rand() % 2;
}

inline bool malfunction() {
    if (rand() % 10 == 7) {
        return 1;
    }
    return 0;
}