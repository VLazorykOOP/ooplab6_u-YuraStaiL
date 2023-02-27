#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std; //  гоглг
namespace SpaceExample2 {
    class Progression {
    public:
        Progression(double first, double constant) : first(first), constant(constant) {}
        virtual double progressionSum(int n) = 0;

        double getFirst()
        {
            return first;
        }

        double getConstant()
        {
            return first;
        }
    protected:
        double first;
        double constant;
    };

    class ArithmeticProgression : public Progression {
    public:
        ArithmeticProgression(double first, double constant) : Progression(first, constant) {}
        double progressionSum(int n) override {
            return n * (2 * first + (n - 1) * constant) / 2;
        }
    };

    class GeometricProgression : public Progression {
    public:
        GeometricProgression(double first, double constant) : Progression(first, constant) {}
        double progressionSum(int n) override {
            return (first * (std::pow(constant, n) - 1)) / (constant - 1);
        }
    };
    int mainExample2()
    {
        
        Progression* progressions[2];
        ArithmeticProgression arithmeticProgression(1.0, 2.0);
        GeometricProgression geometricProgression(1.0, 2.0);
        progressions[0] = &arithmeticProgression;
        progressions[1] = &geometricProgression;

        for (int i = 0; i < 2; ++i) {
            std::cout << "Sum of " << (i == 0 ? "arithmetic" : "geometric") << " progression of first element " << progressions[i]->getFirst() << " and constant " << progressions[i]->getConstant() << " for n = 10: " << progressions[i]->progressionSum(10) << std::endl;
        }

        return 0;
    }


}