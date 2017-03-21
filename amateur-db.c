#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
}

struct Database {
    struct Address rows[MAX_ROWS];
    //defines the max size of the db in the dat file
};

struct Connection {
    FILE *file;
    //the pointer to the file, still dont know what the hell it means exactly
    struct Database *db;
    //
};

void die(const char *message)
{
    if (errno) {
        perror(message);
        //using the perror header file if the error is outside the program's logic
    } else {
        printf("ERROR: %s\n", message);
        //our built-in errors
    }
    //
    exit(1);
}

void Address_print(struct Address *addr)
{
    //print out the data in this row called by the address
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    //Kinda self-explanatory
    //conn->db
    //
    int rc = fread((*conn).db, sizeof(struct Database), 1, conn->file);
    //note the syntax of the conditionals here
    if (rc != 1)
        die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
    // open the DB
    struct Connection *conn = malloc(sizeof(struct Connection));
    //
    if (!conn)
        die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory error");

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file");

    return conn;
}























