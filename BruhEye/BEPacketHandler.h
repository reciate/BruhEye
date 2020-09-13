#pragma once
#include <iostream>
#include "BEPacket.h"
#include "BEFunctions.h"

namespace BEPacketHandler {
	void onReceivedPacket(int* packet, int length);
}