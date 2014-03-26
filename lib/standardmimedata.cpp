#include "standardmimedata.h"

StandardMimeData::StandardMimeData() :
    QMimeData()
{

}
StandardMimeData::~StandardMimeData(){

}

void StandardMimeData::setIndexes(QModelIndexList indexes){
    _indexes = indexes;
}
QModelIndexList StandardMimeData::getIndexes() const{
    return _indexes;
}
