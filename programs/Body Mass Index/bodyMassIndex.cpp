#include <iostream>
#include <cmath>

int main(){
    bool isValid{true};
    //Imperial - feet, inches, and pounds
    //Metric - meters and kilograms
    int ft{}, in{};
    double lb{}, m{}, kg{}, bmi{};
    std::string unit{};

    std::cout<<"imperial or metric: ";
    std::cin>>unit;

    if(unit == "imperial"){
        std::cout<<"Feet: ";
        std::cin>>ft;
        std::cout<<"Inches: ";
        std::cin>>in;
        std::cout<<"Pounds: ";
        std::cin>>lb;
        bmi = lb/pow((ft*12) + in,2)*703.0;
    } else if(unit == "metric"){
        std::cout<<"Meters: ";
        std::cin>>m;
        std::cout<<"Kilograms: ";
        std::cin>>kg;
        bmi = kg/pow(m,2);
    } else {
        std::cout<<"Invalid unit.";
        !isValid;
    }

    if(isValid){
        std::cout<<"\nUnderweight: < 18.5\n";
        std::cout<<"Normal weight: 18.5 - 24.9\n";
        std::cout<<"Overweight: 25 - 29.9\n";
        std::cout<<"Obese: > 30\n\n";
        std::cout<<(double)((int)(bmi*10))/10.0<<'\n';
        if(bmi < 18.5){
            std::cout<<"You are underweight.";
        } else if(18.5 <= bmi < 25){
            std::cout<<"You are normal weight.";
        } else if(25 <= bmi < 30){
            std::cout<<"You are overweight.";
        } else {
            std::cout<<"You are obese";
            if(30 <= bmi < 35){
                std::cout<<"(class 1).";
            } else if(35 <= bmi < 40){
                std::cout<<"(class 2).";
            } else {
                std::cout<<"(class 3).";
            }
        }
    }

    return 0;
}