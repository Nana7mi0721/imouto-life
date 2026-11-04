
undefined4 FUN_005d6050(void)

{
  FARPROC pFVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00f3a044 != (int *)0x0) {
    (**(code **)(*DAT_00f3a044 + 8))(DAT_00f3a044);
    DAT_00f3a044 = (int *)0x0;
  }
  DAT_00f3a048 = (int *)0x0;
  if (DAT_00ddb36c == 0) {
    FUN_0056bb10(&PTR_PTR_007ffd38);
    pFVar1 = GetProcAddress(DAT_00f3a040,"Direct3DCreate9Ex");
    if ((pFVar1 != (FARPROC)0x0) && (iVar2 = (*pFVar1)(0x20,&DAT_00f3a048), iVar2 == 0)) {
      DAT_00f3a044 = DAT_00f3a048;
    }
  }
  if (DAT_00f3a044 == (int *)0x0) {
    FUN_0056bb10(&PTR_PTR_007ffce8);
    pFVar1 = GetProcAddress(DAT_00f3a040,"Direct3DCreate9");
    if (pFVar1 == (FARPROC)0x0) {
      uVar3 = FUN_0056bb10(&PTR_LAB_007ffc90);
      return uVar3;
    }
    DAT_00f3a044 = (int *)(*pFVar1)(0x20);
    if (DAT_00f3a044 == (int *)0x0) {
      uVar3 = FUN_0056bb10(&PTR_PTR_007ffc50);
      return uVar3;
    }
  }
  FUN_0056bb10(&DAT_007d4974);
  return 0;
}

