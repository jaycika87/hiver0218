#pragma once

struct room;

room* entrance();

int getNumDoors(room* r);
room* getRoomAtDoor(room*, int n);

char getRoomId(room* r);