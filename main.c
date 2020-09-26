#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phonebook{
char* name[50];
char* numb[50];
int numofent;

}phonebook;
void insert(phonebook* first , char person[] , char numb[]);
void initialize (phonebook* first);
void print(phonebook* first);
char* search(phonebook *first , char name [] );
void destruct(phonebook *first);
int main()
{phonebook first;

initialize(&first);
insert(&first , "daniel" , "+36 30 510 47-24");
insert(&first , "marija" , "+36 40 510 47-24");
insert(&first , "kinga" , "+36 50 510 47-24");
insert(&first , "stef" , "+36 60 510 47-24");
insert(&first , "stef" , "+36 60 510 47-24");
print(&first);
printf("%s\n" , search(&first , "stef"));
destruct(&first);
    return 0;
}
void initialize(phonebook* first){
first->numofent = 0;

}

void insert(phonebook* first , char *person , char *numb){
first->name[first->numofent] = malloc(sizeof(char)*strlen(person)+1);
first->numb[first->numofent] = malloc(sizeof(char)*strlen(numb)+1);
strcpy(first->name[first->numofent] , person);
strcpy(first->numb[first->numofent] , numb);
first->numofent++;

}

void print(phonebook *first){
    int i = 0;
for(i ; i < first->numofent ; i++){
    printf("%s \t %s\n" , first->name[i] , first->numb[i]);
}

}
char* search(phonebook *first , char name [] ){

    for(int i = 0 ; i < first->numofent ; i++){
        if(strcmp(first->name[i],name) == 0){
            return (first->numb[i]);
        }
    }
    return "0";


}
void destruct(phonebook *first){
free(first);
first->numofent = 0;

}

