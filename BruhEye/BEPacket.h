#pragma once

namespace BEServer {
	struct Packet {
		enum class HeaderID{
			Init,
			Start = 2,
			Request = 4,
			Response = 5,
			Heartbeat = 9
		} headerID;
		unsigned char headerSequence;
		bool isFragmented;
	};
}