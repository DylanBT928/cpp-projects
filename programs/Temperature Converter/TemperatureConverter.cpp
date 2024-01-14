#include <iostream>
double fahrenheit;
double celsius;
double kelvin;

void convertFahrenheit(double f)
{
    std::cout << "Celsius: " << ((f - 32) * ((double)5 / 9)) << '\n';
    std::cout << "Kelvin: " << (((f - 32) / 1.8) + 273.15);
}

void convertCelsius(double c)
{
    std::cout << "Fahrenheit: " << (c * (9 / 5) + 32) << '\n';
    std::cout << "Kelvin: " << (c + 273.15);
}

void convertKelvin(double k)
{
    std::cout << "Fahrenheit: " << (1.8 * (k - 273.15) + 32) << '\n';
    std::cout << "Celsius: " << (k - 273.15);
}

int main()
{
    char option{};

    std::cout << "(f) - fahrenheit\n(c) - celsius\n(k) - kelvin\n";
    std::cout << "choose a temperature scale: ";
    std::cin >> option;

    switch(option)
    {
        case 'f':
            std::cout << "Fahrenheit: ";
            std::cin >> fahrenheit;
            convertFahrenheit(fahrenheit);
            break;
        case 'c':
            std::cout << "Celsius: ";
            std::cin >> celsius;
            convertCelsius(celsius);
            break;
        case 'k':
            std::cout << "Kelvin: ";
            std::cin >> kelvin;
            convertKelvin(kelvin);
            break;
        default:
            std::cout << "Invalid option." << std::endl;
            break;
    }
    
    return 0;
}
