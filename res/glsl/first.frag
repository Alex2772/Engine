#version 330
// здесь версию тоже необходимо помечать

out vec4 color;

// принимаем от вершинного шейдера цвет
// название и тип должны совпадать с вершинным шейдером
in vec3 pass_color;

uniform float animation;

void main() {
	// устарело -> gl_Color = vec4(1, 1, 1, 1);
	// дл€ вывода цвета нужно объ€вить один выход
	
	
	color = vec4(pass_color * animation, 1);
}