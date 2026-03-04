#include "scalar.hpp"

bool is_valid_number(const std::string &str)
{
    size_t i = 0;
    bool point_found = false;

    if (str.empty())
        return false;

    if (str[0] == '+' || str[0] == '-')
        i = 1;

    if (i == str.size()) // sólo un signo no es un número
        return false;

    // Verificar que todos los caracteres restantes sean dígitos
    // utilizamos la i ya inicializada
    for (; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            if (point_found)
                return false; // si hay mas de un punto
            point_found = true;
        }
        else if (!std::isdigit(str[i]))
        {
            return false; // cualquier carácter que no sea dígito ni punto
        }
    }

    // al final, si pasamos todas las pruebas → es válido
    return true;
}

int detect_type(const std::string &literal)
{
    // 1) Pseudo-literals
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return TYPE_DOUBLE;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return TYPE_FLOAT;

    // 2) Char
    if (literal.length() == 1 && isprint(literal[0]) && !std::isdigit(literal[0])) // añadido la comprobacion "2" que es int, no char
        return TYPE_CHAR;

    // Float
    if (literal.back() == 'f' && is_valid_number(literal.substr(0, literal.size() - 1))) // substr devuelve subcadena, 0 pos inicial, literal.size() - 1 pos final, objetivo quitar la f del final
        return TYPE_FLOAT;

    // Double
    if (literal.find('.') != std::string::npos && is_valid_number(literal))
        return TYPE_DOUBLE;

    // 5) Int
    if (is_valid_number(literal)) // comprobar que todos los caracteres son dígitos o un signo
        return TYPE_INT;

    // 6) Si nada coincide
    return TYPE_INVALID;
}

Values change_type(const std::string &literal, int type)
{
    Values v;

    switch (type) // if type == TYPE_CHAR, por si se te olvida
    {
        case TYPE_CHAR:
            v.c = literal[0];
            v.i = static_cast<int>(v.c);
            v.f = static_cast<float>(v.c);
            v.d = static_cast<double>(v.c);
            break;

        case TYPE_INT:
            v.i = std::stoi(literal); // stoi convierte str a int, "42" → 42 
            v.c = static_cast<char>(v.i); // int a char, 42 → '*' en ASCII
            v.f = static_cast<float>(v.i);
            v.d = static_cast<double>(v.i);
            break;

        case TYPE_FLOAT:
            v.f = std::stof(literal); // stof convierte str a float, "42.0f" → 42.0f
            v.i = static_cast<int>(v.f);
            v.c = static_cast<char>(v.f); // de float a char, 42.0f → '*'
            v.d = static_cast<double>(v.f);
            break;

        case TYPE_DOUBLE:
            v.d = std::stod(literal); // stod convierte str a double, "42.0" → 42.0
            v.i = static_cast<int>(v.d);
            v.c = static_cast<char>(v.d);
            v.f = static_cast<float>(v.d);
            break;

        case TYPE_INVALID:
        // default se ejecuta si ningun caso coincide, es preventivo aqui
        default:
            throw std::invalid_argument("Invalid literal"); // aqui la funcion no devuelve nada
    }

    return v;
}

void print_values(const Values &v)
{
    // --- CHAR ---
    // isnan comprueba NaN, not a number, isinf comprueba infinito, los otros rango ascii imprimibles
    // isnan, isinf solo puede usarse con .d, .f, o long double, que tienen los pseudo-literal
    if (std::isnan(v.d) || std::isinf(v.d))
        std::cout << "char: impossible\n";
    else if (v.c < 32 || v.c > 126) // no va a salir nunca este caso pero ya lo tengo puesto
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << v.c << "'\n";

    // --- INT ---
    // min() max(), da obviamente los limites del int, lo mismo que poner -2147483648 a 2147483647
    if (std::isnan(v.d) || std::isinf(v.d) || v.d > std::numeric_limits<int>::max() || v.d < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << v.i << "\n";

    // --- FLOAT ---
    std::cout << "float: ";
    if (std::isnan(v.f))
        std::cout << "nanf\n";
    else if (std::isinf(v.f))
        std::cout << (v.f > 0 ? "+inff\n" : "-inff\n"); // leelo poco a poco
    else
        std::cout << v.f << "f\n";

    // --- DOUBLE ---
    std::cout << "double: ";
    if (std::isnan(v.d))
        std::cout << "nan\n";
    else if (std::isinf(v.d))
        std::cout << (v.d > 0 ? "+inf\n" : "-inf\n"); // igual que arriba
    else
        std::cout << v.d << "\n";
}

void ScalarConverter::convert(const std::string &literal)
{
    // 1) Detectar el tipo
    int type = detect_type(literal);

    // 2) Convertir a los otros tipos usando static_cast
    Values v;
    try
    {
        v = change_type(literal, type);
    }
    // catch se ejecuta solo si se lanzo un throw
    // std::cout << "Exception: " << e.what() << "\n";
    // e.what() devuelve el mensaje "Invalid literal" que tenemos en el throw
    // que 'e' tiene el mensaje vamos
    catch(const std::exception &e)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // 3) Mostrar resultados
    print_values(v);
}
