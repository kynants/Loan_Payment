#include <iostream>
#include <iomanip>
using namespace std;

double loan, annIntRate, monthIntRate, fullPay, monthPay, prinAmt, totalInt;

void count() {
    if (monthPay < (loan * monthIntRate)) {
        cout << "The monthly payment rate is too low.";
    } else {
        while (fullPay < (loan)) {
            prinAmt = monthPay - (loan * monthIntRate);
            loan -= prinAmt;
            fullPay += prinAmt;
            cout << "Loan amount before last payment: $" << setprecision(2)
                 << fixed << monthPay - (loan * monthIntRate) << endl;
            cout << "Amount paid: $" << setprecision(2) << fixed << prinAmt << endl;
            cout << "Remaining debt: $" << setprecision(2) << fixed << loan << endl;
            totalInt = monthPay - prinAmt;
            prinAmt = monthPay;
        }
    }
}

int main() {
    cout << "Enter the loan amount: ";
    cin >> loan;

    cout << "Enter the interest rate per year: ";
    cin >> annIntRate;
    annIntRate *= 0.01;
    monthIntRate = annIntRate / 12;

    cout << "Enter the monthly payment. Make sure it \n"
            "is not less your monthly interest rate: ";
    cin >> monthPay;

    count();

    cout << "Total interest paid: $" << totalInt;

    return 0;
}