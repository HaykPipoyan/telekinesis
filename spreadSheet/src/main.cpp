#include <iostream>
#include "../headers/cell.h"
#include "../headers/spreadSheet.h"

int main() {
    
    SpreadSheet sheet(3, 3);

    sheet[0][0] = 1;
    sheet[0][1] = 2.5;
    sheet[0][2] = 'A';
    sheet[1][0] = true;
    sheet[1][1] = "Hello";
    sheet[1][2] = std::vector<int>{1, 2, 3};
    sheet[2][0] = 10.75;
    sheet[2][1] = 'B';
    sheet[2][2] = false;

    std::cout << "SpreadSheet:" << std::endl;
    std::cout << sheet << std::endl;

    SpreadSheet copy(sheet);

    std::cout << "Copy of SpreadSheet:" << std::endl;
    std::cout << copy << std::endl;

    if (sheet == copy) {
        std::cout << "Sheets are equal." << std::endl;
    } else {
        std::cout << "Sheets are not equal." << std::endl;
    }

    sheet.resize(2, 2);
    std::cout << "Resized SpreadSheet:" << std::endl;
    std::cout << sheet << std::endl;

    return 0;
}
