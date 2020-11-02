#pragma once
#include <iostream>
#include "BEPacket.hpp"
#include "BEFunctions.hpp"

namespace BEPacketHandler {
	void onReceivedPacket(int* packet, int length);
}