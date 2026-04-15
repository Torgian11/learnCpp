#include "Packet.hpp"
#include <iostream>

using namespace std;

void Packet::setType(PacketType newType) {
  type = newType;
}
std::string Packet::getPacketTypeName() const {
  switch (type) {
    case PacketType::UNKNOWN:
      return "UNKNOWN";
      break;
    case PacketType::DATA:
      return "DATA";
      break;
    case PacketType::CONTROL:
      return "CONTROL";
      break;
    case PacketType::ERROR:
      return "ERROR";
      break;
    default:
      return "UNKNOWN ERROR";
      break;
  };
}

std::string Packet::getStatusName() const {
  switch (packetStatus) {
    case Status::PENDING:
      return "PENDING";
      break;
    case Status::VALID:
      return "VALID";
      break;
    case Status::INVALID:
      return "INVALID";
      break;
    case Status::TIMEOUT:
      return "TIMEOUT";
      break;
    default:
      return "Unknown Packet Status";
      break;
  };
}

std::string Packet::getProtocolName() {
  switch (protocol) {
    case Protocol::TCP:
      return "TCP";
      break;
    case Protocol::UDP:
      return "UDP";
      break;
    case Protocol::HTTP:
      return "HTTP";
      break;
    case Protocol::FTP:
      return "FTP";
      break;
    default:
      return "Unknown Protocol";
      break;
  };
}

void Packet::validatePacket() {
  switch (type) {
    case PacketType::DATA:
      if (protocol == Protocol::TCP || protocol == Protocol::UDP) {
        packetStatus = Status::VALID;
      } else {
        packetStatus = Status::INVALID;
      }
      break;
    case PacketType::CONTROL:
      if (protocol == Protocol::TCP) {
        packetStatus = Status::VALID;
      } else {
        packetStatus = Status::INVALID;
      }
      break;
    case PacketType::ERROR:
      packetStatus = Status::VALID;
      break;
    case PacketType::UNKNOWN:
      packetStatus = Status::INVALID;
      break;
    default:
      packetStatus = Status::INVALID;
      break;
  };
}

bool Packet::isError() {
  if (packetStatus == Status::INVALID) {
    return true;
  }

  return false;
}

void Packet::displayInfo() {
  std::cout << getPacketTypeName() << std::endl;
  std::cout << getProtocolName() << std::endl;
  std::cout << getStatusName() << std::endl;
}
