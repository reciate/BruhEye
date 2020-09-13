#include "BEPacketHandler.h"

void handlePacket(BEServer::Packet* packet) {
	switch (packet->headerID) {
		case (BEServer::Packet::HeaderID::Init): {
			std::cout << "Init" << '\n';
			break;
		}
		case (BEServer::Packet::HeaderID::Start): {
			std::cout << "Start" << '\n';
			break;
		}
		case (BEServer::Packet::HeaderID::Request): {
			std::cout << "Request" << '\n';
			break;
		}
		case (BEServer::Packet::HeaderID::Heartbeat): {
			std::cout << "Heartbeat" << '\n';
			break;
		}
	}
}

namespace BEPacketHandler {
	void onReceivedPacket(int* packet, int length) {
		handlePacket(reinterpret_cast<BEServer::Packet*>(packet));
	}
}