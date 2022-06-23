#pragma once

#include <glm/glm.hpp>

namespace mc
{
	// Uses double precision for physics, then downcasts to floats for rendering, just as Mojang does (I think).
	class Vector3
	{
	public:
		constexpr Vector3() noexcept = default;
		constexpr Vector3(const Vector3&) noexcept = default;
		constexpr Vector3& operator=(const Vector3&) noexcept = default;
		constexpr Vector3(const glm::dvec3& crLocalPosition, const glm::i64vec3& crChunkPosition = glm::i64vec3(0)) noexcept;
	public:
		constexpr glm::dvec3 GetLocalPosition() const noexcept;
		constexpr glm::i64vec3 GetChunkPosition() const noexcept;
		constexpr glm::vec3 GetRenderingPosition(const Vector3& crCameraPosition) const noexcept;
	public:
		constexpr Vector3  operator+ (const Vector3& crPosition) const noexcept;
		constexpr Vector3& operator+=(const Vector3& crPosition) noexcept;
		constexpr Vector3  operator+ () const noexcept;
		constexpr Vector3  operator- (const Vector3& crPosition) const noexcept;
		constexpr Vector3& operator-=(const Vector3& crPosition) noexcept;
		constexpr Vector3  operator- () const noexcept;
	private:
		constexpr void Normalize() noexcept;
	private:
		glm::dvec3 m_LocalPosition{ 0.0 };
		glm::i64vec3 m_ChunkPosition{ 0 };
	};
}

#include "Minecraft/Vector3.inl"
