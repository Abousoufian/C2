#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 255

typedef enum{
    FALSE,
    TRUE
} boolean;

typedef enum{
    T_int,
    T_float,
    T_string,
    T_boolean
} Type;

union format{
    int i;
    float f;
    char *s;
    boolean b;
};

struct header{
    Type type;
    char *name;
    struct header *next;
};

struct data{
    Type type;
    union format data;
    struct data *next;
};

struct lines{
    struct lines *prev;
    struct data *data;
    struct lines *next;
};

struct lines_H{
    struct header *header;
    struct lines *next;
};

char length_string(char *input);
struct header* create_header(int columns, char *input, char delimiter[2], char *format);
struct lines* create_line(struct lines_H* head, char *input, char delimiter[2]);
struct data* create_data(struct header* head, char *input, char delimiter[2]);
void print_header (struct header* head);
void print_line (struct lines* head);
void free_structs (struct lines_H* head);
int array_lenght(char *array);
void create_file(char *filename, int colums, char delimiter, char *format);
void import_file(FILE *fl, int colums, char delimiter[2], char *format);

int main(int argc, char *argv[] )
{
    int columns = 0;
    FILE *fl = NULL;
    char search[4][6] = {".csv","-d","-c","-f"};
    char *file_name = NULL;
    char delimiter[2] = ";\0";
    char *format = NULL;
    char input[MAXCHAR]= {0};
    struct lines_H* header = NULL;
    struct lines* current = NULL;

    header = (struct lines_H*)malloc(sizeof (struct lines_H));
    header->header = NULL;
    header->next = NULL;

    printf("start\n");

    for(int i = 0; i<argc; i++)
    {
        if (strstr(argv[i], search[0]) != NULL)
        {
            file_name = argv[i];
            printf("file %s found\n", file_name);
        }
        else if (strstr(argv[i], search[1]) != NULL)
        {
            delimiter[0]= argv[i+1][0];
            printf("delimiter is %c\n", delimiter[0]);
        }
        else if (strstr(argv[i], search[2]) != NULL)
        {
            columns = atoi(argv[i+1]);
            printf("%d colom(men)\n", columns);
        }
        else if (strstr(argv[i], search[3]) != NULL)
        {
            format = argv[i+1];
            printf("format is %s\n", format);
        }
    }
    printf("flags ingeladen\n");
    if (file_name == NULL)
    {
        printf("Wat is de bastands Naam? ");
        gets(input);
        file_name = (char*)calloc(array_lenght(input),sizeof (char));
        strcpy(file_name,input);
    }

    while (strstr(file_name, search[0]) == NULL)
    {
        printf("Dit is een ongeldige bestands naam Gelieve een geldige naam in te geven. ");
        gets(input);
        free(file_name);
        file_name = (char*)calloc(array_lenght(input),sizeof (char));
        strcpy(file_name,input);
    }

    fl = fopen(file_name, "r");


    if (fl == NULL)
    {
//        create_file();
        printf("file niet gevonden\n");
    }
    else
    {
        printf("file opend succesvol\n");
//        import_file(fl,columns,delimiter,format);
        fgets(input,MAXCHAR,fl);
        header->header = create_header(columns,input,delimiter,format);
        fgets(input,MAXCHAR,fl);
        header->next = create_line(header,input,delimiter);
        current = header->next;

        while (feof(fl) == 0)
        {
            fgets(input,MAXCHAR,fl);
            current->next = create_line(header,input,delimiter);
//            print_line(current->next);
            current = current->next;
        }
        printf("input done\n");
    }
    print_header(header->header);
    print_line(header->next);
    free(header);
    free(file_name);
    fclose(fl);
}

struct header* create_header(int columns, char *input, char delimiter[2], char *format)
{
    struct header *first = NULL;
    struct header *pt = NULL;
    char *split = NULL;

    first = (struct header*) malloc(sizeof(struct header));
    pt = first;
    pt->next = NULL;
    split = strtok(input,delimiter);
    for (int i = 0; i< columns; i++)
    {
        if (i != 0)
        {
            pt->next = (struct header*) malloc(sizeof(struct header));
            pt = pt->next;
            pt->next = NULL;
            split = strtok(NULL,delimiter);
        }

        if (split != NULL)
        {
            for(int i = 0; i<length_string((split));i++)
            {
                if(split[i] == '\n')
                {
                    split[i]='\0';
                }
            }
//            printf("%s\n",split);
            pt->name = (char*)calloc(length_string(split),sizeof (char));
            strcpy(pt->name,split);
        }

        switch (format[i])
        {
            case 'i':
                pt->type = T_int;
                break;
            case 'r':
                pt->type = T_float;
                break;
            case 's':
                pt->type = T_string;
                break;
            case 'b':
                pt->type = T_boolean;
                break;
            default:
                printf("dit is geen geldig type.");
                break;
        }
    }
    return first;
}

struct lines* create_line(struct lines_H* head, char *input, char delimiter[2])
{
    struct lines *pt_head = NULL;

    pt_head = (struct lines*)malloc(sizeof (struct lines));
    pt_head->data = create_data(head->header, input, delimiter);
    pt_head->next = NULL;

    return pt_head;
}

struct data* create_data(struct header* head, char *input, char delimiter[2])
{
    struct data* first = NULL;
    struct data* current = NULL;
    boolean first_boolean = TRUE;
    boolean placeholder = 0;
    char *split = NULL;

    first = (struct data*)malloc(sizeof (struct data));
    current = first;
    split = strtok(input,delimiter);
    current->next = NULL;

    while(head != NULL)
    {
        if(first_boolean != TRUE)
        {
            current->next = (struct data*)malloc(sizeof (struct data));
            current = current->next;
            current->next = NULL;
            split = strtok(NULL,delimiter);
        }

        if (split != NULL)
        {
            for(int i = 0; i<length_string((split));i++)
            {
                if(split[i] == '\n')
                {
                    split[i]='\0';
                }
            }
        }

        current->type = head->type;

        switch (current->type)
        {
            case T_int:
                current->data.i = atoi(split);
                break;
            case T_float:
                current->data.f = atof(split);
                break;
            case T_string:
                current->data.s = (char*)calloc(length_string(input),sizeof (char));
                strcpy(current->data.s,split);
                break;
            case T_boolean:
                if (atoi(input) !=0 || atoi(split) != 1 )
                {
                    placeholder = 0;
                }
                else
                {
                    placeholder = atoi(split);
                }
                current->data.b = placeholder;
                break;
            default:
                printf("ERROR bij gegevens toevoegen");
                break;
        }
        first_boolean = FALSE;
        head = head->next;
    }

    return first;
}

char length_string(char *input)
{
    int counter = 0;

    while(input[counter] != '\0')
    {
        counter ++;
    }

    return counter;
}

void print_header (struct header* head)
{
    printf("%c",179);
    while (head != NULL)
    {
        printf("\t%s\t%c",head->name,179);
//        switch (head->type)
//        {
//            case T_int:
//                printf("T: integer\t%c",179);
//                break;
//            case T_float:
//                printf("T: float\t%c",179);
//                break;
//            case T_string:
//                printf("T: string\t%c",179);
//                break;
//            case T_boolean:
//                printf("T: boolean\t%c",179);
//                break;
//        }
        head = head->next;
    }
    printf("\n");
}

void print_line (struct lines* head)
{
    struct data *data = NULL;


    while (head != NULL)
    {
        data = head->data;
        while (data != NULL)
        {
            switch (data->type)
            {
                case T_int:
    //                printf("T: integer\t%c",179);
                    printf("\t %d \t%c",data->data.i,179);
                    break;
                case T_float:
    //                printf("T: float\t%c",179);
                    printf("\t %f \t%c",data->data.f,179);
                    break;
                case T_string:
    //                printf("T: string\t%c",179);
                    printf("\t %s \t%c",data->data.s,179);
                    break;
                case T_boolean:
    //                printf("T: boolean\t%c",179);
                    if(data->data.b == TRUE)
                    {
                        printf("\t TRUE \t%c",179);
                    }
                    else
                    {
                        printf("\t FALSE \t%c",179);
                    }
                    break;
                default:
                    printf("ERROR bij printen data");
                    break;
            }
//            printf("%p",data->next);
            data = data->next;
        }
//        printf("%p",head->next);
        head = head->next;
        printf("\n");
    }
}

void free_structs (struct lines_H* head)
{
    struct header *pt_H = NULL;
    struct header *pt_H_next = NULL;
    struct lines *pt_L =NULL;
    struct lines *pt_L_next =NULL;
    struct data *pt_D =NULL;
    struct data *pt_D_next =NULL;

    pt_H = head->header;
    pt_H_next = pt_H->next;
    while (pt_H != NULL)
    {
        free (pt_H->name);
        free (pt_H);
        pt_H = pt_H_next;
        pt_H_next = pt_H->next;
    }

    pt_L = head->next;
    pt_L_next = pt_L->next;
    pt_D = pt_L->data;
    pt_D_next = pt_D->next;
    while (pt_L != NULL)
    {
        while (pt_D != NULL)
        {
            if (pt_D->type == T_string)
            {
                free (pt_D->data.s);
            }
            free(pt_D);
            pt_D = pt_D_next;
            pt_D_next = pt_D->next;
        }
        free(pt_L);
        pt_L=pt_L_next;
        pt_L_next = pt_L->next;
    }
}

int array_lenght(char *array)
{
    int counter = 0;
    while(array[counter] != '\0')
    {
        counter ++;
    }
    return counter;

}
