
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bace0(void)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_00ef1b94 + 8);
  *(undefined4 *)(iVar1 + 0xc0) = DAT_00f138e4;
  *(undefined4 *)(iVar1 + 0xc4) = _DAT_00f138f4;
  *(undefined4 *)(iVar1 + 200) = _DAT_00f13904;
  *(undefined4 *)(iVar1 + 0xcc) = _DAT_00f13914;
  *(undefined4 *)(iVar1 + 0xd0) = DAT_00f138e8;
  *(undefined4 *)(iVar1 + 0xd4) = _DAT_00f138f8;
  *(undefined4 *)(iVar1 + 0xd8) = _DAT_00f13908;
  *(undefined4 *)(iVar1 + 0xdc) = _DAT_00f13918;
  *(undefined4 *)(DAT_00ef1b94 + 0xc) = 1;
  _DAT_00ef1b98 = 1;
  return 0;
}

