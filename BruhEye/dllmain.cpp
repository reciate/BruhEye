#include <Windows.h>
#include <iostream>
#include "BEStructs.hpp"
#include "BEFunctions.hpp"

extern "C" {
    __declspec(dllexport) int GetVer() {
        return 0;
    }

    __declspec(dllexport) bool Init(int IntegrationVersion, BEClient::GameData* gameData, BEClient::BEData* beData) { //gameData (IN), beData (OUT)
        if (!GetConsoleWindow()) {
            AllocConsole();
            FILE* filePointer{};
            freopen_s(&filePointer, "CONOUT$", "w", stdout);
            std::cout << gameData->GameVersion << '\n';
        }

        BEFunctions::GameData = *gameData;

        beData->Exit = BEFunctions::BEData::Exit;
        beData->Run = BEFunctions::BEData::Run;
        beData->Command = BEFunctions::BEData::Command;
        beData->ReceivedPacket = BEFunctions::BEData::ReceivedPacket;
        beData->OnReceiveAuthTicket = BEFunctions::BEData::OnReceiveAuthTicket;
        beData->AddPeer = BEFunctions::BEData::AddPeer;
        beData->RemovePeer = BEFunctions::BEData::RemovePeer;
        beData->EncryptClientPacket = BEFunctions::BEData::EncryptClientPacket;
        beData->DecryptServerPacket = BEFunctions::BEData::DecryptServerPacket;

        return true; //? SuccessfullyInitialized : NotInitialized
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}