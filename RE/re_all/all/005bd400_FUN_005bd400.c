
undefined4 FUN_005bd400(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((param_1 != 0) && (*(char *)(*(int *)(param_1 + 0x4c) + 8) != '\0')) {
    piVar1 = *(int **)(param_1 + 0x100);
    FUN_005bc640(*(undefined4 *)(*piVar1 + 4),*(undefined4 *)(*piVar1 + 8),piVar1[5],piVar1[6]);
    FUN_005bc490(param_2,param_3);
    return 0;
  }
  DAT_00a380d4 = 0xffffffff;
  if (DAT_00ef7324 == 0) {
    if (DAT_00ef731c == 0) {
      DAT_00a380d4 = 0xffffffff;
      return 0;
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  if (DAT_00ef731c != 0) {
    DAT_00ef72e4 = 1;
  }
  DAT_00ef7320 = 0;
  DAT_00ef731c = 0;
  DAT_00ef72e8 = 1;
  DAT_00ef72cc = 1;
  return 0;
}

