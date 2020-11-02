#pragma once

namespace BEServer {
	struct Packet {
		struct Header {
			enum class ID : char {
				Init,
				Start = 2,
				Request = 4,
				Response = 5,
				Heartbeat = 9
			} id;
			unsigned char sequence;
		} header;
	};
}