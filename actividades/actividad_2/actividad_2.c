#include <stdio.h>
#include "pico/stdlib.h"

/**
 * @brief Programa principal
*/
int main(void) {
	// Inicializo el USB
	stdio_init_all();
	// Demora para esperar la conexion
	sleep_ms(1000);

	// Inicializacion de GPIO con gpio_init()
	gpio_init(20);
	gpio_init(21);
	gpio_init(22);
	gpio_init(6);
	gpio_init(7);
	gpio_init(8);

	// Configuracion de entrada/salida con gpio_set_dir()
	gpio_set_dir(20, false);	// Entrada
	gpio_set_dir(21, false);	// Entrada
	gpio_set_dir(22, false);	// Entrada
	gpio_set_dir(6, true);		// Salida
	gpio_set_dir(7, true);		// Salida
	gpio_set_dir(8, true);		// Salida

	// variables
	bool estado_7 = false;
	bool estado_8 = false;
	bool gpio21_estaba_apretado = false;
	
	while (true) {
			// Resolver logica para 20 -> GPIO6
			bool gpio20_apretado = !gpio_get(20);
			gpio_put(6, gpio20_apretado);

			// Resolver logica para 21 -> GPIO7
			bool gpio21_apretado = !gpio_get(21);
			if (gpio21_apretado && !gpio21_estaba_apretado) {
					estado_7 = !estado_7;
					gpio_put(7, estado_7);
			}
			gpio21_estaba_apretado = gpio21_apretado;

			// Resolver logica para 22 -> GPIO8
			bool gpio22_apretado = !gpio_get(22);
			if (gpio22_apretado) {
					estado_8 = !estado_8;
					gpio_put(8, estado_8);
					sleep_ms(500);
			}
	}

	return 0;
}
