#include "sml.hpp"
#include "adios2.h"
#include "heatload.hpp"

extern Simulation sml;

void init() {
    adios2::ADIOS ad;
    adios2::Engine reader;
    adios2::IO reader_io;

    reader_io = ad.DeclareIO("init");
    reader = reader_io.Open("xgc.units.bp", adios2::Mode::Read);

    double sml_e_charge, sml_prot_mass;
    double ptl_mass_au, ptl_charge_eu, ptl_e_mass_au, ptl_e_charge_eu;
    reader.Get<double>("eq_x_psi", sml.psix);
    reader.Get<double>("sml_e_charge", sml_e_charge);
    reader.Get<double>("sml_prot_mass", sml_prot_mass);
    reader.Get<double>("ptl_mass_au", ptl_mass_au);
    reader.Get<double>("ptl_charge_eu", ptl_charge_eu);
    reader.Get<double>("ptl_e_mass_au",  ptl_e_mass_au);
    reader.Get<double>("ptl_e_charge_eu", ptl_e_charge_eu);
    reader.Get<double>("diag_heat_rmin1", sml.rmin[0] );
    reader.Get<double>("diag_heat_rmax1", sml.rmax[0] );
    reader.Get<double>("diag_heat_zmin1", sml.zmin[0] );
    reader.Get<double>("diag_heat_zmax1", sml.zmax[0] );
    reader.Get<double>("diag_heat_pmin1", sml.pmin[0] );
    reader.Get<double>("diag_heat_pmax1", sml.pmax[0] );
    reader.Get<double>("diag_heat_rmin2", sml.rmin[1] );
    reader.Get<double>("diag_heat_rmax2", sml.rmax[1] );
    reader.Get<double>("diag_heat_zmin2", sml.zmin[1] );
    reader.Get<double>("diag_heat_zmax2", sml.zmax[1] );
    reader.Get<double>("diag_heat_pmin2", sml.pmin[1] );
    reader.Get<double>("diag_heat_pmax2", sml.pmax[1] );
    reader.Close();

    sml.npsi =  N_PSI;
    sml.ncond = N_COND;

    sml.c2_2m[0] = (sml_e_charge * ptl_e_charge_eu) * (sml_e_charge * ptl_e_charge_eu) * 0.5 / (ptl_e_mass_au * sml_prot_mass);
    sml.c2_2m[1] = (sml_e_charge * ptl_charge_eu) * (sml_e_charge * ptl_charge_eu) * 0.5 / (ptl_mass_au * sml_prot_mass);
    
    sml.dpsi[0]=(sml.pmax[0]-sml.pmin[0])/static_cast<double>(sml.npsi-1);
    sml.dpsi[1]=(sml.pmax[1]-sml.pmin[1])/static_cast<double>(sml.npsi-1);
}