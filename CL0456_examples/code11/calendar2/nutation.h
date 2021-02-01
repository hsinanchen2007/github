#ifndef __NUTATION_PARAM_H__
#define __NUTATION_PARAM_H__


/*計算某時刻的黃經章動干擾量，dt是儒略千年數，返回值單位是度*/
double CalcEarthLongitudeNutation(double dt);

/*計算某時刻的黃赤交角章動干擾量，dt是儒略千年數，返回值單位是度*/
double CalcEarthObliquityNutation(double dt);


#endif //__NUTATION_PARAM_H__



