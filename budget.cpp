#include "budget.h"
#include <iostream>
#include <iomanip>

void Budget::addTransaction(const std::string& name, double amount, const std::string& category, bool is_income) {
    transactions.push_back({name, amount, category, is_income});
}

void Budget::displaySummary() const {
    double total = 0;

    // Terminal color codes
    const std::string RESET = "\033[0m";
    const std::string GREEN = "\033[32m";
    const std::string RED = "\033[31m";
    const std::string BOLD = "\033[1m";
    const std::string CYAN = "\033[36m";
    const std::string YELLOW = "\033[33m";

    std::cout << BOLD << CYAN << "\nTransactions Summary:\n" << RESET;

    if (transactions.empty()) {
        std::cout << "No transactions found.\n";
        return;
    }

    std::cout << BOLD;
    std::cout << std::left << std::setw(20) << "Name"
              << std::setw(12) << "Amount"
              << std::setw(15) << "Category"
              << std::setw(10) << "Type" << RESET << "\n";

    for (const auto& t : transactions) {
        std::string color = t.is_income ? GREEN : RED;
        std::string type = t.is_income ? "Income" : "Expense";
        std::cout << color;
        std::cout << std::left << std::setw(20) << t.name
                  << std::setw(12) << t.amount
                  << std::setw(15) << t.category
                  << std::setw(10) << type << RESET << "\n";

        total += t.is_income ? t.amount : -t.amount;
    }

    std::string totalColor = total >= 0 ? GREEN : RED;
    std::cout << BOLD << "\nTotal Balance: " << totalColor << total << RESET << "\n";
}