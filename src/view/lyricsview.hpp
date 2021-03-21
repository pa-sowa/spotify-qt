#pragma once

class LyricsView;

#include "../mainwindow.hpp"

#include <QDockWidget>

class LyricsView: public QDockWidget
{
Q_OBJECT

public:
	LyricsView(const std::string &artist, const std::string &name, QWidget *parent);

	bool lyricsFound() const;

private:
	static QString format(const QString &word);

	bool found;
};