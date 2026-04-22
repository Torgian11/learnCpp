#include "Color.hpp"
#include <iomanip>
#include <cmath>

Color::Color() : redChannel(0), greenChannel(0), blueChannel(0) {}

Color::Color(int red, int green, int blue) {
  redChannel   = CLIP(red);
  greenChannel = CLIP(green);
  blueChannel  = CLIP(blue);
}

Color Color::fromPackedRgb(unsigned int packedRgb) {
  return Color(int((packedRgb >> 16) & 0xffu),
         int((packedRgb >> 8)  & 0xffu),
         int( packedRgb      & 0xffu));
}

Color Color::fromHexLiteral(const char* hexString) {
  if (!hexString || hexString[0] != '#') {
    throw std::invalid_argument("hex literal must start with #");
  }
  int digits[6];
  for (int i = 0; i < 6; ++i) {
    int val = ColorUtility::fromHexDigit(hexString[i + 1]);
    if (val < 0) {
      throw std::invalid_argument("invalid hex digit");
    }
    digits[i] = val;
  }
  return Color(digits[0]*16 + digits[1],
         digits[2]*16 + digits[3],
         digits[4]*16 + digits[5]);
}

int& Color::operator[](int coordIndex) {
  switch (coordIndex) {
    case 0: return redChannel;
    case 1: return greenChannel;
    case 2: return blueChannel;
    default: throw std::out_of_range("Color index");
  }
}

int Color::operator[](int coordIndex) const {
  switch (coordIndex) {
    case 0: return redChannel;
    case 1: return greenChannel;
    case 2: return blueChannel;
    default: throw std::out_of_range("Color index");
  }
}

Color Color::operator+(const Color& rhs) {
  int newRed = ((redChannel   + rhs.redChannel)   / 2.0);
  int newGreen = ((greenChannel + rhs.greenChannel) / 2.0);
  int newBlue  = ((blueChannel  + rhs.blueChannel)  / 2.0);

  return Color(newRed, newGreen, newBlue);
}

Color Color::operator+(const std::vector<int>& offsets) const {
  int newRed = redChannel + (offsets.size() > 0 ? CLIP(offsets[0]) : 0);
  int newGreen = greenChannel + (offsets.size() > 1 ? CLIP(offsets[1]) : 0);
  int newBlue = blueChannel + (offsets.size() > 2 ? CLIP(offsets[2]) : 0);

  return Color(newRed, newGreen, newBlue);
}

Color& Color::operator++() {
  redChannel = CLIP(redChannel + 1);
  greenChannel = CLIP(greenChannel + 1);
  blueChannel = CLIP(blueChannel + 1);

  return *this;
}

Color& Color::operator--() {
  redChannel = CLIP(redChannel - 1);
  greenChannel = CLIP(greenChannel - 1);
  blueChannel = CLIP(blueChannel - 1);

  return *this;
}

Color& Color::operator*(int scale) {
  redChannel = CLIP(redChannel * scale);
  greenChannel = CLIP(greenChannel * scale);
  blueChannel = CLIP(blueChannel * scale);

  return *this;
}

Color Color::operator()(int (*transform)(int)) const {
  const auto newRed = CLIP(transform(redChannel));
  const auto newGreen = CLIP(transform(greenChannel));
  const auto newBlue = CLIP(transform(blueChannel));

  return Color(newRed, newGreen, newBlue);
};

bool Color::operator==(const Color& rhs) {
  return redChannel == rhs.redChannel && greenChannel == rhs.greenChannel && blueChannel == rhs.blueChannel;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
  os << '#' << std::hex << std::setfill('0') << std::setw(2) << color.red()
         << std::setw(2) << color.green()
         << std::setw(2) << color.blue() << std::dec;
  return os;
}

std::istream& operator>>(std::istream& is, Color& color) {
  std::string token;
  is >> token;
  color = Color::fromHexLiteral(token.c_str());
  return is;
}
