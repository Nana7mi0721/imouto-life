
undefined4 FUN_0057ba00(void)

{
  int iVar1;
  
  if (DAT_00ca3a18 != 1) {
    FUN_005808a0(6,0x1248,100,&LAB_0057b350,FUN_0057b370,L"Movie");
    iVar1 = FUN_005e2310();
    if (-1 < iVar1) {
      DAT_00ca3a18 = 1;
      return 0;
    }
  }
  return 0xffffffff;
}

