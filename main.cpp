#include <iostream>
#include <fstream>

using namespace std;

class PersonajeTablero
{
    public:
    int pos_x;
    int pos_y;
    int hp;
    int ataque;
    int jugador;
    PersonajeTablero*sig;


    PersonajeTablero(int pos_x,int pos_y,int hp,int ataque,int jugador)
    {
        this->pos_x=pos_x;
        this->pos_y=pos_y;
        this->hp=hp;
        this->ataque=ataque;
        this->jugador=jugador;
        sig=NULL;
    }
};

class ListaPersonajes
{
    public:
    PersonajeTablero*inicio;
    ListaPersonajes()
    {
        inicio=NULL;
    }
    void agregar(PersonajeTablero *P)
    {
        if(inicio==NULL)
        {
            inicio=P;
        }else
        {
            PersonajeTablero*temp=inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig=P;
        }
    }
    void cargarDesdeArchivo(string path);
    void escribirEnArchivo(string path)
    {
        ofstream w(path.c_str());
        PersonajeTablero*temp=inicio;
        while(temp!=NULL)
        {
            w<<temp->ataque<<endl;
            w<<temp->hp<<endl;
            w<<temp->jugador<<endl;
            w<<temp->pos_x<<endl;
            w<<temp->pos_y<<endl;
            w<<""<<endl;
            temp=temp->sig;
        }
    }
    void danoDeArea(int dano,int jugador)
    {
        PersonajeTablero*temp=inicio;
        while(temp!=NULL)
        {
            if(jugador==temp->jugador){
                temp->hp-=dano;
            }temp=temp->sig;
        }

    }
    void debilitadorDeArea(int debilitador,int jugador)
    {
        PersonajeTablero*temp=inicio;
        while(temp!=NULL)
        {
            if(jugador==temp->jugador){
                temp->ataque-=debilitador;
            }temp=temp->sig;
        }
    }
    void curadorDeArea(int curacion,int jugador)
    {
        PersonajeTablero*temp=inicio;
        while(temp!=NULL)
        {
            if(jugador==temp->jugador){
                temp->hp+=curacion;
            }temp=temp->sig;
        }
    }


};

int main()
{
    ListaPersonajes L;
    L.agregar(new PersonajeTablero(1,1,3,1,1));
    L.agregar(new PersonajeTablero(1,1,5,1,1));
    cout<<L.inicio->hp<<endl;
    L.danoDeArea(2,1);
    cout<<L.inicio->sig->hp<<endl;
    cout<<L.inicio->hp<<endl;

    return 0;
}
