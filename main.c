#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    int cep;
    char street[20];
    char district[20];
    char city[20];
}tAddress;

typedef struct {
    char title[50];
    int number_floor;
    int number_bedroom;
    int area_land;
    int area_built;
}tHouse;

typedef struct {
    char title[50];
    int area_apartment;
    int number_bedroom;
    char position[3];
    int floor_number;
    int value_condominium;
    int garage_number;
}tApartment;

typedef struct {
    char title[50];
    int area_land;
}tLand;

typedef struct {
    tAddress address;
    int price;
    char type[8];
    union t{
        tApartment apartment;
        tHouse house;
        tLand land;
    }
}tProperty;

void insertProperty()
{

}

int main(){
    tProperty p;
    p.land.area_lan = 5;
}
