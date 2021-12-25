#define EmployeStruct struct Employe;

struct Employe
{
    int id;
    char nom[100];
    char poste[10];
    float sal;
    char sexe[10];
    char departement[50];
    char addr[200];
    char phone[15];
    char mail[20];
    char created_at[12];
};

STRING employeToCsvRow(struct Employe *emp) {
    STRING date = malloc(sizeof(char) * 100);
    current_date(date);

    char* row = malloc(sizeof(char) * BUFFER_SIZE);
    sprintf(row, "\n%d,%s,%s,%f,%s,%s,%s,%s,%s,%s", 
    (*emp).id, 
    (*emp).nom, 
    (*emp).poste, 
    (*emp).sal, 
    date,
    (*emp).sexe, 
    (*emp).departement, 
    (*emp).addr, 
    (*emp).phone, 
    (*emp).mail);
    return row;
}

// struct Employe* get_employee_by_id(int id) {
//     STRING buffer = malloc(sizeof(char)*BUFFER_SIZE);
//     select_by_id(2, buffer);

//     struct Employe*employee = malloc(sizeof(struct Employe) * 1);
//     (*employee).id = get_id(buffer);

//     STRING* columns = malloc(sizeof(char)*BUFFER_SIZE);
//     get_col(buffer, columns);

//     // (*employee).id = get_id(buffer);
//     // // (*employee).id = columns[1];
//     // (*employee).nom = columns[2];
//     // (*employee).poste = columns[3];
//     // // (*employee).sal = columns[4];
//     // (*employee).jdate = columns[5];
//     // (*employee).sexe = columns[6];
//     // (*employee).departement = columns[7];
//     // (*employee).addr = columns[8];
//     // (*employee).phone = columns[9];
//     // (*employee).mail = columns[10];

//     // return product;
// }