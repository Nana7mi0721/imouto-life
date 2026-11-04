
undefined4 FUN_005e4fd0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar1 = 5;
  if ((DAT_00dccde4 != 0) && (DAT_00a37dc8 != 0)) {
    uVar1 = 0xd;
  }
  FUN_0059c240(&DAT_00ddb600,uVar1);
  if ((DAT_00ca39f4 != 0) && (DAT_00ca39e8 == 0)) {
    FUN_0057b170(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    DAT_00ca39e8 = 1;
  }
  FUN_00516a20();
  FUN_00524c30();
  DAT_00dda468 = 0;
  FUN_0059d430();
  FUN_0059a710(*(undefined4 *)(param_1 + 0x25c));
  FUN_0059a780(*(undefined4 *)(param_1 + 0x260));
  FUN_0059a7e0(*(undefined4 *)(param_1 + 0x264));
  FUN_0059a840(*(undefined4 *)(param_1 + 0x268));
  FUN_0059a9e0(2);
  thunk_FUN_00567d40();
  iVar2 = 0;
  do {
    FUN_0059b300(*(undefined4 *)(param_1 + 0x270),iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  FUN_0059a8a0(3 - (uint)(*(char *)(param_1 + 0x26c) != '\0'));
  if ((DAT_00a38288 == 0) && (DAT_00a37d78 != 0)) {
    FUN_00519910(0);
  }
  DAT_00a3828c = 0;
  DAT_00a38288 = 0;
  DAT_00e7984c = 3;
  DAT_00e39a0c = 0xffffffff;
  DAT_00e39a10 = 0;
  DAT_00e39a00 = 1;
  if (*(char *)(param_1 + 0x24e) == '\0') {
    local_10 = 0;
  }
  else {
    local_10 = 0x3f800000;
  }
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_0059cb80(&DAT_00ddb600,3,0,0x16,&local_10,1,1);
  return 0;
}

