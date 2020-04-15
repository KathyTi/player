#ifndef CPPMODEL_H
#define CPPMODEL_H
#include <QString>
#include <QModelIndex>

class CppModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    //explicit CppModel(QObject/*QAbstractItemModel*/ *parent = nullptr);
    //Q_INVOKABLE QString name;
    //Q_INVOKABLE QString icon;
    //Q_INVOKABLE QString number;
    //Q_INVOKABLE QString color;
    //Q_INVOKABLE QString path;
    //Q_INVOKABLE QString mark_next;
    enum Roles{
        nameRole = Qt::UserRole+1,
        iconRole,
        numberRole,
        colorRole,
        pathRole,
        markRole
    };
    CppModel(QObject *parent = 0);
public slots:
    //rowCount, data, roles и в твоем случае canFetchMore и FetchMore.
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;
    void addElement(int indx);
    QString getName(int indx);
    QString getIcon(int indx);
    QString getNumber(int indx);
    QString getColor(int indx);
    QString getPath(int indx);
    QString getMark(int indx);
private:
    QStringList m_name;
    QStringList m_icon;
    QStringList m_number;
    QStringList m_color;
    QStringList m_path;
    QStringList m_mark;
    QString tmpstr;
};

#endif // CPPMODEL_H
