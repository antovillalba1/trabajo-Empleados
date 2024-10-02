#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"  
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

int main()
{
    int i,opc_1, categoria, a_legajo[3], a_categoria[3], legajo, nuevaCategoria,opc_2;
    int sueldo, horas, a_horas_trabajadas[40];
    char a_nombre[3][20], a_tipo_empleado[3], input[10];
    const int PLANTA = 2000;
    const int ADMI = 1500;
    const int VENDEDOR = 1000;
    const char*categorias[]={"Planta", "Administrativo","Vendedor"};
    
    do {
        do
        {
            printf(MAGENTA"___MENU___\n"RESET);
            printf("1. Cargar empleados\n");
            printf("2. Mostrar empleados\n");
            printf("3. Mostrar el sueldo de un empleado\n");
            printf("4. Modificar la categoria de un empleado\n");
            printf("5. Salir\n");
            printf("\n");
            printf("Elegir una opcion: ");
            scanf("%s", input); 

            opc_1 = atoi(input); 

            if (strlen(input) == 0 || (opc_1 < 1 || opc_1 > 5)) 
            {
                printf(RED"Usted ha elegido una opcion invalida o ha ingresado una letra, por favor volver a ingresar.\n"RESET);
                printf("\n");
            }
            
        }while (opc_1<0||opc_1>5);
        
        switch (opc_1)
        {
            case 1:
            for(i=0; i<3; i++)
            {
                printf(YELLOW"Ingresar el legajo del empleado: \t"RESET);
                scanf("%d", &a_legajo[i]);
                printf(YELLOW"Ingresar el nombre del empleado: \t"RESET);
                scanf("%s", &a_nombre[i]);
                printf(YELLOW"Ingrese las horas trabajadas: \t"RESET);
                scanf("%d", &a_horas_trabajadas[i]);
                printf(YELLOW"Ingresar la categoria: \t"RESET);
                scanf("%d", &a_categoria[i]); 
                printf(MAGENTA"______________________________________\n"RESET);
    
            }
            break;
            case 2:
            printf(GREEN"Los datos de los empleados son:\n"RESET);
            for(i=0; i<3; i++)
            {
                
                printf(GREEN"Nombre: %s\t  Legajo: %d\t Horas trabajadas: %d\t Categoria: %s\t\n"RESET, a_nombre[i], a_legajo[i] ,a_horas_trabajadas[i],categorias[a_categoria[i]-1]);
            }    
            break;
            case 3:
                printf(YELLOW"Ingrese el legajo del empleado: "RESET);
                scanf("%d", &legajo);
                for (i=0; i<3;i++)
                {
                    if (a_legajo[i] == legajo) 
                    {
                    printf(GREEN"Nombre del empleado: %s\n"RESET, a_nombre[i]);
                    printf(GREEN"El legajo del empleado es: %d\n "RESET, a_legajo[i]);

                    if (a_categoria[i] == 1)
                    {
                    sueldo = a_horas_trabajadas[i] * 2000; //Planta
                    printf(GREEN"El sueldo del empleado de la planta es: %d\n"RESET, sueldo);
                    }
                    else if (a_categoria[i] == 2) //Administativo
                    {
                    sueldo = a_horas_trabajadas[i] * 1500;
                    printf(GREEN"El sueldo del empleado Administativo es: %d\n"RESET, sueldo);
                    }
                    else if (a_categoria[i] == 3) //Vendedor
                    {
                    sueldo = a_horas_trabajadas[i] * 1500;
                    printf(GREEN"El sueldo del empleado Vendedor es: %d\n"RESET, sueldo);
                    }
                    
                    }
                }    
                    break;
            case 4:
            do
            {
                printf(YELLOW"Ingrese el legajo del empleado del cual desea modificar la categoria: "RESET);
                scanf("%d", &legajo);
                for(i=0;i<3;i++)
                {
                    if (a_legajo[i] == legajo) 
                    {   printf(GREEN"La categoria actual del empleado es: %d \n"RESET, a_categoria[i]);
                        printf(YELLOW"Ingrese nueva categoria: "RESET);
                        scanf("%d", &nuevaCategoria);
                        a_categoria[i] = nuevaCategoria;
                        break;
                    }
                }    
                    printf(CYAN"Dato modificado exitosamente\n"RESET);
                
                    printf("%d", a_categoria[i]);
                    printf(YELLOW"Desea modificar la categoria de otro empleado:\n"RESET);
                    printf("1-Si\n");
                    printf("2-No\n");
                    scanf("%d", &opc_2);
            }while (opc_2!=2);
        } 
    } while (opc_1 !=5);
    return 0;
}
