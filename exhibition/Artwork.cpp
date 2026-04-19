#include "Artwork.hpp"
#include <iostream>

Artwork::Artwork(
    std::string artTitle,
    std::string artistFullName,
    int artworkId,
    std::string artworkMedium,
    double artworkPrice,
    bool soldStatus) : title(artTitle), artistName(artistFullName), id(artworkId), medium(artworkMedium), price(artworkPrice), sold(soldStatus) {};

Artwork::Artwork(const Artwork& other) {
  std::cout << "Copy Constructor: Copied " << other.title << "\n";
  title = other.title;
  artistName = other.artistName;
  id = other.id;
  medium = other.medium;
  price = other.price;
  sold = other.sold;
}

Artwork& Artwork::operator=(const Artwork& other) {
  std::cout << "Copy Assignment: Copying " << other.title << "\n";
  if (this != &other) {
    title = other.title;
    artistName = other.artistName;
    id = other.id;
    medium = other.medium;
    price = other.price;
    sold = other.sold;
  }
  return *this;
}

Artwork::Artwork(Artwork&& other) : 
    title(std::move(other.title)),
    artistName(std::move(other.artistName)),
    medium(std::move(other.medium)),
    id(other.id),
    price(other.price),
    sold(other.sold) {
  std::cout << "Move Constructor: Moved " << title << "\n";
}

Artwork& Artwork::operator=(Artwork&& other) {
  std::cout << "Move Assignment: Moving " << other.title << "\n";
  if (this != &other) {
    title = std::move(other.title);
    artistName = std::move(other.artistName);
    medium = std::move(other.medium);
    id = other.id;
    price = other.price;
    sold = other.sold;
  }
  return *this;
}

Artwork::~Artwork() {
  std::cout << "Destructor: Destroying Artwork " << (title.empty() ? "N/A" : title) << "\n";
}


void Artwork::markAsSold() {
  sold = true;
}
