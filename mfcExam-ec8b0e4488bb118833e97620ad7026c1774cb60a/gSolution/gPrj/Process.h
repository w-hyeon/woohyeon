#pragma once

// CProcess ��� ����Դϴ�.


class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

	int getStarInfo(CImage* image, int nTh);
};


