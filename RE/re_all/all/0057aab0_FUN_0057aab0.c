
int FUN_0057aab0(undefined4 param_1)

{
  BOOL BVar1;
  WCHAR local_800 [1024];
  
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  FUN_005764b0(param_1,0xffffffff,DAT_00aba250,local_800,0x800,0x4b0);
  BVar1 = SetCurrentDirectoryW(local_800);
  return (BVar1 != 0) - 1;
}

