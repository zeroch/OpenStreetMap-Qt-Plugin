// reference from MarbleQuickItem.
// #include "GeoDataPlacemark.h"
// #include "MarbleGlobal.h"
#ifndef MAPQUICKITEM_H
#define MAPQUICKITEM_H
namespace pasa
{
	//TODO, MARBLE_EXPORT link
	class MapQuickItem : public QQuickPaintedItem
	{
		Q_OBJECT
	public:
		MapQuickItem(QQuickItem *parent = 0);
		~MapQuickItem();
	public slots:
		// void goHome();
		// void setZoom();
		// void centerOn(const GeoDataPlacemark& placemark, bool animated = false);

		void zoomIn(FlyToMode mode = Automatic);
		void zoomOut(FlyToMode mode = Automatic);
	public:
		void paint(QPainter *painter);

		void classBegin();
		void componentComplete();

	protected:
		MapModel* model();
		const MapModel* model() const;

		Map* map();
		const Map* map() const;

		QObject *getEventFilter() const;
		void pinch(QPointF center, qreal scale, Qt::GestureState state);

	private:
		typedef QSharedPointer<MapQuickItemPrivate> MapQuickItemPrivatePtr;
		MapQuickItemPrivatePtr p;
		friend class MapQuickItemPrivate;
	};
}
#endif

