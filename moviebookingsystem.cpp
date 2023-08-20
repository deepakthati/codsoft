#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const double TICKET_PRICE = 250.00;

class MovieTheater {
private:
    vector<vector<char>> seats;
    vector<string> selectedSeats;
    double totalCost;

public:
    MovieTheater() : seats(NUM_ROWS, vector<char>(NUM_COLS, 'O')), totalCost(0.0) {}

    void displaySeats() const {
        cout << "  ";
        for (int col = 1; col <= NUM_COLS; ++col) {
            cout << setw(3) << col;
        }
        cout << "\n   ---------------------" << endl;

        for (int row = 0; row < NUM_ROWS; ++row) {
            cout << char('A' + row) << " | ";
            for (int col = 0; col < NUM_COLS; ++col) {
                cout << seats[row][col] << "  ";
            }
            cout << endl;
        }
    }

    bool bookSeat(int row, int col) {
        if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seats[row][col] == 'O') {
            selectedSeats.push_back(string(1, 'A' + row) + " " + to_string(col + 1));
            seats[row][col] = 'X';
            totalCost += TICKET_PRICE;
            return true;
        }
        return false;
    }

    void displayBookingSummary() const {
        cout << "Booking summary:" << endl;
        cout << "Selected seats: ";
        for (const string &seat : selectedSeats) {
            cout << seat << " ";
        }
        cout << "\nTotal cost: INR " << fixed << setprecision(2) << totalCost << endl;
    }
};

int main() {
    MovieTheater theater;

    char rowChoice;
    int colChoice;

    do {
        cout << "Movie Ticket Booking System" << endl;
        cout << "---------------------------" << endl;
        theater.displaySeats();

        cout << "\nSelect a seat (e.g. A 1) or enter 'Q' to quit: ";
        cin >> rowChoice;

        if (rowChoice == 'Q') {
            break;
        }

        cin >> colChoice;

        int row = rowChoice - 'A';
        int col = colChoice - 1;

        if (theater.bookSeat(row, col)) {
            cout << "Seat " << rowChoice << colChoice << " booked successfully!" << endl;
        } else {
            cout << "Invalid seat selection or seat is already booked." << endl;
        }

    } while (true);

    theater.displayBookingSummary();

    return 0;
}
