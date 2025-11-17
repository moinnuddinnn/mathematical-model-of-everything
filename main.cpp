
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
//

//mathematical framework represented by a class
class OuterVenv {
    private:
    //smallest non-zero non-negitive number(hypothetical)
    long double a000;
    //dynamic factor
    long double u;
    //Explaination: A dynamic number is a data form that consists of a smallest unit "a000" and a dynamic factor "u". the smallest unit represents the minimal quantifiable value, while the dynamic factor allows for variability and evolution of the number over time or operations wrt to the expansion of the spacetime's metric..
    //long double a001; //material pointlike aspect
    //long double a002; //wave-like aspect

    class MEPointLike {
        //a mass-energy pointlikes have a dynamic factor 0, meaning it cannot evolve exponentially over time and they follow E8​→SU(3)C​×SU(2)L​×U(1)Y​×(others)
        private:
        long double a001; //mass-energy pointlike aspect

        public:
        MEPointLike(long double init_a001 = 1e308) : a001(init_a001) {} 

        
    };

    public:
    //declaring constructor/parameterized constructor: lets you create an objevt and manually define a000 and u. but we wont be using them here because ur broke asf lol
    OuterVenv(long double init_a000 = 1e308, long double init_u = 1e308) : a000(init_a000), u(init_u) {}
    //default constructor
    //OuterVenv(); lets not define it here because idk

    //disply method
    void display() const {
        std::cout << "X = " << a000 << " + " << u << std::endl;
    }

    //exponential growth ova time
    void exponentialGrowth(long double rate, int duration_seconds) {
        auto start = std::chrono::steady_clock::now();
        while (true) {
            auto now = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = now - start;
            if (elapsed_seconds.count() >= duration_seconds) break;

            // exponential grouth for u/dynamic factor
            u = a000 * std::exp(rate * elapsed_seconds.count());

            //show progresss
            std::cout << "t = " << elapsed_seconds.count() << "s: X = ";
            display();

            //making it sleep a bit to avoid spamming
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        std::cout << "\nEvolution ended after: " << duration_seconds << " seconds." << std::endl;

    }

};    

int main() {
    OuterVenv X;
    X.display();

    std::cout << "Starting exponential growth simulation..." << std::endl;
    X.exponentialGrowth(0.1L, 5); // rate=0.1, duration=5 seconds

    return 0;
}

