#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char* argv[])
{
    void *module = dlopen(argv[1], RTLD_LAZY);
    if (!module) {
        puts(dlerror());
        return 1;
    }

    void (*attack)(void) = (void (*)(void))dlsym(module, "attack");

    if (attack == NULL) {
        puts(dlerror());
        dlclose(module);
        return 1;
    }

    puts("👾 怪物出现了！");
    attack();

    dlclose(module);
    return 0;
}
