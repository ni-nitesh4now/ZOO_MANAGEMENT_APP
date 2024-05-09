/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATABASE_FILE "db.txt"
#define MAX_LINE_LENGTH 100

int MaxSize = 0;
typedef struct {
    int k;
    char val[MAX_LINE_LENGTH];
} Keyval;
Keyval *database = NULL;

void put(int k, char *val);
void get(int k);
void delete(int k);
void clear();
void all();
void loadDatabase();
void saveDatabase();
void commands(char *command);


int main(int argc, char *argv[]) {
    loadDatabase();

    // Process command-line arguments
    for (int i = 1; i < argc; i++) {
        commands(argv[i]);
    }

    saveDatabase();
    free(database);

    return 0;
}



void put(int k, char *val) {
    for (int i = 0; i < MaxSize; i++) {
        if (database[i].k == k) {
            printf("key %d already exists. Updating val.\n", k);
            strcpy(database[i].val, val);
            return;
        }
    }

    database = realloc(database, (MaxSize + 1) * sizeof(Keyval));
    if (database == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    database[MaxSize].k = k;
    strcpy(database[MaxSize].val, val);
    MaxSize++;
}

void get(int k) {
    for (int i = 0; i < MaxSize; i++) {
        if (database[i].k == k) {
            printf("%d,%s\n", database[i].k, database[i].val);
            return;
        }
    }
    printf("Key %d not found\n", k);
}

void delete(int k) {
    for (int i = 0; i < MaxSize; i++) {
        if (database[i].k == k) {
            // Shift elements to overwrite the deleted entry
            for (int j = i; j < MaxSize - 1; j++) {
                database[j] = database[j + 1];
            }
            MaxSize--;
            return;
        }
    }
    printf("Key %d not found\n", k);
}

void clear() {
    free(database);
    database = NULL;
    MaxSize = 0;
}

void all() {
    for (int i = 0; i < MaxSize; i++) {
        printf("%d,%s\n", database[i].k, database[i].val);
    }
}

void loadDatabase() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        return;
    }
    int k;
    char val[MAX_LINE_LENGTH];
    while (fscanf(file, "%d,%s", &k, val) == 2) {
        put(k, val);
    }
    fclose(file);
}

void saveDatabase() {
    FILE *file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        printf("Error: Unable to save database\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MaxSize; i++) {
        fprintf(file, "%d,%s\n", database[i].k, database[i].val);
    }
    fclose(file);
}

void commands(char *cmd) {
    char *symbol;
    symbol = strtok(cmd, ",\n");
    if (symbol == NULL) {
        printf("Bad command\n");
        return;
    }

    if (strcmp(symbol, "p") == 0) {
        int k = atoi(strtok(NULL, ","));
        char *val = strtok(NULL, ",");
        if (val == NULL) {
            printf("Bad command\n");
            return;
        }
        put(k, val);
    } else if (strcmp(symbol, "g") == 0) {
        int k = atoi(strtok(NULL, ","));
        get(k);
    } else if (strcmp(symbol, "d") == 0) {
        int k = atoi(strtok(NULL, ","));
        delete(k);
    } else if (strcmp(symbol, "c") == 0) {
        clear();
    } else if (strcmp(symbol, "a") == 0) {
        all();
    } else {
        printf("Bad command\n");
    }
}