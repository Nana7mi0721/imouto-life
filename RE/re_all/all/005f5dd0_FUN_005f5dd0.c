
undefined4 FUN_005f5dd0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined1 local_42c [1024];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  int *local_20;
  undefined1 local_1c [4];
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1 == 0) {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar2 = DAT_00aba250;
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    FUN_005764b0(param_2,0xffffffff,DAT_00aba24c,local_42c,0x400,iVar2);
    local_14 = thunk_FUN_00595690(local_42c);
  }
  else {
    local_14 = thunk_FUN_00595690(param_1);
  }
  if (local_14 == 0) {
    return 0xffffffff;
  }
  local_8 = FUN_00671750(s_1_6_12_00a05944,0,0,0);
  if (local_8 == 0) {
    return 0xffffffff;
  }
  local_10 = FUN_00669210(local_8);
  if (local_10 == 0) {
    FUN_00671c80(&local_8,0);
    return 0xffffffff;
  }
  uVar1 = FUN_00668c20(local_8,&LAB_006c5890,0x40);
  iVar2 = __setjmp3(uVar1,0);
  if (iVar2 == 0) {
    FUN_005f5d90(local_8,local_14);
    FUN_00671d70(local_8,0,0xf8);
    FUN_00671fe0(local_8,param_4);
    FUN_006720f0(local_8,local_10,*(undefined4 *)(param_3 + 0x428),*(undefined4 *)(param_3 + 0x42c),
                 8,(-(*(char *)(param_3 + 0xb) != '\0') & 4U) + 2,0,0,0);
    FUN_00671370(local_8,local_10);
    piVar3 = (int *)FUN_0056e030(*(int *)(param_3 + 0x42c) << 2,
                                 s_D__DxLib_Develop_Source_Library__00a058f8,0x37f);
    local_18 = piVar3;
    if (piVar3 != (int *)0x0) {
      FUN_0056d380(piVar3,0,*(int *)(param_3 + 0x42c) << 2);
      local_c = 0;
      if (0 < *(int *)(param_3 + 0x42c)) {
        local_20 = piVar3;
        do {
          puVar4 = (undefined1 *)
                   FUN_0056e030(((*(char *)(param_3 + 0xb) != '\0') + 3) * *(int *)(param_3 + 0x428)
                                ,s_D__DxLib_Develop_Source_Library__00a058f8,900);
          *local_20 = (int)puVar4;
          if (puVar4 == (undefined1 *)0x0) goto LAB_005f60ee;
          if (*(char *)(param_3 + 0xb) == '\0') {
            iVar2 = 0;
            if (0 < *(int *)(param_3 + 0x428)) {
              do {
                FUN_00549840(param_3,iVar2,local_c,local_1c,local_24,local_28,local_2c);
                *puVar4 = local_1c[0];
                puVar4[1] = local_24[0];
                puVar4[2] = local_28[0];
                iVar2 = iVar2 + 1;
                puVar4 = puVar4 + 3;
              } while (iVar2 < *(int *)(param_3 + 0x428));
            }
          }
          else {
            iVar2 = 0;
            if (0 < *(int *)(param_3 + 0x428)) {
              do {
                FUN_00549840(param_3,iVar2,local_c,local_1c,local_24,local_28,local_2c);
                *puVar4 = local_1c[0];
                puVar4[1] = local_24[0];
                puVar4[2] = local_28[0];
                puVar4[3] = local_2c[0];
                iVar2 = iVar2 + 1;
                puVar4 = puVar4 + 4;
              } while (iVar2 < *(int *)(param_3 + 0x428));
            }
          }
          local_c = local_c + 1;
          local_20 = local_20 + 1;
          piVar3 = local_18;
        } while (local_c < *(int *)(param_3 + 0x42c));
      }
      FUN_00671830(local_8,piVar3);
      FUN_00671620(local_8,local_10);
      FUN_00671c80(&local_8,&local_10);
      thunk_FUN_005956d0(local_14);
      iVar2 = 0;
      if (0 < *(int *)(param_3 + 0x42c)) {
        do {
          if (*piVar3 != 0) {
            FUN_0056e1d0(*piVar3);
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < *(int *)(param_3 + 0x42c));
        piVar3 = local_18;
      }
      FUN_0056e1d0(piVar3);
      return 0;
    }
  }
  else {
    piVar3 = local_18;
LAB_005f60ee:
    if (piVar3 != (int *)0x0) {
      local_c = 0;
      if (0 < *(int *)(param_3 + 0x42c)) {
        piVar5 = piVar3;
        do {
          if (*piVar5 != 0) {
            FUN_0056e1d0(*piVar5);
          }
          local_c = local_c + 1;
          piVar5 = piVar5 + 1;
        } while (local_c < *(int *)(param_3 + 0x42c));
      }
      FUN_0056e1d0(piVar3);
    }
  }
  if (local_14 != 0) {
    thunk_FUN_005956d0(local_14);
  }
  FUN_00671c80(&local_8,&local_10);
  return 0xffffffff;
}

