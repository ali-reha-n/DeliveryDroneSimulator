#include <iostream>
#include <ctime>
#include <cstdlib>

inline void startingmsg();
inline int weathergen();
inline bool obstacle();
inline bool malfunction();

void main() {
    char deliveryloc;
    float battery = 100;
    int weather;
    srand(time(0));

    startingmsg();

    for (int i = 0; i < 3; i++) {
        std::cout << "Enter Delivery Location( A,B,C ) : ";
        std::cin >> deliveryloc;
        weather = weathergen();
        if (weather == 1 && battery >= 30) {
            std::cout << "Order Completed" << std::endl;
        }
        else if (weather == 2 || weather == 3) {
            std::cout << "Weather insufficent. Try again later.";
            break;
        }
        else if (battery < 30) {
            std::cout << "Low battery. Recharge.";
            break;
        }



    }
}

inline void startingmsg() {
    std::cout << "---------------Delivery Drone---------------" << std::endl;
    std::cout << "Good Morning!" << std::endl;
    std::cout << "Let's start the day. \n\n" << std::endl;
}

inline int weathergen() {
    return rand() % 3 + 1;
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