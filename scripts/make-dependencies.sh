#!/bin/bash

set -e

WORKSPACE="$(pwd)"
PREFIX="${WORKSPACE}/deps"
PKG_PREFIX="${WORKSPACE}/pkgs"

mkdir -p "${PREFIX}"
mkdir -p "${PKG_PREFIX}"

FREETYPE_VERSION="2.13.1"
FREETYPE_PKG="freetype-${FREETYPE_VERSION}.tar.gz"
FREETYPE_URL="https://sourceforge.net/projects/freetype/files/freetype2/${FREETYPE_VERSION}/${FREETYPE_PKG}/download"

OGG_VERSION="1.3.5"
OGG_PKG="libogg-${OGG_VERSION}.tar.gz"
OGG_URL="http://downloads.xiph.org/releases/ogg/${OGG_PKG}"

VORBIS_VERSION="1.3.7"
VORBIS_PKG="libvorbis-${VORBIS_VERSION}.tar.gz"
VORBIS_URL="http://downloads.xiph.org/releases/vorbis/${VORBIS_PKG}"

#
# Download tarballs

cd "${PKG_PREFIX}"

[ -f "${FREETYPE_PKG}" ] || curl -L -o "${FREETYPE_PKG}" "${FREETYPE_URL}"
[ -f "${OGG_PKG}" ] || curl -L -o "${OGG_PKG}" "${OGG_URL}"
[ -f "${VORBIS_PKG}" ] || curl -L -o "${VORBIS_PKG}" "${VORBIS_URL}"

#
# Extract tarballs

cd "${WORKSPACE}"

tar xf "${PKG_PREFIX}/${FREETYPE_PKG}"
tar xf "${PKG_PREFIX}/${OGG_PKG}"
tar xf "${PKG_PREFIX}/${VORBIS_PKG}"

#
# Build dependencies

cd "${WORKSPACE}/freetype-${FREETYPE_VERSION}"
cmake -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH="${PREFIX}" \
    -DBUILD_SHARED_LIBS=0
cmake --build build
cmake --install build --prefix "${PREFIX}"

cd "${WORKSPACE}/libogg-${OGG_VERSION}"
cmake -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH="${PREFIX}" \
    -DBUILD_SHARED_LIBS=0 \
    -DBUILD_TESTING=0
cmake --build build
cmake --install build --prefix "${PREFIX}"

# Note: partially ignores --prefix parameter,
# but not CMAKE_INSTALL_PREFIX
cd "${WORKSPACE}/libvorbis-${VORBIS_VERSION}"
cmake -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH="${PREFIX}" \
    -DCMAKE_INSTALL_PREFIX="${PREFIX}" \
    -DBUILD_SHARED_LIBS=0
cmake --build build
cmake --install build

# Is this what hell looks like?

