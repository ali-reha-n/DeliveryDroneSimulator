#include <iostream>
#include <ctime>
#include <cstdlib>
//small functions
inline void startingmsg();
inline int weathergen();
inline bool isobstacle();
inline void addminutes(int& hours, int& minutes , int add);
//medium functions
void rechargebattery(float& battery, int& hours, int& minutes);
void takeload(double& load);
void taketime(int& hours, int& minutes);
void takeloc(std::string& deliveryloc);
//large function
void delivery(float &battery, int &hours,int &minutes , std::string loc , double load , float & battcon , int& deliveries);

void main() {//start of main
    std::string  deliveryloc;
    float battery = 100 , battcon=0;
    double load;
    int weather , hours=0 , minutes=0 , deliveries=0;
    srand(time(0));
    //starting remarks and taking time input
    startingmsg();
    taketime( hours , minutes );
    //loop to deliver until time is below 19:00
    while( hours < 18 ) {
        //prints the upper line to differentiate each delivery
        for (int i = 0; i <= 60; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        takeloc(deliveryloc); //takes a valid delivery
        if (deliveryloc == "null") {// breaks loop if null is entered as location
            std::cout << "Shutting down all operations for the day.....\n";
            break;
        }

        takeload(load);//takes a valid load
        //delivers the package
        delivery(battery, hours, minutes, deliveryloc , load, battcon,deliveries);
        //recharges battery if battery is less than 30%
        rechargebattery(battery, hours, minutes);
    }

    if (hours >= 18 ) {//prints time ending remarks if time is over
        std::cout << "Drone charging time approaching......." << std::endl;
        std::cout << "Terminating all operations. " << std::endl;
    }

    //whole day's summary with efficiency
    std::cout << "\n\nDay Summary: \n";
    std::cout << "Deliveries:" << deliveries << std::endl;
    std::cout << "Battery Consumed: " << battcon << std::endl;
    std::cout << "Battery per Delivery: " << battcon / (float)deliveries << std::endl;

    //ending remarks
    std::cout << "Thanks for using. See you tomorrow - or not.";
}

inline void startingmsg() {
    std::cout << "---------------Delivery Drone---------------" << std::endl;
    std::cout << "-----An Initiative by IESE to deliver environmentally friendly utensils to the cafes.-----" << std::endl;
    std::cout << "Enter 'null' in location to end the day." << std::endl;
    std::cout << "Let's start the day. \n\n" << std::endl;
}
//generates weather
inline int weathergen() {
    return rand() % 3 + 1;
}
//generates obstacle
inline bool isobstacle() {
    return rand() % 2;
}
//adds minutes in time
inline void addminutes(int& hours, int& minutes , int add) {
    minutes = minutes + add;
    if (minutes >= 60) { //increases hours if minutes exceed or equal 60
        minutes = minutes % 60;
        hours++;
    }
}
//recharges battery
void rechargebattery(float& battery, int& hours, int& minutes) {
    while (battery < 30) {//recharges battery until 30
        std::cout << "Low Battery.Recharging.....\n";
        battery += 5;
        addminutes(hours, minutes, 15);
        std::cout << "Battery: " << battery << "%" << std::endl;
        std::cout << "Time: " << hours << ":" << minutes << std::endl;
        if (hours >= 18 && minutes >= 0) {//ensures time does not cross the limit
            return;
        }
    }
}
//takes a valid load
void takeload(double& load) {
    do {//takes load until a valid load is entered
        std::cout << "Enter the load (kg)(Greater than 0 and not exceeding 15):";
        std::cin >> load;
        if (load <= 0 || load > 15) {
            std::cout << "Invalid load value entered. Enter again...." << std::endl;
        }
    } while (load <= 0 || load > 15);
}
//takes a valid time
void taketime(int& hours, int& minutes) {
    do {//keeps taking time until valid value is entered
        std::cout << "Enter the time in 24 hours format.\n" << std::endl;

        std::cout << "Hours:";
        std::cin >> hours;

        std::cout << "Minutes:";
        std::cin >> minutes;

    } while (hours < 0 || hours > 24 || minutes < 0 || minutes >= 60);
}
//takes a valid delivery loc
void takeloc(std::string& deliveryloc) {
    do {
        std::cout << "Enter the delivery location (C1,C2,C3): ";
        std::cin >> deliveryloc;

        if (deliveryloc != "C1" && deliveryloc != "C2" && deliveryloc != "C3" && deliveryloc != "null") {
            std::cout << "Invalid location. Enter again....\n";
        }

    } while (deliveryloc != "C1" && deliveryloc != "C2" && deliveryloc != "C3" && deliveryloc != "null");
}
//BIGGEST FUNCTION

void delivery(float& battery, int& hours, int& minutes , std::string loc , double load , float& battcon, int&deliveries) {
    bool obstacle= isobstacle(); //generates obstacle
    int weather = weathergen(); // 1 = sunny , 2 = windy , 3 = rainy
    //WEATHER CONDITIONS
    if (weather == 1) { //prints weather is sunny
        std::cout << "Weather: Sunny" << std::endl;
    }
    else if (weather == 2) { //prints weather is windy
        std::cout << "Weather: Windy\n";
        if (battery < 40) {//chagres battery if below 40
            do {
                if (hours >= 18 && minutes >= 0) {//checks if time is over
                    return;
                }
                std::cout << "Battery Low.\nCurrent Battery:" << battery << "\nReacharging.....\n";
                addminutes(hours, minutes, 30);
                if (battery + 10 >= 100) {//adds battery but does not let it exceed 100%
                    battery = 100;
                }
                else {
                    battery += 10;
                }
            } while (battery < 40);
            //battery charged 
            std::cout << "Battery charged to sufficent level.\n";
            std::cout << "Battery: " << battery << "%\n";
            std::cout << "Delivering......\n";
        }
        //deductions for windy weather
        battery -= 5;
        battcon += 5;
        addminutes(hours, minutes, 10);
    }
    else if (weather == 3) { //rainy weather
        do {//waits and recharges until weather is clear
            if (hours >= 18 && minutes >= 0) {//checks if time is exceeded
                return;
            }
            std::cout << "Weather:Rainy\nDelivery Delayed.\nWaiting for 1 hour and recharging.....\n";
            addminutes(hours, minutes, 60);//adds time
            if (battery + 20 >= 100) {//charges battery but does not let it exceed 100
                battery = 100;
            }
            else {
                battery += 20;
            }
            weather = weathergen();//regenerates weather
        } while (weather == 3);
        std::cout << "Weather clear. Taking off and delivering........\n";
    }
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;

    //LOAD POENALITY
    if (load > 10) {
        std::cout << "Heavy load. Will cost more time and battery.\n";
        battery -= 5;
        battcon += 5;
        addminutes(hours, minutes, 10);
        std::cout << "Battery: " << battery << "%" << std::endl;
        std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;
    }

    //Deductions if obstacle is present
    if (obstacle) {
        std::cout << "Obstacle Detected. Rerouting.....\n";
        battery -= 10;
        battcon += 10;
        addminutes(hours, minutes, 5);
        std::cout << "Battery: " << battery << "%" << std::endl;
        std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;

    }
    
    //decductions acccording to location
    if (loc == "C1") {
        battery -= 10;
        battcon += 10;
        addminutes(hours, minutes, 15);
    }
    else if (loc == "C2") {
        battery -= 20;
        battcon += 20;
        addminutes(hours, minutes, 25);
    }
    else if (loc == "C3") {
        battery -= 25;
        battcon += 25;
        addminutes(hours, minutes, 45);
    }

    //ending remarks of delivery
    std::cout << "Delivery Successfull.\n";
    std::cout << "Battery: " << battery << "%" << std::endl;
    std::cout << "Time: " << hours << ":" << minutes << "\n" << std::endl;
    deliveries++; //adds 1 to deluvery if delivery was successfull
}