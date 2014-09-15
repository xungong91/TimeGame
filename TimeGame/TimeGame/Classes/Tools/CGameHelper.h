#ifndef _C_GAME_HELPER_H_
#define _C_GAME_HELPER_H_

#include "cocos2d.h"
#include <algorithm>

USING_NS_CC;
using namespace std;

class CGameHelper
{
public:
	static Rect getRectIntersection(const Rect &rect1, const Rect &rect2);
	static Rect getRectInset(const Rect &rect, float w, float h);
private:
};
#endif