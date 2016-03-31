#include "imageparameter.h"

ImageParameter::ImageParameter(QObject *parent) : AbstractItem(parent)
{

}
ImageParameter::ImageParameter(bool isRoot, QObject *parent) : AbstractItem(isRoot, parent){

}

ImageParameter::ImageParameter(QList<QMap<int, QVariant> > _data, QObject *parent, bool isRoot) : AbstractItem(_data, parent, isRoot){

}

ImageParameter::~ImageParameter()
{

}

