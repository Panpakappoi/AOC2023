// AOC2023Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <unordered_map>
struct calibration{
    int first_value;
    int last_value;
};


int convert_char_to_int(char c) {
    return c - '0';

}



void first_part() {
    std::ifstream istream;
    istream.open("AOCInput.txt");
    if (istream.fail()) {
        std::cout << " Failed to open file, please try again\n";
    }
    std::vector<calibration> inputList;
    std::string line;
    while (std::getline(istream, line)) {
        calibration numbers;
        for (int i = 0; i < line.length(); i++)
        {
            if (convert_char_to_int(line[i]) < 10)
            {
                numbers.first_value = convert_char_to_int(line[i]);
                break;
            }
        }
        for (int i = line.length() - 1; i >= 0; i--) {
            if (line[i] - '0' < 10)
            {
                numbers.last_value = convert_char_to_int(line[i]);
                break;
            }
        }
        inputList.emplace_back(numbers);
    }
    std::vector<std::string> composites;
    for (auto input : inputList) {
        std::cout << input.first_value << " " << input.last_value << "\n";
        std::string composite = std::to_string(input.first_value) + std::to_string(input.last_value);
        composites.emplace_back(composite);
    }
    std::vector<int> actual_values;
    for (auto composite : composites) {
        std::cout << composite << '\n';
        actual_values.emplace_back(std::stoi(composite));
    }
    int sum = 0;
    for (auto value : actual_values)
        sum += value;
    std::cout << sum << '\n';
}

void second_part() {
    std::ifstream istream;
    istream.open("AOCInput.txt");
    if (istream.fail()) {
        std::cout << " Failed to open file, please try again\n";
    }
    std::unordered_map<std::string, int> hashMap;
    hashMap = {
            {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
            {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    std::vector<calibration> input_list;
    std::string line;
    std::vector<std::string> inputs;
    while (std::getline(istream, line))
    {
        inputs.emplace_back(line);
    }
    for (const auto& input : inputs)
    {
        calibration numbers{ 0,0 };
        std::string temp = "";
        for (int i = 0; i < input.length(); i++)
        {
            if (convert_char_to_int(input[i]) < 10)
            {
                numbers.first_value = convert_char_to_int(input[i]);
                break;
            }
            else {
                temp += input[i];
                std::cout << temp << '\n';
                for (auto key : hashMap) {
                    if (temp.find(key.first) != std::string::npos) {

                        numbers.first_value = hashMap[key.first];
                        break;
                    }
                }
                if (numbers.first_value == 1 || numbers.first_value == 2 || numbers.first_value == 3 ||
                    numbers.first_value == 4 || numbers.first_value == 5 || numbers.first_value == 6 ||
                    numbers.first_value == 7 || numbers.first_value == 8 || numbers.first_value == 9)
                    break;
            }
        }
        temp = "";
        for (int i = input.length() - 1; i >= 0; i--) {

            if (input[i] - '0' < 10)
            {
                numbers.last_value = convert_char_to_int(input[i]);
                break;
            }
            else {
                temp = input[i] + temp;
                std::cout << "Temp: " << temp << '\n';
                for (auto key : hashMap) {
                    if (temp.find(key.first) != std::string::npos) {
                        numbers.last_value = hashMap[key.first];
                        std::cout << "Found: " << key.first << '\n';
                        break;
                    }
                }
                if (numbers.last_value == 1 || numbers.last_value == 2 || numbers.last_value == 3 ||
                    numbers.last_value == 4 || numbers.last_value == 5 || numbers.last_value == 6 ||
                    numbers.last_value == 7 || numbers.last_value == 8 || numbers.last_value == 9)
                    break;

            }
        }
        input_list.emplace_back(numbers);
    }

    for (auto i : input_list)
    {
        std::cout << i.first_value << " " << i.last_value << '\n';
    }
    for (auto input : input_list)
        std::cout << input.first_value << input.last_value << '\n';
    std::vector<std::string> composites;
    for (auto input : input_list) {
        std::cout << input.first_value << " " << input.last_value << "\n";
        std::string composite = std::to_string(input.first_value) + std::to_string(input.last_value);
        composites.emplace_back(composite);
    }
    std::vector<int> actual_values;
    for (auto composite : composites) {
        std::cout << composite << '\n';
        actual_values.emplace_back(std::stoi(composite));
    }
    int sum = 0;
    for (auto value : actual_values)
        sum += value;
    std::cout << sum << '\n';

    
}

int main()
{
    
    first_part();
    second_part();
    return 0;
}
    





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
