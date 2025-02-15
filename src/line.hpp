struct Line
{
    int start_vertex_index;
    int end_vertex_index;
    bool compressible;
    float length;

    Line() = default;
    Line(int start_vertex_index_, int end_vertex_index_, bool compressible_, float length_)
        : start_vertex_index{start_vertex_index_},
          end_vertex_index{end_vertex_index_},
          compressible{compressible_},
          length{length_} {}
};