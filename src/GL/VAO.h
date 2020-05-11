#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace GL
{
	class VAO
	{
	private:
		/**
		 * \brief Объект VAO
		 */
		unsigned int mVao;

		/**
		 * \brief Обычные буферы атрибутов
		 */
		std::vector<unsigned int> mBuffers;

		/**
		 * \brief Буфер индексов
		 */
		unsigned mIndicesBuffer = 0;

		/**
		 * \brief Количество индексов
		 */
		size_t mIndicesCount = 0;
		
	public:
		VAO();
		VAO(const VAO&) = delete;
		void bind();
		void draw(unsigned type = 0x0004);
		void addVertexBufferObject(const std::vector<float>& data);
		void addVertexBufferObject(const std::vector<glm::vec2>& data);
		void addVertexBufferObject(const std::vector<glm::vec3>& data);
		void addVertexBufferObject(const std::vector<glm::vec4>& data);
		void addIndices(const std::vector<unsigned>& data);
		~VAO();
	};
}
