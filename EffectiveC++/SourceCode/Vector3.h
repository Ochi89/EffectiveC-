
//=============================================================================
//	@file	Vector3.h
//	@brief	演算子オーバーロードのテストプログラム
//	@autor	Takuya Ochi
//	@date	2019/05/25
//=============================================================================

//-----------------------------------------------------------------------------
//	@brief	プリプロセッサ
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
//	@brief	演算子オーバーロードのテストプログラム
//-----------------------------------------------------------------------------
class Vector3 final
{
public:

	Vector3();		//	デフォルトコンストラクタ
	~Vector3();		//	デストラクタ

	//	比較演算子の状態
	//	小さい
	enum ComparisonSmall
	{
		NONE,
		SMALL_X,
		SMALL_Y,
		SMALL_Z,
		SMALL_XY,
		SMALL_XZ,
		SMALL_YZ,
		SMALL_ALL,
	};

	//	大きい
	enum ComparisonLarge
	{
		NONE,
		LARGE_X,
		LARGE_Y,
		LARGE_Z,
		LARGE_XY,
		LARGE_XZ,
		LARGE_YZ,
		LARGE_ALL,
	};

	//	ベクトルの要素
	float x;
	float y;
	float z;

	//	加算演算子のオーバーロード
	Vector3& operator+(const Vector3& _add)
	{
		//	同じ要素同士を加算
		x += _add.x;
		y += _add.y;
		z += _add.z;
		
		return *this;
	}

	//	加減演算子のオーバーロード
	Vector3& operator-(const Vector3& _sub)
	{
		//	同じ要素同士を減算
		x -= _sub.x;
		y -= _sub.y;
		z -= _sub.z;

		return *this;
	}

	//	代入演算子のオーバーロード
	Vector3& operator=(const Vector3& _copy)
	{
		//	同じ要素同士を代入
		x = _copy.x;
		y = _copy.y;
		z = _copy.z;

		return *this;
	}

	//	スカラー倍の演算子のオーバーロード
	Vector3& operator*(const float _scale)
	{
		//	同じ要素同士を減算
		x *= _scale;
		y *= _scale;
		z *= _scale;

		return *this;
	}

	//	比較演算子のオーバーロード
	ComparisonSmall operator<=(const Vector3& _comparison)
	{
		//	同じ要素同士を比較
		//	小なりイコール
		const bool isSmallX = x <= _comparison.x;
		const bool isSmallY = y <= _comparison.y;
		const bool isSmallZ = z <= _comparison.z;
		const bool isSmallXY = isSmallX && isSmallY;
		const bool isSmallXZ = isSmallX && isSmallZ;
		const bool isSmallYZ = isSmallY && isSmallZ;
		const bool isSmallAll = isSmallX && isSmallY && isSmallZ;

		if (isSmallAll) { return ComparisonSmall::SMALL_ALL; }
		if (isSmallXY) { return ComparisonSmall::SMALL_XY; }
		if (isSmallXZ) { return ComparisonSmall::SMALL_XZ; }
		if (isSmallYZ) { return ComparisonSmall::SMALL_YZ; }
		if (isSmallX) { return ComparisonSmall::SMALL_X; }
		if (isSmallY) { return ComparisonSmall::SMALL_Y; }
		if (isSmallZ) { return ComparisonSmall::SMALL_Z; }

		return ComparisonSmall::NONE;

	}

	//	比較演算子のオーバーロード
	ComparisonSmall operator<(const Vector3& _comparison)
	{
		//	同じ要素同士を比較
		//	小なりイコール
		const bool isSmallX = x < _comparison.x;
		const bool isSmallY = y < _comparison.y;
		const bool isSmallZ = z < _comparison.z;
		const bool isSmallXY = isSmallX && isSmallY;
		const bool isSmallXZ = isSmallX && isSmallZ;
		const bool isSmallYZ = isSmallY && isSmallZ;
		const bool isSmallAll = isSmallX && isSmallY && isSmallZ;

		if (isSmallAll) { return ComparisonSmall::SMALL_ALL; }
		if (isSmallXY) { return ComparisonSmall::SMALL_XY; }
		if (isSmallXZ) { return ComparisonSmall::SMALL_XZ; }
		if (isSmallYZ) { return ComparisonSmall::SMALL_YZ; }
		if (isSmallX) { return ComparisonSmall::SMALL_X; }
		if (isSmallY) { return ComparisonSmall::SMALL_Y; }
		if (isSmallZ) { return ComparisonSmall::SMALL_Z; }

		return ComparisonSmall::NONE;

	}

	//	比較演算子のオーバーロード
	ComparisonLarge operator>=(const Vector3& _comparison)
	{
		//	同じ要素同士を比較
		//	小なりイコール
		const bool isSmallX = x >= _comparison.x;
		const bool isSmallY = y >= _comparison.y;
		const bool isSmallZ = z >= _comparison.z;
		const bool isSmallXY = isSmallX && isSmallY;
		const bool isSmallXZ = isSmallX && isSmallZ;
		const bool isSmallYZ = isSmallY && isSmallZ;
		const bool isSmallAll = isSmallX && isSmallY && isSmallZ;

		if (isSmallAll) { return ComparisonLarge::LARGE_ALL; }
		if (isSmallXY) { return ComparisonLarge::LARGE_XY; }
		if (isSmallXZ) { return ComparisonLarge::LARGE_XZ; }
		if (isSmallYZ) { return ComparisonLarge::LARGE_YZ; }
		if (isSmallX) { return ComparisonLarge::LARGE_X; }
		if (isSmallY) { return ComparisonLarge::LARGE_Y; }
		if (isSmallZ) { return ComparisonLarge::LARGE_Z; }

		return ComparisonLarge::NONE;

	}

	//	比較演算子のオーバーロード
	ComparisonLarge operator>(const Vector3& _comparison)
	{
		//	同じ要素同士を比較
		//	小なりイコール
		const bool isSmallX = x < _comparison.x;
		const bool isSmallY = y < _comparison.y;
		const bool isSmallZ = z < _comparison.z;
		const bool isSmallXY = isSmallX && isSmallY;
		const bool isSmallXZ = isSmallX && isSmallZ;
		const bool isSmallYZ = isSmallY && isSmallZ;
		const bool isSmallAll = isSmallX && isSmallY && isSmallZ;

		if (isSmallAll) { return ComparisonLarge::LARGE_ALL; }
		if (isSmallXY) { return ComparisonLarge::LARGE_XY; }
		if (isSmallXZ) { return ComparisonLarge::LARGE_XZ; }
		if (isSmallYZ) { return ComparisonLarge::LARGE_YZ; }
		if (isSmallX) { return ComparisonLarge::LARGE_X; }
		if (isSmallY) { return ComparisonLarge::LARGE_Y; }
		if (isSmallZ) { return ComparisonLarge::LARGE_Z; }

		return ComparisonLarge::NONE;

	}


};