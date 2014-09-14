#ifndef _DEFINES_H_
#define _DEFINES_H_

#define WINSIZE cocos2d::Director::getInstance()->getWinSize()

enum class _ActionState
{
	empty = 0,
	run,
	jump
};

#endif