#pragma once
#include <vector>

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
		~VAO();
	};
}
