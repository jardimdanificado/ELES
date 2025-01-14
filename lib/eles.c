#include "bruter.h"

typedef char **Map2D;
typedef char ***Map3D;
typedef Stack(Map2D) Map2DList;
typedef Stack(Map3D) Map3DList;
#define TYPE_MAP2D 9
#define TYPE_MAP3D 10

// not a string list, its a list of char**
Map2DList *maps2d;
Map3DList *maps3d;

function(map2d_new)
{
    Int size_x = arg(0).number;
    Int size_y = arg(1).number;
    Map2D map = malloc(size_x * sizeof(char *));
    for (Int i = 0; i < size_x; i++)
    {
        map[i] = malloc(size_y * sizeof(char));
    }
    Int result = new_var(vm);
    data_t(result) = TYPE_MAP2D;
    data(result).pointer = map;
    stack_push(*maps2d, map);
    return result;
}

function(map2d_delete)
{
    Map2D map = data(arg(0).integer).pointer;
    Int size_x = arg(1).number;
    for (Int i = 0; i < size_x; i++)
    {
        free(map[i]);
    }
    free(map);
    return 0;
}

function(map2d_get_tile)
{
    Map2D map = data(arg(0).integer).pointer;
    Int x = arg(1).number;
    Int y = arg(2).number;
    Int result = new_var(vm);
    data_t(result) = TYPE_INTEGER;
    data(result).integer = map[x][y];
    return result;
}

function(map2d_get_row)
{
    Map2D map = data(arg(0).integer).pointer;
    Int x = arg(1).number;
    Int row = new_var(vm);
    data_t(row) = TYPE_STRING;
    data(row).pointer = map[x];
    return row;
}

function(map2d_set_tile)
{
    Map2D map = data(arg(0).integer).pointer;
    Int x = arg(1).number;
    Int y = arg(2).number;
    map[x][y] = arg(3).integer;
    return 0;
}

function(map2d_set_row)
{
    Map2D map = data(arg(0).integer).pointer;
    Int x = arg(1).number;
    char *row = data(arg(2).integer).string;
    free(map[x]);
    map[x] = row;
    return 0;
}

init(eles)
{
    maps2d = (Map2DList *)malloc(sizeof(Map2DList));
    stack_init(*maps2d);
    register_builtin(vm, "map2d.new", map2d_new);
    register_builtin(vm, "map2d.delete", map2d_delete);
}