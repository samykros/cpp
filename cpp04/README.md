virtual: tengo una clase Animal con un metodo (funcion) sonido
         y una clase Perro que hereda de animal que tambien tiene
         una funcion llamada sonido, al poner virtual sonido en la
         funcion de Animal, estas haciendo que cuando crees a
         Animal y Perro y luego pidas hacer sonido desde Animal,
         si Perro tiene la misma funcion (sonido), utiliza la de
         Perro, se llama sobrecargar funciones

override: buena practica por si cambias el nombre en Animal saber
          que era un metodo sobrecargado

void virtual sonido() = 0: si pones esto en Animal "obligas" a que
                        las clases que hereden tengan su propio sonido
                        y eso lo convierte en una clase abstracta,
                        porque tiene metodos completamente virtuales

this: this hace referencia al puntero implícito que apunta al objeto
      actual en una función miembro de una clase. cuando trabajas con
      métodos de una clase, puedes acceder al objeto actual que ha
      invocado ese método usando la palabra clave this. No suele ser
      necesario a menos que haya ambigüedad. Por ejemplo, si una
      función tiene un parámetro con el mismo nombre que una variable
      miembro, puedes utilizar this para referirte explícitamente a la
      variable miembro de la clase. this en funciones de retorno.
      Cuando necesitas devolver el objeto actual desde un método,
      puedes devolver *this para devolver una referencia al objeto actual.
      class MiClase
      {
        public:
            int numero;

            MiClase(int numero) {
                this->numero = numero;
            }

            MiClase& incrementar() {
                this->numero++;
                return *this;  // Devuelve el objeto actual
            }

            void mostrar() {
                cout << "Número: " << this->numero << endl;
            }
      };

deep copy: El constructor de copia (o copy constructor) en este contexto
           se asegura de que cuando se copie un objeto, se haga una copia
           completa del contenido de ese objeto, no solo de los punteros.
           Esto significa que, en lugar de que dos objetos apunten a la
           misma dirección de memoria (lo que sería una copia superficial),
           se crean copias independientes de los datos. Se usa el operator=
           cuendo quieres hacer una deep copy

Interfaz: Una interfaz es una clase abstracta que contiene solo las
          declaraciones de los métodos (sin implementación) y no puede
          ser instanciada directamente. Por eso no tiene constructor
          El propósito de una interfaz es asegurar que todas las clases
          que la implementen proporcionen un conjunto común de funcionalidades,
          pero con su propia implementación específica.

nullptr: NULL es simplemente un 0, lo que puede causar confusión o errores si
         se mezcla con funciones sobrecargadas, porque no está claramente tipado.
         nullptr no es un número: es un tipo especial que solo puede usarse como
         puntero nulo. Por eso es más seguro, claro y compatible con sobrecarga
         de funciones. nullptr no es un número, es un valor nulo con tipo
         especial: std::nullptr_t.
