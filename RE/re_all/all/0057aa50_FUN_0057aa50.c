
undefined4 FUN_0057aa50(undefined4 param_1,undefined4 param_2)

{
  WCHAR local_800 [1024];
  
  GetCurrentDirectoryW(0x400,local_800);
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  FUN_005764b0(local_800,0xffffffff,0x4b0,param_1,param_2,DAT_00aba250);
  return param_1;
}

