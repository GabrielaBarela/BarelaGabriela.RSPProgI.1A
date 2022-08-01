#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

#endif // VEHICULO_H_INCLUDED
int get_peso(eVehiculo* this, float* peso);
eVehiculo* vehiculo_new();
eVehiculo* newParametros(char* idStr,char* tipo,char* marcaStr,char* pesostr);
void v_delete(eVehiculo* this);
///GETTER &STTER
int set_id(eVehiculo* this, int id);

int set_tipo(eVehiculo* this, int tipo);

int set_marca(eVehiculo* this, char* marca);

int set_peso(eVehiculo* this, float peso);

//--------------------
int getId(eVehiculo* this, int* id);
int get_tipo(eVehiculo* this, int* tipo);
int get_marca(eVehiculo* this, char* marca);
int get_peso(eVehiculo* this, float* peso);
int controller_SaveAsText(char*path, LinkedList* pArrayList);
