#include "generator.h"

#include <cmath>
#include <QTextStream>

#include <iostream>
#include <iomanip>

double CGenerator::gradToRad (double grad)
{
    return std::sin (grad * M_PI / 180.0);
}

CGenerator::CGenerator (int msTime,
                        double start,
                        double step,
                        double maxAmplitude,
                        QObject *parent)
    : QObject (parent),
      _step (step),
      _currentValue (start),
      _maxAmplitude (maxAmplitude)
{
    startTimer (msTime);
}

// generate datum
double CGenerator::generateDatum (double newseed)
{
    if ( std::isnan (newseed) == false)
    {
        _currentValue = newseed;
    }
    else
    {
        if (_started)
        {
            _currentValue += _step;
        }
        else
        {
            _started = true;
        }
    }

    double ret = std::sin (_currentValue) * _maxAmplitude;

    return ret;
}

// print to screen
void CGenerator::generate()
{
    std::cout << std::fixed
              << std::setprecision (0)
              << generateDatum() <<
              std::endl;
}

void CGenerator::timerEvent (QTimerEvent *event)
{
    Q_UNUSED (event);
    generate();
}
