#include "akasztofa.h"
#include <string>
#include <gtest/gtest.h>

TEST(AkasztofaTest, getHatra_feladvanyHossz) {
  std::string feladvany = "abcde";
  Akasztofa a(feladvany);
  EXPECT_EQ(feladvany.length(), a.getHatra())
    << "A feladvany hosszanak kell lennie az alapertelmezett "
    << "maximalis probalkozasi szamnak.\n";
}

TEST(AkasztofaTest, getHatra_adottHossz) {
  int hossz = 10;
  Akasztofa a("abcde", hossz);
  EXPECT_EQ(hossz, a.getHatra())
    << "A feladvany hosszanak " << hossz << "-nak kell lennie.\n";
}

TEST(AkasztofaTest, tipp_felfedes) {
  Akasztofa a("aaa bb c");
  EXPECT_EQ(6, a.tipp('x')) 
    << "Hibas tippre a rejtett betuk szama nem csokkenhet.\n";
  EXPECT_EQ(3, a.tipp('a')) 
    << "Minden 'a' betut fel kellene ismernie.\n";
  EXPECT_EQ(1, a.tipp('b')) 
    << "Minden 'b' betut fel kellene ismernie.\n";
  EXPECT_EQ(0, a.tipp('c')) 
    << "Minden karakternek felfedettnek kellene lennie.\n";
}

TEST(AkasztofaTest, tipp_kivetel) {
  Akasztofa a("a", 1);
  EXPECT_NO_THROW(a.tipp('a')) << "Egyet kellene tudni tippelni.\n";
  EXPECT_THROW(a.tipp('b'), const char*) 
    << "Nem lenne szabad ujabbat tippelni.\n";
}

TEST(AkasztofaTest, kiiras) {
  Akasztofa a("aaa bb c");
  testing::internal::CaptureStdout();
  std::cout << a << std::endl;
  a.tipp('c');
  std::cout << a << std::endl;
  a.tipp('b');
  std::cout << a << std::endl;
  a.tipp('a');
  std::cout << a << std::endl;
  std::string kimenet = testing::internal::GetCapturedStdout();
  EXPECT_EQ("*** ** *\n*** ** c\n*** bb c\naaa bb c\n", kimenet);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
