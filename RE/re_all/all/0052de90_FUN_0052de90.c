
undefined4 FUN_0052de90(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00a496f0 == 1) {
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007d5a88);
  FUN_005808a0(0x11,0x68,0x8000,FUN_005e2310,FUN_0052c7b0,L"File");
  PTR_thunk_FUN_00571e60_0084ca0c = thunk_FUN_00571e60;
  PTR_DAT_0084ca10 = &DAT_0052c640;
  PTR_DAT_0084ca14 = &DAT_0052c650;
  PTR_FUN_0084ca08 = FUN_0052c610;
  PTR_thunk_FUN_00571dd0_0084ca04 = thunk_FUN_00571dd0;
  PTR_thunk_FUN_00571d20_0084ca18 = thunk_FUN_00571d20;
  PTR_FUN_0084ca24 = FUN_0052d0f0;
  PTR_FUN_0084ca28 = FUN_0052d190;
  PTR_LAB_0084ca2c = &LAB_0052d1a0;
  PTR_LAB_0084ca20 = &LAB_0052d070;
  PTR_LAB_0084ca1c = &LAB_0052d060;
  PTR_FUN_0084ca30 = FUN_0052d050;
  iVar1 = FUN_005e2310();
  if (iVar1 < 0) {
    uVar2 = FUN_0056bb10("1YWe\n");
    return uVar2;
  }
  FUN_0056bb10(&DAT_007d4974);
  DAT_00a496f0 = 1;
  return 0;
}

