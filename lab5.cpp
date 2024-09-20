 #include <iostream>
#include <string>
#include "math.h"
using namespace std;

class Airplane {
private:
    string model;
    int capacity;
    float fuelLevel;
    float maxWeight;
    float maxSpeed; 
    float mileagePerGallon;   
    float maxFuelLevel;

public:
    Airplane(const string& model, int capacity, float fuelLevel, float maxWeight, float mileagePerGallon,float maxSpeed) 
        {
            this->model = model;
            this->capacity = capacity;
            this->fuelLevel = fuelLevel;
            this->maxWeight = maxWeight;
            this->mileagePerGallon = mileagePerGallon;
            this->maxSpeed = maxSpeed;
            this->maxFuelLevel = 1000;
        }

    // Getters 
    string getModel() const {return model;}
    int getCapacity() const {return capacity;}
    float getFuelLevel() const {return fuelLevel;}
    float getMaxWeight() const {return maxWeight;}
    float getMaxSpeed() const {return maxSpeed;}
    float getMileagePerGallon() const {return mileagePerGallon;}
    float getMaxFuelLevel() const {return maxFuelLevel;}
    // Setters
    void setModel(const string& model) {this->model = model;}
    void setCapacity(int capacity) {this->capacity = capacity;}
    void setFuelLevel(float fuelLevel) {this->fuelLevel = fuelLevel;}
    void setMaxWeight(float maxWeight) {this->maxWeight = maxWeight;}
    void setMaxSpeed(float maxSpeed) {this->maxSpeed = maxSpeed;}
    void setMileagePerGallon(float mileagePerGallon) {this->mileagePerGallon = mileagePerGallon;}
    void setMaxFuelLevel(float maxLevel) {this->maxFuelLevel = maxLevel;}

    void display() const {
    cout << "Model: " << model << endl;
    cout << "Capacity: " << capacity << " passengers" << endl;
    cout << "Fuel level: " << fuelLevel << " liters" << endl;
    cout << "Maximum weight: " << maxWeight << " lb" << endl;
    cout << "Maximum speed: " << maxSpeed << " miles/hour" << endl;
    cout << "Mileage per gallon: " << mileagePerGallon << " miles/gallon" << endl;
    cout << "Maximum fuel level: " << maxFuelLevel << " gallon" << endl;
    }

    Airplane(string model);
    bool checkCapacityAndWeight(int people);
    float pumpFuelInOunces(float ounces);
    string stateFuelLevel();
    bool canAirplaneCoverDistance(int desired_speed, float distance);
    float calculateTimeToReachHeight(float launch_angle_deg, float launch_speed, float target_height);
    void fly(float distance);
    bool equals(Airplane model);
};

/*****************************************************************************************
 * EXERCISE #1
 * Constructor description:
 * Initializes an Airplane object with default values.
 * - `capacity`: The passenger capacity of the airplane, set to 100 by default.
 * - `fuelLevel`: The fuel level of the airplane, set to 50 liters by default.
 * - `maxWeight`: The maximum weight of the airplane, set to 5000 lb by default.
 * - `maxSpeed`: The maximum speed of the airplane, set to 100
 * - `mileagePerGallon`:  The mileage per galon of the airplane, set to 20 
 * - `maxFuelLevel`: The maximum fuel level, set to 100
 * Use this constructor to create an Airplane object with default parameters.
 *****************************************************************************************/
Airplane::Airplane(string model){
    this-> capacity = 100;
    this-> fuelLevel = 50;
    this-> maxWeight = 5000;
    this-> maxSpeed = 100;
    this-> mileagePerGallon = 20;
    this-> maxFuelLevel = 100;
    this->model = model;

}

/*****************************************************************************************
 * EXERCISE #2
 * Method description:
 * Checks if two airplane objects are equal based on their model, capacity, and max weight.
 * Parameters:
 * - `airplane`: The airplane object to compare with.
 * Returns:
 * - `true` if the airplanes have the same model, capacity, and max weight.
 * - `false` otherwise.
 *****************************************************************************************/

bool Airplane::equals(Airplane airplane){
    if(this->model == airplane.getModel() && this->capacity == airplane.getCapacity() && this->maxWeight == airplane.getMaxWeight())
    return true;
    else
    return false;
}

/*****************************************************************************************
 * EXERCISE #3
 * Method description:
 * Checks if the airplane is full based on the number of people and the weight.
 * Parameters:
 * - `people`: The number of people on the airplane.
 * Returns:
 * - `false` if the airplane is full (total weight exceeds maxWeight OR the people exceeds the capacity).
 * - `true` otherwise.
 * 
 * assumes that the weight of each person is 30lb
 *****************************************************************************************/
bool  Airplane::checkCapacityAndWeight(int people){
    int weight = people * 30;
    if(this->capacity < people || this-> maxWeight < weight)
    return false;
    else
    return true;
    
}

/*****************************************************************************************
 * EXERCISE #4
 * Method description:
 * Adds fuel to the airplane in ounces.
 * Parameters:
 * - `ounces`: The amount of fuel to add to the airplane in ounces.
 * Use this method to refuel the airplane. The input `ounces` is converted to gallons 
 * before being added to the fuel level. You can assume that 1 gallon contains 128 ounces.
 * If the resulting fuel level exceeds the maximum fuel level, the fuel level is capped 
 * Return the fuel level, If the resulting fuel level exceeds the maximum fuel level, the fuel level is set at the maximum, the extra fuel that couldn't be added you return as a negative value (Negative extra fuel).


 *****************************************************************************************/
float Airplane::pumpFuelInOunces(float ounces) {
    float gallons = ounces/128;
    float negativefuel = 0;
    if(gallons > (this->maxFuelLevel -this->fuelLevel )){
        negativefuel = (this->maxFuelLevel - this->fuelLevel) - gallons ;
    setFuelLevel(maxFuelLevel);
    return negativefuel;

    }
    else{
    this->fuelLevel = this->fuelLevel + gallons;
    return this->fuelLevel;


    
    }
    return -1;
} /*this->fuelLevel = this->fuelLevel + gallons;

    if(this->fuelLevel > this->maxFuelLevel){
    setMaxFuelLevel(float maxLevel) {this->maxFuelLevel = maxLevel;}*/


/*****************************************************************************************
 * EXERCISE #5
 * Method description:
 * Returns the state of the fuel level (full, normal, or empty).
 * Returns:
 * - "full" if the fuel level is equal 90% or more of capacity.
 * - "normal" if the fuel level is between 50% and 90% of capacity.
 * - "empty" if the fuel level is equal  or less than 50% of capacity.
 *****************************************************************************************/
string Airplane::stateFuelLevel() {
    
    float full = this->maxFuelLevel * 0.9;
    float normal = this->maxFuelLevel * 0.5;

    if(this->fuelLevel >= full){
    return "full";}
    else if(this->fuelLevel > normal && this->fuelLevel  < full){
    return "normal";}
    else
    return "empty";
    
}

/*****************************************************************************************
 * EXERCISE #6
 * Method description:
 * Checks if the airplane can cover a certain distance at a desired speed without 
 * running out of fuel.
 * Parameters:
 * - `desired_speed`: The desired speed of the airplane.
 * - `distance`: The distance to be covered.
 * Returns:
 * - `true` if the airplane can cover the distance at the desired speed without 
 *   running out of fuel.
 * - `false` otherwise.
 * Hint: If the desired speed is less than the maximum speed and the fuel consumption is less than
 *  or equal to fuel level.
 *    consumption = distance / milleage per Gallon
 *****************************************************************************************/
bool Airplane::canAirplaneCoverDistance(int desired_speed, float distance) {
    float consumption = distance/this->mileagePerGallon;
    if(desired_speed < this->maxSpeed && consumption <= this->mileagePerGallon)
    return true;
    else
    return false;
}

/*****************************************************************************************
 * EXERCISE #7
 * Method description:
 * Calculates the time required for the airplane to reach a certain height after launch.
 * Parameters:
 * - `launch_angle_deg`: The launch angle of the airplane in degrees.
 * - `launch_speed`: The launch speed of the airplane.
 * - `target_height`: The target height to reach.
 * Returns:
 * - The time (in seconds) required for the airplane to reach the target height.
 * Equation:
 * - Time to reach height = Target height / Vertical velocity
 * Steps:
 * 1. Convert launch angle from degrees to radians (the angle is between 0 and 90 degrees).
 *     radians=degrees * M_PI / 180.0;
 * 2. Calculate horizontal and vertical components of initial velocity.
 *     vx = v * cos(launch_angle);
 *     vy = v * sin(launch_angle);
 * 3. Calculate time to reach height using vertical velocity.
 *     time = height / vy;
 * 4. Return the calculated time.
 *****************************************************************************************/
float Airplane::calculateTimeToReachHeight(float launch_angle_deg, float launch_speed, float target_height) {
    float radians = launch_angle_deg * M_PI / 180.0;

    float vy = launch_speed * sin(radians);

    float time = target_height/vy;

    return time;
}

/*****************************************************************************************
 * EXERCISE #8
 * Method description:
 * Simulates flying the airplane for a certain distance.
 * Parameters:
 * - `distance`: The distance to be covered.
 * This method updates the fuel level of the airplane based on the distance traveled 
 * and the mileage per gallon. Set 0 the fuel level if the value of fuel level is negative.
 * Hint: use this subtrai the fuel level:
 * -     gallon_per_mile =(1/mileage_per_gallon)
 *       consumption = distance * gallon_per_mile 
 *****************************************************************************************/
void Airplane::fly( float distance) {
    float gallon_per_mile  =(1/this->mileagePerGallon);
       float consumption = distance * gallon_per_mile ;

       if(this->fuelLevel > consumption){
        this->fuelLevel = this->fuelLevel - consumption;

       setFuelLevel(fuelLevel);}
       else
       setFuelLevel(0);


}

void test1(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane = Airplane("Boeing 737");
    Airplane airplaneTest = Airplane("Boeing 737",100,50,5000,20,100);
    cout<< "EXERCISE #1"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< (
        (airplane.getCapacity() == airplaneTest.getCapacity() &&
        airplane.getModel() == airplaneTest.getModel() &&
        airplane.getFuelLevel() == airplaneTest.getFuelLevel() &&
        airplane.getMaxWeight() == airplaneTest.getMaxWeight() &&
        airplane.getMileagePerGallon() == airplaneTest.getMileagePerGallon() &&
        airplane.getMaxSpeed() == airplaneTest.getMaxSpeed() )?"PASS": "FAIL"
    )<< endl;
    cout << endl;
    cout << "EXPECTED: "<< endl;
    airplaneTest.display();
    cout << endl;
    cout << "OBTAINED: "<< endl;
    airplaneTest.display();
    cout << endl;
    cout << line << endl;
}
void test2(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane = Airplane("Boeing 737",100,50,5000,20,100);
    Airplane airplaneTest = Airplane("Boeing 737",100,50,5000,20,100);
    cout<< "EXERCISE #2"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< ((airplane.equals(airplaneTest) )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "TRUE"<< endl;
    cout << "OBTAINED: "<< (airplane.equals(airplaneTest)?"TRUE":"FALSE")<<endl;
    cout << endl;
    airplaneTest.setCapacity(50);
    cout <<"TEST 2: "<< ((!airplane.equals(airplaneTest) )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "FALSE"<< endl;
    cout << "OBTAINED: "<< (airplane.equals(airplaneTest)?"TRUE":"FALSE")<<endl;
    cout << endl;
    cout << line << endl;
}
void test3(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane =  Airplane("Boeing 747", 500, 2000.0, 10000.0, 20.0, 500.0);
    
    cout<< "EXERCISE #3"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< ((airplane.checkCapacityAndWeight(100) )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "TRUE"<< endl;
    cout << "OBTAINED: "<< (airplane.checkCapacityAndWeight(100)?"TRUE":"FALSE")<<endl;
    cout << endl;
    
    cout <<"TEST 2: "<< ((!airplane.checkCapacityAndWeight(400) )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "FALSE"<< endl;
    cout << "OBTAINED: "<< (airplane.checkCapacityAndWeight(400)?"TRUE":"FALSE")<<endl;
    cout << endl;
    cout << line << endl;
}
void test4(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane =  Airplane("Boeing 747", 500, 0, 10000.0, 20.0, 500.0);
    Airplane airplaneTest =  Airplane("Boeing 747", 500, 50.0/128, 10000.0, 20.0, 500.0);
    airplane.setMaxFuelLevel(20);

    cout<< "EXERCISE #4"<< endl;
    cout << endl;
    float resulting = airplane.pumpFuelInOunces(50);
    cout <<"TEST 1: "<< ((resulting==airplaneTest.getFuelLevel() && airplane.getFuelLevel()==airplaneTest.getFuelLevel() )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< airplaneTest.getFuelLevel() << " Fuel level : " << airplaneTest.getFuelLevel() << endl;
    cout << "OBTAINED: "<< resulting<<" Fuel level : "<< airplane.getFuelLevel() <<endl;
    cout << endl;
    airplane= Airplane("Boeing 747", 500, 15, 10000.0, 20.0, 500.0);
    airplane.setMaxFuelLevel(20);
    resulting = airplane.pumpFuelInOunces(6*128);
    cout <<"TEST 2: "<< ((resulting==-1 && airplane.getFuelLevel()==airplane.getMaxFuelLevel() )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< -1 << " Fuel level : " << airplane.getMaxFuelLevel() << endl;
    cout << "OBTAINED: "<< resulting<<" Fuel level : "<< airplane.getFuelLevel() <<endl;
    cout << endl;

    cout << line << endl;
}
void test5(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane =  Airplane("Boeing 747", 500, 2000.0, 10000.0, 20.0, 500.0);
    airplane.setMaxFuelLevel(100);
    airplane.setFuelLevel(100);
    cout<< "EXERCISE #5"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< ((airplane.stateFuelLevel() == "full" )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "full"<< endl;
    cout << "OBTAINED: "<< airplane.stateFuelLevel() <<endl;
    cout << endl;
    
    airplane.setFuelLevel(51);
    cout <<"TEST 2: "<< ((airplane.stateFuelLevel() == "normal" )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "normal"<< endl;
    cout << "OBTAINED: "<< airplane.stateFuelLevel() <<endl;
    cout << endl;

    airplane.setFuelLevel(50);
    cout <<"TEST 3: "<< ((airplane.stateFuelLevel() == "empty" )?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "empty"<< endl;
    cout << "OBTAINED: "<< airplane.stateFuelLevel() <<endl;
    cout << endl;
    cout << line << endl;
}
void test6(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane =  Airplane("Boeing 747", 500, 100, 10000.0, 10, 200);
    cout<< "EXERCISE #6"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< ((airplane.canAirplaneCoverDistance(150, 100.0f))?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "TRUE"<< endl;
    cout << "OBTAINED: "<< (airplane.canAirplaneCoverDistance(150, 100.0f)?"TRUE":"FALSE")<<endl;
    cout << endl;
    airplane=Airplane("Boeing 747", 500, 100, 10000.0, 10, 200);
    cout <<"TEST 2: "<< ((!airplane.canAirplaneCoverDistance(250, 100.0f))?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< "FALSE"<< endl;
    cout << "OBTAINED: "<< (airplane.canAirplaneCoverDistance(250, 100.0f)?"TRUE":"FALSE")<<endl;
    cout << endl;

    cout << line << endl;
}
void test7(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane =  Airplane("Boeing 747", 500, 100, 10000.0, 10, 200);
    cout<< "EXERCISE #7"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< ((airplane.calculateTimeToReachHeight(45.0f, 10.0f, 20.0f)==2.82842708f)?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< 2.82843<< endl;
    cout << "OBTAINED: "<< airplane.calculateTimeToReachHeight(45.0f, 10.0f, 20.0f)<<endl;
    cout << endl;
    airplane=Airplane("Boeing 747", 500, 100, 10000.0, 10, 200);
    cout <<"TEST 2: "<< ((airplane.calculateTimeToReachHeight(30, 15, 30.0f)==4)?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< 4 << endl;
    cout << "OBTAINED: "<< airplane.calculateTimeToReachHeight(30, 15, 30.0f)<<endl;
    cout << endl;

    cout << line << endl;
}
void test8(){
    string line;
    for (int i = 0; i < 50; ++i) {
            line += "*";
    }
    cout << line << endl;
    Airplane airplane =  Airplane("Boeing 747", 500, 100, 10000.0, 10, 200);
    Airplane airplaneTest =  Airplane("Boeing 747", 500, 80, 10000.0, 10, 200);
    airplane.fly(200);
    cout<< "EXERCISE #8"<< endl;
    cout << endl;
    cout <<"TEST 1: "<< ((airplane.getFuelLevel()==airplaneTest.getFuelLevel())?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< airplaneTest.getFuelLevel()<< endl;
    cout << "OBTAINED: "<< airplane.getFuelLevel()<<endl;
    cout << endl;
    airplane =  Airplane("Boeing 747", 500, 100, 10000.0, 10, 200);
    airplaneTest =  Airplane("Boeing 747", 500, 0, 10000.0, 10, 200);
    airplane.fly(1000);
    cout <<"TEST 2: "<< ((airplane.getFuelLevel()==airplaneTest.getFuelLevel())?"PASS": "FAIL")<< endl;
    cout << "EXPECTED: "<< airplaneTest.getFuelLevel()<< endl;
    cout << "OBTAINED: "<< airplane.getFuelLevel()<<endl;
    cout << endl;

    cout << line << endl;
}

int main(){
    test1();// EXERCISE # 1 TEST
    test2();// EXERCISE # 2 TEST
    test3();// EXERCISE # 3 TEST
    test4();// EXERCISE # 4 TEST
    test5();// EXERCISE # 5 TEST
    test6();// EXERCISE # 6 TEST
    test7();// EXERCISE # 7 TEST
    test8();// EXERCISE # 8 TEST
}
