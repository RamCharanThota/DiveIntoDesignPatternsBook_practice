#include"simpleremote.hpp"

int main(){
    SimpleRemoteControl remote;
    Light light;
    LightOnCommand lighton(light);
    remote.setCommand(&lighton);
    remote.buttonWasPressed();

    GarageDoor g_door;
    GarageDoorOpenCommand g_open(g_door);
    remote.setCommand(&g_open);
    remote.buttonWasPressed();
}