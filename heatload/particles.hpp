#ifndef PARTICLES_HPP
#define PARTICLES_HPP

// Phase + ct + B data structure from XGC
struct Phase{
    double r;
    double z;
    double phi;
    double rho;
    double w1;
    double w2;
    double mu;
    double w0;
    double f0;
    double B;
    double psi;
};

//particle data strcuture 
class Particles {

    Phase ph;
    long long int gid;
    int flag;
    int esc_step;

};

//#include "particles.tpp"
#endif