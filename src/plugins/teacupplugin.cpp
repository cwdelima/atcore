/* AtCore KDE Libary for 3D Printers
    Copyright (C) <2016>

    Authors:
        Tomaz Canabrava <tcanabrava@kde.org>
        Chris Rizzitello <sithlord48@gmail.com>
        Patrick José Pereira <patrickelectric@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "teacupplugin.h"
#include "temperature.h"

#include <QLoggingCategory>
#include <QString>

#include "atcore.h"

QString TeacupPlugin::_ok = QStringLiteral("ok");

Q_LOGGING_CATEGORY(TEACUP_PLUGIN, "org.kde.atelier.core.firmware.teacup");

QString TeacupPlugin::name() const
{
    return QStringLiteral("Teacup");
}

TeacupPlugin::TeacupPlugin()
{
    qCDebug(TEACUP_PLUGIN) << name() << " plugin loaded!";
}

void TeacupPlugin::validateCommand(const QString &lastMessage)
{
    if (lastMessage.contains(_ok)) {
        emit readyForCommand();
    }
}

QByteArray TeacupPlugin::translate(const QString &command)
{
    return command.toLocal8Bit();
}
