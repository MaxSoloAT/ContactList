#include "contactlistmodel.h"

ContactListModel::ContactListModel(QObject *parent) : QAbstractListModel{parent}
{

    //create 50 people(contacts, generate images, names+surnames)
    int ListSize = 50;
    QString Name = "Name";
    QString Surname = "Surname";

    for(int i = 0; i < ListSize; i++)
    {
        QImage image(128, 128, QImage::Format_RGB32);
        QRgb value;
        value = qRgb(189+i, 149-i, 39+i);
        image.fill(QColor(value));
        QString ImageName = QString::number(i)+".png";
        image.save(ImageName);
        bool fav=false;
        AllContact.push_back({Name + QString::number(i) + " " + Surname + QString::number(i),QDir::currentPath()+"/"+ImageName,"+108050" + QString::number(i),fav});
    }

    roles[NameAndSurnameRole] = "name";
    roles[ImagePathRole] = "path";
    roles[PhoneRole] = "phone";
    roles[FavoritteRole] = "favorite";

}
int ContactListModel::rowCount(const QModelIndex& parent ) const //size
{
    Q_UNUSED(parent);
    return AllContact.size();
}

QVariant ContactListModel::data(const QModelIndex& index, int role) const //data for each role
{

    if(!index.isValid())
    {
        return QVariant{};
    }
    const int rowIndex{index.row()};

    switch (role) {
        case NameAndSurnameRole: return QVariant::fromValue(AllContact.at(rowIndex).Name);
        case ImagePathRole: return QVariant::fromValue(AllContact.at(rowIndex).Path);
        case PhoneRole: return QVariant::fromValue(AllContact.at(rowIndex).Phone);
        default: return QVariant();
    }
}

QHash<int, QByteArray> ContactListModel::roleNames() const //custom roles
{
    return roles;
}

void ContactListModel::getIndex(QVariant index) //get index for phone
{
    indexphone = index.toInt();
}

void ContactListModel::makeCall() //confirm call
{
    call(indexphone);
}

void ContactListModel::call(int index) //do call
{
    QString PhoneNumber = AllContact.at(index).Phone;
    qDebug()<<PhoneNumber<<endl;
}

