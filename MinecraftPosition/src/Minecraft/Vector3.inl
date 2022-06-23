#include "Minecraft/Constants.h"

namespace mc
{
	constexpr Vector3::Vector3(const glm::dvec3& crLocalPosition, const glm::i64vec3& crChunkPosition) noexcept
		: m_LocalPosition(crLocalPosition)
		, m_ChunkPosition(crChunkPosition)
	{
		Normalize();
	}

	constexpr glm::dvec3 Vector3::GetLocalPosition() const noexcept
	{
		return m_LocalPosition;
	}

	constexpr glm::i64vec3 Vector3::GetChunkPosition() const noexcept
	{
		return m_ChunkPosition;
	}

	constexpr glm::vec3 Vector3::GetRenderingPosition(const Vector3& crCameraPosition) const noexcept
	{
		return glm::dvec3((m_ChunkPosition - crCameraPosition.m_ChunkPosition) * s_ChunkBlockSize) + (m_LocalPosition - crCameraPosition.m_LocalPosition);
	}

	constexpr Vector3 Vector3::operator+(const Vector3& crPosition) const noexcept
	{
		return +*this += crPosition;
	}

	constexpr Vector3& Vector3::operator+=(const Vector3& crPosition) noexcept
	{
		m_LocalPosition += crPosition.m_LocalPosition;
		m_ChunkPosition += crPosition.m_ChunkPosition;
		Normalize();
		return *this;
	}

	constexpr Vector3 Vector3::operator+() const noexcept
	{
		return Vector3(+m_LocalPosition, +m_ChunkPosition);
	}

	constexpr Vector3 Vector3::operator-(const Vector3& crPosition) const noexcept
	{
		return +*this -= crPosition;
	}

	constexpr Vector3& Vector3::operator-=(const Vector3& crPosition) noexcept
	{
		m_LocalPosition -= crPosition.m_LocalPosition;
		m_ChunkPosition -= crPosition.m_ChunkPosition;
		Normalize();
		return *this;
	}

	constexpr Vector3 Vector3::operator-() const noexcept
	{
		return Vector3(-m_LocalPosition, -m_ChunkPosition);
	}

	// Normalizes the vector's local position into (-s_ChunkBlockSize, s_ChunkBlockSize)
	// and puts the excess position information in its chunk position.
	constexpr void Vector3::Normalize() noexcept
	{
		glm::i64vec3 excessChunkPosition = m_LocalPosition / static_cast<double>(s_ChunkBlockSize);
		m_ChunkPosition += excessChunkPosition;
		m_LocalPosition -= excessChunkPosition * s_ChunkBlockSize;
	}
}
