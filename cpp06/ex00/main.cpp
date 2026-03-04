#include "scalar.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
    return 0;
}

///////////////////////////
//         TESTS         //
///////////////////////////

/*
./Scalar "0"
./Scalar "0.0"
./Scalar "-2147483648"
./Scalar "2147483647"
./Scalar "2147483648"
./Scalar "+123"
./Scalar " "   # espacio, imprimible, int = 32, como poner "a"
./Scalar "\t"  # son dos char, como poner "hi"
./Scalar "-inff"
./Scalar "nan"
./Scalar "42.0ff" # mal formatado
./Scalar "42.0fef0" # mal formatado
./Scalar "42..0f" # mal formatado
*/


/////////////////////////////
//         APUNTES         //
/////////////////////////////

/*
Pseudo-literal	Tipo	Significado
nan             double	Not a Number (no es un número)
nanf            float	Not a Number en float
+inf            double	Infinito positivo
-inf	        double	Infinito negativo
+inff	        float	Infinito positivo en float
-inff	        float	Infinito negativo en float
*/

/*
float → número decimal simple precisión (~7 dígitos significativos).
double → número decimal doble precisión (~15 dígitos significativos).
*/