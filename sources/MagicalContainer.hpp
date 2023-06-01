//
// Created by Lara Abu Hamad on 5/24/23.
//

#ifndef CPP_HW5_MAGICALCONTAINER_HPP
#define CPP_HW5_MAGICALCONTAINER_HPP

#include <vector>

using namespace std;
namespace ariel {
    class MagicalContainer {
    private:
        vector<int> elements;

    public:
        MagicalContainer();

        void addElement(int elem);

        void removeElement(int elem);

        int size();

        vector<int> getElements();

        class AscendingIterator {
        private:
            MagicalContainer &magc;
            int index;

        public:
            AscendingIterator();

            AscendingIterator(MagicalContainer &magc);

            AscendingIterator(const AscendingIterator &other);

            ~AscendingIterator() = default;

            AscendingIterator &operator=(const AscendingIterator &other);

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();

            AscendingIterator begin();

            AscendingIterator end();

            int getIndex();

            MagicalContainer getContainer();
        };

        class SideCrossIterator {
        private:
            MagicalContainer &magc;
            int frontIndex;
            int backIndex;
        public:
            SideCrossIterator();

            SideCrossIterator(MagicalContainer &magc);

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator() = default;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin();

            SideCrossIterator end();

            int getFindex();

            int getBindex();

            MagicalContainer getContainer();
        };

        class PrimeIterator {
        private:
            MagicalContainer &magc;
            int currIndex;

            bool isPrime(int number) {
                return true;
            }

        public:
            PrimeIterator();

            PrimeIterator(MagicalContainer &mgc);

            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator() = default;

            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();

            PrimeIterator begin();

            PrimeIterator end();

            int getIndex();

            MagicalContainer getContainer();
        };
    };
}
#endif //CPP_HW5_MAGICALCONTAINER_HPP
