#include <stdio.h>
#include <stdlib.h>
#define HOUSE 1
#define APARTMENT 2
#define LAND 3
#define TRUE 4
#define FALSE 0

typedef struct {
    int number;
    int cep;
    char street[20];
    char district[20];
    char city[20];
}tAddress;

typedef struct {
    int number_floor;
    int number_bedroom;
    int area_land;
    int area_built;
}tHouse;

typedef struct {
    int area_apartment;
    int number_bedroom;
    char position[4];
    int floor_number;
    int value_condominium;
    int garage_number;
}tApartment;

typedef struct {
    int area_land;
}tLand;

typedef struct {
    tAddress address;
    int id;
    char title[50];
    int type_property;
    char type_negotiation[10];
    int price;
    union t{
        tApartment apartment;
        tHouse house;
        tLand land;
    };
}tProperty;

tProperty vector_property[500];
int count = 0;

void insertProperty(tAddress address, int type)
{
    tProperty property;

    property.type_property = type;
    printf("Preco:\n");
    scanf("%d", &(property.price));
    getchar(); //
    printf("Titudo anuncio\n");
    fgets(property.title, 50, stdin);
    printf("Vender ou Alugar?:\n");
    fgets(property.type_negotiation, 10, stdin);

    if (HOUSE == type) {
        printf("Numero de quartos:\n");
        scanf("%d", &property.house.number_bedroom);
        printf("Numero de pavimentos:\n");
        scanf("%d", &property.house.number_floor);
        printf("Area do terreno:\n");
        scanf("%d", &property.house.area_land);
        printf("Area da construcao:\n");
        scanf("%d", &property.house.area_built);
    }
    else if (APARTMENT == type) {
        printf("Area do apartamento:\n");
        scanf("%d", &property.apartment.area_apartment);
        printf("Numero de quartos:\n");
        scanf("%d", &property.apartment.number_bedroom);
        printf("Posicao:\n");
        getchar();
        fgets(property.apartment.position, 4, stdin);
        printf("Andar:\n");
        scanf("%d", &property.apartment.floor_number);
        printf("Valor condominio:\n");
        scanf("%d", &property.apartment.value_condominium);
        printf("Numero de vagas na garagem:\n");
        scanf("%d", &property.apartment.garage_number);
    }
    else if (LAND == type) {
        printf("Area do terreno:\n");
        scanf("%d",&property.land.area_land);
    }
    property.address = address;
    property.id = count+1;
    vector_property[count++] = property;
}

tAddress insertAddress() {
    tAddress address;

    printf("Informe o endereco do imovel\n");
    printf("rua:\n");
    getchar(); //
    fgets(address.street, 20, stdin);
    printf("bairro:\n");
    fgets(address.district, 20, stdin);
    printf("cidade:\n");
    fgets(address.city, 20, stdin);
    printf("cep:\n");
    scanf("%d", &address.cep);
    printf("numero:\n");
    scanf("%d", &address.number);

    return address;
}

char* typeProperty(int type) {
    if (type == HOUSE)
        return "casa";
    else if (type == LAND)
        return "terreno";
    else
        return "apartemendo";
}

void show(tProperty property) {
    printf("%d. ", property.id);
    printf("%s", property.title);
    printf("%s para %s", typeProperty(property.type_property), property.type_negotiation);
    printf("Valor: %d\n", property.price);
    printf("\n");

}

void showAddress(tProperty property) {
    printf("Endereco:\n"
           "oiiii");
}
void showDetails(tProperty property){
    printf("Titulo: %s", property.title);
    printf("%s para %s", typeProperty(property.type_property), property.type_negotiation);
    printf("Valor: %d\n", property.price);
    showAddress(property);
    switch (property.type_property) {

        case HOUSE:

            break;
        case APARTMENT:

            break;
        case LAND:

            break;
    }

}

void showProperty() {
    int show_number = 1;
    for (int i = 0; i < count; ++i) {
        if (show_number == 5) {
            int option;
            printf("---------------------------------------------------------------\n");
            printf("Escolha o anuncio pelo id para ver mais detalhes\n(0) para exibir os próximos\n(-1) para sair");
            scanf("%d", &option);
            if (option == 0) {
                system("cls");
                show_number = 1;
            }
            else if(option < 0){
                system("cls");
                break;
            } else
                showDetails(vector_property[option-1]);
            /*printf("Deseja exibir os proximos?\n"
                   "Sim:(s)\t Nao:(n)\n");
            char c;
            getchar();
            scanf("%c", &c);*/
        }
        show(vector_property[i]);
        show_number++;
    }
    int option;
    printf("---------------------------------------------------------------\n");
    printf("Escolha o anuncio pelo id para ver mais detalhes\n (-1) para sair");
    scanf("%d", &option);
    if(option <= 0){
        system("cls");
    } else
        showDetails(vector_property[option-1]);
}

int main(){


    while (TRUE) {
        tAddress address;
        int option;
        printf("1 - Inserir casa\n"
               "2 - Inserir apartemento\n"
               "3 - Inserir terreno\n"
               "4 - Exibir anuncios\n");
        scanf("%d", &option);

        switch (option) {

            case 1:
                insertProperty(insertAddress(), 1);
                break;
            case 2:
                insertProperty(insertAddress(), 2);
                break;
            case 3:
                insertProperty(insertAddress(), 3);
                break;
            case 4:
                showProperty();
                break;
            default:
                break;
        }

        if (option > 4)
            break;
    }
}
