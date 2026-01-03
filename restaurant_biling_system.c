#include <stdio.h>

#define GST 0.18
#define SIZE 5

// Arrays for Menu
char items[][25] = {"Burger", "Pizza", "Sandwich", "Coffee", "Ice Cream"};
float prices[] = {120, 200, 90, 60, 80};

// Function Declarations
void showMenu();
float takeOrder();

int main() {

    printf("===== SIMPLE RESTAURANT BILLING SYSTEM =====\n");

    showMenu();

    float subtotal = takeOrder();
    float gst = subtotal * GST;
    float total = subtotal + gst;

    printf("\n--------- FINAL BILL ---------\n");
    printf("Subtotal : Rs %.2f\n", subtotal);
    printf("GST 18%% : Rs %.2f\n", gst);
    printf("Total   : Rs %.2f\n", total);
    printf("--------------------------------\n");

    return 0;
}

// Function to display menu
void showMenu() {
    printf("\nAvailable Menu Items:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d. %-12s Rs %.2f\n", i+1, items[i], prices[i]);
    }
}

// Function to accept orders
float takeOrder() {
    int choice, qty;
    float subtotal = 0;
    char more;

    do {
        printf("\nEnter item number: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > SIZE) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        subtotal += prices[choice-1] * qty;

        printf("Add more items? (y/n): ");
        scanf(" %c", &more);

    } while(more == 'y' || more == 'Y');

    return subtotal;
}