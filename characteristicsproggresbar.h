#ifndef CHARACTERISTICSPROGGRESBAR_H
#define CHARACTERISTICSPROGGRESBAR_H
#include "stdafx.h"

class characteristicsProggresBar : public QProgressBar
{
    Q_OBJECT

public:
    characteristicsProggresBar(QWidget* container);
private slots:
    void progressChanged(int current, int total);
};

#endif // CHARACTERISTICSPROGGRESBAR_H
