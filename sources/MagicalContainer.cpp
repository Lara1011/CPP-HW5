//
// Created by Lara Abu Hamad on 5/24/23.
//

#include "MagicalContainer.hpp"
namespace ariel {
    MagicalContainer::MagicalContainer() : elements(0) {}

    int MagicalContainer::size() {
        return 0;
    }

    void MagicalContainer::addElement(int elem) {}

    void MagicalContainer::removeElement(int elem) {}

    vector<int> MagicalContainer::getElements() {
        return elements;
    }

    MagicalContainer::AscendingIterator::AscendingIterator() : index(0), magc(*new MagicalContainer()) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magc) : magc(magc), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : magc(other.magc) {}

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return 1;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        return *this;
    }

    int MagicalContainer::AscendingIterator::getIndex() {
        return 0;
    }

    MagicalContainer MagicalContainer::AscendingIterator::getContainer() {
        return magc;
    }

    MagicalContainer::PrimeIterator::PrimeIterator() : magc(*new MagicalContainer()), currIndex(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magc) : magc(magc), currIndex(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : magc(other.magc) {}

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return 1;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        return *this;
    }

    int MagicalContainer::PrimeIterator::getIndex() {
        return 0;
    }

    MagicalContainer MagicalContainer::PrimeIterator::getContainer() {
        return magc;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator() : magc(*new MagicalContainer()), frontIndex(0), backIndex(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magc) : magc(magc), frontIndex(0), backIndex(magc.size()) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : magc(other.magc) {}

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return 1;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
        return *this;
    }

    int MagicalContainer::SideCrossIterator::getBindex() {
        return 0;
    }

    int MagicalContainer::SideCrossIterator::getFindex() {
        return 0;
    }

    MagicalContainer MagicalContainer::SideCrossIterator::getContainer() {
        return magc;
    }
}