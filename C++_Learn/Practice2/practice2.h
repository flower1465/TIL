#pragma once

class CMyData {
private:
	int m_nX;
public:
	CMyData():m_nX(0) {
		//m_nX = 0;
	}
	CMyData(int nx):m_nX(nx) {
		SetData(nx);
	}
	int GetData() const { return m_nX; };
	void SetData(int nX) {
		m_nX = nX;
	}
};

class CMyDataEX : public CMyData
{
public:
	CMyDataEX():m_nY(0) {}
	CMyDataEX(int nx, int ny) {
		SetData(nx, ny);
	}
	void SetData(int nx, int ny) {
		CMyData::SetData(nx);
		m_nY = ny;
	}
	int GetX() {
		return CMyData::GetData();
	}
	int GetY() {
		return m_nY;
	}

private:
	int m_nY;
};