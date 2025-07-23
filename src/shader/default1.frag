 #version 460 core
    // in vec2 TexCoord;
    out vec4 FragColor;
    uniform sampler2D u_Texture;
    // uniform ivec2 u_AtlasSize;
    // uniform ivec2 u_TileIndex;

    ;
    void main() {
        // vec2  tileSize = 1.0 / vec2(u_AtlasSize);
        // vec2  tileOffset = vec2(u_TileIndex) * tileSize;
        // vec2  atlasUV= tileOffset +TexCoord * tileSize;
        // FragColor =  texture(u_Texture, atlasUV);
        FragColor = vec4(1.0, 0.5, 0.2, 1.0); 
    }