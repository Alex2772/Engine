#version 330
// ����� ������ ���� ���������� ��������

out vec4 color;

// ��������� �� ���������� ������� ����
// �������� � ��� ������ ��������� � ��������� ��������
in vec3 pass_color;

uniform float animation;

void main() {
	// �������� -> gl_Color = vec4(1, 1, 1, 1);
	// ��� ������ ����� ����� �������� ���� �����
	
	
	color = vec4(pass_color * animation, 1);
}