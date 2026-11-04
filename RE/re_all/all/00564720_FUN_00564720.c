
undefined4 FUN_00564720(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (((((int)param_2 < 0) || ((param_2 & 0x7c000000) != 0x24000000)) ||
      (uVar3 = param_2 & 0xffff, 0xff < uVar3)) ||
     ((iVar4 = uVar3 * 0x5c, (&DAT_00aa84b8)[uVar3 * 0x17] == 0 ||
      ((&DAT_00aa84bc)[uVar3 * 0x17] * 0x10000 != (param_2 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  iVar2 = FUN_0050e220(param_1);
  iVar1 = *(int *)(&DAT_00aa84cc + iVar4);
  if (iVar1 < iVar2) {
    iVar2 = iVar1;
  }
  FUN_0056cfa0(*(undefined4 *)(&DAT_00aa84e0 + iVar4),iVar1 * 2,param_1,iVar2);
  *(undefined2 *)(*(int *)(&DAT_00aa84e0 + iVar4) + iVar2 * 2) = 0;
  *(int *)(&DAT_00aa84c8 + iVar4) = iVar2;
  *(int *)(&DAT_00aa84dc + iVar4) = iVar2;
  *(undefined4 *)(&DAT_00aa84d4 + iVar4) = 0xffffffff;
  *(undefined4 *)(&DAT_00aa84d0 + iVar4) = 0xffffffff;
  if (iVar2 < *(int *)(&DAT_00aa84d8 + iVar4)) {
    *(int *)(&DAT_00aa84d8 + iVar4) = iVar2;
  }
  FUN_00564700();
  return 0;
}

