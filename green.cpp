#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Constants
const double LED_SAVINGS_PER_BULB_KWH = 0.08 * 5 * 30; // 8W savings per bulb, 5h/day, 30d
const double AC_CONSUMPTION_PER_HOUR_KWH = 1.2;
const double CO2_PER_KWH = 0.92 / 1000;

// Function declarations
int getPositiveIntInput(const string& prompt);
bool getYesNoInput(const string& prompt);
int getMenuSelection();
void displayEnergyTips();
double calculateLightingSavings(int bulbs);
double calculateACUsage(int hoursPerDay);
double calculateTransportEmissions(bool useEV, int kmPerDay);
double calculateApplianceSavings(bool useSmartPlugs);

int main() {
    cout << "🌍🔋 === Welcome to Smart Living Energy Advisor === 🔋🌍\n";

    while (true) {
        int choice = getMenuSelection();

        if (choice == 1) {
            string name;
            cout << "🧑 Please enter your name: ";
            cin.ignore();
            getline(cin, name);

            int ledBulbs = getPositiveIntInput("💡 How many LED bulbs do you use? ");
            int acHours = getPositiveIntInput("❄️  How many hours/day do you use air conditioning? ");
            bool useSmartPlug = getYesNoInput("🔌 Do you use smart plugs? (1 = Yes, 0 = No): ");
            bool useEV = getYesNoInput("🚗 Do you drive an electric vehicle (EV)? (1 = Yes, 0 = No): ");
            int kmPerDay = getPositiveIntInput("🛣️  On average, how many km/day do you drive? ");

            // Calculations
            double lightSavings = calculateLightingSavings(ledBulbs);
            double acUsage = calculateACUsage(acHours);
            double applianceSavings = calculateApplianceSavings(useSmartPlug);
            double transportCO2 = calculateTransportEmissions(useEV, kmPerDay);
            double totalEnergyUsed = acUsage - lightSavings - applianceSavings;
            if (totalEnergyUsed < 0) totalEnergyUsed = 0;

            double totalCO2Reduced = (lightSavings + applianceSavings) * CO2_PER_KWH;

            // Output Results
            cout << fixed << setprecision(2);
            cout << "\n📊 ==== Eco Impact Report for " << name << " ====\n";
            cout << "💡 Lighting energy saved:        " << lightSavings << " kWh\n";
            cout << "🔌 Appliance energy saved:       " << applianceSavings << " kWh\n";
            cout << "❄️  AC energy used:              " << acUsage << " kWh\n";
            cout << "🚗 Transport CO₂ emitted:        " << transportCO2 << " tons/month\n";
            cout << "🌿 Total CO₂ reduced:            " << totalCO2Reduced << " tons/month\n";
            cout << "⚡ Net monthly energy usage:     " << totalEnergyUsed << " kWh\n";
            cout << "✅ Done! Press [Enter] to return to the menu...\n";
            cin.ignore();
            cin.get();

        } else if (choice == 2) {
            displayEnergyTips();
            cout << "\n✅ Press [Enter] to return to the menu...\n";
            cin.ignore();
            cin.get();

        } else if (choice == 3) {
            cout << "\n👋 Exiting the program. Thank you for contributing to a smarter planet!\n";
            break;
        }
    }

    return 0;
}

// Menu selection with input validation
int getMenuSelection() {
    int selection;
    while (true) {
        cout << "\n🧭 Main Menu:\n";
        cout << "1️⃣  Calculate my smart living energy stats\n";
        cout << "2️⃣  View smart living tips\n";
        cout << "3️⃣  Exit\n";
        cout << "👉 Please select an option (1-3): ";

        cin >> selection;

        if (cin.fail() || selection < 1 || selection > 3) {
            cout << "❌ Invalid selection. Please enter 1, 2, or 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return selection;
        }
    }
}

int getPositiveIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < 0) {
            cout << "❗ Please enter a valid non-negative number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

bool getYesNoInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || (input != 0 && input != 1)) {
            cout << "❗ Invalid input. Please enter 1 (Yes) or 0 (No).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return input == 1;
        }
    }
}

double calculateLightingSavings(int bulbs) {
    return bulbs * LED_SAVINGS_PER_BULB_KWH;
}

double calculateACUsage(int hoursPerDay) {
    return hoursPerDay * AC_CONSUMPTION_PER_HOUR_KWH * 30;
}

double calculateApplianceSavings(bool useSmartPlugs) {
    return useSmartPlugs ? 15.0 : 0.0;
}

double calculateTransportEmissions(bool useEV, int kmPerDay) {
    double emissionPerKm = useEV ? 0.04 : 0.18;
    return emissionPerKm * kmPerDay * 30
}

void displayEnergyTips() {
    cout << "\n💡 === Smart Living Tips === 💡\n";
    cout << "🌱 Switch to LED lighting to cut energy waste.\n";
    cout << "🔌 Use smart plugs to stop vampire power loss.\n";
    cout << "🌬️ Set AC to 25°C and clean filters regularly.\n";
    cout << "🚴‍♀️ Use EVs, walk, or cycle whenever possible.\n";
    cout << "📴 Unplug unused electronics or put on a timer.\n";
    cout << "🏠 Invest in energy-efficient home insulation.\n";
}
