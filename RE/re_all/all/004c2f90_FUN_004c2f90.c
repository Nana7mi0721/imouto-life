
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c2f90(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if (((*(char *)(param_1 + 0x290) != '\0') && (*(char *)(param_1 + 0x256) != '\0')) &&
     (*(int *)(param_1 + 600) != -1)) {
    if (DAT_00a117bc == 0) {
      FUN_005160d0(0,0xff);
    }
    else {
      FUN_005160d0(1,0xfe);
    }
    if (DAT_00a18a4c == -1) {
      if (DAT_0084b248 == 1) {
        uVar1 = FUN_004fe844(0,(*(int *)(param_1 + 0x278) / 5) *
                               (*(int *)(param_1 + 0x284) / *(int *)(param_1 + 0x27c)),
                             *(undefined4 *)(param_1 + 0x280),
                             *(int *)(param_1 + 0x284) / *(int *)(param_1 + 0x27c),
                             *(undefined4 *)(param_1 + 600),DAT_0084b240,0,0);
        FUN_00526e30((int)DAT_00a18ac6 - *(int *)(param_1 + 0x280) / 2,uVar1);
      }
      if (DAT_0084b248 == 2) {
        uVar1 = FUN_0052a120();
        iVar2 = FUN_004fe844(uVar1,DAT_0084b240);
        uVar3 = FUN_004fe844((((int)DAT_00a18ac6 - *(int *)(param_1 + 0x280) / 2) +
                             *(int *)(param_1 + 0x280)) * 2,
                             (iVar2 + *(int *)(param_1 + 0x284) / *(int *)(param_1 + 0x27c)) * 2);
        FUN_0051f060(((int)DAT_00a18ac6 - *(int *)(param_1 + 0x280) / 2) * 2,uVar3);
        FUN_00515700(uVar1,0);
      }
    }
    else {
      if (DAT_0084b248 == 1) {
        iVar2 = FUN_004fe844();
        if (iVar2 < DAT_00a18ac8 + DAT_00a18a4c) {
          local_14 = FUN_004fe844();
        }
        else {
          local_14 = DAT_00a18ac8 + DAT_00a18a4c;
        }
        if (local_14 < 0) {
          local_18 = 0;
        }
        else {
          iVar2 = FUN_004fe844();
          if (iVar2 < DAT_00a18ac8 + DAT_00a18a4c) {
            local_1c = FUN_004fe844();
          }
          else {
            local_1c = DAT_00a18ac8 + DAT_00a18a4c;
          }
          local_18 = local_1c;
        }
        FUN_00526e30((int)DAT_00a18ac6 - *(int *)(param_1 + 0x280) / 2,local_18,0,
                     (*(int *)(param_1 + 0x278) / 5) *
                     (*(int *)(param_1 + 0x284) / *(int *)(param_1 + 0x27c)),
                     *(undefined4 *)(param_1 + 0x280),
                     *(int *)(param_1 + 0x284) / *(int *)(param_1 + 0x27c),
                     *(undefined4 *)(param_1 + 600),DAT_0084b240,0,0);
      }
      if (DAT_0084b248 == 2) {
        uVar1 = FUN_0052a120();
        iVar2 = FUN_004fe844();
        if (iVar2 < DAT_00a18ac8 + DAT_00a18a4c) {
          local_20 = FUN_004fe844();
        }
        else {
          local_20 = DAT_00a18ac8 + DAT_00a18a4c;
        }
        if (local_20 < 0) {
          local_24 = 0;
        }
        else {
          iVar2 = FUN_004fe844();
          if (iVar2 < DAT_00a18ac8 + DAT_00a18a4c) {
            local_28 = FUN_004fe844();
          }
          else {
            local_28 = DAT_00a18ac8 + DAT_00a18a4c;
          }
          local_24 = local_28;
        }
        iVar2 = FUN_004fe844();
        if (iVar2 < DAT_00a18ac8 + DAT_00a18a4c) {
          local_2c = FUN_004fe844();
        }
        else {
          local_2c = DAT_00a18ac8 + DAT_00a18a4c;
        }
        if (local_2c < 0) {
          local_30 = 0;
        }
        else {
          iVar2 = FUN_004fe844();
          if (iVar2 < DAT_00a18ac8 + DAT_00a18a4c) {
            local_34 = FUN_004fe844();
          }
          else {
            local_34 = DAT_00a18ac8 + DAT_00a18a4c;
          }
          local_30 = local_34;
        }
        FUN_0051f060(((int)DAT_00a18ac6 - *(int *)(param_1 + 0x280) / 2) * 2,local_30 << 1,
                     *(int *)(param_1 + 0x280) * 2 +
                     ((int)DAT_00a18ac6 - *(int *)(param_1 + 0x280) / 2) * 2,
                     (*(int *)(param_1 + 0x284) << 1) / *(int *)(param_1 + 0x27c) + local_24 * 2,
                     uVar1,DAT_0084b240);
        FUN_00515700(uVar1,0);
      }
    }
  }
  if (*(int *)(param_1 + 0x270) < 1) {
    FUN_005160d0(0,0xff);
    FUN_00494480(1,_DAT_00802e18,_DAT_00802e18,_DAT_007d0a60);
  }
  return;
}

