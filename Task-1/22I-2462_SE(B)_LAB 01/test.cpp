// #include "pch.h" 
// #include "../Hospital.h"
// #include "../Patient.h"
// TEST(HospitalTest, CalculateChargesInPatient) {
//     Patient patient("John", "in-patient", 5);
//     Hospital hospital(patient, 100, 50.0, 200);

//     double expectedCharges = (5 * 50.0) + 200 + 100;

//     EXPECT_DOUBLE_EQ(expectedCharges, hospital.calculateCharges());
// }

// TEST(HospitalTest, CalculateChargesOutPatient) {
//     Patient patient("Alice", "out-patient", 0);
//     Hospital hospital(patient, 50, 0.0, 150);

//     double expectedCharges = 150 + 50;

//     EXPECT_DOUBLE_EQ(expectedCharges, hospital.calculateCharges());
// }
