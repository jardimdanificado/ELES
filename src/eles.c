#include "bruter.h"

Int new_creature(VirtualMachine* vm, IntList* args)
{
    char* name = vm->stack->data[stack_shift(*args)].string;
    eval(vm, "mem.push 0;");
    Int index = vm->stack->size-1;
    vm->stack->data[index].string = str_duplicate(name);
    vm->typestack->data[index] = TYPE_STRING;
    eval(vm,
             "mem.push 0;"                     // p.x
             "mem.push 0;"                     // p.y
             "mem.push 100;"                   // food
             "mem.push 100;"                   // drink
             "mem.push 100;"                   // sleep
             "mem.push 0;"                     // poo
             "mem.push 0;"                     // pee
             "mem.push 100;"                   // hygiene
             "mem.push 100;"                   // social
             "mem.push (mem.copy world.time);" // birthdate
        );

    //

    return index;
}

void init_eles(VirtualMachine* vm)
{
    register_number(vm, "world.time", 0);
    register_list(vm, "world.creatures");
    register_list(vm, "world.items");
    register_number(vm, "world.map", 0);

    register_builtin(vm, "creature.new", new_creature);
}
