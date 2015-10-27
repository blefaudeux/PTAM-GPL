varying vec3 vertex;
varying vec3 normal;
varying vec3 eye;

uniform sampler2D DiffuseMap;

void computeLight(in int i, inout vec4 ambient, inout vec4 diffuse, inout vec4 specular)
{
    ambient += gl_LightSource[i].ambient * gl_FrontMaterial.ambient;

    vec3 light;

    if(gl_LightSource[i].position.w == 1.0)
        light = gl_LightSource[i].position.xyz - vertex;

    else
        light = gl_LightSource[i].position.xyz;

    vec3 lightDiri = normalize(light);

    float NdotL = max(0.0, dot(normal, lightDiri));

    if(NdotL > 0.0)
    {
        float att = 1.0;

        // Calcule l'attinuation dans le cas d'une lumier pointctuelle
        if(gl_LightSource[i].position.w == 1.0)
        {
            float distance = length(light);

            att = 1.0 / (gl_LightSource[i].constantAttenuation
            + gl_LightSource[i].linearAttenuation
            * distance
            + gl_LightSource[i].quadraticAttenuation
            * distance
            * distance);
        }

        float NdotHV = dot(normal, normalize(lightDiri + eye));

        diffuse  += gl_FrontMaterial.diffuse * gl_LightSource[i].diffuse * NdotL * att;
        specular += gl_FrontMaterial.specular * gl_LightSource[i].specular * pow(NdotHV, gl_FrontMaterial.shininess) * NdotL * att;
    }
}

void main()
{
    vec4 ambient = vec4(0);
    vec4 diffuse = vec4(0);
    vec4 specular = vec4(0);

    vec4 finalColor = vec4(0);

    computeLight(0, ambient, diffuse, specular);
    finalColor = ambient + diffuse * 0.5; // * shadow

    finalColor *= gl_Color;
    // *** This is what you asking for !
    finalColor *= texture2D(DiffuseMap, gl_TexCoord[0].st);
    finalColor += specular;

    // Foged ?
    float z = gl_FragCoord.z / gl_FragCoord.w;
    float fogFactor = (gl_Fog.end - z) / (gl_Fog.end - gl_Fog.start);
    fogFactor = clamp(fogFactor, 0.0, 1.0);

    gl_FragColor = mix(gl_Fog.color, finalColor, fogFactor);
    gl_FragColor *= finalColor.aaaa;
} 
