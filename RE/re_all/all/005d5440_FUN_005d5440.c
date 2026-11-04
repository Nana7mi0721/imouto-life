
undefined4 FUN_005d5440(void)

{
  FARPROC pFVar1;
  int iVar2;
  
  if (DAT_00f3a068 != (int *)0x0) {
    (**(code **)(*DAT_00f3a068 + 8))(DAT_00f3a068);
    DAT_00f3a068 = (int *)0x0;
    DAT_00f3a06c = (int *)0x0;
  }
  FUN_0056bb10(0x7ffc00);
  pFVar1 = GetProcAddress(DAT_00f3a05c,"CreateDXGIFactory1");
  if (pFVar1 == (FARPROC)0x0) {
    FUN_0056bb10("1YWe\n");
  }
  else {
    FUN_0056bb10(&DAT_007d4974);
    FUN_0056bb10(&PTR_PTR_007ffbb8);
    iVar2 = (*pFVar1)(&DAT_0085e654,&DAT_00f3a06c);
    if (iVar2 < 0) {
      FUN_0056bb10("1YWe\n");
    }
    else {
      FUN_0056bb10(&DAT_007d4974);
      DAT_00f3a068 = DAT_00f3a06c;
    }
  }
  if (DAT_00f3a068 != (int *)0x0) {
    return 0;
  }
  FUN_0056bb10(&PTR_DAT_007ffb68);
  pFVar1 = GetProcAddress(DAT_00f3a05c,"CreateDXGIFactory");
  if (pFVar1 != (FARPROC)0x0) {
    FUN_0056bb10(&DAT_007d4974);
    FUN_0056bb10(&PTR_PTR_007ffb1c);
    iVar2 = (*pFVar1)(&DAT_0085e644,&DAT_00f3a068);
    if (-1 < iVar2) {
      FUN_0056bb10(&DAT_007d4974);
      return 0;
    }
  }
  FUN_0056bb10("1YWe\n");
  return 0xffffffff;
}

