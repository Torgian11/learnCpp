#include "Gallery.hpp"
#include <iostream>

void Gallery::addArtwork(Artwork&& art) {
  artworks.push_back(std::move(art));
}

void Gallery::sellArtwork(int id) {
  for (auto& art : artworks) {
    if (art.id == id) {
      art.markAsSold();
      break;
    }
  }
}

void Gallery::displayGallery() const {
  for (const auto& art : artworks) {
    std::cout << "ID: " << art.id
              << ", Title: " << (art.title.empty() ? "N/A" : art.title)
              << ", Artist: " << (art.artistName.empty() ? "N/A" : art.artistName)
              << ", Medium: " << art.medium
              << ", Price: $" << art.price
              << ", Status: " << (art.sold ? "Sold" : "Available")
              << "\n";
  }
}

Gallery::Gallery(const Gallery& other) {
  std::cout << "Gallery Copy Constructor\n";
  artworks = other.artworks;
}

Gallery& Gallery::operator=(const Gallery& other) {
  std::cout << "Gallery Copy Assignment\n";
  if (this != &other) {
    artworks = other.artworks;
  }
  return *this;
}

Gallery::Gallery(Gallery&& other) noexcept {
  std::cout << "Gallery Move Constructor\n";
  artworks = std::move(other.artworks);
}

Gallery& Gallery::operator=(Gallery&& other) noexcept {
  std::cout << "Gallery Move Assignment\n";
  if (this != &other) {
    artworks = std::move(other.artworks);
  }
  return *this;
}

Gallery::~Gallery() {
  std::cout << "Gallery Destructor\n";
}
