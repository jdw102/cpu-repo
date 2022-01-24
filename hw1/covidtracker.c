#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person {
    char *name;
    char *a[2];
    struct person* next; 
};

bool search(struct person* head, char target[]){
    while (head != NULL){
        if (strcmp(target, head->name) == 0){
            return true;
        }
        head = head->next;
    }
    return false;
}

void mutate(struct person* head, char target[], char victim[]){
    while(head != NULL){
        if(strcmp(target, head->name) == 0){
            if (head->a[0] = NULL){
                head->a[0] = victim;
            }
            else if(strcmp(head->a[0], victim) > 0){
                char* temp;
                temp = head->a[0];
                head->a[0] = victim;
                head->a[1] = temp;
            }
            else {
                head->a[1] = victim;
            }
        }
        head = head->next;
    }
}

void printlist(struct person* head){
    while (head != NULL){
        printf("%s %s %s\n", head->name, head->a[0], head->a[1]);
        head = head->next;
    }
}


int main(int argc, char* argv[]){
        char* filename = argv[1];
        FILE *f1 = fopen(filename, "r");
        if (f1 == NULL){
            printf("ERROR: COULD NOT OPEN FILE");
            return 1;
        }
        int size = 0;
        struct person* final = NULL;
        struct person* previous = NULL;
        char c;
        while (true){
            char currname[30] = "";
            int i = 0;
            for (c=getc(f1); c != EOF; c = getc(f1)){
                if (c == ' ' || c == '\n'){
                    i = 0;
                    break;
                }
                currname[i] = c;
                i++;

            }
            if (strcmp(currname, "DONE") == 0){
                final = previous;
                break;
            }
            struct person* p = (struct person*) malloc(sizeof(struct person*));
            if (c == ' '){
                if (search(previous, currname) == true){
                    continue;
                }
                else{
                    strcpy(p->name, currname);
                }
            }
            if (c == '\n'){
                if (search(previous, currname) == true){
                    mutate(previous, currname, previous->name);
                }
                else{
                    p->name = currname;
                    p->a[0] = previous->name;
                }
            }
            p->next = previous;
            previous = p;
        }
        printlist(final);
        return 0;  
}



void sortlist(struct person* head){

}
