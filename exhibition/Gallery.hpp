#pragma once

#include "Artwork.hpp"
#include <vector>

class Gallery {
public:
  std::vector<Artwork> artworks;

  void addArtwork(Artwork&& art);
  void sellArtwork(int id);
  void displayGallery() const;

  Gallery() = default;

  Gallery(const Gallery& other);
  Gallery& operator=(const Gallery& other);

  Gallery(Gallery&& other) noexcept;
  Gallery& operator=(Gallery&& other) noexcept;

  ~Gallery();
};
