#include <stdio.h>
#define MATERIA 3
#define ESTUDIANTE 5
int main() {

  float notas[ESTUDIANTE][MATERIA];
  float promedioE, promedioM;
  float suma;
  int opcion;
  int mayor, menor;
  do {
    printf("*MENU DE OPCIONES*\n");
    printf("1. Ingreso de notas\n");
    printf("2. Mostrar pomedio del estudiante\n");
    printf("3. Mostrar promedio materia\n");
    printf("4. Nota mayor por Estudiante\n");
    printf("5. Nota mayor por Materia\n");
    printf("6. Ver quien aprueba y reprueba\n");
    printf("7. Salida del programa\n");
    printf("Escoja la opcion:\n");


    scanf("%d", &opcion);
    switch (opcion) {

    case 1:

      for (int i = 0; i < MATERIA; i++) {
        for (int j = 0; j < ESTUDIANTE; j++) {
          float nota;
          do {

            printf("\n Ingrese las notas del estudiante  %d materia %d: ",
                   j + 1, i + 1);
            scanf("%f", &nota);

            if (nota < 0 || nota > 10) {
              printf("Nota fuera de rango (0-10) \n");
            }

          } while (nota < 0 || nota > 10);

          notas[j][i] = nota;
        }
      }
      break;

    case 2:

      for (int j = 0; j < ESTUDIANTE; j++) {
        suma = 0;
        for (int i = 0; i < MATERIA; i++) {
          suma += notas[j][i];
        }
        promedioE = suma / MATERIA;
        printf("Estudiante %d tiene una nota de: %.2f\n", j + 1, promedioE);
      }
      break;

    case 3:
      // calculo de promedio por materia
      for (int i = 0; i < MATERIA; i++) {
        suma = 0;
        for (int j = 0; j < ESTUDIANTE; j++) {
          suma += notas[j][i];
        }
        promedioM = suma / ESTUDIANTE;
        printf("Materia %d tiene una nota de: %.2f\n", i + 1, promedioM);
      }
      break;

    case 4:
      for (int j = 0; j < ESTUDIANTE; j++) {

        mayor = notas[j][0];
        menor = notas[j][0];
        for (int i = 0; i < MATERIA; i++) {

          if (notas[j][i] > mayor) {
            mayor = notas[j][i];
          }
          if (notas[j][i] < menor) {
            menor = notas[j][i];
          }
        }
        printf("La nota del estudiante %d mayor es %d y la nota menor es %d\n", j + 1, mayor, menor);
      }
      break;

    case 5:

      for (int i = 0; i < MATERIA; i++) {
        mayor = notas[0][i];
        menor = notas[0][i];
        for (int j = 1; j < ESTUDIANTE; j++) {
          if (notas[j][i] > mayor) {
            mayor = notas[j][i];
          }
          if (notas[j][i] < menor) {
            menor = notas[j][i];
          }
        }
        printf("La nota de la materia %d mayor es %d y la nota menor es %d\n", i + 1, mayor, menor);
      }

      break;

    case 6:
      for (int j = 0; j < ESTUDIANTE; j++) {
        suma = 0;
        for (int i = 0; i < MATERIA; i++) {
          suma += notas[j][i];
        }
        promedioE = suma / MATERIA;
        if (promedioE >= 6) {
          printf("Estudiante %d aprueba con  un promedio de %.2f\n", j + 1,
                 promedioE);
        } else {
          printf("Estudiante %d reprueba con un promedio de %.2f\n", j + 1,
                 promedioE);
        }
      }
      break;
      case 7:
      	    printf("Saliendo del programa...");
      	    
      	    break;


    default:
      printf("Ingrese una opcion valida");
      break;
    }

  } while (opcion != 7);

  return 0;
}
