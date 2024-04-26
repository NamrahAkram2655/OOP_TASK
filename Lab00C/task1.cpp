/*Task 1 Namrah Akram BITF21m542*/
#include <iostream>
using namespace std;
float calculateCharges(int days, float dailyRate, float MedCharges, float HospServices)
{
    float daily = 0.0;
    for (int i = 0; i < days; i++)
    {
        daily = daily + dailyRate;
    }
    return (daily + MedCharges + HospServices);
}
float calculateCharges(float MedCharges, float HospServices)
{
    return MedCharges + HospServices;
}
int main()
{
    // task 1
    string patientType;
    cout << "Patient was admitted a an in-patient (ip) or out-patient (op) : ";
    cin >> patientType;
    int days;
    float dailyRate, MedCharges, HospServices;
    if (patientType == "ip")
    {
        cout << "Number of days he/she spent in hospital : ";
        cin >> days;
        cout << "daily rate : ";
        cin >> dailyRate;
        cout << "Hospital medication charges : ";
        cin >> MedCharges;
        cout << "charges for hospital services (lab/test etc...) : ";
        cin >> HospServices;
        cout << "Total charges are : " << calculateCharges(days, dailyRate, MedCharges, HospServices) << endl;
    }
    else if (patientType == "op")
    {
        cout << "Hospital medication charges : ";
        cin >> MedCharges;
        cout << "charges for hospital services (lab/test etc...) : ";
        cin >> HospServices;
        cout << "Total charges are : " << calculateCharges(MedCharges, HospServices) << endl;
    }
    return 0;
}