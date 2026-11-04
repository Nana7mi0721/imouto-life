
undefined4 FUN_005647d0(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (((((int)param_2 < 0) || ((param_2 & 0x7c000000) != 0x24000000)) ||
      (uVar2 = param_2 & 0xffff, 0xff < uVar2)) ||
     (((&DAT_00aa84b8)[uVar2 * 0x17] == 0 ||
      ((&DAT_00aa84bc)[uVar2 * 0x17] * 0x10000 != (param_2 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  if (DAT_00aba24c == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba24c;
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  FUN_005764b0(*(undefined4 *)(&DAT_00aa84e0 + uVar2 * 0x5c),0xffffffff,DAT_00aba250,param_1,
               0x7fffffff,iVar1);
  return 0;
}

