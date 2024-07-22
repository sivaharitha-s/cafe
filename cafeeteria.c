#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

// Structure for items
struct Item
{
    char name[40];
    float rating;
    float price;
    int food_ID_No;
    struct Item *next;
    struct Item *prev;
};

int cust_id = 1;
struct Item *head;
struct Item *last;
int Today_customer = 0;
float total_income;

// Structure for order history
struct order_hist
{
    int customer_ID;
    int items[10][2];
    float amount;
    char date[11]; 
    struct order_hist *next;
    struct order_hist *prev;
};

struct order_hist *head1;
struct order_hist *last1;

// Function to create a new node for items
struct Item *getnewNode(char a[], float p, int fin)
{
    struct Item *temp = (struct Item *)malloc(sizeof(struct Item));
    temp->food_ID_No = fin;
    strcpy(temp->name, a);
    temp->rating = 4.0;
    temp->price = p;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to insert a new item
int insert(char n[], float p, int fin)
{
    struct Item *temp1 = getnewNode(n, p, fin);
    if (head == NULL)
    {
        head = temp1;
        last = temp1;
    }
    else
    {
        temp1->prev = last;
        last->next = temp1;
        last = temp1;
    }
}

// Function to display the menu
int display()
{
    printf("                                                      --------------------                                              \n");
    printf("-------------------------------------------------------------MENU-------------------------------------------------------\n");
    printf("                                                      --------------------                                              \n");
    printf("INDEX       ITEM NAME        PRICE      RATINGS\n ");
    struct Item *temp = head;
    if (head == NULL)
    {
        printf("empty");
    }
    while (temp != NULL)
    {
        printf("%d\t%s\t%f\t%f\t%f\n", temp->food_ID_No, temp->name, temp->price, temp->rating);
        temp = temp->next;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

// Function for login
int login()
{
    char username[30];
    char userpwd[20];
    int i;
    printf("enter your username");
    scanf("%d", username);
    printf("enter your password");
    for (i = 0; i < 10; i++)
    {
        userpwd[i] = getch();
        printf("*");
    }
    userpwd[i] = '\0';
    if (!strcmp(username, "Admin") && !strcmp(userpwd, "haritha"))
    {
        printf("\n\n logged in successfully\n");
        return 1;
    }
    else
    {
        printf("\n incorrect username or password\n");
        return 0;
    }
}

// Function for placing an order
void order()
{
    int a[10][2];
    int n, j = 0, i = 0;
    do
    {
        printf("please enter the food id number and its quantity");
        for (i = 0; i < 2; i++)
        {
            scanf("%d", &a[j][i]);
        }
        j++;
        printf("you want more item \n1.yes\n2.no");
        scanf("%d", &n);
    } while (n == 1);

    float total_amount = 0.0;
    char name[25];
    char Date[11];
    printf("enter your name :");
    scanf("%s", &name);
    printf("enter todays Date :");
    scanf("%s", &Date);
    int k = 0;

    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                             BILL                                                                           \n");
    printf("name:-%s \n", name);
    printf("date:-%s \n", Date);
    for (k = 0; k < j; k++)
    {
        struct Item *temp = head;
        while (temp->food_ID_No != a[k][0])
        {
            temp = temp->next;
        }
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%d\t%f\t", temp->food_ID_No, temp->name, a[k][1], (a[k][1] * (temp->price)));
        total_amount += (a[k][1] * (temp->price));
    }
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n total payble amount is:-\t\t%f\n", total_amount);
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    struct order_hist *temp2 = (struct order_hist *)malloc(sizeof(struct order_hist));
    temp2->amount = total_amount;
    temp2->customer_ID = cust_id++;

    int p, s;
    for (p = 0; p < j; p++)
    {
        for (s = 0; s < 2; s++)
        {
            temp2->items[p][s] = a[p][s];
        }
    }

    if (head1 == NULL)
    {
        head1 = last1 = temp2;
    }
    else
    {
        last1->next = temp2;
        temp2->prev = last1;
        last1 = temp2;
    }
    strcpy(temp2->date, Date);
    Today_customer++;
    total_income += total_amount;
}

// Function to display order history
void display_rd_hist()
{
    printf("                                    ------------------                                                             \n");
    printf("\n------------------------------------ORDER HISTORY----------------------------------------------------------------\n");
    printf("                                   -------------------                                                             \n");
    printf("SR_NO       DATE      TOTAL AMOUNT \n");

    struct order_hist *temp = head1;
    if (head1 == NULL)
    {
        printf("Empty");
    }

    while (temp != NULL)
    {
        printf("%d\t%s\t%f\t\n", temp->customer_ID, temp->date, temp->amount);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    last = NULL;

    insert("Burger ", 70.23, 1);
    insert("Pizza",   235.67, 6);
    insert("Hot Cake ",  750.63, 10);
    insert("Coffee ",  70.24, 2);
    insert("Ice-cream",  70.23, 3);
    insert("Sandwich",  60.23, 4);
    insert("Grill",  52.29, 7);
    insert("Nun-Bread",  35.13, 8);
    insert("Cold Drinks",  20.13, 9);

    int choice;

    do
    {
        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("\n1.....FOOD PART");
        printf("\n2.....ADMIN PANEL");
        printf("\n3..... EXIT ");

        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("");
            int ex;

            do
            {
                printf("1.      FOOD LIST\n2.             ORDER\n");
                int n;
                scanf("%d", &n);

                switch (n)
                {
                case 1:
                    display();
                    break;
                case 2:
                    order();
                    break;
                }

                printf("FOOD PART\n2.MAIN MENU\n");
                scanf("%d", &ex);
            } while (ex == 1);
            break;

        case 2:
            printf("\n");
            int k = login();
            int e;
            if (k == 1)
            {

                do
                {
                    printf("--------------------------------------------------------------------------------------------------\n");
                    printf("1.      ADD NEW DISH\n");
                    printf("2.      TODAYS TOTAL INCOME\n");
                    printf("3.      TODAY TOTAL NO OF CUSTOMER\n");
                    printf("4.      ORDER HISTORY\n");
                    printf("5.      LIST OF ITEM\n");
                    printf("\n----------------------------------------------------------------------------------------------------\n");

                    int ch;
                    scanf("%d", &ch);
                    switch (ch)
                    {
                    case 1:
                        printf(" ");
                        float p;
                        int fin;
                        char n[50];

                        printf("Enter the name of Item");
                        scanf("%s", n);

                        printf("Enter the price of Item");
                        scanf("%f", &p);

                        printf("Enter the food_id_no of item");
                        scanf("%d", &fin);

                        insert(n, p, fin);
                        printf("------------------------------------------------------------------------------------------------\n");
                        printf("                      NEW DISH IS ADDED SUCCESSFULLY.........\n");
                        printf("--------------------------------------------------------------------------------------------------\n");
                        printf("\n");
                        break;
                    case 2:
                        printf("------------------------------------------------------------------------------------------------\n");
                        printf("                      TODAYS TOTAL INCOME IS :-%f\n", total_income);
                        printf("--------------------------------------------------------------------------------------------------\n");
                        printf("\n");
                        break;

                    case 3:
                        printf("------------------------------------------------------------------------------------------------\n");
                        printf("                      TODAYS TOTAL NO OF TH CUSTOMER VISITED ID:-%d\n", Today_customer);
                        printf("--------------------------------------------------------------------------------------------------\n");
                        printf("\n");
                        break;

                    case 4:
                        printf("------------------------------------------------------------------------------------------------\n");
                        printf("                                ORDER SUMMARY                                                    \n");
                        printf("-------------------------------------------------------------------------------------------------\n");
                        display_rd_hist();
                        printf("\n");
                        break;

                    case 5:
                        printf("\n");
                        display();
                        break;
                    }
                } while (e == 1);
            }
            break;

        case 3:
            // Exit the program
            printf("Exiting...\n");
            return 0;
        }
    } while (1);

    return 0;
}
