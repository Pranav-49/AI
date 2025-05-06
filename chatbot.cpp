#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string input;

    cout << "ChatBot: Hello! Welcome to Support Chat.\n";
    cout << "ChatBot: Type 'bye' to end the chat.\n";

    while (true) 
    {

        cout << "\nYou: ";
        getline(cin, input);

        // Convert input to lowercase manually for simple keywords
        for (char &c : input) c = tolower(c);

        if (input == "bye") {
            cout << "ChatBot: Thank you! Have a nice day.\n";
            break;
        } else if (input.find("product") != string::npos) {
            cout << "ChatBot: We offer mobiles, laptops, and accessories.";
        } else if (input.find("price") != string::npos || input.find("cost") != string::npos) {
            cout << "ChatBot: Prices start from ₹5,000. Please specify a product.";
        } else if (input.find("support") != string::npos || input.find("help") != string::npos) {
            cout << "ChatBot: Call 1800-123-456 or email help@example.com.";
        } else if (input.find("warranty") != string::npos) {
            cout << "ChatBot: Products have 1-year warranty.";
        } else {
            cout << "ChatBot: Sorry, I didn't get that.";
        }
    }

    return 0;
}
