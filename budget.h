#ifndef BUDGET_H
#define BUDGET_H

#include <vector>
#include <string>

struct Transaction {
    std::string name;
    double amount;
    std::string category;
    bool is_income;
};

class Budget {
public:
    void addTransaction(const std::string& name, double amount, const std::string& category, bool is_income);
    double calculateBalance() const;
    void displaySummary() const;

private:
    std::vector<Transaction> transactions;
};

#endif // BUDGET_H