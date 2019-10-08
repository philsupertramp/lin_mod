/**
 * File              : insurance.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 08.10.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
#ifndef INSURANCE_H
#define INSURANCE_H

#include "../typedef.h"

double compoundingFactor(double i);
double discountFactor(double i);
double fundamentalValue(interest);
double endValue(interest);
double termInPeriods(interest);
double fundamentalValueOfAnnuityInAdvance(interest);
double endValueOfAnnuityInAdvance(interest);
double fundamentalValueOfAnnuityInArrear(interest);
double endValueOfAnnuityInArrear(interest);


#endif
