#include <iostream>
using namespace std;

class excvcvbtyhdf3453
{
public:
    virtual void Execute1(int* cmdBuffer);
    virtual void Execute2(int* cmdBuffer) = 0;
};

class hkuzvxcfaxvxqqfhj355424
{
public:
    excvcvbtyhdf3453* m_picturePkt = nullptr;
};

class dyhfghnbfgjjfgj : public hkuzvxcfaxvxqqfhj355424
{
public:
    void yfggvsdd456546hghjghkj(int* cmdBuffer);
};

void dyhfghnbfgjjfgj::yfggvsdd456546hghjghkj(int* cmdBuffer)
{
    cout << "dyhfghnbfgjjfgj::yfggvsdd456546hghjghkj" << endl;
    m_picturePkt->Execute1(nullptr);
    m_picturePkt->Execute2(nullptr);
}

void excvcvbtyhdf3453::Execute1(int* cmdBuffer)
{
    cout << "excvcvbtyhdf3453::Execute1" << endl;
}

class hghghjgyjfhfgssf : public excvcvbtyhdf3453
{
public:
    virtual void Execute1(int* cmdBuffer) override;
    virtual void Execute2(int* cmdBuffer) override;
};

class uyuimnfnbdfgwsz : public excvcvbtyhdf3453
{
public:
    virtual void Execute1(int* cmdBuffer) override;
    virtual void Execute2(int* cmdBuffer) override;

};

class srwqerfsdrgtfjgjk : public excvcvbtyhdf3453
{
public:
    virtual void Execute1(int* cmdBuffer) override;
    virtual void Execute2(int* cmdBuffer) override;
};

void hghghjgyjfhfgssf::Execute1(int* cmdBuffer)
{
    cout << "hghghjgyjfhfgssf::Execute1" << endl;
}
void hghghjgyjfhfgssf::Execute2(int* cmdBuffer)
{
    cout << "hghghjgyjfhfgssf::Execute2" << endl;
}

void uyuimnfnbdfgwsz::Execute1(int* cmdBuffer)
{
    cout << "uyuimnfnbdfgwsz::Execute1" << endl;
}
void uyuimnfnbdfgwsz::Execute2(int* cmdBuffer)
{
    cout << "uyuimnfnbdfgwsz::Execute2" << endl;
}

void srwqerfsdrgtfjgjk::Execute1(int* cmdBuffer)
{
    cout << "srwqerfsdrgtfjgjk::Execute1" << endl;
}
void srwqerfsdrgtfjgjk::Execute2(int* cmdBuffer)
{
    cout << "srwqerfsdrgtfjgjk::Execute2" << endl;
}

int main()
{
    dyhfghnbfgjjfgj* pkt = new dyhfghnbfgjjfgj();

    pkt->m_picturePkt = new srwqerfsdrgtfjgjk();
    pkt->yfggvsdd456546hghjghkj(nullptr);
    delete pkt->m_picturePkt;
    pkt->m_picturePkt = nullptr;

    pkt->m_picturePkt = new hghghjgyjfhfgssf();
    pkt->yfggvsdd456546hghjghkj(nullptr);
    delete pkt->m_picturePkt;
    pkt->m_picturePkt = nullptr;

    pkt->m_picturePkt = new uyuimnfnbdfgwsz();
    pkt->yfggvsdd456546hghjghkj(nullptr);
    delete pkt->m_picturePkt;
    pkt->m_picturePkt = nullptr;

    delete pkt;
    pkt = nullptr;

    //system("pause");
    return 0;
}