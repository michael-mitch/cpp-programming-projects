#include <iostream>
#include <cmath>
using namespace std;

//ParentClass
class PatientVitals {
private:
	double height;
	double weight;

public:
	//DefaultConstructor
	PatientVitals() {
		height = 0.0;
		weight = 0.0;
	}

	//ParamConstructor
	PatientVitals(double h, double w) {
		height = h;
		weight = w;
	}

	//VoidPrintMethod
	virtual void print() {
		double bmi = 0.0;
		double bsa = 0.0;

		if (height > 0) {
			bmi = weight / (height * height);
			bsa = sqrt ((height * weight * 100) / 3600);
		}


		cout << "Height: " << height << " m" << endl;
                cout << "Weight: " << weight << " kg" << endl;
                cout << "BMI: " << bmi << endl;
                cout << "Body Surface Area (BSA): " << bsa << endl;

	}
};


//ChildClass
class CardiacPatient : public PatientVitals {
private:
	double heartRate;

public:
	//DefaultConstructor
	CardiacPatient() : PatientVitals() {
		heartRate = 0.0;
	}

	//ParamConstructor
	CardiacPatient(double h, double w, double hr) : PatientVitals(h, w) {
		heartRate = hr;
	}

	//OverrideMethod
	void print() override {
		cout << "Heart Rate: " << heartRate << " BPM" << endl;
		PatientVitals::print();
	}
};


//MainClass
int main() {

	//TwoPTVitalsObj
	PatientVitals patientOne;
	PatientVitals patientTwo(1.75, 70.0);

	//TwoCardiactPTOBJ
	CardiacPatient cardiacOne;
	CardiacPatient cardiacTwo(1.80, 85.0, 72.0);

	cout << "Patient One:" << endl;
	patientOne.print();
	cout << endl;

        cout << "Patient Two:" << endl;
        patientTwo.print();
        cout << endl;

        cout << "Cardiac Patient One:" << endl;
        cardiacOne.print();
        cout << endl;

        cout << "Cardiac Patient Two:" << endl;
        cardiacTwo.print();
        cout << endl;

	return 0;
}
