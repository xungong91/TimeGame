#include "CGameHelper.h"

Rect CGameHelper::getRectIntersection( const Rect &rect1, const Rect &rect2 )
{
	if (!rect1.intersectsRect(rect2))
	{
		return Rect::ZERO;
	}
	Point ori;    //左下角顶点     cocos2dx的CCRect是以左下角为原点，w,h为参数(宽和高)，并不是左上角是top,右下角为bottom
	Point topM;   //右下角顶点
	float width = 0.f, height = 0.f;

	ori.x = max(rect1.getMinX(), rect2.getMinX()); //左下角x坐标取两个矩形ori顶点x坐标大的
	ori.y = max(rect1.getMinY(), rect2.getMinY()); //左下角y坐标取两个矩形ori顶点y坐标大的

	topM.x = min(rect1.getMaxX(), rect2.getMaxX()); //右上角x坐标取两个矩形右上角顶点x坐标小的
	topM.y = min(rect1.getMaxY(), rect2.getMaxY());

	width = topM.x - ori.x;
	height = topM.y - ori.y;

	return CCRectMake(ori.x, ori.y, width, height);
}

Rect CGameHelper::getRectInset( const Rect &rect, float w, float h )
{
	Rect result = Rect(rect.origin.x + w, rect.origin.y + h,
		rect.size.width - w*2, rect.size.height - h*2);
	return result;
}

