#include "Texture.h"

#include <cassert>

GL::Texture::Texture()
{
	glGenTextures(1, &mHandle);
	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
}

GL::Texture::~Texture()
{
	glDeleteTextures(1, &mHandle);
}

void GL::Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, mHandle);
}

void GL::Texture::setImage(const Image& image)
{
	bind();
	
	GLenum glFormat;

	switch (image.getFormat())
	{
	case Image::RGB:
		glFormat = GL_RGB;
		break;
	case Image::RGBA:
		glFormat = GL_RGBA;
		break;

	default:
		assert(0);
	}
	
	glTexImage2D(GL_TEXTURE_2D,
				 0,
		         glFormat,
		         image.getWidth(),
		         image.getHeight(),
		         0,
		         glFormat, 
		         GL_UNSIGNED_BYTE,
		         image.getData().data());
}
