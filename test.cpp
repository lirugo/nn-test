#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Weight {
    public:
        double weight;
};

class Neuron {
    public:
        double net;
        double out;
        Weight w1;
        Weight w2;

    double getOut(){
        return 1/(1+pow(M_E, -net));
    }
};







int main()
{
    //Init
    double error1, error2, totalError;
    double target1, target2;
    double b1 = 0.35, b2 = 0.60;
    Neuron i1, i2, h1, h2, o1, o2;
    Weight w1, w2, w3, w4, w5, w6, w7, w8;
    i1.out = 0.05;
    i2.out = 0.10;
    target1 = 0.01;
    target2 = 0.99;

    w1.weight = 0.15;
    w2.weight = 0.20;
    w3.weight = 0.25;
    w4.weight = 0.30;
    w5.weight = 0.40;
    w6.weight = 0.45;
    w7.weight = 0.50;
    w8.weight = 0.55;

    //////////////////////////
    // --- FORWARD PASS --- //
    //////////////////////////

    /// Step 1 - get h1, h2
    h1.net = i1.out*w1.weight + i2.out*w2.weight + b1*1;
    h2.net = i1.out*w3.weight + i2.out*w4.weight + b1*1;

    /// Step 2 - get o1, o2
    o1.net = h1.getOut()*w5.weight + h2.getOut()*w6.weight + b2*1;
    o2.net = h1.getOut()*w7.weight + h2.getOut()*w8.weight + b2*1;

    /// Step 3 - get errors
    error1 = 0.5*pow((target1-o1.getOut()), 2);
    error2 = 0.5*pow((target2-o2.getOut()), 2);
    totalError = error1 + error2;



    ///////////////////////////
    // --- BACKWARD PASS --- //
    ///////////////////////////

    // TODO ....


    ///////////////////////////
    // -------- OUT -------- //
    ///////////////////////////



    cout << error1 << endl;
    cout << error2 << endl;
    cout << totalError << endl;


    return 0;
} 