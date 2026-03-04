# cpp

Concepto	        Puntero (Base* p)	                Referencia (Base& r)
Qué es	            Dirección de memoria del objeto     Alias / apodo para un objeto existente
Puede ser nullptr?	Sí	                                No
Sintaxis para usar	p->miembro	                        r.miembro
Se puede cambiar	Sí, p = otra_direccion	            No, siempre apunta al mismo objeto
Crear	            Base* p = &obj;	                    Base& r = obj;


Puntero → papel con la dirección de la casa
Referencia → alias pegado a la casa: “llámame CasaA” → siempre apunta a la misma casa
* → “abrir el papel de dirección y ver la casa” (desreferenciar)
& → “tomar la dirección de la casa”


Base* obj = generate();   // obj = puntero a Base (puede ser A/B/C)
identify(obj);            // pasamos puntero
identify(*obj);           // pasamos referencia, "dame el objeto al que apunta el puntero"