// #version version_number
// in type in_variable_name;
// in type in_another_variable;
// 
// out type out_variable;
// 
// uniform type uniform_name;
// 
// void main() {
//     ...
//     out_variable = idk_man;
// }
// 
// // normally what vertex shader does:
// // input = vertex attribute
// // GL_MAX_VERTEX_ATTRIBS for max vertex possible
// 
// // types:
// bool NAME = ;
// int NAME = ;
// float NAME = ;
// double NAME = ;
// uint NAME = ;
// bool NAME = ;
// 
// vec2(, );
// vec3(, , );
// vec4(, , , );
// ivec2(, );
// bvec2(, );
// uvec2(, );
// dvec2(, );
// 
// // swizzling
// vec2 a = vec2(2,3);
// a.xxy == vec3(2,2,3);
// 
// // to ommit `layout (location = 0)` you can just do this in c; `glGetAttribLocation()`
// 
// // fragment shaders WILL output a vec4.

