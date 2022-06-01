#include "system.h"
#include "delay.h"

int main() {
    system_init();

    while (1)
    {
        delay(1000);
    }
}
