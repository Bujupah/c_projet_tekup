#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB FILE*
#define STRING char*

#define EMPLOYEE_DB "db/employee.csv"

#define BUFFER_SIZE 1000

void showEmploye(STRING*);
void cliSpace(char, int);

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

void select_all() {
  DB db = fopen(EMPLOYEE_DB, "r");
  char * buffer = 0;
  long length;

  if (db) {
    fseek (db, 0, SEEK_END);
    length = ftell (db);
    fseek (db, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer) {
      fread (buffer, 1, length, db);
    }
    fclose (db);
  }

  STRING* columns = malloc(sizeof(char)*BUFFER_SIZE);
  STRING row = malloc(sizeof(char)*BUFFER_SIZE);
  if (buffer) {
    printf("\t\t");
    for (long i = 0; i < length; i++) {
      if (*(buffer + i - 1) == '\n' || *(buffer + i - 1) == '\0') {
        cliSpace('\n\t', 2);
      }
      printf("%c", *(buffer + i));
    }
    printf("\n");
  }
}

void select_by_id(int id) {
  DB db = fopen(EMPLOYEE_DB, "r");
  int totalRead = 0;
  STRING* columns = malloc(sizeof(char)*BUFFER_SIZE);
  STRING row = malloc(sizeof(char)*BUFFER_SIZE);
  
  while(fgets(row, BUFFER_SIZE, db) != NULL) {
    if (row[0] == 'I') continue;
    totalRead = strlen(row);
    row[totalRead - 1] = row[totalRead - 1] == '\n' ? '\0' : row[totalRead - 1];
    get_col(row, columns);

    int idAsInt = atoi(columns[0]);
    if (id == idAsInt) {
      showEmploye(columns);
      break;
    }

  }
  fclose(db);
}

void select_by_query(int col, STRING query) {
  DB db = fopen(EMPLOYEE_DB, "r");
  int totalRead = 0;
  STRING* columns = malloc(sizeof(char)*BUFFER_SIZE);
  STRING row = malloc(sizeof(char)*BUFFER_SIZE);
  
  while(fgets(row, BUFFER_SIZE, db) != NULL) {
    if (row[0] == 'I') continue;
    totalRead = strlen(row);
    row[totalRead - 1] = row[totalRead - 1] == '\n' ? '\0' : row[totalRead - 1];
    get_col(row, columns);
    if (strcmp(columns[col], query) == 0) {
      showEmploye(columns);
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