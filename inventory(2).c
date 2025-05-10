#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int total_custs = 0;
int total_items = 0;
FILE *custs_db;

typedef struct
{
    int c_id;
    char *name;
    char *mail;
    char *phone;
    char *pin;
} customer;

typedef struct
{
    int itm_id;
    char *itm_name;
    char *itm_type;
    char *itm_description;
    int rate;
} items;

customer *custs;
items *itms;

/*manually allocation of memory*/
int id_var = 1;
void add_customer()
{

    char temp[25];
    total_custs++;
    custs = realloc(custs, total_custs * sizeof(customer));

    printf("\nENTER DETAILS:\n1. NAME:\n");
    scanf(" %[^\n]", temp);
    custs[total_custs - 1].name = (char *)malloc(strlen(temp) + 1);
    strcpy(custs[total_custs - 1].name, temp);

    printf("\n2. ENTER MAIL:\n");
    scanf(" %[^\n]", temp);
    custs[total_custs - 1].mail = (char *)malloc(strlen(temp) + 1);
    strcpy(custs[total_custs - 1].mail, temp);

    printf("\n3. ENTER PHONE:\n");
    scanf(" %[^\n]", temp);
    custs[total_custs - 1].phone = (char *)malloc(strlen(temp) + 1);
    strcpy(custs[total_custs - 1].phone, temp);

    printf("\n4. ENTER PIN:\n");
    scanf(" %[^\n]", temp);
    custs[total_custs - 1].pin = (char *)malloc(strlen(temp) + 1);
    strcpy(custs[total_custs - 1].pin, temp);

    custs[total_custs - 1].c_id = 1000 + id_var;
    fopen();



    id_var++;
}

void view_customers()
{
    for (int i = 0; i < total_custs; i++)
    {
        printf("%-5d %-5s %-5s %-5s %-5s\n", custs[i].c_id, custs[i].name, custs[i].mail, custs[i].phone, custs[i].pin);
    }
}

void remove_customer()
{
    char del_var[30];
    char id_var[10];
    int id_del;
    int i = 0;
    printf("ENTER THE NAME OF THE CUSTOMER YOU WANT TO REMOVE:\n");
    scanf(" %[^\n]", del_var);
    for (i; i < total_custs; i++)
    {
        if (strcmp(del_var, custs[i].name) == 0)
            printf("%-5d %-5s %-5s %-5s %-5s\n", custs[i].c_id, custs[i].name, custs[i].mail, custs[i].phone, custs[i].pin);
    }
    printf("ENTER THE ID OF THE CUSTOMER YOU WANT TO DELETE:\n");
    scanf(" %d", &id_del);
    for (int i = 0; i < total_custs; i++)
    {
        if (id_del == custs[i].c_id)
        {
            free(custs[i].name);
            free(custs[i].mail);
            free(custs[i].phone);
            free(custs[i].pin);

            /*assigning values from i+1 to i*/
            for (int j = i; j < total_custs; j++)
            {
                custs[j] = custs[j + 1];
            }
        }
    }
    total_custs--;
    custs = realloc(custs, total_custs * sizeof(customer));
    printf("CUSTOMER DELETED.");
}

void add_items()
{

    char temp[25];
    total_items++;
    itms = realloc(itms, total_items * sizeof(items));

    printf("ENTER ITEM NAME:\n");
    scanf(" %[^\n]", temp);
    itms[total_items - 1].itm_name = (char *)malloc(strlen(temp) + 1);
    strcpy(itms[total_items - 1].itm_name, temp);

    printf("ENTER ITEM DESCRIPTION:\n");
    scanf(" %[^\n]", temp);
    itms[total_items - 1].itm_description = (char *)malloc(strlen(temp) + 1);
    strcpy(itms[total_items - 1].itm_description, temp);

    printf("ENTER ITEM TYPE:\n");
    scanf(" %[^\n]", temp);
    itms[total_items - 1].itm_type = (char *)malloc(strlen(temp) + 1);
    strcpy(itms[total_items - 1].itm_type, temp);

    printf("ENTER ITEM RATE:\n");
    scanf("%d", &itms[total_items - 1].rate);

    itms[total_items - 1].itm_id = total_items;
}

void view_items()
{
    for (int i = 0; i < total_items; i++)
    {
        printf("%d\t%s\t%s\t%s\t%d\n", itms[i].itm_id, itms[i].itm_name, itms[i].itm_description, itms[i].itm_type, itms[i].rate);
    }
}

/*ADMIM
  ACCESS
  FUNCTION
*/
void admin_access()
{
    /*In Admin access function, We need to implement:
    Adding Customers.
    Deleting Customers.
    Adding Items to Inventory.
    View Orders function
    View all customers
    */
    int swch_var;
    while (1)
    {
        printf("SELECT OPTION:\n1. ADD CUSTOMER\n2. REMOVE CUSTOMER\n3. ADD ITEMS\n4. VIEW ITEMS\n5. VIEW ALL CUSTOMERS\n6. RETURN TO LOGIN\n");
        scanf("%d", &swch_var);
        switch (swch_var)
        {
        case 1:
            add_customer();
            break;

        case 2:
            remove_customer();
            break;
        case 3:
            add_items();
            break;
        case 4:
            view_items();
            break;
            /*view_orders();
             break;*/
        case 5:
            view_customers();
            break;
        case 6:
            return;
            /*default:
                printf("EXITING...");
                exit(0);
               break;
            }*/
        }
    }
}

void place_order()
{
    int Q;
    int id;
    view_items();
    printf("SELECT YOUR ITEM BY ENTERING ID: ");
    scanf("%d", &id);
    printf("ENTER THE QUANTITY OF YOUR ITEM: ");
    scanf("%d", &Q);
    printf("YOUR TOTAL IS %d", itms[id].rate*Q);
    printf("YOUR ORDER WAS PLACED SUCESSFULLY!");


}

void customer_access()
    /*
    In Customer access function, We need to implement:
    Checkout.
    Updating Customers.
    Order History of the Customer.

    */
    
{
    int swch;
    while (1)
    {
        printf("\nSELECT OPTION:\n1. PLACE YOUR ORDER \n2. UPDATE YOUR DETAILS\n 3. YOUR ORDER HISTORY");
        scanf("%d", &swch);
        switch (swch)
    {
    case 1:
        place_order();
        break;

    default:
        break;
    }
    }

    
}

int main()
{

    int swch_var;
    char pin[10];
    char passkey[9] = "adminkey";
    char password[20];
    char mail[100];
    while (1)
    {
        printf("\nPLEASE LOGIN: SELECT OPTION\n1. CUSTOMER LOGIN\n2. ADMIN LOGIN\nTO EXIT, PRESS ANY KEY.");
        scanf("%d", &swch_var);

        switch (swch_var)
        {
        case 1:
            printf("ENTER MAIL: ");
            scanf(" %[^\n]", mail);

            for (int i = 0; i <= total_custs; i++)
            {
                if (strcmp(mail, custs[i].mail) == 0)
                {
                    printf("ENTER PIN: ");
                    scanf(" %[^\n]", pin);
                    if (strcmp(pin, custs[i].pin) == 0)
                    {
                        customer_access();
                    }
                    else
                    {
                        printf("WRONG PIN");
                        break;
                    }
                }
                else
                {
                    printf("CUSTOMER NOT FOUND.");
                }
                break;
            }

        case 2:
            printf("ENTER ADMIN PASSKEY: \n");
            scanf(" %[^\n]", password);
            if (strcmp(password, passkey) == 0)
            {
                admin_access();
            }
            else
            {
                printf("WRONG KEY.");
            }
            break;
        default:
            exit(0);
        }
    }

    return 0;
}