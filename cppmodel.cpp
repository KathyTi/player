#include "cppmodel.h"
#include "settings.h"

CppModel::CppModel(QObject *parent):
    QAbstractListModel(parent)
{

}

int CppModel::rowCount(const QModelIndex &parent) const     //переопределим возврат количества строк листа
{
    if (parent.isValid()) {return 0;}

    return m_number.size();
}

QVariant CppModel::data(const QModelIndex &index, int role) const       //определим возврат данных о ролях элемента
{
    if (!index.isValid()) {return QVariant();}

    switch (role) {
    case nameRole:
        return m_name.at(index.row());
    case colorRole:
        return m_color.at(index.row());
    case numberRole:
        return m_number.at(index.row()+".");
    case iconRole:
        return m_icon.at(index.row());
    case pathRole:
        return m_path.at(index.row());
    case markRole:
        return m_mark.at(index.row());
    default:
        return QVariant();
    }
}
QHash<int, QByteArray> CppModel::roleNames() const      //roleNames хранит список имён ролей доступных из делегата. Переопредилим их имена в более удобные
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[nameRole] = "name";
    roles[iconRole] = "icon";
    roles[numberRole] = "number";
    roles[colorRole] = "color";
    roles[pathRole] = "path";
    roles[markRole] = "mark";

    return roles;
}
void CppModel::addElement(int indx)
{
    beginInsertRows(QModelIndex(), m_number.size(), m_number.size());
    m_name.append(indx);
    m_icon.append(indx);
    m_number.append(indx);
    m_color.append(indx);
    m_path.append(indx);
    m_mark.append(indx);
    endInsertRows();

    //QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    //emit dataChanged(index, index);
}

//currentPL, i, shuffle_state
QString CppModel::getName(int indx)
{
    QString currentpl = Settings::viewPL(Settings::getCurrentPL(), indx, Settings::getShuffleState());

    return currentpl;
}
QString CppModel::getIcon(int indx)
{
    tmpstr = Settings::loadnamefromPL(Settings::setLastTrack(Settings::getShuffleState()));
    QString currenticon = Settings::viewPL(Settings::getCurrentPL(), indx, Settings::getShuffleState()) == tmpstr ? (Settings::getStopState() == true ? "curstop.png" : Settings::getPauseState() == false ? "curplay.png" : "curpause.png") : "audio.png";

    return currenticon;
}
QString CppModel::getNumber(int indx)
{
    tmpstr = QString::number(indx);

    return tmpstr;
}
QString CppModel::getColor(int indx)
{
    tmpstr = Settings::loadnamefromPL(Settings::setLastTrack(Settings::getShuffleState()));
    QString currentcolor = Settings::viewPL(Settings::getCurrentPL(), indx, Settings::getShuffleState()) == tmpstr ? "#22acee48" : "#00000000";

    return currentcolor;
}
QString CppModel::getPath(int indx)
{
    tmpstr = Settings::getPathOfTrack(Settings::getCurrentPL(), indx, Settings::getShuffleState());

    return tmpstr;
}
QString CppModel::getMark(int indx)
{
    return "mark_next.png";
}



















