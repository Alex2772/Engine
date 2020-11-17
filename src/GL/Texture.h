#pragma once
#include "gl.h"
#include "Util/Image.h"

namespace GL
{
	class Texture
	{
	private:
		GLuint mHandle;

	public:
		Texture();
		~Texture();
		Texture(const Texture&) = delete;

		void bind();
		
		/**
		 * \brief ��������� ����������� � ��������.
		 */
		void setImage(const Image& image);
	};
}
