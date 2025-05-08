const int MEM_SIZE = 100 * 1024;
class Ram {
    char mem[MEM_SIZE];
    int size;

public:
    Ram();
    char read(int addr);
    void write(int addr, char value);

private:
    bool isValidAddr(int addr);
};
Ram::Ram() {
    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = 0;
    size = MEM_SIZE;
}
Ram::~Ram() {
    cout << "메모리 제거됨" << endl;
}
bool Ram::isValidAddr(int addr) {
    if (addr < 0 || addr >= MEM_SIZE) {
        cout << "주소 범위를 벚어남" << endl;
        return false;
    }
    return true;
}
char Ram::read(int addr) {
    if (!isValidAddr(addr))
        return -1;
    return mem[addr];
}
void Ram::write(int addr, char value) {
    if (!isValidAddr(addr))
        return;
    mem[addr] = value;
}