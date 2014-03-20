uniform sampler2D texUnit;

void main()
{
	// gl_FragColor = gl_Color;
	gl_FragColor = texture2D( texUnit, gl_TexCoord[0].xy);
}
