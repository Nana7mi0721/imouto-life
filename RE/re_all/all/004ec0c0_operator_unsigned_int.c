
/* Library Function - Single Match
    public: __thiscall std::locale::id::operator unsigned int(void)
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

uint __thiscall std::locale::id::operator_unsigned_int(id *this)

{
  if (*(int *)this == 0) {
    FUN_0050d92b(0);
    if (*(int *)this == 0) {
      DAT_00a20158 = DAT_00a20158 + 1;
      *(int *)this = DAT_00a20158;
    }
    FUN_0050d94e();
  }
  return *(uint *)this;
}

