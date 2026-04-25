#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include "CsvParser.hpp"
#include "DataType.hpp"
#include "StGenerator.hpp"

int main()
{
    bool success = false;
    try {
        auto file = OpenCsv("data.csv");
        auto parsedCsv = ParseCsv(file);
        auto variables = BuildVariables(parsedCsv);

        std::vector<std::string> st;

        for (auto variable : variables) {
            std::cout << "________________________________" << std::endl;
            std::cout << variable.name << " - " << variable.dataType << " - " << variable.description << 
                " - " << variable.modbusAddress << std::endl;

            std::string newStLine{ GenerateStLine(variable) };
            st.push_back(newStLine);

            std::cout << "ST code generated and added: " + newStLine << std::endl;
            std::cout << "________________________________" << std::endl;
        }
        success = true;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error ocured." << std::endl;
        return 1;
    }

    std::cout << "\nPress ENTER to exit...";
    std::cin.get();

    return success ? 0 : 1;
}
