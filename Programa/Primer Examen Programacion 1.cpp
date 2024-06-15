#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

// Estructura Usuario para almacenar la información de cada usuario
struct Usuario {
    char nombre[50];
    char cedula[50];
    char telefono[50];
    char direccion[100]; // Nueva información de dirección
    double plastico;
    double vidrio;
    double papel;
    double metal;
    int puntos;
};

// Estructura EcoProducto para los productos ecológicos
struct EcoProducto {
    char nombre[50];
    int puntosRequeridos;
};

// Vector de usuarios para almacenar la lista de usuarios
std::vector<Usuario> usuarios;

// Vector de EcoProductos para almacenar la lista de productos ecológicos
std::vector<EcoProducto> ecoProductos;

// Función para inicializar algunos productos ecológicos
void inicializarEcoProductos() {
    EcoProducto p1 = {"Bolsa Reutilizable", 50};
    EcoProducto p2 = {"Botella de Agua Eco", 100};
    EcoProducto p3 = {"Kit de Siembra", 150};
    EcoProducto p4 = {"Kit de Limpieza Eco", 250};
    EcoProducto p5 = {"Lamparas Eco", 200};
    ecoProductos.push_back(p1);
    ecoProductos.push_back(p2);
    ecoProductos.push_back(p3);
    ecoProductos.push_back(p4);
    ecoProductos.push_back(p5);
}

// Función para registrar un nuevo usuario
void registrarUsuario() {
    Usuario nuevoUsuario;
    printf("Ingrese su numero de cedula: ");
    scanf("%s", nuevoUsuario.cedula);
    printf("Ingrese nombre del usuario: ");
    scanf("%s", nuevoUsuario.nombre);
    printf("Ingrese su numero de telefono: ");
    scanf("%s", nuevoUsuario.telefono);
    printf("Ingrese su direccion: ");
    scanf(" %[^\n]", nuevoUsuario.direccion); // Leer toda la línea incluida con espacios
    nuevoUsuario.plastico = 0;
    nuevoUsuario.vidrio = 0;
    nuevoUsuario.papel = 0;
    nuevoUsuario.metal = 0;
    nuevoUsuario.puntos = 0;
    usuarios.push_back(nuevoUsuario);
    printf("Usuario registrado correctamente.\n");
}

// Función para ingresar material reciclado por un usuario
void ingresarMaterialReciclado() {
    char nombre[50];
    printf("Ingrese nombre del usuario: ");
    scanf("%s", nombre);
    
    // Buscar el usuario en el vector de usuarios
    for (int i = 0; i < usuarios.size(); ++i) {
        if (strcmp(usuarios[i].nombre, nombre) == 0) {
            double cantidad;
            char tipo[10];
            printf("Ingrese tipo de material (plastico, vidrio, papel, metal): ");
            scanf("%s", tipo);
            printf("Ingrese cantidad en kg: ");
            scanf("%lf", &cantidad);
            
            if (strcmp(tipo, "plastico") == 0) {
                usuarios[i].plastico += cantidad;
            } else if (strcmp(tipo, "vidrio") == 0) {
                usuarios[i].vidrio += cantidad;
            } else if (strcmp(tipo, "papel") == 0) {
                usuarios[i].papel += cantidad;
            } else if (strcmp(tipo, "metal") == 0) {
                usuarios[i].metal += cantidad;
            } else {
                printf("Tipo de material no válido.\n");
                return;
            }
            printf("Material registrado correctamente.\n");
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

// Función para calcular los puntos de cada usuario basado en la cantidad de material reciclado
void calcularPuntos() {
    for (int i = 0; i < usuarios.size(); ++i) {
        usuarios[i].puntos = static_cast<int>(usuarios[i].plastico * 2 + usuarios[i].vidrio * 3 + usuarios[i].papel * 1 + usuarios[i].metal * 5);
    }
    printf("Puntos calculados correctamente.\n");
}

// Función para generar estadísticas de los usuarios
void generarEstadisticas() {
    for (int i = 0; i < usuarios.size(); ++i) {
        printf("Usuario: %s\n", usuarios[i].nombre);
        printf("Plastico: %.2f kg\n", usuarios[i].plastico);
        printf("Vidrio: %.2f kg\n", usuarios[i].vidrio);
        printf("Papel: %.2f kg\n", usuarios[i].papel);
        printf("Metal: %.2f kg\n", usuarios[i].metal);
        printf("Puntos: %d\n\n", usuarios[i].puntos);
    }
}

// Función para mostrar los EcoProductos disponibles
void mostrarEcoProductos() {
    printf("\nLista de EcoProductos disponibles:\n");
    for (int i = 0; i < ecoProductos.size(); ++i) {
        printf("%d. %s - %d puntos\n", i + 1, ecoProductos[i].nombre, ecoProductos[i].puntosRequeridos);
    }
    printf("\n\n***Para canjear tus EcoPuntos por dinero, ve al siguiente enlace\n");
    printf("https://www.EarthWiseEcoSolutions.com/CanjearEcoPuntos\n\n");
}

// Función para canjear puntos por EcoProductos
void canjearPuntos() {
    char nombre[50];
    printf("Ingrese nombre del usuario: ");
    scanf("%s", nombre);

    // Buscar el usuario en el vector de usuarios
    for (int i = 0; i < usuarios.size(); ++i) {
        if (strcmp(usuarios[i].nombre, nombre) == 0) {
            mostrarEcoProductos();
            int opcion;
            printf("Ingrese el numero del producto que desea canjear: ");
            scanf("%d", &opcion);

            if (opcion > 0 && opcion <= ecoProductos.size()) {
                int puntosRequeridos = ecoProductos[opcion - 1].puntosRequeridos;
                if (usuarios[i].puntos >= puntosRequeridos) {
                    usuarios[i].puntos -= puntosRequeridos;
                    printf("Producto canjeado exitosamente. Te quedan %d puntos.\n", usuarios[i].puntos);
                } else {
                    printf("No tienes suficientes puntos para canjear este producto.\n");
                }
            } else {
                printf("Opcion no valida.\n");
            }
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

// Función principal que muestra el menú y llama a las funciones según la opción seleccionada
int main() {
    inicializarEcoProductos();
    int opcion;
    do {
        printf("                                    ------------------------------------------\n");
        printf("                                       BIENVENIDOS A EARTHWISE ECOSOLUTIONS\n");
        printf("                                    ------------------------------------------\n");
        printf("Nuestro planeta es hermoso, pero necesita nuestra ayuda. En EARTHWISE ECOSOLUTIONS,\n");
        printf("creemos que cada pequeño esfuerzo cuenta. Por eso, estamos lanzando nuestra iniciativa\n");
        printf("de reciclaje y queremos que seas parte de ella. Unete a nuestra mision y descubre como\n");
        printf("puedes contribuir a un planeta mas limpio y verde.\n");
        printf("\n***Recolecta EcoPuntos y participa en nuestro sorteo mensual***\n");
        printf("\n·Cualquier pregunta o consulta al: +506 2445-1156·\n");
        printf("\nMenu de opciones:\n");
        printf("1. Registrar usuario\n");
        printf("2. Ingresar material reciclado\n");
        printf("3. Calcular puntos\n");
        printf("4. Generar estadisticas\n");
        printf("5. Ver EcoProductos\n");
        printf("6. Canjear puntos\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                ingresarMaterialReciclado();
                break;
            case 3:
                calcularPuntos();
                break;
            case 4:
                generarEstadisticas();
                break;
            case 5:
                mostrarEcoProductos();
                break;
            case 6:
                canjearPuntos();
                break;
            case 7:
            	printf("\n-----MUCHAS GRACIAS POR RECICLAR CON NOSOTROS-----\n");
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 7);

    return 0;
}

