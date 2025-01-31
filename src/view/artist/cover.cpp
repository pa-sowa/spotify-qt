#include "view/artist/cover.hpp"

View::Artist::Cover::Cover(QWidget *parent)
	: QLabel(parent)
{
	setFixedHeight(maxHeight);
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
}

void View::Artist::Cover::setJpeg(const QByteArray &jpeg)
{
	cover.loadFromData(jpeg, "jpeg");
	scaleCover(width());
}

void View::Artist::Cover::resizeEvent(QResizeEvent *event)
{
	if (cover.isNull())
	{
		QWidget::resizeEvent(event);
		return;
	}
	scaleCover(event->size().width());
}

void View::Artist::Cover::scaleCover(int width)
{
	auto pixmap = cover.scaled(width, maxHeight,
		Qt::KeepAspectRatioByExpanding);

	const auto adjust = pixmap.height() - maxHeight;
	if (adjust > 0)
	{
		pixmap = pixmap.copy(0, adjust / 2,
			width, maxHeight);
	}

	setFixedHeight(pixmap.height());
	QLabel::setPixmap(pixmap);
}
