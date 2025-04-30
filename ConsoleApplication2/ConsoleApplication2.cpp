// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



//#include <windows.h>
//#include <iostream>
//#include <string>
//
//// 获取最后一个错误的描述字符串
//std::string GetLastErrorAsString() {
//    DWORD errorMessageID = ::GetLastError();
//    if (errorMessageID == 0) {
//        return std::string(); // 没有错误
//    }
//
//    LPSTR messageBuffer = nullptr;
//    size_t size = FormatMessageA(
//        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
//        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
//
//    std::string message(messageBuffer, size);
//    LocalFree(messageBuffer);
//    return message;
//}
//
//// 检查句柄的有效性并获取句柄信息
//void CheckHandle(HANDLE hHandle) {
//    DWORD flags;
//    if (GetHandleInformation(hHandle, &flags)) {
//        std::cout << "Handle is valid" << std::endl;
//        if (flags & HANDLE_FLAG_INHERIT) {
//            std::cout << "Handle is inheritable" << std::endl;
//        }
//        if (flags & HANDLE_FLAG_PROTECT_FROM_CLOSE) {
//            std::cout << "Handle is protected from close" << std::endl;
//        }
//    }
//    else {
//        std::string errorMessage = GetLastErrorAsString();
//        std::cout << "Handle is invalid, error: " << errorMessage << std::endl;
//    }
//}
//
//int main() {
//    // 使用 new HMODULE() 创建一个未初始化的 HMODULE 句柄
//    HMODULE* pModule = new HMODULE();
//    CheckHandle(*pModule);
//
//    // 释放分配的内存
//    delete pModule;
//
//    // 使用 LoadLibrary 获取一个有效的 HMODULE 句柄
//    LPCWSTR str1 = TEXT("kernel32.dll");
//    HMODULE hModule = LoadLibrary(str1);
//    if (hModule != NULL) {
//        std::cout << "Loaded kernel32.dll successfully." << std::endl;
//        CheckHandle(hModule);
//        FreeLibrary(hModule);
//    }
//    else {
//        std::cerr << "Failed to load kernel32.dll, error: " << GetLastErrorAsString() << std::endl;
//    }
//
//    system("pause");
//    return 0;
//}

#include <iostream>
using namespace std;

class HevcDecodePicPkt
{
public:
    virtual void Execute1(int* cmdBuffer);
    virtual void Execute2(int* cmdBuffer) = 0;
};

class HevcDecodeLongPkt
{
public:
    HevcDecodePicPkt* m_picturePkt = nullptr;
};

class HevcDecodeLongPktXe3_Lpm_Base : public HevcDecodeLongPkt
{
public:
    void PackPictureLevelCmds(int* cmdBuffer);
};

void HevcDecodeLongPktXe3_Lpm_Base::PackPictureLevelCmds(int* cmdBuffer)
{
    cout << "HevcDecodeLongPktXe3_Lpm_Base::PackPictureLevelCmds" << endl;
    m_picturePkt->Execute1(nullptr);
    m_picturePkt->Execute2(nullptr);
}

void HevcDecodePicPkt::Execute1(int* cmdBuffer)
{
    cout << "HevcDecodePicPkt::Execute1" << endl;
}

class HevcDecodePicPktXe2_Lpm_Base : public HevcDecodePicPkt
{
public:
    virtual void Execute1(int* cmdBuffer) override;
    virtual void Execute2(int* cmdBuffer) override;
};

class HevcDecodePicPktXe3_Lpm_Base : public HevcDecodePicPkt
{
public:
    virtual void Execute1(int* cmdBuffer) override;
    virtual void Execute2(int* cmdBuffer) override;

};

class HevcDecodePicPktXe_Lpm_Plus_Base : public HevcDecodePicPkt
{
public:
    virtual void Execute1(int* cmdBuffer) override;
    virtual void Execute2(int* cmdBuffer) override;
};

void HevcDecodePicPktXe2_Lpm_Base::Execute1(int* cmdBuffer)
{
    cout << "HevcDecodePicPktXe2_Lpm_Base::Execute1" << endl;
}
void HevcDecodePicPktXe2_Lpm_Base::Execute2(int* cmdBuffer)
{
    cout << "HevcDecodePicPktXe2_Lpm_Base::Execute2" << endl;
}

void HevcDecodePicPktXe3_Lpm_Base::Execute1(int* cmdBuffer)
{
    cout << "HevcDecodePicPktXe3_Lpm_Base::Execute1" << endl;
}
void HevcDecodePicPktXe3_Lpm_Base::Execute2(int* cmdBuffer)
{
    cout << "HevcDecodePicPktXe3_Lpm_Base::Execute2" << endl;
}

void HevcDecodePicPktXe_Lpm_Plus_Base::Execute1(int* cmdBuffer)
{
    cout << "HevcDecodePicPktXe_Lpm_Plus_Base::Execute1" << endl;
}
void HevcDecodePicPktXe_Lpm_Plus_Base::Execute2(int* cmdBuffer)
{
    cout << "HevcDecodePicPktXe_Lpm_Plus_Base::Execute2" << endl;
}

int main()
{
    HevcDecodeLongPktXe3_Lpm_Base* pkt = new HevcDecodeLongPktXe3_Lpm_Base();

    pkt->m_picturePkt = new HevcDecodePicPktXe_Lpm_Plus_Base();
    pkt->PackPictureLevelCmds(nullptr);
    delete pkt->m_picturePkt;
    pkt->m_picturePkt = nullptr;

    pkt->m_picturePkt = new HevcDecodePicPktXe2_Lpm_Base();
    pkt->PackPictureLevelCmds(nullptr);
    delete pkt->m_picturePkt;
    pkt->m_picturePkt = nullptr;

    pkt->m_picturePkt = new HevcDecodePicPktXe3_Lpm_Base();
    pkt->PackPictureLevelCmds(nullptr);
    delete pkt->m_picturePkt;
    pkt->m_picturePkt = nullptr;

    delete pkt;
    pkt = nullptr;

    //system("pause");
    return 0;
}