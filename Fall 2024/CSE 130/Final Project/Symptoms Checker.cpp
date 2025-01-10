/*
Michael Porter
Dr. Yampolskiy
CSE-130-50-4248
Friday, November 22 - Monday, November 25
Description: This program simulates an illness symptoms checker, analyzing randomly generated symptoms for multiple patients to determine if they have COVID-19, Cold, Flu, 
				or an unknown illness. It provides a detailed summary of the results, including the number and percentage of patients diagnosed with each illness, along with a 
				visual representation of the distribution.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Abstract base class for illnesses
class Illness {
public:
    virtual string identifyIllness(const vector<string>& symptoms) const = 0;
    virtual ~Illness() {}
};

// Derived class for COVID-19
class COVID19 : public Illness {
public:
    string identifyIllness(const vector<string>& symptoms) const override {
        if (symptoms[0] == "present" && symptoms[1] == "present" && symptoms[2] == "present" &&
            symptoms[3] == "present" && symptoms[4] == "present" && symptoms[5] == "absent" &&
            symptoms[6] == "present") {
            return "COVID-19";
        }
        return "";
    }
};

// Derived class for Cold
class Cold : public Illness {
public:
    string identifyIllness(const vector<string>& symptoms) const override {
        if (symptoms[0] == "absent" && symptoms[1] == "present" && symptoms[2] == "absent" &&
            symptoms[3] == "present" && symptoms[4] == "present" && symptoms[5] == "present" &&
            symptoms[6] == "present") {
            return "Cold";
        }
        return "";
    }
};

// Derived class for Flu
class Flu : public Illness {
public:
    string identifyIllness(const vector<string>& symptoms) const override {
        if (symptoms[0] == "present" && symptoms[1] == "present" && symptoms[2] == "absent" &&
            symptoms[3] == "present" && symptoms[4] == "present" && symptoms[5] == "absent" &&
            symptoms[6] == "present") {
            return "Flu";
        }
        return "";
    }
};

// Function to generate random symptoms
string randomSymptom() {
    return rand() % 2 == 0 ? "present" : "absent";
}

// Function to display the symptom guide
void displaySymptomGuide() {
    cout << "Reference: * Common, + Sometimes, - None\n";
    cout << "==================================================\n";
    cout << "Symptoms       | COVID-19 | Cold   | Flu    |\n";
    cout << "==================================================\n";
    cout << "Fever          | *        | +      | *      |\n";
    cout << "Cough          | *        | +      | *      |\n";
    cout << "Shortness      | *        | -      | -      |\n";
    cout << "Runny Nose     | +        | *      | +      |\n";
    cout << "Headaches      | +        | +      | *      |\n";
    cout << "Sneezing       | -        | *      | -      |\n";
    cout << "Fatigue        | +        | +      | *      |\n";
    cout << "==================================================\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Illness objects
    COVID19 covid;
    Cold cold;
    Flu flu;

    vector<const Illness*> illnesses = {&covid, &cold, &flu};
    vector<string> symptomsList = {"Fever", "Cough", "Shortness of Breath", "Runny Nose", "Headaches", "Sneezing", "Fatigue"};

    cout << "Welcome to the Illness Identification System\n";
    displaySymptomGuide();

    int patientCount;
    cout << "Enter the number of patients to analyze: ";
    cin >> patientCount;
    cout << "Processing...\n";

    map<string, int> illnessStatistics = {
        {"COVID-19", 0},
        {"Cold", 0},
        {"Flu", 0},
        {"Unknown", 0}
    };

    for (int i = 0; i < patientCount; ++i) {
        vector<string> patientSymptoms;
        for (size_t j = 0; j < symptomsList.size(); ++j) {
            patientSymptoms.push_back(randomSymptom());
        }

        string detectedIllness = "Unknown";
        for (const Illness* illness : illnesses) {
            string result = illness->identifyIllness(patientSymptoms);
            if (!result.empty()) {
                detectedIllness = result;
                break;
            }
        }

        illnessStatistics[detectedIllness]++;
    }

    // Report results
    cout << "===================================\n";
    cout << "Analysis Summary:\n";
    cout << illnessStatistics["COVID-19"] << " patients diagnosed with COVID-19\n";
    cout << illnessStatistics["Cold"] << " patients diagnosed with Cold\n";
    cout << illnessStatistics["Flu"] << " patients diagnosed with Flu\n";
    cout << illnessStatistics["Unknown"] << " patients diagnosed with Unknown Illness\n";
    cout << "===================================\n";

    // Calculate and display percentages
    cout << "Illness Distribution:\n";
    for (const auto& entry : illnessStatistics) {
        double percentage = (static_cast<double>(entry.second) / patientCount) * 100.0;
        cout << entry.first << ": [" << fixed << setprecision(1) << percentage << "%] ";
        for (int i = 0; i < static_cast<int>(percentage); ++i) {
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}
