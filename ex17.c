#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "str_line.h"

#define MAX_DATA 512
#define MAX_ROWS 100
#define MAX_LIMIT 25

// figure out in which contexts STRUCT 
// is declarative or referential


//structs

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database
{
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	FILE *file;
	struct Database *db;	
};

//end structs


//begin voids

void die(const char *message)
{
	if (errno){
		perror(message);
	}else{
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

//

void Address_print(struct Address *addr)
{
	printf("%d %s %s %p %ld\n", addr->id, addr->name, addr->email, &addr, sizeof(addr));
}
//
void Name_print(struct Address *addr)
{
	printf("%d %s \n", addr->id, addr->name);
}

//
void Email_Address_print(struct Address *addr)
{
	printf("%d %s \n", addr->id, addr->email);
}

//

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to load database");
}

//

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)
		die("Memory Error");

	conn->db = malloc(sizeof(struct Database));
	if(!conn->db)
		die("Memory error");

	if(mode == 'c'){
		conn->file = fopen(filename,"w");
	}else{
		conn->file = fopen(filename, "r+");

		if(conn->file){
			Database_load(conn);
		}
	}
	if(!conn->file)
		die("Failed to open file");

	return conn;		
}

//

void Database_close(struct Connection *conn)
{
	if (conn){
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

//

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die("Failed to write database.");

	rc = fflush(conn->file);
	if(rc == -1)
		die("Cannot flush database.");
}

//

void Database_create(struct Connection *conn)
{
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++){
		struct Address addr = {.id = i,.set = 0};
		conn->db->rows[i] = addr;
	}
}

//

void Database_set(struct Connection *conn, int id, const char *name,
	const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
		die("Already set, delete it first.");

		addr->set = 1;

		char *res = strncpy(addr->name, name, MAX_DATA);
		if(!res)
			die("Name copy failed");

		res = strncpy(addr->email, email, MAX_DATA);
		if(!res)
			die("Email copy failed");
}

//

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set){
		Address_print(addr);
	}else{
		die("ID is not set");
	}
}

//

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn, int id)
{
	int n = 0;
	int i = 0;
	struct Database *db = conn->db;

	printf("\nEnron Employee Database\n*******\n");

	for (i = 0; i < MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set){
			Address_print(cur);
			n++;
		}

	}
	

	printf("*******\n");
	printf("Number of rows in db: %u\n\n", n);
	
	printf("*******\n");

	for (i = 0; i < MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set){
			Name_print(cur);
			n++;
		}

	}

	printf("*******\n");

	for (i = 0; i < MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set){
			Email_Address_print(cur);
			n++;
		}

	}
	printf("*******\n");
}

//end voids


//custom functions

int Increment_id(struct Connection *conn, int id)
{
	int n = 0;
	int i = 0;
	struct Database *db = conn->db;

	for (i = 0; i < MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set){	
			n++;
		}
	}
	return n + 1;
}

char* get_name(struct Connection *conn, int id){
	struct Address *addr = &conn->db->rows[id];

	if(addr->set){
		return addr->name;
	}else{
		die("ID is not set");
		return 0;
	}
}







//begin main



int main(int argc, char *argv[])
{
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	char name_input[MAX_LIMIT];
	char email_input[MAX_LIMIT];
	struct Connection *conn = Database_open(filename, action);
	int id = 0;
	int next_id = 0;
	int id_input;


	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records");

	switch (action){
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if(argc == 3)
				id = 1;

			Database_get(conn, id);
			break;

		case 's':
			
			next_id = Increment_id(conn, id);
			
			printf("Enter Employee name:\n");
			fgets(name_input, MAX_LIMIT, stdin);
			
			printf("Enter Employee email:\n");
			fgets(email_input, MAX_LIMIT, stdin);

			Database_set(conn, next_id, End_line(name_input), End_line(email_input));
			Database_write(conn);
			Database_list(conn, id);
			break;

		case 'u':

			Database_get(conn, id);
			
			if (argc != 4)
				die ("Need id to update");


			
			Database_get(conn, id);
			
			printf("Enter Updated Employee name:\n");
			fgets(name_input, MAX_LIMIT, stdin);

			printf("Enter Updated Employee email:\n");
			fgets(email_input, MAX_LIMIT, stdin);

			Database_delete(conn, id);

			Database_set(conn, id, End_line(name_input), End_line(email_input));
			Database_write(conn);
			Database_list(conn, id);	
			break;

		case 'd':
			if (argc != 4)
				die ("Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn, id);
			break;

		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");

	}

	Database_close(conn);

	return 0;

}

// end main









