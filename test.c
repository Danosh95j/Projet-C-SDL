#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "mysql/include/mysql.h"


int SDL_main(int argc, char *argv[])
{
    char option;
    int connect = 0;
    char loggedInUsername[50];
    char loggedInPassword[20];
    int result = 0;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Graphical database generator and manager ======\n");
        printf("\n\t\t====== Choose what you want : ======\n");
        printf("\n\t\t\t1. Create an account");
        printf("\n\t\t\t2. Log in to an account");
        printf("\n\t\t\t3. Access the database management menu");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);
        getchar();

        switch (option)
        {
        case '1':
            createDatabase();
            break;
        case '2':
            //result = authenticateUser(&connect, loggedInUsername, loggedInPassword);
            break;
        case '3':
            /*if (result == 0){
                mainMenu(loggedInUsername, loggedInPassword);
            } else {
                system("cls");
                printf("\n\n\t\t\tYou must be logged in to access the main menu.");
                printf("\n\n\t\t\tEnter any keys to continue.......");
                getch();
            }
            result = 0;
            break;*/
        case '4':
            testMySQLConnection();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
            printf("\n\n\t\t\tEnter any keys to continue.......");
            getch();
        }
    }
    return 0;
}

int testMySQLConnection()
{
    MYSQL *conn = mysql_init(NULL);

    if (mysql_real_connect(conn, "localhost", "root", "root", "bdd", 3306, NULL, 0)) {
        printf("\n\t\t\tDatabase connection successful\n");
        printf("\n\n\t\t\tEnter any keys to continue.......");
        getch();

        // Exécuter des requêtes SQL ici

        mysql_close(conn);
    } else {
        fprintf(stderr, "\n\t\t\tDatabase connection failed: %s\n", mysql_error(conn));
        printf("\n\n\t\t\tEnter any keys to continue.......");
        getch();
    }

    return 0;
}

int createDatabase()
{
    system("cls");
    printf("\t\t\t====== Creation of your new database ======\n");

    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "\n\n\t\t\tMySQL connection initialization error\n");
        return 1;
    }

    if (mysql_real_connect(conn, "localhost", "root", "root", NULL, 3306, NULL, 0)) {
        char dbName[100];
        printf("\n\n\t\t\tEnter the name of the new database : ");
        fgets(dbName, sizeof(dbName), stdin);

        dbName[strcspn(dbName, "\n")] = '\0';

        char query[150];
        snprintf(query, sizeof(query), "CREATE DATABASE %s", dbName);

        if (mysql_query(conn, query) == 0) {
            printf("\n\n\t\t\tDatabase '%s' created successfully.\n", dbName);
            printf("\n\n\t\t\tEnter any keys to continue.......");
            getch();
        } else {
            fprintf(stderr, "\n\n\t\t\tError creating database: %s\n", mysql_error(conn));
            printf("\n\n\t\t\tEnter any keys to continue.......");
            getch();
        }

        mysql_close(conn);
        return 0;
    } else {
        fprintf(stderr, "\n\n\t\t\tFailed to connect to MySQL server: %s\n", mysql_error(conn));
        printf("\n\n\t\t\tEnter any keys to continue.......");
        getch();
        mysql_close(conn);
        return 1;
    }
}