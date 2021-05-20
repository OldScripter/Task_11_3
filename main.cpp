#include <iostream>
#include <cmath>

// ip - ip address, part - part of ip from 1 to 4.
std::string getPartOfIP(std::string ip, int part)
{
    if (part < 1 || part > 4) return "ERR";

    std::string result = "";
    int dotCount = 0;
    for (int i = 0; i < ip.length(); i++)
    {

        if (ip[i] == '.') dotCount++;
        else if (ip[i] < '0' || ip[i] > '9') return "ERR";
        else if (dotCount == part - 1) result += ip[i];
        else if(dotCount == part) break;
    }
    if (result == "") return "ERR";
    if (part == 4 && dotCount > 3) return "ERR";
    return result;
}

int ipPartToInt(std::string ipPart)
{
    if (ipPart == "ERR") return -1;

    int result = 0;
    for (int i = ipPart.length() - 1; i >= 0; i--)
    {
        if (ipPart[0] == '0' && ipPart.length() > 1) return -1;
        result += (ipPart[i] - '0') * (int)std::pow(10.0,ipPart.length() - i - 1);
    }
    return result;
}

void checkIP(std::string ip)
{
    for (int i = 1; i <= 4; i++)
    {
        int number = ipPartToInt(getPartOfIP(ip, i));
        if (number < 0 || number > 255)
        {
            std::cout << "IP format is not valid!\n";
            return;
        }
    }
    std::cout << "IP is valid\n";
}

int main() {
    std::string ip;
    std::cout << "Please enter the ip: ";
    std::cin >> ip;
    checkIP(ip);
}