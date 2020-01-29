//
// Created by chenjs on 1/16/20.
//

#ifndef FLEXIBLEGAMEENGINE_STRUCTURE_H
#define FLEXIBLEGAMEENGINE_STRUCTURE_H

#include "Common.h"
#include "Pixel.h"

using Vector2f = Array<float, 2>;

using Vector3f = Array<float, 3>;

using Vector4f = Array<float, 4>;

using Vector3b = Array<uint8_t, 3>;

using Vector4b = Array<uint8_t, 4>;

using Matrix4x4f = Array<Vector4f, 4>;

struct alignas(sizeof(float)) Vertex1p{
    Vector3f p;
};

struct Vertex1p1n1uv{
    Vector3f p;
    Vector3f n;
    Vector2f uv;
};

struct Vertex1p1d1s2uv4j{
    Vector3f p;
    Vector4b d;
    Vector4b s;
    Vector2f uv0;
    Vector2f uv1;
    Vector4b k;
    Vector3b w;
};

struct Transform{
    Vector3f position;
    Vector3f rotation;
    Vector3f scale;
};

template <typename TVertex>
using Triangle = Array<TVertex, 3>;

using IndexFormat = uint32_t;

struct Bound{
    Vector3f extend;
    Vector3f size;
    Vector3f center;
    Vector3f min;
    Vector3f max;
};

struct BoneWeight{
    Array<float, 4> weight_array;
    Array<uint32_t, 4> bone_index_array;
};

struct Mesh{
    Bound bound;
    List<Vector3f> vertex_list;
//    Array<List<Vector2f>, 8> uv_array;
    List<uint32_t> triangle_list;
    List<Rgba32> color_list;
//    List<Matrix4x4f> bind_pose_list;
//    uint32_t sub_mesh_count;
//    List<Vector4f> tangents;
//    List<BoneWeight> bone_weight_list;

    uint32_t add_vertex(Vector3f vertex){
        vertex_list.push_back(vertex);
        return vertex_list.size() - 1;
    }

    void add_triangle(Vector3f a, Vector3f b, Vector3f c){
        uint32_t index_a = add_vertex(a);
        uint32_t index_b = add_vertex(b);
        uint32_t index_c = add_vertex(c);
        triangle_list.push_back(index_a);
        triangle_list.push_back(index_b);
        triangle_list.push_back(index_c);
    }
};

#endif //FLEXIBLEGAMEENGINE_STRUCTURE_H
