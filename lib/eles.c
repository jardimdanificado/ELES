#include "bruter.h"

typedef char **Map;
typedef Stack(Map) MapList;
#define TYPE_MAP 9

// not a string list, its a list of char**
MapList *maps;

function(map_new)
{
    Int size_x = arg(0).number;
    Int size_y = arg(1).number;
    Map map = malloc(size_x * sizeof(char *));
    for (Int i = 0; i < size_x; i++)
    {
        map[i] = malloc(size_y * sizeof(char));
    }
    Int result = new_var(vm);
    data_t(result) = TYPE_MAP;
    data(result).pointer = map;
    //stack_push(*maps, map);
    return result;
}

function(map_delete)
{
    Map map = data(arg(0).integer).pointer;
    Int size_x = arg(1).number;
    for (Int i = 0; i < size_x; i++)
    {
        free(map[i]);
    }
    free(map);
    return 0;
}

init(eles)
{
    maps = (MapList *)malloc(sizeof(MapList));
    stack_init(*maps);
    register_builtin(vm, "map.new", map_new);
    register_builtin(vm, "map.delete", map_delete);
}