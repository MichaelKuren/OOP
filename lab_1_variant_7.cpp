#include <iostream>
#include <string>
#include <cmath>

bool is_number(std::string s)
{
    if (s[0] == '-')
    {
        s.erase(s.begin());
        std::string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

float f(float x, int n)
{
    float s = 0.0;
    for (int i = 1; i <= n; i++)
        if (x + 5 != 0)
            s += pow(x / (x + 5), i) * cos(i*x);
        else
        {
            std::cout << "Error: Undefined!";
            return 1.0;
        }
    return 1 + 2 * s;
}

void process_simple_operations(std::string operation)
{
    std::string input_x, input_y = "";
    std::cout << "x: ";
    getline(std::cin, input_x);
    if (is_number(input_x))
    {
        std::cout << "y: ";
        getline(std::cin, input_y);
        if (is_number(input_x))
        {
            if (operation == "+")
                std::cout << "Result: " << std::stoi(input_x) + std::stoi(input_y) << "\n";
            else if (operation == "-")
                std::cout << "Result: " << std::stoi(input_x) - std::stoi(input_y) << "\n";
            else if (operation == "*")
                std::cout << "Result: " << std::stoi(input_x) * std::stoi(input_y) << "\n";
            else if (operation == "/")
            {
                if (std::stoi(input_x) != 0)
                    std::cout << "Result: " << std::stof(input_x) / std::stof(input_y) << "\n";
                else
                    std::cout << "Error: Devision by zero!\n";
            }
        }
        else
            std::cout << "Error: Wrong input!\n";
    }
    else
        std::cout << "Error: Wrong input!\n";
}

void process_f()
{
    std::string input_x, input_n = "";
    std::cout << "x: ";
    getline(std::cin, input_x);
    if (is_number(input_x))
    {
        if (std::stoi(input_x) == -5)
        {
            std::cout << "Error: Undefined!\n";
            return;
        }

        std::cout << "n: ";
        getline(std::cin, input_n);
        if (is_number(input_n))
        {
            if (std::stoi(input_n) >= 0)
                std::cout << "Result: " << f(std::stof(input_x), std::stoi(input_n)) << "\n";
            else
                std::cout << "Error: \"n\" is negative!\n";
        }
        else
            std::cout << "Error: Wrong input!\n";
    }
    else
        std::cout << "Error: Wrong input!\n";
}

int main()
{
    while (1)
    {
        std::string input_operation = "";
        std::cout << "Select operation (\"+\", \"-\", \"/\", \"f\") or \"exit\": ";
        getline(std::cin, input_operation);

        if (input_operation == "+" || input_operation == "-" || input_operation == "*" || input_operation == "/")
            process_simple_operations(input_operation);
        else if (input_operation == "f")
            process_f();
        else if (input_operation == "exit")
            exit(0);
        else
            std::cout << "Error: Wrong operation!\n";

        std::cout << "\n";
    }

}
