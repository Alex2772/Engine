#version 330
// здесь версию тоже необходимо помечать

out vec4 color;

// принимаем от вершинного шейдера цвет
// название и тип должны совпадать с вершинным шейдером
in vec2 pass_uv;


// принимаем текстуру
uniform sampler2D tex;

void main() {
	// устарело -> gl_Color = vec4(1, 1, 1, 1);
	// для вывода цвета нужно объявить один выход
	
	
	color = texture(tex, pass_uv);
}

