#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "struct.h"
#include "userlib.h"
#include "ndata.h"
#include "mixed.h"

SET_FIT_METHODS("simp","scan","min","minos");
SET_INDIVIDUAL_FITS_ENGINE(N,par);

double Meq(double tau, double N, double *par, double k )
{
  double Minf, af;

  Minf=PAR(N_0,k);

  First_Make_Individual_Fits(N,par,N_0);
  af=Minf;
  return af;
}

double Exp(double tau, double N, double *par, double p, double k, double m)
{
  double Minf, M0, T1, af;

 Minf = PAR(N_0,k);
 M0   = PAR(N_0,p);
 T1    = PAR(N_0,m);

  af=  (M0-Minf)*exp(-tau/T1);
  return af;
}


