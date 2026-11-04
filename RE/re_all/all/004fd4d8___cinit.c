
/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2003 Release */

int __cdecl __cinit(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (PTR___fpmath_0084b490 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_0084b490)(param_1);
  }
  iVar1 = 0;
  puVar2 = &DAT_0084b1cc;
  do {
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((code *)*puVar2 != (code *)0x0) {
      iVar1 = (*(code *)*puVar2)();
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 < &DAT_0084b1e4);
  if (iVar1 == 0) {
    _atexit((_func_4879 *)&LAB_005049a9);
    puVar2 = &DAT_0084b000;
    do {
      if ((code *)*puVar2 != (code *)0x0) {
        (*(code *)*puVar2)();
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 < &DAT_0084b1c8);
    iVar1 = 0;
  }
  return iVar1;
}

