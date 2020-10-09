#include <iostream>
#include <queue>

using namespace std;

struct canciones{
    string titulo;
    string cantante;
    string genero;
    int duracion;
};
typedef struct canciones cancion;

void mostrarPlaylist(queue<cancion> *cancion);

int main(){
    queue<cancion> happyPlaylist;//Playlist para estar feliz
    queue<cancion> sadPlaylist;//Playlist para estar triste
    queue<cancion> specialPlaylist;//Playlist para estudiar
    cancion cancionHappy;
    cancion cancionSad;
    cancion cancionEspecial;
    int opcion=0,opcion1=0, opcion2=0, opcion3=0;
    bool estado=true;
    while(estado){
        cout << "- - - - - - - - - Selecciona tu playlist - - - - - - - - - " << endl;
        cout <<"1. Happy Playlist" << endl;
        cout <<"2. Sad Playlist" << endl;
        cout <<"3. Special Playlist" << endl;
        cout <<"4. Salir" << endl;
        cout << ">>>> ";
        cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1:
            cout << "- - - - - - - - - Que desea hacer? - - - - - - - - - " << endl;
            cout <<"1. Agregar una cancion" << endl;
            cout <<"2. Eliminar una cancion" << endl;
            cout <<"3. Vaciar la playlist" << endl;
            cout <<"4. Mostrar el contenido de la playlist" << endl;
            cout << ">>>> ";
            cin >> opcion1;
            cin.ignore();
            switch(opcion1){
                case 1:
                    cancionHappy.duracion=-1;
                    cout << "Inserte titulo de la cancion: "; getline(cin, cancionHappy.titulo);
                    cout << "Inserte cantante: "; getline(cin, cancionHappy.cantante);
                    cout << "Inserte genero: "; getline(cin, cancionHappy.genero);
                    while(cancionHappy.duracion<=0){
                        cout << "Inserte duracion (En segundos): "; cin >> cancionHappy.duracion;
                    } 
                    cin.ignore();
                    happyPlaylist.push(cancionHappy);
                break;
                case 2: 
                    if(!happyPlaylist.empty()){
                        happyPlaylist.pop();
                    }
                    else{
                        cout << "Error, playlist vacia" << endl;
                    };
                break;
                case 3:
                    if(happyPlaylist.empty()){
                        cout << "Error, playlist vacia" << endl;
                    }
                    while(!happyPlaylist.empty()){
                    happyPlaylist.pop();
                    };
                break;
                case 4:
                    cout << "- - - - - - - - - Canciones en playlist - - - - - - - - - " << endl;
                    mostrarPlaylist(&happyPlaylist);
                break;
                default: cout << "Ingrese una opcion valida"; break;
            }
            break;
            case 2:
                cout << "- - - - - - - - - Que desea hacer? - - - - - - - - - " << endl;
                cout <<"1. Agregar una cancion" << endl;
                cout <<"2. Eliminar una cancion" << endl;
                cout <<"3. Vaciar la playlist" << endl;
                cout <<"4. Mostrar el contenido de la playlist" << endl;
                cout << ">>>> ";
                cin >> opcion2;
                cin.ignore();
                switch(opcion2){
                case 1:
                cancionSad.duracion=-1;
                cout << "Inserte titulo de la cancion: "; getline(cin, cancionSad.titulo);
                cout << "Inserte cantante: "; getline(cin, cancionSad.cantante);
                cout << "Inserte genero: "; getline(cin, cancionSad.genero);
                while(cancionSad.duracion<=0){
                    cout << "Inserte duiracion (En segundos): "; cin >> cancionSad.duracion;
                } 
                cin.ignore();
                sadPlaylist.push(cancionSad);
                break;
                case 2: 
                if(!sadPlaylist.empty()){
                    sadPlaylist.pop();
                }
                else{
                    cout << "Error, playlist vacia" << endl;
                }
                break;
                case 3:
                    if(sadPlaylist.empty()){
                        cout << "Error, playlist vacia" << endl;
                    }
                    while(!sadPlaylist.empty()){
                    sadPlaylist.pop();
                    }
                break;
                case 4:
                    cout << "- - - - - - - - - Canciones en playlist - - - - - - - - - " << endl;
                    mostrarPlaylist(&sadPlaylist);
                break;
                default: cout << "Ingrese una opcion valida"; break;
            }
            break;
            case 3:
            cout << "- - - - - - - - - Que desea hacer? - - - - - - - - - " << endl;
                cout <<"1. Agregar una cancion" << endl;
                cout <<"2. Eliminar una cancion" << endl;
                cout <<"3. Vaciar la playlist" << endl;
                cout <<"4. Mostrar el contenido de la playlist" << endl;
                cout << ">>>> ";
                cin >> opcion3;
                cin.ignore();
                switch(opcion3){
                case 1:
                cancionEspecial.duracion=-1;
                cout << "Inserte titulo de la cancion: "; getline(cin, cancionEspecial.titulo);
                cout << "Inserte cantante: "; getline(cin, cancionEspecial.cantante);
                cout << "Inserte genero: "; getline(cin, cancionEspecial.genero);
                while(cancionEspecial.duracion<=0){
                    cout << "Inserte duiracion (En segundos): "; cin >> cancionEspecial.duracion;
                } 
                cin.ignore();
                specialPlaylist.push(cancionEspecial);
                break;
                case 2: 
                if(!specialPlaylist.empty()){
                    specialPlaylist.pop();
                }
                else{
                    cout << "Error, playlist vacia" << endl;
                }
                break;
                case 3:
                    if(specialPlaylist.empty()){
                        cout << "Error, playlist vacia" << endl;
                    }
                    while(!specialPlaylist.empty()){
                    specialPlaylist.pop();
                    }
                break;
                case 4:
                    mostrarPlaylist(&specialPlaylist);
                break;
                default: cout << "Ingrese una opcion valida"; break;
            }
            break;
            cout << "- - - - - - - - - Canciones en playlist - - - - - - - - - " << endl;
            case 4: estado = false; break;
            default: cout << "Ingrese una opcion valida"; break;
        }
    }
    return 0;
}

void mostrarPlaylist(queue<cancion> *cancion){
    queue<canciones> auxiliar = *cancion;
    if(auxiliar.empty()){
        cout << "Error, aun no ha insertado canciones en esta playlist" << endl;
    }
    while(!auxiliar.empty()){
        cout << "Titulo: " << auxiliar.front().titulo << endl;
        cout << "Cantante: " << auxiliar.front().cantante << endl;
        cout << "Genero: " << auxiliar.front().genero << endl;
        cout << "Duracion: " << auxiliar.front().duracion << endl;
        cout << endl;
        auxiliar.pop();
    }
}

