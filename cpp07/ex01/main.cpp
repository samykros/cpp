#include "iter.hpp"

void printInt(int &x)
{
    std::cout << x << " ";
}
void printString(const std::string &s)
{
    std::cout << s << " ";
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"Hola", "Mundo", "!"};
    const std::string strArrConst[] = {"Hola", "Mundo", "Const", "!"};

    iter(arr, 5, printInt);        // imprime: 1 2 3 4 5
    std::cout << std::endl;

    iter(strArr, 3, printString);  // imprime: Hola Mundo !
    std::cout << std::endl;

    iter(strArrConst, 4, printString);  // imprime: Hola Mundo Const !
    std::cout << std::endl;
}
