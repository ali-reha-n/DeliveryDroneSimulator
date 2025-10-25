#include <iostream>
#include <ctime>
#include <cstdlib>

inline void startingmsg();
inline int weathergen();
inline bool isobstacle();
inline bool malfunction();
inline void taketime( int &hours , int &minutes );
inline void addminutes(int& hours, int& minutes , int add);

void delivery(float &battery, int &hours,int &minutes , std::string loc );

void main() {
    std::string  deliveryloc;
    float battery = 100;
    int weather , hours=0 , minutes=0;
    srand(time(0));

    startingmsg();

    taketime( hours , minutes );

    for (int i = 0; i < 3; i++) {
        std::cout << "Enter Delivery Location( C1 , C2 , C3 ) : ";
        std::cin >> deliveryloc;

        delivery(battery, hours, minutes, deliveryloc);
        if (hours >= 18 && minutes >= 0) {
            std::cout << "Drone charging time approaching......." << std::endl;
            std::cout << "Terminating all operations. " << std::endl;
            break;
        }
    }

    std::cout << "Thanks for using. See you tomorrow - or not.";
}

inline void startingmsg() {
    std::cout << "---------------Delivery Drone---------------" << std::endl;
    std::cout << "-----An Initiative by IESE to deliver environmentally friendly utensils to the cafes.-----" << std::endl;
    std::cout << "Good Morning!" << std::endl;
    std::cout << "Let's start the day. \n\n" << std::endl;
}

inline int weathergen() {
    return rand() % 3 + 1;
}

inline bool isobstacle() {
    return rand() % 2;
}

inline bool malfunction() {
    if (rand() % 10 == 7) {
        return 1;
    }
    return 0;
}

void taketime(int & hours, int& minutes) {
    do {
        std::cout << "Enter the time in 24 hours format.\n" << std::endl;

        std::cout << "Hours:";
        std::cin >> hours;
        
        std::cout << "Minutes:";
        std::cin >> minutes;
    
    } while (hours < 0 || hours > 24 || minutes < 0 || minutes >= 60);
}

void addminutes(int& hours, int& minutes , int add) {
    minutes = minutes + add;
    if (minutes >= 60) {
        minutes = minutes % 60;
        hours++;
    }
}

void delivery(float& battery, int& hours, int& minutes , std::string loc) {
    bool obstacle= isobstacle();
    int weather = weathergen(); // 1 = sunny , 2 = windy , 3 = rainy

    if (weather == 2 && battery < 40) {
        do {
            std::cout << "Battery Low.\nCurrent Battery:" << battery << "\nReacharging.....\n";
            addminutes(hours, minutes, 30);
        } while (battery < 40);
        std::cout << "Battery charged to sufficent level. Taking off and delivering....";
    }
    else if (weather == 3) {
        do {
            std::cout << "Rainy Weather.\nDelivery Delayed.\nWaiting for 1 hour.....\n";
            addminutes(hours, minutes, 60);
            weather = weathergen();
        } while (weather == 3);
        std::cout << "Weather clear. Taking off and delivering........\n";
    }

    if (obstacle) {
        std::cout << "Obstacle Detected. Rerouting.....\n";
        battery -= 10;
        addminutes(hours, minutes, 5);
    }

    if (loc == "C1") {
        battery -= 10;
        addminutes(hours, minutes, 15);
    }
    else if (loc == "C2") {
        battery -= 20;
        addminutes(hours, minutes, 25);
    }
    else if (loc == "C3") {
        battery -= 25;
        addminutes(hours, minutes, 45);
    }

    std::cout << "Delivery Successfull.\n";
    std::cout << "Battery Level:" << battery << std::endl;
    std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;
}