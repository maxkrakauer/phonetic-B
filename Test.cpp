#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}

/* Add more test cases here */


TEST_CASE("Test replacement of v and w") {
    string text = "xxx vappv yyy";
    CHECK(find(text, "wappv") == string("vappv"));
    CHECK(find(text, "wabbw") == string("vappv"));
    CHECK(find(text, "vapbv") == string("vappv"));
    CHECK(find(text, "vabpw") == string("vappv"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of w with v") {
    string text = "xxx wappw yyy";
    CHECK(find(text, "wappv") == string("wappw"));
    CHECK(find(text, "wabbw") == string("wappw"));
    CHECK(find(text, "vapbv") == string("wappw"));
    CHECK(find(text, "vabpw") == string("wappw"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of v with w") {
    string text = "xxx valve yyy";
    CHECK(find(text, "walve") == string("valve"));
    CHECK(find(text, "walwe") == string("valve"));
    CHECK(find(text, "valve") == string("valve"));
    CHECK(find(text, "valwe") == string("valve"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of b with f") {
    string text = "before and after";
    CHECK(find(text, "bebore") == string("before"));
    CHECK(find(text, "fefore") == string("before"));
    CHECK(find(text, "febore") == string("before"));
    CHECK(find(text, "before") == string("before"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of p with f") {
    string text = "forbear the future";
    CHECK(find(text, "forbear") == string("forbear"));
    CHECK(find(text, "forfear") == string("forbear"));
    CHECK(find(text, "borfear") == string("forbear"));
    CHECK(find(text, "borbear") == string("forbear"));

    CHECK_THROWS(find(text,"forbeav"));
    CHECK_THROWS(find(text,"norbeav"));
    CHECK_THROWS(find(text,"torbeav"));
    CHECK_THROWS(find(text,"forbeat"));
    
    /* Add more checks here */
}

TEST_CASE("Test replacement of g with j") {
    string text = "let's go jogging";
    CHECK(find(text, "jogging") == string("jogging"));
    CHECK(find(text, "gogging") == string("jogging"));
    CHECK(find(text, "jojjing") == string("jogging"));
    CHECK(find(text, "jojging") == string("jogging"));
    CHECK(find(text, "jogjing") == string("jogging"));
    CHECK(find(text, "gogginj") == string("jogging"));
    CHECK(find(text, "jojjinj") == string("jogging"));

    
    CHECK_THROWS(find(text,"joggint"));
    CHECK_THROWS(find(text,"soggint"));
    CHECK_THROWS(find(text,"jogging"));
    CHECK_THROWS(find(text,"dogginj"));
    
    
    /* Add more checks here */
}

TEST_CASE("Test replacement of c with k") {
    string text = "clark kent";
    CHECK(find(text, "clark") == string("clark"));
    CHECK(find(text, "klark") == string("clark"));
    CHECK(find(text, "clarc") == string("clark"));
    CHECK(find(text, "klarc") == string("clark"));

    CHECK(find(text, "kent") == string("kent"));
    CHECK(find(text, "cent") == string("kent"));
    
    CHECK_THROWS(find(text,"clart"));
    CHECK_THROWS(find(text,"mlark"));
    CHECK_THROWS(find(text,"kenr"));
    CHECK_THROWS(find(text,"kenm"));
    
    
    /* Add more checks here */
}


TEST_CASE("Test replacement of c with q") {
    string text = "cents and quarters";
    CHECK(find(text, "cents") == string("cents"));
    CHECK(find(text, "qents") == string("cents"));
    
    CHECK(find(text, "quarters") == string("quarters"));
    CHECK(find(text, "cuarters") == string("quarters"));
    
    CHECK_THROWS(find(text,"cenps"));
    CHECK_THROWS(find(text,"tents"));
    CHECK_THROWS(find(text,"tuarters"));
    CHECK_THROWS(find(text,"muarters"));
    
    
    
    /* Add more checks here */
}

TEST_CASE("Test replacement of k with q") {
    string text = "quell and kill";
    CHECK(find(text, "quell") == string("quell"));
    CHECK(find(text, "kuell") == string("quell"));
    
    CHECK(find(text, "kill") == string("kill"));
    CHECK(find(text, "qill") == string("kill"));

    CHECK_THROWS(find(text,"tuell"));
    CHECK_THROWS(find(text,"buell"));

    CHECK_THROWS(find(text,"mill"));
    CHECK_THROWS(find(text,"fill"));
    
    /* Add more checks here */
}

TEST_CASE("Test replacement of s with z") {
    string text = "suez canal";
    CHECK(find(text, "suez") == string("suez"));
    CHECK(find(text, "zuez") == string("suez"));
    CHECK(find(text, "sues") == string("suez"));
    CHECK(find(text, "zues") == string("suez"));

    CHECK_THROWS(find(text,"muez"));
    CHECK_THROWS(find(text,"tuez"));
    CHECK_THROWS(find(text,"suen"));
    CHECK_THROWS(find(text,"zueb"));
    
    /* Add more checks here */
}





TEST_CASE("word doesn't appear in text") {
    string text1 = "xxx valve yyy";
    CHECK_THROWS(find(text1, "aaa"));
    CHECK_THROWS(find(text1, "bgfd"));
    CHECK_THROWS(find(text1, "vallv"));
    CHECK_THROWS(find(text1, "ybt"));

    string text2 = "hey my tamborine man";
    CHECK_THROWS(find(text2, "ty"));
    CHECK_THROWS(find(text2, "san"));
    CHECK_THROWS(find(text2, "ban"));
    CHECK_THROWS(find(text2, "g"));

    string text3 = "time time";
    CHECK_THROWS(find(text3, "tim"));
    CHECK_THROWS(find(text3, "rime"));
    CHECK_THROWS(find(text3, "mime"));
    CHECK_THROWS(find(text3, "ime"));

    string text4 = "never say never to always";
    CHECK_THROWS(find(text4, "day"));
    CHECK_THROWS(find(text4, "to a"));
    CHECK_THROWS(find(text4, "alway"));
    CHECK_THROWS(find(text4, "never "));
    CHECK_THROWS(find(text4, "t"));
    CHECK_THROWS(find(text4, "day"));
    CHECK_THROWS(find(text4, "to "));
    CHECK_THROWS(find(text4, "lways"));
    CHECK_THROWS(find(text4, "nver"));
    CHECK_THROWS(find(text4, "tever"));
    CHECK_THROWS(find(text4, "ot"));
    CHECK_THROWS(find(text4, "reven"));
    CHECK_THROWS(find(text4, "yas"));
    CHECK_THROWS(find(text4, "ne"));
    CHECK_THROWS(find(text4, "n"));
    CHECK_THROWS(find(text4, "neveg"));








    
    /* Add more checks here */
}





