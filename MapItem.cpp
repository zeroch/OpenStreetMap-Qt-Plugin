#include "MapItem.h"



MapItem::~MapItem()
{
}

void MapItem::componentComplete()
{
	QQuickItem *pinch = findChild<QQuickItem*>("pinchArea");
	if (pinch)
	{
            pinch->installEventFilter(getEventFilter());
	}
}
void MapItem::makePinch(QPointF center, Qt::GestureState currentState, qreal scale =1)
{
	scale = sqrt(sqrt(scale));
	scale = qBound(0.5, scale, 2.0);
	pinch(center, scale, currentState);
}

void MapItem::pinchStart(QPointF center)
{
	makePinch(center, Qt::GestureStarted);
}

void MapItem::pinchEnd(QPointF center, bool stop)
{
	// cancle the pinch or the pinch finished
	makePinch(center, stop ? Qt::GestureFinished : Qt::GestureCanceled);
}

void MapItem::pinchUpdate(QPointF center, qreal scaleFactor)
{
	makePinch(center, Qt::GestureUpdated, scaleFactor);
}

