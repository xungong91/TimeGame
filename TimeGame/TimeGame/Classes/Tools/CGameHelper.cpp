#include "CGameHelper.h"

Rect CGameHelper::getRectIntersection( const Rect &rect1, const Rect &rect2 )
{
	if (!rect1.intersectsRect(rect2))
	{
		return Rect::ZERO;
	}
	Point ori;    //���½Ƕ���     cocos2dx��CCRect�������½�Ϊԭ�㣬w,hΪ����(��͸�)�����������Ͻ���top,���½�Ϊbottom
	Point topM;   //���½Ƕ���
	float width = 0.f, height = 0.f;

	ori.x = max(rect1.getMinX(), rect2.getMinX()); //���½�x����ȡ��������ori����x������
	ori.y = max(rect1.getMinY(), rect2.getMinY()); //���½�y����ȡ��������ori����y������

	topM.x = min(rect1.getMaxX(), rect2.getMaxX()); //���Ͻ�x����ȡ�����������ϽǶ���x����С��
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

