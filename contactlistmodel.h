#ifndef CONTACTLISTMODEL_H
#define CONTACTLISTMODEL_H
#include <QAbstractListModel>
#include <QDebug>
#include <QImage>
#include <QDir>
#include <QList>
class ContactListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles
    {
        NameAndSurnameRole = Qt::DisplayRole,
        ImagePathRole = Qt::UserRole,
        PhoneRole = Qt::UserRole + 2,
        FavoritteRole = Qt::UserRole + 3
    };
    Q_ENUM(Roles)

    explicit ContactListModel(QObject *parent = nullptr);

    struct ContactList
    {
        QString Name;
        QString Path;
        QString Phone;
        bool Favorite;
    };

    QList<ContactList> AllContact;

    int rowCount(const QModelIndex& parent = QModelIndex{})const override;
    QVariant data(const QModelIndex& index ,int role = Qt::DisplayRole)const override;

    Q_INVOKABLE void getIndex(QVariant index);
    Q_INVOKABLE void makeCall();

protected:
    QHash<int, QByteArray> roleNames() const override;
    void call(int index);
private:
    QHash<int, QByteArray> roles;
    int indexphone;
};

#endif // CONTACTLISTMODEL_H

