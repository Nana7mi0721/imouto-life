
/* WARNING: Removing unreachable block (ram,0x005a7cac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005a7c20(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  FUN_00568ca0(0,param_1);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  _DAT_00e79898 = (float)_DAT_0081ec30;
  _DAT_00e7988c = (float)(param_2 >> 0x10 & 0xff) / _DAT_00e79898;
  _DAT_00e79890 = (float)(param_2 >> 8 & 0xff) / _DAT_00e79898;
  _DAT_00e79894 = (float)(param_2 & 0xff) / _DAT_00e79898;
  _DAT_00e79898 = (float)(param_2 >> 0x18) / _DAT_00e79898;
  FUN_005a2cb0();
  iVar1 = FUN_005d3a70(0x8b,param_2);
  return -(uint)(iVar1 != 0);
}

