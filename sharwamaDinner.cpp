// Copyright (c) 2024 Jayden Smith All rights reserved.
// Created by: Jayden Smith
// Date: April 6, 2024
// This program calculates the cost of user's sharwarma.

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    // Defining my constants
    const float HST = 0.13;
    const float SHAWARMA_WRAP = 4.50;
    const float SHAWARMA_PLATE = 5.42;
    const float VEGETABLE = 3.40;
    const float MEAT = 3.48;
    const float DRINK = 5.00;

    // Defining my variables
    std::string main_course_option;
    std::string side_course_option;
    std::string drink_option;
    int main_course_option_int;
    int side_course_option_int;
    int drink_option_int;
    float main_course_option_float;
    float side_course_option_float;
    float drink_option_float;
    float subtotal = 0;

    // User input for what their order is
    std::cout << "Hello Welcome to Jayden's Dinner Calculator! \n ";
    std::cout << "Enter 1 for Shawarma Wrap or 0 for Shawarma Plate: ";
    std::cin >> main_course_option;

    std::cout << "Enter 1 for meat side or 0 for vegetable side: ";
    std::cin >> side_course_option;

    std::cout << "Enter 1 for a drink or 0 for no drink: ";
    std::cin >> drink_option;
    try {
        // Tries to convert the options into integers
        int main_course_option_int = stoi(main_course_option);
        int side_course_option_int = stoi(side_course_option);
        int drink_option_int = stoi(drink_option);
        float main_course_option_float = std::stof(main_course_option);
        float side_course_option_float = std::stof(side_course_option);
        // If it is a decimal this happens
        float drink_option_float = std::stof(drink_option);
        if ((main_course_option_float != main_course_option_int) ||
         (side_course_option_float!= side_course_option_int) ||
         (drink_option_float != drink_option_int) ) {
            std::cout << "Please enter a valid menu option!";
            // If not the code continues as follows
        } else {
            // Switch case for what main course you picked and options for it
            switch (main_course_option_int) {
                case 1:
                    subtotal = SHAWARMA_WRAP;
                    if (side_course_option_int == 1) {
                        subtotal = subtotal + MEAT;
                    } else if (side_course_option_int == 0) {
                        subtotal = subtotal + VEGETABLE;
                    } else {
                        std::cout << "Please enter a real side course option";
                        return 0;
                    }
                if (drink_option_int == 1) {
                    subtotal= subtotal + DRINK;
                }

                break;
            case 0:
                subtotal = SHAWARMA_PLATE;
                if (side_course_option_int == 1) {
                    subtotal =  subtotal + MEAT;
                } else if (side_course_option_int == 0) {
                    subtotal = subtotal + VEGETABLE;
                } else {
                    std::cout << "Please enter a real side course option";
                    return 0;
                }
                if (drink_option_int == 1) {
                    subtotal = subtotal + DRINK;
                }

                break;
            // If it main course is not valid this happens
            default:
                std::cout << "Invalid main course option." << std::endl;
        }
    // Cost is calculated then displayed
    float tax = subtotal * HST;
    float total = subtotal + tax;

    std::cout << "Total cost is: $" << std::fixed <<
     std::setprecision(2) << total << std::endl;
        }
    // If the menu options are not ints this happens
    } catch (std::invalid_argument) {
    std::cout << "Please enter a valid option!";
    }
}
