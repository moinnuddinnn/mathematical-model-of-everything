#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>

//mathematical framework represented by a class
class DynamicNumerals {
    private:
    //smallest non-zero non-negitive number(hypothetical)
    long double a0;
    //dynamic factor
    long double u;
    //Explaination: A dynamic number is a data form that consists of a smallest unit "a0" and a dynamic factor "u". the smallest unit represents the minimal quantifiable value, while the dynamic factor allows for variability and evolution of the number over time or operations wrt to the expansion of the spacetime's metric..


    public:
    //declaring constructor
    DynamicNumerals(long double init_a0, long double init_u);
    //default constructor
    DynamicNumerals();

    //disply method
    void display() const {
        std::cout << "X = " << a0 << " + " << u << std::endl;
    }

    //operator overloading for addition
    DynamicNumerals operator+(const DynamicNumerals& other) const {
        return DynamicNumerals(a0, u + other.u);
    }

    //connection operation (⊗)
    DynamicNumerals connect(const DynamicNumerals& other) const {
        long double connected_u = sqrt(u * other.u + 1); // arbitrary for demo
        return DynamicNumerals(a0, connected_u);
    }   

    //method to evolve dynamic factor u
    void evolve(long double delta) {
        u += delta;
    }
};
