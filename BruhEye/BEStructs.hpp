#pragma once

namespace BEClient {
	struct GameData {
		char* GameVersion;
		unsigned int Address;
		unsigned short Port;
		void(*PrintMessage)(char* Message); //__cdecl*
		void(*RequestRestart)(int Reason);
		void(*SendPacket)(int* Packet, int Length);
		void(*DisconnectPeer)(int* PeerGUID, int GUIDLength, char* Reason);
	};

	struct BEData {
		bool(*Exit)();
		void(*Run)();
		void(*Command)(char* Command);
		void(*ReceivedPacket)(int* Packet, int Length);
		void(*OnReceiveAuthTicket)(int* Ticket, int TicketLength);
		void(*AddPeer)(int* PeerGUID, int GUIDLength);
		void(*RemovePeer)(int* PeerGUID, int GUIDLength);
		int* EncryptionKey;
		int EncryptionKeyLength;
		void(*EncryptClientPacket)(int* Packet, int Length, int* EncryptedPacket, int* EncryptedLength);
		void(*DecryptServerPacket)(int* Packet, int Length, int* DecryptedPacket, int* DecryptedLength);
	};
}