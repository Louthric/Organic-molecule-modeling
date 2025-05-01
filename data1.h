// data1.h

#ifndef DATA1_H
#define DATA1_H


const int side = 175;

const int Mocycle = 1021;  // molecules

const int Moducycle = 40;	// modulators

const double hoppingTime = 10.2 * 1E8 + 1;  // steps for cycles

const int Mointerval = Mocycle / Moducycle;

const int interval = int(hoppingTime) / 100;

const double Er = 0.02;  // repulsive energy /eV
const double Ea = 1.3;   // bonding energy /eV
const double Eb = 1.2;
const double Tc = 400;    // temp./K

const double poss = 0.33;  // possible motion for dimer

const double kB = 8.625E-5;  // Boltzmann constant in eV/K unit

//取向数组
const int arrayi[6] = { -1,+0,+1,+1,+0,-1 };
const int arrayj[6] = { +0,+1,+1,+0,-1,-1 };

const int arrayii[6] = { +1,+2,+1,-1,-2,-1 };
const int arrayjj[6] = { +2,+1,-1,-2,-1,+1 };

const int arrayiii[6] = { +2,+4,+2,-2,-4,-2 };
const int arrayjjj[6] = { +4,+2,-2,-4,-2,+2 };


#endif  // DATA1_H