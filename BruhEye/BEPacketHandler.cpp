#include <iostream>
#include "BEPacketHandler.hpp"

void handlePacket(BEServer::Packet* packet) {
	switch (packet->header.id) {
		case (BEServer::Packet::Header::ID::Init): {
			std::cout << "Init" << '\n';
			unsigned char response[]{0, 5};
			BEFunctions::GameData.SendPacket(reinterpret_cast<int*>(&response), sizeof(response));
			break;
		}
		case (BEServer::Packet::Header::ID::Start): {
			std::cout << "Start" << '\n';
			unsigned char response[]{ 2, 0 };
			BEFunctions::GameData.SendPacket(reinterpret_cast<int*>(&response), sizeof(response));
			break;
		}
		case (BEServer::Packet::Header::ID::Request): {
			std::cout << "Request" << '\n';
			unsigned char response[]{ 4, 1 };
			BEFunctions::GameData.SendPacket(reinterpret_cast<int*>(&response), sizeof(response));
			break;
		}
		case (BEServer::Packet::Header::ID::Heartbeat): {
			std::cout << "Heartbeat" << '\n';
			unsigned char response[]{ 9, packet->header.sequence, 0 };
			BEFunctions::GameData.SendPacket(reinterpret_cast<int*>(&response), sizeof(response));
			break;
		}
	}
}

namespace BEPacketHandler {
	void onReceivedPacket(int* packet, int length) {
		handlePacket(reinterpret_cast<BEServer::Packet*>(packet));
	}
}