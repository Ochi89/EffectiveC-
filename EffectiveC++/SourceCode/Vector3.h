
//=============================================================================
//	@file	Vector3.h
//	@brief	���Z�q�I�[�o�[���[�h�̃e�X�g�v���O����
//	@autor	Takuya Ochi
//	@date	2019/05/25
//=============================================================================

//-----------------------------------------------------------------------------
//	@brief	�v���v���Z�b�T
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
//	@brief	���Z�q�I�[�o�[���[�h�̃e�X�g�v���O����
//-----------------------------------------------------------------------------
class Vector3 final
{
public:

	Vector3();		//	�f�t�H���g�R���X�g���N�^
	~Vector3();		//	�f�X�g���N�^

	//	��r���Z�q�̏��
	//	������
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

	//	�傫��
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

	//	�x�N�g���̗v�f
	float x;
	float y;
	float z;

	//	���Z���Z�q�̃I�[�o�[���[�h
	Vector3& operator+(const Vector3& _add)
	{
		//	�����v�f���m�����Z
		x += _add.x;
		y += _add.y;
		z += _add.z;
		
		return *this;
	}

	//	�������Z�q�̃I�[�o�[���[�h
	Vector3& operator-(const Vector3& _sub)
	{
		//	�����v�f���m�����Z
		x -= _sub.x;
		y -= _sub.y;
		z -= _sub.z;

		return *this;
	}

	//	������Z�q�̃I�[�o�[���[�h
	Vector3& operator=(const Vector3& _copy)
	{
		//	�����v�f���m����
		x = _copy.x;
		y = _copy.y;
		z = _copy.z;

		return *this;
	}

	//	�X�J���[�{�̉��Z�q�̃I�[�o�[���[�h
	Vector3& operator*(const float _scale)
	{
		//	�����v�f���m�����Z
		x *= _scale;
		y *= _scale;
		z *= _scale;

		return *this;
	}

	//	��r���Z�q�̃I�[�o�[���[�h
	ComparisonSmall operator<=(const Vector3& _comparison)
	{
		//	�����v�f���m���r
		//	���Ȃ�C�R�[��
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

	//	��r���Z�q�̃I�[�o�[���[�h
	ComparisonSmall operator<(const Vector3& _comparison)
	{
		//	�����v�f���m���r
		//	���Ȃ�C�R�[��
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

	//	��r���Z�q�̃I�[�o�[���[�h
	ComparisonLarge operator>=(const Vector3& _comparison)
	{
		//	�����v�f���m���r
		//	���Ȃ�C�R�[��
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

	//	��r���Z�q�̃I�[�o�[���[�h
	ComparisonLarge operator>(const Vector3& _comparison)
	{
		//	�����v�f���m���r
		//	���Ȃ�C�R�[��
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