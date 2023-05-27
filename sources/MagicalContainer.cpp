//
// Created by Lara Abu Hamad on 5/24/23.
//

#include "MagicalContainer.h"

MagicalContainer::MagicalContainer() : elements(0) {}

int MagicalContainer::size() {
    return 0;
}

void MagicalContainer::addElement(int elem) {}

void MagicalContainer::removeElement(int elem) {}

vector<int> MagicalContainer::getElements() {
    return elements;
}

AscendingIterator::AscendingIterator(): index(0), magc(MagicalContainer()) {}

AscendingIterator::AscendingIterator(MagicalContainer &magc) : magc(magc), index(0) {}

AscendingIterator::AscendingIterator(const AscendingIterator &other) : magc(other.magc) {}

AscendingIterator AscendingIterator::begin() {
    return *this;
}

AscendingIterator AscendingIterator::end() {
    return *this;
}

bool AscendingIterator::operator>(const AscendingIterator &other) const {
    return true;
}

bool AscendingIterator::operator<(const AscendingIterator &other) const {
    return true;
}

bool AscendingIterator::operator==(const AscendingIterator &other) const {
    return true;
}

bool AscendingIterator::operator!=(const AscendingIterator &other) const {
    return false;
}

int AscendingIterator::operator*() const {
    return 1;
}

AscendingIterator &AscendingIterator::operator++() {
    return *this;
}

AscendingIterator &AscendingIterator::operator=(const AscendingIterator &other) {
    return *this;
}

int AscendingIterator::getIndex() {
    return 0;
}

MagicalContainer AscendingIterator::getContainer() {
    return magc;
}

PrimeIterator::PrimeIterator() : magc(MagicalContainer()), currIndex(0) {}

PrimeIterator::PrimeIterator(MagicalContainer &magc) : magc(magc), currIndex(0) {}

PrimeIterator::PrimeIterator(const PrimeIterator &other) : magc(other.magc) {}

PrimeIterator PrimeIterator::begin() {
    return *this;
}

PrimeIterator PrimeIterator::end() {
    return *this;
}

bool PrimeIterator::operator>(const PrimeIterator &other) const {
    return true;
}

bool PrimeIterator::operator<(const PrimeIterator &other) const {
    return true;
}

bool PrimeIterator::operator==(const PrimeIterator &other) const {
    return true;
}

bool PrimeIterator::operator!=(const PrimeIterator &other) const {
    return false;
}

int PrimeIterator::operator*() const {
    return 1;
}

PrimeIterator &PrimeIterator::operator++() {
    return *this;
}

PrimeIterator &PrimeIterator::operator=(const PrimeIterator &other) {
    return *this;
}

int PrimeIterator::getIndex() {
    return 0;
}

MagicalContainer PrimeIterator::getContainer() {
    return magc;
}

SideCrossIterator::SideCrossIterator() : magc(MagicalContainer()), frontIndex(0), backIndex(0){}

SideCrossIterator::SideCrossIterator(MagicalContainer &magc) : magc(magc), frontIndex(0), backIndex(magc.size()) {}

SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : magc(other.magc) {}

SideCrossIterator SideCrossIterator::begin() {
    return *this;
}

SideCrossIterator SideCrossIterator::end() {
    return *this;
}

bool SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return true;
}

bool SideCrossIterator::operator<(const SideCrossIterator &other) const {
    return true;
}

bool SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return true;
}

bool SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return false;
}

int SideCrossIterator::operator*() const {
    return 1;
}

SideCrossIterator &SideCrossIterator::operator++() {
    return *this;
}

SideCrossIterator &SideCrossIterator::operator=(const SideCrossIterator &other) {
    return *this;
}

int SideCrossIterator::getBindex() {
    return 0;
}

int SideCrossIterator::getFindex() {
    return 0;
}

MagicalContainer SideCrossIterator::getContainer() {
    return magc;
}