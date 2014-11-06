#ifndef MAP_PLUGIN_H
#define MAP_PLUGIN_H

#include <QQmlExtensionPlugin>

class MapPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // MAP_PLUGIN_H

