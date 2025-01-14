#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec {};
    char selection;
    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;
        switch (selection) {
            case 'P':
            case 'p':
                if (vec.size() < 1) {
                    cout << "[] - the list is empty" << endl;
                } else {
                    cout << "[ ";
                    for (auto val: vec)
                        cout << val << " ";
                    cout << "]";
                }                
                break;
            case 'A':
            case 'a':
                int data;
                cout << "Enter an integer you want to add to the list" << endl;
                cin >> data;
                vec.push_back(data);
                cout << data << " added" << endl;
                break;
            case 'M':
            case 'm':
                if (vec.size() < 1) {
                    cout << "Unable to calculate the mean - no data" << endl;
                } else {
                    float sum {0};
                    float average {0};
                    for (auto val: vec) {
                        sum += val;
                    }
                    cout << sum << endl;
                    average = sum / vec.size();
                    cout << "The mean of the elements in the list is: " << average << endl;
                }
                break;
            case 'S':
            case 's':
                if (vec.size() < 1) {
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                } else {
                    auto small = min_element(vec.begin(), vec.end());
                    cout << "The smallest number is " << *small << endl;
                }
                break;
            case 'L':
            case 'l':
                if (vec.size() < 1) {
                    cout << "Unable to determine the largest number - list is empty" << endl;
                } else {
                    auto large = max_element(vec.begin(), vec.end());
                    cout << "The largest number is " << *large << endl;
                }
                break;
            case 'Q':
            case 'q':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Unknown selection, please try again!" << endl;
        }
        cout << endl;
    } while (selection != 'Q' && selection != 'q');

    return 0;
}