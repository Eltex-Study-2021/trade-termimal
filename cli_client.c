#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char assortment[][10] = {"Snickers", "KitKat", "Milky Way", "Mars", "Water", "Cookie", "Lemonade", "Gum", "Juice", "Waffles"};
int price[10] = {60, 49, 35, 38, 20, 69, 40, 15, 100, 76};
int q_arr[10];

int menu()
{
    int n;
    puts("1. Assortment\n2. Buy\n");
    scanf("%d", &n);
    return n;
}

void printCli()
{

}

int main(void)
{
    srand(time(NULL));
    const int n = 10;
    int count;
    char name[20];
    int quantity = 0, result;
    int w_num = 3, w_name = 22, w_qua = 10, w_price = 9;

    for(int i = 0; i < n; i++)
    {
        q_arr[i] = rand() % 20 + 3;
    }

    do
    {
        count = menu();
        switch(count)
        {
            case 1:
                puts(" ________________________________________________");
                puts("|   |                      |          |         |");
                puts("| № |         Name         | Quantity |  Price  |");
                puts("|___|______________________|__________|_________|");
 
                for(int i = 0; i < n; i++)
                {
                    printf("|%*d|%*s|%*d|%*d|\n", w_num, i, w_name, assortment[i], w_qua, q_arr[i], w_price, price[i]);
                }
                puts(" ________________________________________________");

                break;
            case 2:
                puts("\nEnter product name: ");
                gets(name);
                gets(name);
                puts("\nEnter quantity: ");
                scanf("%d", &quantity);
                for(int i = 0; i < n; i++)
                {
                    if((strcmp(name, assortment[i]) == 0) && (quantity <= q_arr[i]))
                    {
                        q_arr[i] -= quantity;
                        result = quantity * price[i];
                        printf("\nYour purchase: %d x %s - %d | =%d\n", quantity, assortment[i], price[i], result);
                    }
                    else if(strcmp(name, assortment[i]) == 1)
                    {
                        printf("No such product\n");
                    }
                    else if(quantity > q_arr[i])
                    {
                        printf("Out of stock\n");
                    }
                }

                break;
            default:
                break;
        }
    }while(count != 3);

    getchar();
    return 0;
}
