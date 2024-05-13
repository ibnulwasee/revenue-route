#include <stdio.h>
#include <string.h>

#define MAX_SALES_DATA 100
#define MAX_EXPENSES 100

// Arrays to store expense data
double expenses[MAX_EXPENSES];
char expense_category[MAX_EXPENSES][50];
int expense_count = 0;

// Function prototypes
void calculate_revenue();
void calculate_gross_profit_loss();
void record_expense();
void display_total_expenses();
void calculate_operating_profit();
void calculate_tax_liabilities();
void calculate_net_profit();
void calculate_discount();
void future_growth_analysis();
void gross_profit_margin_analysis();

// Main function to display menu and handle user choices
int main() {
    int choice;

    while (1) {
        printf("\n--- Business Growth Calculator ---\n\n");
        printf("1. Calculate Revenue\n");
        printf("2. Calculate Gross Profit/Loss & Percentage\n");
        printf("3. Record Expenses\n");
        printf("4. Display Total Expenses\n");
        printf("5. Calculate Operating Profit\n");
        printf("6. Calculate Tax Liabilities\n");
        printf("7. Calculate Net Profit\n");
        printf("8. Discount Calculator\n");
        printf("9. Future Growth Analysis\n");
        printf("10. Gross Profit Margin Analysis\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_revenue();
                break;
            case 2:
                calculate_gross_profit_loss();
                break;
            case 3:
                record_expense();
                break;
            case 4:
                display_total_expenses();
                break;
            case 5:
                calculate_operating_profit();
                break;
            case 6:
                calculate_tax_liabilities();
                break;
            case 7:
                calculate_net_profit();
                break;
            case 8:
                calculate_discount();
                break;
            case 9:
                future_growth_analysis();
                break;
            case 10:
                gross_profit_margin_analysis();
                break;
            case 11:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

// Function to calculate revenue
void calculate_revenue() {
    double cost_per_unit, selling_price_per_unit;
    int units_in_stock, units_sold;

    printf("Enter cost per unit: ");
    scanf("%lf", &cost_per_unit);
    printf("Enter selling price per unit: ");
    scanf("%lf", &selling_price_per_unit);
    printf("Enter units in stock: ");
    scanf("%d", &units_in_stock);
    printf("Enter units sold: ");
    scanf("%d", &units_sold);

    double total_revenue_earned = selling_price_per_unit * units_sold;
    double projected_total_revenue = selling_price_per_unit * (units_in_stock);

    printf("Total revenue earned so far: %.2f\n", total_revenue_earned);
    printf("Projected total revenue: %.2f\n", projected_total_revenue);
}

// Function to calculate gross profit/loss
void calculate_gross_profit_loss() {
    double cost, selling_price;
    int units_in_stock, units_sold;

    printf("Enter cost per unit: ");
    scanf("%lf", &cost);
    printf("Enter selling price per unit: ");
    scanf("%lf", &selling_price);
    printf("Enter units sold: ");
    scanf("%d", &units_sold);

    double gross_profit_loss_per_unit = selling_price - cost;
    double gross_profit_loss_total = gross_profit_loss_per_unit * units_sold;
    double gross_profit_loss_percentage = (gross_profit_loss_total / (cost * units_sold)) * 100;

    printf("Gross profit/loss per unit: %.2f\n", gross_profit_loss_per_unit);
    printf("Gross profit/loss in earned till now : %.2f\n", gross_profit_loss_total);
    printf("Gross profit/loss percentage: %.2f%%\n", gross_profit_loss_percentage);
}

// Function to record expenses
void record_expense() {
    char category[50];
    double amount;

    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: ");
    scanf("%lf", &amount);

    strcpy(expense_category[expense_count], category);
    expenses[expense_count] = amount;
    expense_count++;

    printf("Expense recorded successfully.\n");
}

// Function to display total expenses
void display_total_expenses() {
    double total_expenses = 0;

    printf("\n--- Expense Summary ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%s: $%.2f\n", expense_category[i], expenses[i]);
        total_expenses += expenses[i];
    }
    printf("Total expenses: $%.2f\n", total_expenses);
}

// Function to calculate operating profit
void calculate_operating_profit() {
    double total_revenue, total_gross_profit, total_expenses;

    printf("Enter total gross profit: ");
    scanf("%lf", &total_gross_profit);
    printf("Enter total expenses: ");
    scanf("%lf", &total_expenses);

    double operating_profit = total_gross_profit - total_expenses;

    printf("Operating profit after cutting expenses: %.2f\n", operating_profit);
}


// Function to calculate tax liabilities
void calculate_tax_liabilities() {
    double total_gross_profit, tax_percentage;

    printf("Enter total gross profit: ");
    scanf("%lf", &total_gross_profit);
    printf("Enter tax percentage: ");
    scanf("%lf", &tax_percentage);

    double total_tax_liability = (total_gross_profit * tax_percentage) / 100;

    printf("Total tax liability: %.2f\n", total_tax_liability);
}

// Function to calculate net profit
void calculate_net_profit() {
    double total_operating_profit, tax_percentage;

    printf("Enter total operating profit: ");
    scanf("%lf", &total_operating_profit);
    printf("Enter tax percentage: ");
    scanf("%lf", &tax_percentage);

    double total_net_profit = total_operating_profit * (1 - (tax_percentage / 100));

    printf("Total net profit: %.2f\n", total_net_profit);
}

// Function to calculate discount
void calculate_discount() {
    double cost, selling_price;
    int total_units;
    double discount_percentage;

    printf("Enter cost per unit: ");
    scanf("%lf", &cost);
    printf("Enter selling price per unit: ");
    scanf("%lf", &selling_price);
    printf("Enter total units: ");
    scanf("%d", &total_units);
    printf("Enter discount percentage: ");
    scanf("%lf", &discount_percentage);

    double discounted_selling_price = selling_price * (1 - discount_percentage / 100);
    double original_gross_profit = (selling_price - cost) * total_units;
    double new_gross_profit = (discounted_selling_price - cost) * total_units;
    double original_gross_profit_percentage = (original_gross_profit / (cost * total_units)) * 100;
    double new_gross_profit_percentage = (new_gross_profit / (cost * total_units)) * 100;

    printf("Discounted selling price: %.2f\n", discounted_selling_price);
    printf("Original gross profit: %.2f\n", original_gross_profit);
    printf("New gross profit: %.2f\n", new_gross_profit);
    printf("Original gross profit percentage: %.2f%%\n", original_gross_profit_percentage);
    printf("New gross profit percentage: %.2f%%\n", new_gross_profit_percentage);
}

// Function to perform future growth analysis
void future_growth_analysis() {
    double cost, net_profit_percentage;
    int units_in_stock, units_sold;

    printf("Enter cost per unit: ");
    scanf("%lf", &cost);
    printf("Enter net profit percentage: ");
    scanf("%lf", &net_profit_percentage);
    printf("Enter units in stock: ");
    scanf("%d", &units_in_stock);
    printf("Enter units sold: ");
    scanf("%d", &units_sold);

    double net_profit_earned_so_far = (cost * net_profit_percentage / 100) * units_sold;
    double projected_total_net_profit = (cost * net_profit_percentage / 100) * (units_in_stock + units_sold);

    printf("Net profits earned up to now: %.2f\n", net_profit_earned_so_far);
    printf("Projected total net profits: %.2f\n", projected_total_net_profit);
}

// Function to perform gross profit margin analysis
void gross_profit_margin_analysis() {
    double cost, selling_price;
    int num_prices;

    printf("Enter cost per unit: ");
    scanf("%lf", &cost);
    printf("Enter the number of different selling prices: ");
    scanf("%d", &num_prices);

    printf("Enter the different selling prices:\n");
    for (int i = 0; i < num_prices; i++) {
        printf("Price %d: ", i + 1);
        scanf("%lf", &selling_price);

        double profit = selling_price - cost;
        double profit_percentage = (profit / cost) * 100;

        printf("Profit for selling price %.2f: %.2f\n", selling_price, profit);
        printf("Profit percentage for selling price %.2f: %.2f%%\n", selling_price, profit_percentage);
    }
}
