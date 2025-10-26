Project Title: Delivery Drone Simulator

Team Members:

  1. Hassaan Ali Khoso (Logic Designer)
  2. Ali Rehan (Programmer)
  3. Hassan Ghazi (Tester, Documenter)


Overview:
  The Delivery drone simulation program models an autonomous delivery drone that makes intelligent decisions by evaluating it’s environment. The program is designed to be able    to make three deliveries in a day to three locations. It will assess weather conditions, the battery percentage and obstacles in it’s route before deciding if it will take      off for delivery, return to base for recharging or delay the delivery. The program is quite relevant to the real-world as it reflects real-life drone delivery scenarios.


Program Design:
  The following functions have been implemented:
  •	inline void startingmsg (to print the starting message)
  •	inline int weathergen (to generate random weather conditions)
  •	inline bool isobstacle (to generate obstacle)
  •	inline void taketime (time input)
  •	inline void addminutes (increase time after activity)
  •	void delivery (delivery process)
  •	inline void recharge battery (to recharge the battery)
  •	void takeload (package load input)
  •	void takeloc (location input)


Logic flow:
  The program first asks the user to enter the time in hours and minutes. The next input is the delivery location followed by the load of the package. Next the program will       generate random weather conditions (sunny, windy or rainy) and will randomly decide if there will be an obstacle in the route.
  Based on the weather and battery the drone will decide to either:
  - Take off for delivery
  - Reroute (incase of obstacle)
  - Delay the delivery and wait for clear skies
  - Return to base for recharge


Execution Instructions:
  After compiling and running code:
  - Enter the time. First the hours and then the minutes (24 hour format).
  - Enter the delivery location from the three provided ones (C1, C2, C3).
  - Enter the load of the package (0-15kg).
	  The program will then generate random conditions and delivery will be executed accordingly.
  - Repeat for next delivery.

  
Team Collaboration Summary:
    The three team members made the following contributions:
    Hassaan Ali Khoso: Designed flowcharts and logic for different versions of the project along with extensive use of git.
    Ali Rehan: Wrote source codes for different versions of the project according to their respective flowcharts and used git extensively.
    Hassan Ghazi: Tested project versions and documented the project along with extensive git use.


AI Tool Reflection:
  Ai was used only at one instance to get some test case examples in the early part of the project.

  
Future Improvements:
  The  program can be improved in the following ways in the future:

  - By adding a real-time delay for deliveries to make the simulation more realistic.
  - By adding a malfunction function. This will also contribute to enhance the realism of the simulation.
  - By Implementing a GUI to make it more user-friendly.
  - By adding a database to store daily info. 

