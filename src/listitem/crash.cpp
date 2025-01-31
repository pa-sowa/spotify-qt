#include "listitem/crash.hpp"

ListItem::Crash::Crash(const lib::crash_info &crashInfo, QListWidget *parent)
	: QListWidgetItem(parent)
{
	auto dateTime = QDateTime::fromSecsSinceEpoch(crashInfo.timestamp);
	setText(QLocale::system().toString(dateTime, QLocale::ShortFormat));

	setData(static_cast<int>(ListItem::Crash::Role::StackTrace),
		QString::fromStdString(crashInfo.to_string()));
	setData(static_cast<int>(ListItem::Crash::Role::Timestamp), dateTime);
}

auto ListItem::Crash::operator<(const QListWidgetItem &item) const -> bool
{
	auto role = static_cast<int>(ListItem::Crash::Role::Timestamp);
	return data(role).toDateTime() < item.data(role).toDateTime();
}
