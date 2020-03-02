#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace GL
{
	class VAO
	{
	private:
		unsigned int mVao;
		std::vector<unsigned int> mBuffers;
	public:
		VAO();
		VAO(const VAO&) = delete;
		void bind();
		void draw(size_t count);
		void addVertexBufferObject(const std::vector<float>& data);
		void addVertexBufferObject(const std::vector<glm::vec2>& data);
		void addVertexBufferObject(const std::vector<glm::vec3>& data);
		void addVertexBufferObject(const std::vector<glm::vec4>& data);
		~VAO();
	};
}
