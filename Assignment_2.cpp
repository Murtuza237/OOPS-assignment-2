#include <iostream>
#include <cstring> 
using namespace std;

// Base class: Person
class Person {
protected:
    char name[50];
    int age;
    char gender[10];
public:
    Person(const char* n, int a, const char* g) : age(a) {
        strcpy(name, n);
        strcpy(gender, g);
    }
    virtual void display() = 0;
};

// Class: Patient (for Hospital Patient Record Management - Admin)
class Patient : public Person {
private:
    char patientID[10];
    char medicalHistory[100];
public:
    Patient(const char* n, int a, const char* g, const char* pid, const char* mh) : Person(n, a, g) {
        strcpy(patientID, pid);
        strcpy(medicalHistory, mh);
    }
    void display() {
        cout << "Patient ID: " << patientID<< endl << "Name: " << name << endl<< "Age: " << age << endl<< "Gender: " << gender<< endl << "Medical History: " << medicalHistory << endl; 
    }
    const char* getPatientID() { return patientID; }
};

// Class: PharmacyInventory (for Inventory Management - Pharmacy)
class PharmacyInventory {
private:
    char medicines[5][30]; 
    int stock[5];         
    int medicineCount;
public:
    PharmacyInventory() : medicineCount(0) {}

    void addMedicine(const char* medicine, int qty) {
        if (medicineCount < 5) {
            strcpy(medicines[medicineCount], medicine);
            stock[medicineCount] = qty;
            medicineCount++;
        } else {
            cout << "Inventory full. Cannot add more medicines." << endl;
        }
    }

    void updateStock(const char* medicine, int qty) {
        for (int i = 0; i < medicineCount; i++) {
            if (strcmp(medicines[i], medicine) == 0) {
                stock[i] += qty;
                break;
            }
        }
    }

    void showInventory() {
        cout << "Pharmacy Inventory:\n";
        for (int i = 0; i < medicineCount; i++) {
            cout << medicines[i] << ": " << stock[i] << " units\n";
        }
    }
};

// Class: Billing (for Billing Department Management)
class Billing {
private:
    float totalBill;
public:
    Billing() : totalBill(0) {}

    void generateBill(float consultation, float medicine) {
        totalBill = consultation + medicine;
    }

    void displayBill() {
        cout << "Total Bill: " << totalBill << endl;
    }
};

// Class: RnD (for COVID Identification and Probability - R&D)
class RnD {
public:
    const char* covidProbability(int symptomsCount) {
        if (symptomsCount >= 5) {
            return "High probability of COVID-19.";
        } else if (symptomsCount >= 3) {
            return "Moderate probability of COVID-19.";
        } else {
            return "Low probability of COVID-19.";
        }
    }
};

// Class: Insurance (for Insurance Management - Third party)
class Insurance {
private:
    char insuranceProvider[30];
    float coverageAmount;
public:
    Insurance(const char* provider, float amount) : coverageAmount(amount) {
        strcpy(insuranceProvider, provider);
    }

    void showInsuranceDetails() {
        cout << "Insurance Provider: " << insuranceProvider << ", Coverage: " << coverageAmount << endl;
    }

    bool isEligibleForClaim(float billAmount) {
        return billAmount <= coverageAmount;
    }
};

// Main Function to demonstrate interactions
int main() {
    // Creating a patient record
    Patient patient1("Gourav", 20, "Male", "P123", "Hypertension");
    patient1.display();

    // Inventory Management in Pharmacy
    PharmacyInventory pharmacy;
    pharmacy.addMedicine("Paracetamol", 100);
    pharmacy.addMedicine("Aspirin", 50);
    pharmacy.updateStock("Paracetamol", 20); 
    pharmacy.showInventory();

    // Billing process
    Billing bill;
    bill.generateBill(100, 50); 
    bill.displayBill();

    // COVID-19 Probability Calculation
    RnD research;
    cout << research.covidProbability(4) << endl;

    // Insurance processing
    Insurance insurance("HealthPlus", 500);
    insurance.showInsuranceDetails();
    if (insurance.isEligibleForClaim(150)) {
        cout << "Claim eligible.\n";
    } else {
        cout << "Claim not eligible.\n";
    }

    return 0;
}
