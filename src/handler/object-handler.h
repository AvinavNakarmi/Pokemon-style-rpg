class MeshHandler
{
    private:
        std::vector<Mesh> meshes;
    public:
        MeshHandler() = default;
        ~MeshHandler() = default;
        void AddMesh(const Mesh& mesh) {
            meshes.push_back(mesh);
        }
        void RemoveMesh(size_t index) {
            for (size_t i = 0; i <meshes.size() ; i++)
            {
                if (meshes[i].id == index) {
                    meshes.erase(meshes.begin() + i);
                    return;
                }
            }
            
            if (index < meshes.size()) {
                meshes.erase(meshes.begin() + index);
            } else {
                std::cerr << "Index out of bounds: " << index << std::endl;
            }
        }
}