// UzemljivacMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>
#include<memory>

#include "GroundingDeviceClass.h"
#include "GroundRod.h"
#include "GroundRing.h"
#include "EarthingTape.h"
#include "CircularPlate.h"
#include "HemisphericalGroundingElectrode.h"
#include "VerticalRectangularPlate.h"

// 1: #define NIVO_1_DOD "Nivo I sa dodatnim merama zastite"
// 2: #define NIVO_1_DOD 1
// 3:
enum LevelOfProtection {
    LEVEL_1D,  // Level I with additional protection measures
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4
};




//Definition of a function that checks whether the spreading resistance of the selected earth electrode is
//within a satisfactory limit compared to the level of protectionand the specific density of the soil

std::string calculate(std::string report, double ro_ground, int density_ground, double resistance_omsk, std::vector<int>tab_compactness, std::map<int, int>tab_resistance)
{
    std::string grounding_testing(double, double);
    double interpolation(double, double, double, double, double);


    for (int specific_density : tab_compactness)
    {
        if (ro_ground < specific_density)
        {
            if (specific_density == density_ground)
            {
                report = grounding_testing(resistance_omsk, tab_resistance[density_ground]);
            }
            else
            {
                double resistance_interpolation = interpolation(ro_ground, density_ground, specific_density, tab_resistance[density_ground], tab_resistance[specific_density]);

                std::cout << std::endl;
                std::cout << "The interpolation resistance, which must be greater than the grounding resistance, is: " << resistance_interpolation << " oma ." << std::endl << std::endl;

                report = grounding_testing(resistance_omsk, resistance_interpolation);
            }
        }
        density_ground = specific_density;
        if (report != "Test whether the earth electrode satisfies") { break; };
    }

    return report;

}


//Definition of a function that returns an interpolation value

double interpolation(double x, double x1, double x2, double y1, double y2)
{
    double resistance = y1 + (x - x1) * ((y2 - y1) / (x2 - x1));
    return resistance;
}


//Definition of the "grounding" function that returns a pointer of type: shared_ptr 

std::shared_ptr<GroundingDevice> entering_grounding_parameters(std::string grounding_device)
{
    if (grounding_device == "ground_rod")
    {
        std::cout << "Enter the parameters of the ground rod in meters and ohms:" << std::endl << std::endl << std::endl;
        double ro_ground_rod;
        double l_ground_rod;
        double d_ground_rod;
        double h_ground_rod;

        std::cout << "ro[om]=";
        std::cin >> ro_ground_rod;
        std::cout << std::endl;

        std::cout << "l[meter]=";
        std::cin >> l_ground_rod;
        std::cout << std::endl;

        std::cout << "d[meter]=";
        std::cin >> d_ground_rod;
        std::cout << std::endl;

        std::cout << "H[meter]=";
        std::cin >> h_ground_rod;
        std::cout << std::endl;

        GroundingDevice* ptr = new GroundRod(ro_ground_rod, l_ground_rod, d_ground_rod, h_ground_rod);
        std::shared_ptr<GroundingDevice> PTR(ptr);
        return PTR;
    }
    else if (grounding_device == "ground_ring")
    {
        std::cout << "Enter the parameters of the ground ring in meters and ohms:" << std::endl << std::endl << std::endl;

        double ro_ground_ring;
        double d_ground_ring;
        double D_ground_ring;
        double h_ground_ring;

        std::cout << "ro[om]=";
        std::cin >> ro_ground_ring;
        std::cout << std::endl;


        std::cout << "d[meter]=";
        std::cin >> d_ground_ring;
        std::cout << std::endl;


        std::cout << "D[meter]=";
        std::cin >> D_ground_ring;
        std::cout << std::endl;

        std::cout << "H[meter]=";
        std::cin >> h_ground_ring;
        std::cout << std::endl;


        GroundingDevice* ptr = new GroundRing(ro_ground_ring, d_ground_ring, D_ground_ring, h_ground_ring);
        std::shared_ptr<GroundingDevice> PTR(ptr);
        return PTR;

    }
    else if (grounding_device == "earthing_tape")
    {
        std::cout << "Enter the parameters of the earthing tape in meters and ohms:" << std::endl << std::endl << std::endl;

        double ro_earthing_tape;
        double l_earthing_tape;
        double a_earthing_tape;
        double b_earthing_tape;
        double h_earthing_tape;

        std::cout << "ro[om]=";
        std::cin >> ro_earthing_tape;
        std::cout << std::endl;

        std::cout << "l[meter]=";
        std::cin >> l_earthing_tape;
        std::cout << std::endl;


        std::cout << "a[meter]=";
        std::cin >> a_earthing_tape;
        std::cout << std::endl;

        std::cout << "b[meter]=";
        std::cin >> b_earthing_tape;
        std::cout << std::endl;

        std::cout << "H[meter]=";
        std::cin >> h_earthing_tape;
        std::cout << std::endl;


        GroundingDevice* ptr = new EarthingTape(ro_earthing_tape, l_earthing_tape, a_earthing_tape, b_earthing_tape, h_earthing_tape);
        std::shared_ptr<GroundingDevice> PTR(ptr);
        return PTR;
    }
    else if (grounding_device == "circular_plate")
    {
        std::cout << "Enter the parameters of the circular plate in meters and ohms:" << std::endl << std::endl << std::endl;

        double ro_circular_plate;
        double D_circular_plate;
        double h_circular_plate;

        std::cout << "ro[om]=";
        std::cin >> ro_circular_plate;
        std::cout << std::endl;


        std::cout << "D[meter]=";
        std::cin >> D_circular_plate;
        std::cout << std::endl;

        std::cout << "H[meter]=";
        std::cin >> h_circular_plate;
        std::cout << std::endl;


        GroundingDevice* ptr = new CircularPlate(ro_circular_plate, D_circular_plate, h_circular_plate);
        std::shared_ptr<GroundingDevice> PTR(ptr);
        return PTR;

    }
    else if (grounding_device == "hemispherical_grounding_electrode")
    {
        std::cout << "Enter the parameters of the hemispherical grounding electrode in meters and ohms:" << std::endl << std::endl << std::endl;

        double ro_hemispherical_grounding_electrode;
        double D_hemispherical_grounding_electrode;

        std::cout << "ro[om]=";
        std::cin >> ro_hemispherical_grounding_electrode;
        std::cout << std::endl;

        std::cout << "D[meter]=";
        std::cin >> D_hemispherical_grounding_electrode;
        std::cout << std::endl;

        GroundingDevice* ptr = new HemisphericalGroundingElectrode(ro_hemispherical_grounding_electrode, D_hemispherical_grounding_electrode);
        std::shared_ptr<GroundingDevice> PTR(ptr);
        return PTR;

    }
    else if (grounding_device == "vertical_rectangular_plate")
    {
        std::cout << "Enter the parameters of the vertical rectangular plate in meters and ohms:" << std::endl << std::endl << std::endl;

        double ro_vertical_rectangular_plate;
        double a_vertical_rectangular_plate;
        double b_vertical_rectangular_plate;


        std::cout << "ro[om]=";
        std::cin >> ro_vertical_rectangular_plate;
        std::cout << std::endl;

        std::cout << "a[meter]=";
        std::cin >> a_vertical_rectangular_plate;
        std::cout << std::endl;

        std::cout << "b[meter]=";
        std::cin >> b_vertical_rectangular_plate;
        std::cout << std::endl;


        GroundingDevice* ptr = new VerticalRectangularPlate(ro_vertical_rectangular_plate, a_vertical_rectangular_plate, b_vertical_rectangular_plate);
        std::shared_ptr<GroundingDevice> PTR(ptr);
        return PTR;
    }
    else
    {
        return std::shared_ptr<GroundingDevice>();
    }
}


//Definition of a function that checks whether the resistance of the grounding device satisfies depending on the level of protection and the density of the soil 

std::string grounding_testing(double x, double y)
{
    std::string conclusion;

    if (x <= y)
    {
        conclusion = "The selected grounding device satisfies !";
        std::cout << conclusion << std::endl;
    }
    else
    {
        conclusion = "The selected grounding device does not satisfy!";
        std::cout << conclusion << std::endl;
    }

    return conclusion;
}



int main() {

    //******************************************************************//
    //*******Determining the level of protection of the lightning rod*********//


    //Enter the value of the equivalent area of the object's lightning rod determined by the graphical method in the AutoCad software

    std::cout << "Enter the value of the equivalent area in square meters:" << std::endl << std::endl;

    double Ae;

    std::cout << "Ae[m^2]=";
    std::cin >> Ae;
    std::cout << std::endl << std::endl;


    std::cout << "Enter the name of the largest city from the following list of cities in the vicinity of which the facility is located:" << std::endl << std::endl;


    std::ifstream nearby_cities("NamesOfNearbyCities.txt");

    while (true)
    {
        std::string name_city;
        nearby_cities >> name_city;
        if (nearby_cities)
        {
            std::cout << name_city << std::endl;
        }
        else
        {
            break;
        }
    }

    nearby_cities.close();
    std::cout << std::endl << std::endl;


    std::string city;
    std::cin >> city;

    std::map<std::string, int>cities;


    //Opening the input files with the names of the citiesand inserting them into
    //the map : "cities" the city name as the key and the value of the coefficient Td 
    //which represents the average number of days with thunderstorms per year for each city individually

    std::ifstream frequency_strikes("FrequencyOfLightningStrikes.txt");

    while (true)
    {
        std::string name_city;
        int number_of_strokes;
        frequency_strikes >> name_city >> number_of_strokes;
        if (frequency_strikes)
        {
            cities[name_city] = number_of_strokes;
        }
        else
        {
            break;
        }
    }

    frequency_strikes.close();

    int Td = cities[city];

    //The variable Td represents the number of days with thunderstorms, 
    //which is taken separately for each city from the Isokeraunic map located in the project folder

    double Ng;

    Ng = 0.04 * pow(Td, 1.25);
    std::cout << std::endl;

    std::cout << "The density coefficient of the atmospheric discharge in the ground, Ng, is equal to:" << Ng << std::endl << std::endl;

    double Nd;

    Nd = Ng * Ae * pow(10, -6);

    std::cout << "The coefficient of average discharge density (number of lightning strikes/km x year) Nd, is equal to:" << Nd << std::endl;

    //  Entering coefficients:

    //  -C1(depends on the type of building construction)
    //  -C2(depends on the content of the object)
    //  -C3(depends on the purpose of the object)
    //  -C4(depends on the consequences of a lightning strike on the object)


    int C1, C2, C3, C4;
    std::cout << std::endl << std::endl;

    std::cout << "C1=";
    std::cin >> C1;
    std::cout << std::endl;

    std::cout << "C2=";
    std::cin >> C2;
    std::cout << std::endl;

    std::cout << "C3=";
    std::cin >> C3;
    std::cout << std::endl;

    std::cout << "C4=";
    std::cin >> C4;
    std::cout << std::endl;

    int C = C1 * C2 * C3 * C4;

    double Nc = (3 * pow(10, -3)) / C;

    std::cout << "The damage analysis coefficient Nc is equal to: " << Nc << std::endl;

    double Er;

    if (Nd <= Nc)
    {
        std::cout << "Lightning protection installation not required" << std::endl;
    }
    else
    {
        Er = 1 - Nc / Nd;
    }

    // int R;
    // double I;
    //std::string nivo_zastite;
    LevelOfProtection level_of_protection;

    //Determining the level of protection based on the value of the lightning rod efficiency coefficient Er 

    if (Er > 0.98)
    {

        level_of_protection = LEVEL_1D;
    }
    else if (Er > 0.95)
    {
        level_of_protection = LEVEL_1;
    }
    else if (Er > 0.9)
    {
        level_of_protection = LEVEL_2;
    }
    else if (Er > 0.8)
    {
        level_of_protection = LEVEL_3;
    }
    else if (Er > 0)
    {
        level_of_protection = LEVEL_4;
    }


    std::cout << "The lightning rod efficiency coefficient Er is equal to: " << Er << std::endl << std::endl;

    std::cout << "For Er= " << Er << " The level of protection of the lightning rod is: " << level_of_protection << std::endl;


    //****************************************************************//
    //********Selection of the appropriate grounding device***********//


    while (true)
    {

        std::string grounding_device;
        std::cout << std::endl << std::endl;

        std::cout << "Enter the name of the proposed grounding device from the following list of grounding devices:" << std::endl;

        std::ifstream list_of_grounding_devices("ListOfGroundingDevices.txt");
        std::cout << std::endl;
        while (true)
        {
            std::string name_of_grounding_device;
            list_of_grounding_devices >> name_of_grounding_device;
            if (list_of_grounding_devices)
            {
                std::cout << name_of_grounding_device << std::endl;
            }
            else
            {
                break;
            }
        }

        list_of_grounding_devices.close();

        std::cout << std::endl << std::endl;


        //Entering the name of the proposed grounding device

        std::cout << "The name of the proposed grounding device is: ";

        std::cin >> grounding_device;
        std::cout << std::endl << std::endl;


        //Entering the parameters of the selected grounding device

        std::shared_ptr<GroundingDevice> pointer = nullptr;


        pointer = entering_grounding_parameters(grounding_device);

        if (!pointer)
        {
            std::cout << "No grounding device was selected from the offered grounding devices" << std::endl;
            break;
        }


        std::cout << "Spreading  resistance value for " << pointer->name_of_grounding_device << " is : " << pointer->resistance_of_grounding_device << " oma ." << std::endl << std::endl;

        double r_omsk = pointer->resistance_of_grounding_device;
        double ro = pointer->specific_density;

        std::ifstream strike_resistance("ImpactResistance.txt");
        std::map<int, int>tab_resistance_I_level;
        std::map<int, int>tab_resistance_other_levels;
        std::vector<int>tab_density;

        while (true)
        {
            int soil_density, resistance_I_level, resistance_other_levels;
            //double b_udara;
            strike_resistance >> soil_density >> resistance_I_level >> resistance_other_levels;

            if (strike_resistance)
            {
                tab_resistance_I_level[soil_density] = resistance_I_level;
                tab_resistance_other_levels[soil_density] = resistance_other_levels;
                tab_density.push_back(soil_density);
            }
            else
            {
                break;
            }
        }

        strike_resistance.close();

        //Checking whether the spreading resistance of the selected earth electrode is within 
        //satisfactory limit compared to the level of protectionand the specific density of the soil


        int soil_density = 100;
        std::string message = "Check whether the grounding device satisfies";

        if (level_of_protection == LEVEL_1 || level_of_protection == LEVEL_1D)
        {
            message = calculate(message, ro, soil_density, r_omsk, tab_density, tab_resistance_I_level);
        }
        else
        {
            message = calculate(message, ro, soil_density, r_omsk, tab_density, tab_resistance_other_levels);
        }

        //If the selected grounding device is satisfactory, the program ends,
        //and if it is not satisfactory, then we reselect grounding device

        if (message == "The selected grounding device satisfies !") { break; };

    }
    //end of the program
};





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
