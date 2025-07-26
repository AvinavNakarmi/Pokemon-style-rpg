 #version 460 core
    in vec2 TexCoord;
    out vec4 FragColor;
    uniform sampler2D u_Texture;
    uniform ivec2 u_AtlasSize;
    uniform ivec2 u_TileIndex;
    uniform int u_time;
    void main() {
        vec2 repeatedCoord = fract(TexCoord);
        vec2  tileSize = 1.0 / vec2(u_AtlasSize);
        vec2  tileOffset = vec2(0,u_time) * tileSize;
        vec2  atlasUV= tileOffset +repeatedCoord * tileSize;
        FragColor =  texture(u_Texture, atlasUV);
        // FragColor = vec4(vec2(u_TileIndex), 0.2, 1.0); 
    }