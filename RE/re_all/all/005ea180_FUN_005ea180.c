
undefined4 FUN_005ea180(int param_1)

{
  int iVar1;
  
  FUN_00516a20();
  FUN_00524c30();
  DAT_00dda468 = 0;
  FUN_005b9210(*(undefined4 *)(param_1 + 0x25c));
  FUN_005b9270(*(undefined4 *)(param_1 + 0x260));
  FUN_005b92d0(*(undefined4 *)(param_1 + 0x264));
  FUN_005b9330(*(undefined4 *)(param_1 + 0x268));
  thunk_FUN_00567d40();
  iVar1 = 0;
  do {
    FUN_005bb0b0(*(undefined4 *)(param_1 + 0x270),iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  FUN_005b9390(3 - (uint)(*(char *)(param_1 + 0x26c) != '\0'));
  if ((DAT_00a38288 == 0) && (DAT_00a37d78 != 0)) {
    FUN_00519910(0);
  }
  DAT_00a3828c = 0;
  DAT_00a38288 = 0;
  DAT_00f07678 = 3;
  DAT_00ef72d8 = 0xffffffff;
  DAT_00ef72dc = 0;
  DAT_00ef72cc = 1;
  DAT_00ef72e8 = 1;
  FUN_005bb350(*(undefined1 *)(param_1 + 0x24e));
  return 0;
}

