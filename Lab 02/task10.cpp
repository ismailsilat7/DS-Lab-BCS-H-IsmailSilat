#include <iostream>
using namespace std;

class LibraryRecords {

    private:
        int** bookIDs;
        int numCategories;
        int* numBooks;
        string* categories;
    public:
        LibraryRecords(int n) {
            numCategories = n;
            bookIDs = new int*[numCategories];
            numBooks = new int[numCategories];
            categories = new string[numCategories];

            for (int i = 0; i < numCategories; i++) {
                cout << "Enter name of category " << i + 1 << ": ";
                cin >> categories[i];

                cout << "Enter number of books in " << categories[i] << ": ";
                cin >> numBooks[i];

                bookIDs[i] = new int[numBooks[i]];
                cout << "Enter book IDs for " << categories[i] << endl;
                for (int j = 0; j < numBooks[i]; j++) {
                    cout << "  Book " << j + 1 << ": ";
                    cin >> bookIDs[i][j];
                }
            }
        }

        void searchBook(int id) {
            for (int i = 0; i < numCategories; i++) {
                for (int j = 0; j < numBooks[i]; j++) {
                    if (bookIDs[i][j] == id) {
                        cout << "Book with ID " << id << " found in category " << categories[i] << endl;
                        return;
                    }
                }
            }
            cout << "Book " << id << " not found in library records." << endl;
        }

        ~LibraryRecords() {
            cout << "Deallocating memory." << endl;
            for (int i = 0; i < numCategories; i++) {
                delete[] bookIDs[i];
            }
            delete[] bookIDs;
            delete[] numBooks;
            delete[] categories;
        }
};

int main() {
    int n;
    cout << "Enter number of categories: ";
    cin >> n;

    LibraryRecords library(n);

    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    library.searchBook(searchID);

    return 0;
}