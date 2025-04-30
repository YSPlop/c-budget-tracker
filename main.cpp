#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include "budget.h"

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isExitCommand(const std::string& input) {
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    return lowerInput == "exit";
}

void displayMenu() {
    std::cout << "\n=== Personal Budget Tracker ===\n";
    std::cout << "1. Add Transaction\n";
    std::cout << "2. Show Summary\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option (1-3 or type 'exit'): ";
}

int getValidatedIntInput(int min, int max) {
    std::string input;
    int value;
    while (true) {
        std::getline(std::cin, input);
        if (isExitCommand(input)) return -1;

        try {
            value = std::stoi(input);
            if (value >= min && value <= max)
                return value;
        } catch (...) {}

        std::cout << "❌ Invalid input. Enter a number between " << min << " and " << max << ": ";
    }
}

double getValidatedAmount() {
    std::string input;
    double value;
    while (true) {
        std::getline(std::cin, input);
        if (isExitCommand(input)) return -1;

        try {
            value = std::stod(input);
            if (value > 0)
                return value;
        } catch (...) {}

        std::cout << "❌ Invalid amount. Please enter a positive number: ";
    }
}

std::string getLineInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (isExitCommand(input)) return "exit";
    return input;
}

int main() {
    Budget myBudget;
    int choice;

    while (true) {
        displayMenu();
        choice = getValidatedIntInput(1, 3);
        if (choice == -1) break;

        if (choice == 1) {
            std::string name = getLineInput("\nEnter transaction name (or 'exit'): ");
            if (isExitCommand(name)) break;

            std::cout << "Enter amount (or 'exit'): ";
            double amount = getValidatedAmount();
            if (amount == -1) break;

            std::string category = getLineInput("Enter category (or 'exit'): ");
            if (isExitCommand(category)) break;

            std::cout << "Type (1 = Income, 2 = Expense) or 'exit': ";
            int type = getValidatedIntInput(1, 2);
            if (type == -1) break;

            bool is_income = (type == 1);
            myBudget.addTransaction(name, amount, category, is_income);
            std::cout << "✅ Transaction added.\n";
        }
        else if (choice == 2) {
            myBudget.displaySummary();
        }
        else if (choice == 3) {
            break;
        }
    }

    std::cout << "\n📊 Final Budget Summary:\n";
    myBudget.displaySummary();
    std::cout << "👋 Exiting... Thank you!\n";
    return 0;
}