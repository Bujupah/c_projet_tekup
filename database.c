#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB FILE*
#define STRING char*

#define EMPLOYEE_DB "db/employee.csv"

#define BUFFER_SIZE 1000

void _initDbHeader() {
    char* row = malloc(sizeof(char) * BUFFER_SIZE);
    sprintf(row, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", 
        "ID", "NOM PRENOM", "POSTE", "SALAIRE", "CREATED DATE", "SEXE", 
        "DEPARTEMENT", "ADRESSE", "TELEPHONE", "EMAIL");
    add_row(row);
}

int get_db_size() {
  DB db = fopen(EMPLOYEE_DB, "r");
  char buffer[BUFFER_SIZE];
  int count = 0;
  while(fgets(buffer, BUFFER_SIZE, db) != NULL)
    count += strlen(buffer);
  return count;
}

int get_id(STRING row) {
  int i = 0;
  char value[32];
  while (i < 32) {
    if (row[i] == ',') break;
    value[i] = row[i];
    i++;
  }
  return atoi( value );
}

void get_col(STRING buffer, STRING* result) {
  STRING splitted = strtok(buffer, ",");
  int i = 0;
  while( splitted != NULL ) {
    result[i] = splitted;
    i++;
    splitted = strtok(NULL, ",");
  }
}

void select_all(STRING* result) {
  DB db = fopen(EMPLOYEE_DB, "r");
  int totalRead = 0;

  int line = 0;
  while(fgets(result[line], BUFFER_SIZE, db) != NULL) {
    totalRead = strlen(result[line]);
    result[line][totalRead - 1] = result[line][totalRead - 1] == '\n' ? '\0' : result[line][totalRead - 1];
    line++;
  }

  fclose(db);
}

void select_by_id(int id, STRING result) {
  DB db = fopen(EMPLOYEE_DB, "r");
  int totalRead = 0;
  while(fgets(result, BUFFER_SIZE, db) != NULL) {
    totalRead = strlen(result);
    result[totalRead - 1] = result[totalRead - 1] == '\n' ? '\0' : result[totalRead - 1];
    if (id == get_id(result)) {
      break;
    }
  }
  fclose(db);
}

void add_row(STRING row) {
  DB db = fopen(EMPLOYEE_DB, "a");
  fputs(row, db);
  fclose(db);
}

void _init_db(STRING db_path) {
  DB db = fopen(db_path, "r");
  if (db == NULL) {
    db = fopen(db_path, "w");
    if (db == NULL) {
      perror("Failed to initialize database!.\n");
      exit(EXIT_FAILURE);
    }
    _initDbHeader();
  }
}

void init_db() {
  _init_db(EMPLOYEE_DB);
}

void current_date(STRING current) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(current, "%d/%d/%d", 
  tm.tm_year + 1900, 
  tm.tm_mon + 1, 
  tm.tm_mday);
}