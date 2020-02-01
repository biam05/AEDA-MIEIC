/*
 * Doctor.cpp
 */

#include "Doctor.h"


Patient::Patient(unsigned codP, string mS): codeP(codP), medicalSpecialty(mS)
{}

string Patient::getMedicalSpecialty() const {
	return medicalSpecialty;
}

unsigned Patient::getCode() const {
	return codeP;
}

Doctor::Doctor(unsigned codM, string mS): codeM(codM), medicalSpecialty(mS)
{}


Doctor::Doctor(unsigned codM, string mS, queue<Patient> patients1): codeM(codM), medicalSpecialty(mS), patients(patients1)
{}

unsigned Doctor::getCode() const {
	return codeM;
}

string Doctor::getMedicalSpecialty() const {
	return medicalSpecialty;
}

queue<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient &p1) {
	patients.push(p1);
}

Patient Doctor::removeNextPatient() {
	if (!patients.empty()) {
		Patient p1 = patients.front();
		patients.pop();
		return p1;
	}
	else throw PatientInexistent();
}




void Doctor::moveToFront(unsigned codP1) {
	// TODO
	int n = patients.size();
    vector<Patient> aux;
    while(!patients.empty())
    {
        aux.push_back(patients.front());
        patients.pop();
    }
    for(int i = 0; i < aux.size(); i++)
    {
        if(aux[i].getCode() == codP1)
        {
            aux.insert(aux.begin(), aux[i]);
            aux.erase(aux.begin()+(i+1));
        }
    }
    for(int i = 0; i < aux.size(); i++)
    {
        patients.push(aux[i]);
    }
}

