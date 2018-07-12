#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <cmath>

class CGenerator : public QObject {
    Q_OBJECT

    static double gradToRad (double grad);

public:
    explicit CGenerator (int msTime,
                         double start = 0,
                         double step = M_PI / 500.0,
                         double maxAmplitude = 512.0,
                         QObject *parent = nullptr);

    virtual double generateDatum (double newstart = NAN);

signals:

public slots:
    void generate();

protected:
    void timerEvent (QTimerEvent *event);

    double _step = M_PI / 10.0;
    double _currentValue = 0.0;
    double _maxAmplitude = 512.0;

    bool _started = false;

};

#endif // GENERATOR_H
