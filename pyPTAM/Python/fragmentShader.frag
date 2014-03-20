#version 130

uniform Material {
	vec4 diffuse;
	vec4 ambient;
	vec4 specular;
	vec4 emissive;
	float shininess;
	int texCount;
};

uniform	sampler2D texUnit;

in vec3 Normal;
in vec2 TexCoord;

void main()
{
	vec4 color;
	vec4 amb;
	float intensity;
	vec3 lightDir;
	vec3 n;

	lightDir = normalize(vec3(1.0,1.0,1.0));
	n = normalize(Normal);	
	intensity = max(dot(lightDir,n),0.0);

	if (texCount == 0) {
		color = diffuse;
		amb = ambient;
	}
	else {
		color = texture(texUnit, TexCoord);
		amb = color * 0.33;
	}
	gl_FragColor = (color * intensity) + amb;
	//output = vec4(texCount,0.0,0.0,1.0);
}




