#include "../headers/spreadSheet.h"

int main() {
	spreadSheet obj{1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3," ", " ", 9 , 1, 2, 3, 4};
	spreadSheet ob1;
	ob1.copy_from(2, 2, obj);
	ob1.print();
}
