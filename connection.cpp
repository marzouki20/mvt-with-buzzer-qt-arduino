#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de donnée ODBC
db.setUserName("econnet");//inserer le nom de l'utilisateur
db.setPassword("123");//inserer le mot de passe de cet utilisateur
if(db.open()) test=true;

return test;
}

void Connection::closeConnection(){db.close();}
