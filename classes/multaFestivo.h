#ifndef MULTAFESTIVA_H
#define MULTAFESTIVA_H
#include <string>

#include "Multa.h"

class MultaPeriodoFestivo : public Multa
{
public:
    double calcularMulta() override;
};

#endif