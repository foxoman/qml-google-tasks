#include "settings_manager.h"
#include <QSettings>
#include <QDebug>

SettingsManager::SettingsManager(QObject *parent) :
    QObject(parent)
{
    m_organization = "ICS";
    m_application  = "Tasks Client";

    QSettings::setPath(QSettings::NativeFormat, QSettings::UserScope, "qml/google_api_tasks_qml");
    QSettings settings(QSettings::UserScope, m_organization, m_application);
    m_strAccessToken = settings.value("access_token", "").toString();
    m_strRefreshToken = settings.value("refresh_token", "").toString();
    //m_strRefreshToken = "";
}

QVariant SettingsManager::accessToken() const
{
    return m_strAccessToken;
}

void SettingsManager::setAccessToken(const QVariant& token)
{
    m_strAccessToken = token.toString();
    QSettings settings(QSettings::UserScope, m_organization, m_application);
    settings.setValue("access_token", m_strAccessToken);
}

QVariant SettingsManager::refreshToken() const
{
    return m_strRefreshToken;
}

void SettingsManager::setRefreshToken(const QVariant& token)
{
    m_strRefreshToken = token.toString();
    QSettings settings(QSettings::UserScope, m_organization, m_application);
    settings.setValue("refresh_token", m_strRefreshToken);
}
