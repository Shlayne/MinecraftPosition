#include "Test.h"
#include "Minecraft/Vector3.h"
#include <iostream>

template<typename T, glm::qualifier Q = glm::defaultp>
std::ostream& operator<<(std::ostream& ostream, const glm::vec<3, T, Q>& vec3)
{
	return ostream
		<< '<'
			<< vec3.x << ','
			<< vec3.y << ','
			<< vec3.z
		<< '>';
}

std::ostream& operator<<(std::ostream& rOstream, const mc::Vector3& crPosition)
{
	return rOstream
		<< "Position{"
			<< "Local=" << crPosition.GetLocalPosition()
			<< ", Chunk=" << crPosition.GetChunkPosition()
			<< ", Rendering=" << crPosition.GetRenderingPosition({ glm::dvec3(0.0), glm::i64vec3(1LL << 48, 0, 0) })
		<< '}';
}

namespace test
{
	void Perform()
	{
		mc::Vector3 pos{ glm::dvec3(11.35, 21.672, 31.6358), glm::i64vec3((1LL << 48) + 1, 2, 3) };

		pos += glm::dvec3(18.0234, 13.1345, -2.542);

		std::cout << pos << '\n';
		std::cin.get();
	}
}
