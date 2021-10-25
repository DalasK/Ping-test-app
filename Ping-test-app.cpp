//coder par DalasK
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

 static string hote; //chaîne de caractère statique permettant l'entrée de lettres, points,...
 static string nouv_ping;

void ping()
{
    SetConsoleTitleA("Ping-Test-App"); //Titre de la fenêtre 

    system("cls"); //nettoyage des entrées et réponses précédentes 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //couleur bleue pour le texte de la console

    cout << "Hote a ping : "; //demande un hôte dont on souhaite connaître la latence 
    cin >> hote;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    system(("ping " + hote).c_str());
    cout << endl; //Affichage 
   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "Souhaitez-vous tester le ping d'un autre hote ? "; 
    cout << "(O)ui ou (N)on\n\n";
    cin >> nouv_ping; //On récupère la nouvelle entrée de l'utilisateur 

    if (nouv_ping == "O" || nouv_ping == "o") //S'il a choisit la lettre O ou o (pour oui) = nouvel appel de notre fonction ping
    {
        system("cls"); //pour que se soit plus lisible 
        ping();
    }

    else if (nouv_ping == "N" || nouv_ping == "n") //Si c'est la lettre N ou n = quitte automatiquement le programme
 {
        ExitProcess(0); 
 
    }
}

int main()
{
   ping(); //Appel 

    return(0); 
}
