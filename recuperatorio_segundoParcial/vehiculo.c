#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "vehiculo.h"
#include "LinkedList.h"
eVehiculo* vehiculo_new()
{
    return (eVehiculo*)calloc(1,sizeof(eVehiculo));
}
eVehiculo* newParametros(char* idStr,char* tipo,char* marcaStr,char* pesostr)
{
    eVehiculo* auxV = vehiculo_new();

    if(auxV != NULL)
    {
        set_id(auxV,atoi(idStr));
        set_tipo(auxV, atoi(tipo));
        set_marca(auxV,marcaStr);
        set_peso(auxV,atof(pesostr));
    }
    return auxV;
}
void  v_delete(eVehiculo* this)
{
    if(this!=NULL)
    free(this);
}
///GETTER &STTER
int set_id(eVehiculo* this, int id)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id=id;
            todoOk=1;
        }
    }
    return todoOk;
}
int set_tipo(eVehiculo* this, int tipo)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(tipo>0)
        {
            this->tipo=tipo;
            todoOk=1;
        }
    }
    return todoOk;
}
int set_marca(eVehiculo* this, char* marca)
{
    int todoOk = 0;
    if(this!=NULL && strlen(marca)!=0)
    {
        strcpy(this->marca,marca);
        todoOk=1;
    }
    return todoOk;
}
int set_peso(eVehiculo* this, float peso)
{
    int todoOk=0;
    if(this!=NULL)
    {
        if(peso >= 0)
        {
            this->peso = peso;
            todoOk=1;
        }
    }
    return todoOk;
}
//--------------------
int getId(eVehiculo* this, int* id)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *id = this->id;
        todoOk=1;
    }
    return todoOk;
}
int get_tipo(eVehiculo* this, int* tipo)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *tipo = this->tipo;
        todoOk=1;
    }
    return todoOk;
}
int get_marca(eVehiculo* this, char* marca)
{
    int todoOk;
    if(this!=NULL)
    {
        strcpy(marca,this->marca);
        todoOk=1;
    }
    return todoOk;
}
int get_peso(eVehiculo* this, float* peso)
{
    int todoOk=0;
    if(this!=NULL)
    {
        *peso= this->peso;
        todoOk=1;
    }
    return todoOk;
}

int controller_SaveAsText(char*path, LinkedList* pArrayList)
{
    int todoOk=-1;
    int id;
    int tipo;
    char marca[20];
    float peso;
    eVehiculo* vAux=NULL;
    FILE* pFile;
    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path, "w");
        vAux=vehiculo_new();
        if(vAux!=NULL)
        {
            fprintf(pFile, "id,titulo,genero,rating\n");
            for(int i=0;i<ll_len(pArrayList);i++)
            {
                vAux=(eVehiculo*) ll_get(pArrayList, i);
                if(vAux!=NULL)
                {
                    getId(vAux, &id);
                    get_tipo(vAux, &tipo);
                    get_marca(vAux, marca);
                    get_peso(vAux, &peso);

                    fprintf(pFile,"%d,%s,%s,%.2f\n",id,tipo,marca,peso);
                    todoOk=1;
                }
                else
                {
                    todoOk=0;
                    break;
                }
            }
        }
        fclose(pFile);
        if(todoOk)
        {
            printf("Se ha guardado correctamente el listado!\n");
        }
    }
    return todoOk;
}
