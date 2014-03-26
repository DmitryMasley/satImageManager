#include "characteristicsproggresbar.h"

characteristicsProggresBar::characteristicsProggresBar(QWidget *container):QProgressBar(container)
{
}
void characteristicsProggresBar::progressChanged(int current, int total)
{
    if (current !=0)
    {
        this->setValue((int)(100*current/total));
    }
    else
    {
        this->setValue(0);
    }
}
