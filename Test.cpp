//
// Created by Lara Abu Hamad on 5/27/23.
//

#include "doctest.h"
#include "sources/MagicalContainer.h"

TEST_SUITE("Initialization") {
    TEST_CASE("Magical Container") {
        CHECK_NOTHROW(MagicalContainer mc2{});
        MagicalContainer mc1{};
        CHECK(mc1.size() == 0);
    }

    MagicalContainer mc{};

    TEST_CASE("Ascending Iterator") {
        CHECK_NOTHROW(AscendingIterator());
        CHECK_NOTHROW(AscendingIterator ai{mc});
        AscendingIterator ai{mc};
        CHECK(ai.getIndex() == 0);
    }

    TEST_CASE("Prime Iterator") {
        CHECK_NOTHROW(PrimeIterator());
        CHECK_NOTHROW(PrimeIterator pi{mc});
        PrimeIterator pi{mc};
        CHECK(pi.getIndex() == 0);
    }

    TEST_CASE("Side Cross Iterator") {
        CHECK_NOTHROW(SideCrossIterator());
        CHECK_NOTHROW(SideCrossIterator sci{mc});
        SideCrossIterator sci{mc};
        CHECK(sci.getBindex() == 0);
        CHECK(sci.getFindex() == 0);
    }
}

TEST_SUITE("Testing functions") {
    MagicalContainer mc{};

    TEST_CASE("Magical container functions") {
        CHECK(mc.size() == 0);
        CHECK_NOTHROW(mc.addElement(1));
        CHECK_NOTHROW(mc.removeElement(1));
    }

    TEST_CASE("Ascending iterator functions") {
        AscendingIterator ai{mc};
        AscendingIterator ai2{mc};
        CHECK(ai.getIndex() == 0);
        CHECK_NOTHROW(ai.begin());
        CHECK_NOTHROW(ai.end());
        CHECK_FALSE(ai.operator!=(ai2));
        CHECK_FALSE(!ai.operator==(ai2));
        CHECK_FALSE(!ai.operator<(ai2));
        CHECK_FALSE(!ai.operator>(ai2));
        CHECK(ai.operator*() == 1);
        CHECK_NOTHROW(ai.operator++());
        CHECK_NOTHROW(ai.operator=(ai2));
    }

    TEST_CASE("Prime iterator functions") {
        PrimeIterator pi{mc};
        PrimeIterator pi2{mc};
        CHECK_NOTHROW(pi.begin());
        CHECK_NOTHROW(pi.end());
        CHECK_FALSE(pi.operator!=(pi2));
        CHECK_FALSE(!pi.operator==(pi2));
        CHECK_FALSE(!pi.operator<(pi2));
        CHECK_FALSE(!pi.operator>(pi2));
        CHECK(pi.operator*() == 1);
        CHECK_NOTHROW(pi.operator++());
        CHECK_NOTHROW(pi.operator=(pi2));
    }

    TEST_CASE("Side cross iterator functions") {
        SideCrossIterator sci{mc};
        SideCrossIterator sci2{mc};
        CHECK_NOTHROW(sci.begin());
        CHECK_NOTHROW(sci.end());
        CHECK_FALSE(sci.operator!=(sci2));
        CHECK_FALSE(!sci.operator==(sci2));
        CHECK_FALSE(!sci.operator<(sci2));
        CHECK_FALSE(!sci.operator>(sci2));
        CHECK(sci.operator*() == 1);
        CHECK_NOTHROW(sci.operator++());
        CHECK_NOTHROW(sci.operator=(sci2));
    }
}

TEST_SUITE("Test Demo") {
    TEST_CASE("") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        CHECK(container.size() == 5);
        vector<int> elements = container.getElements();
        CHECK(elements.at(0) == 17);
        CHECK(elements.at(1) == 2);
        CHECK(elements.at(2) == 25);
        CHECK(elements.at(3) == 9);
        CHECK(elements.at(4) == 3);

        AscendingIterator ascIter(container);
        vector<int> expected{2, 3, 9, 17, 25};
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
            CHECK(*it == expected[static_cast<vector<int>::size_type>(it.getIndex())]);
        }

        SideCrossIterator crossIter(container);
        vector<int> expected2{2, 25, 3, 17, 9};
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
            CHECK(*it == expected2[static_cast<vector<int>::size_type>(it.getFindex())]);
        }

        PrimeIterator primeIter(container);
        vector<int> expected3{2, 3, 17};
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
            CHECK(*it == expected3[static_cast<vector<int>::size_type>(it.getIndex())]);
        }

        container.removeElement(9);
        CHECK(container.size() == 4);
    }
}

TEST_SUITE("Magical Container") {
    TEST_CASE("Empty containers") {
        MagicalContainer container;
        CHECK(container.size() == 0);
        CHECK_FALSE(!container.getElements().empty());
    }

    TEST_CASE("Remove and update size") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.removeElement(9);
        CHECK(container.size() == 3);
        CHECK(container.getElements() == vector<int>{17, 2, 25});
    }

    TEST_CASE("Add and then remove again") {
        MagicalContainer container;
        container.addElement(17);
        CHECK(container.size() == 1);
        container.removeElement(17);
        CHECK(container.size() == 0);
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        CHECK(container.size() == 3);
        container.removeElement(17);
        CHECK(container.size() == 2);
        container.removeElement(2);
        CHECK(container.size() == 1);
        container.removeElement(25);
        CHECK(container.size() == 0);
        CHECK_FALSE(!container.getElements().empty());
    }

    TEST_CASE("duplicate") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(5);
        container.addElement(5);
        container.addElement(5);
        CHECK(container.size() == 4);
        CHECK(container.getElements() == vector<int>{5, 5, 5, 5});
    }
}

TEST_CASE("Ascending Iterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    AscendingIterator ascIter(container);

    SUBCASE("operator++"){
        CHECK(*ascIter == 2);
        ++ascIter;
        CHECK(*ascIter == 3);
        ++ascIter;
        CHECK(*ascIter == 9);
        ++ascIter;
        CHECK(*ascIter == 17);
        ++ascIter;
        CHECK(*ascIter == 25);
    }

    SUBCASE("operator==") {
        AscendingIterator ai1(container);
        AscendingIterator ai2(container);
        AscendingIterator ai3(container);
        ++ai1;
        ++ai2;
        ++ai3;
        CHECK(ai1 == ai1);
        CHECK(ai2 == ai2);
        CHECK(ai3 == ai3);
    }

    SUBCASE("operator!="){
        AscendingIterator ai1(container);
        AscendingIterator ai2(container);
        AscendingIterator ai3(container);
        CHECK(ai1 != ai1);
        CHECK(ai2 != ai2);
        CHECK(ai3 != ai3);
    }

    SUBCASE("getIndex") {
        CHECK(ascIter.getIndex() == 0);
        ++ascIter;
        CHECK(ascIter.getIndex() == 1);
        ++ascIter;
        CHECK(ascIter.getIndex() == 2);
        ++ascIter;
        CHECK(ascIter.getIndex() == 3);
        ++ascIter;
        CHECK(ascIter.getIndex() == 4);
    }

}

TEST_CASE("Side Cross Iterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    SideCrossIterator crossIter(container);

    SUBCASE("operator++") {
        CHECK(*crossIter == 2);
        ++crossIter;
        CHECK(*crossIter == 25);
        ++crossIter;
        CHECK(*crossIter == 3);
        ++crossIter;
        CHECK(*crossIter == 17);
        ++crossIter;
        CHECK(*crossIter == 9);
    }

    SUBCASE("operator==") {
        SideCrossIterator sci1(container);
        SideCrossIterator sci2(container);
        SideCrossIterator sci3(container);
        ++sci1;
        ++sci2;
        ++sci3;
        CHECK(sci1 == sci1);
        CHECK(sci2 == sci2);
        CHECK(sci3 == sci3);
    }

    SUBCASE("operator!="){
        SideCrossIterator sci1(container);
        SideCrossIterator sci2(container);
        SideCrossIterator sci3(container);
        CHECK(sci1 != sci1);
        CHECK(sci2 != sci2);
        CHECK(sci3 != sci3);
    }

    SUBCASE("getFindex") {
        CHECK(crossIter.getFindex() == 0);
        ++crossIter;
        CHECK(crossIter.getFindex() == 1);
        ++crossIter;
        CHECK(crossIter.getFindex() == 2);
        ++crossIter;
        CHECK(crossIter.getFindex() == 3);
        ++crossIter;
        CHECK(crossIter.getFindex() == 4);
    }

    SUBCASE("getBindex") {
        CHECK(crossIter.getBindex() == 5);
        ++crossIter;
        CHECK(crossIter.getBindex() == 4);
        ++crossIter;
        CHECK(crossIter.getBindex() == 3);
        ++crossIter;
        CHECK(crossIter.getBindex() == 2);
        ++crossIter;
        CHECK(crossIter.getBindex() == 1);
    }
}

TEST_CASE("Prime Iterator") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    PrimeIterator primeIter(container);

    SUBCASE("Test operator++") {
        CHECK(*primeIter == 2);
        ++primeIter;
        CHECK(*primeIter == 3);
        ++primeIter;
        CHECK(*primeIter == 17);
    }

    SUBCASE("Test operator== and operator!=") {
        PrimeIterator pi1(container);
        PrimeIterator pi2(container);
        ++pi1;
        ++pi2;
        CHECK(pi1 == pi1);
        CHECK(pi2 == pi2);
    }

    SUBCASE("operator!="){
        PrimeIterator pi1(container);
        PrimeIterator pi2(container);
        CHECK(pi1 != pi2);
    }

    SUBCASE("getIndex") {
        CHECK(primeIter.getIndex() == 0);
        ++primeIter;
        CHECK(primeIter.getIndex() == 1);
        ++primeIter;
        CHECK(primeIter.getIndex() == 2);
        ++primeIter;
        CHECK(primeIter.getIndex() == 3);
        ++primeIter;
        CHECK(primeIter.getIndex() == 4);
    }
}