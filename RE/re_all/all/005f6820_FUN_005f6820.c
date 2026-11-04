
undefined4 FUN_005f6820(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined1 local_690 [1024];
  undefined *local_290 [33];
  undefined1 local_20c [64];
  undefined4 local_1cc [7];
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  int *local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  if (param_1 == 0) {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar1 = DAT_00aba250;
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    FUN_005764b0(param_2,0xffffffff,DAT_00aba24c,local_690,0x400,iVar1);
    local_10 = thunk_FUN_00595690(local_690);
  }
  else {
    local_10 = thunk_FUN_00595690(param_1);
  }
  if (local_10 == 0) {
    return 0xffffffff;
  }
  FUN_0056d380(local_1cc,0,0x1a8);
  local_1cc[0] = FUN_00683b90(local_290);
  local_290[0] = &DAT_005f6160;
  iVar1 = __setjmp3(local_20c,0);
  if (iVar1 == 0) {
    FUN_00683d40(local_1cc,0x5a,0x1a8);
    FUN_005f6750(local_1cc,local_10);
    local_1b0 = *(undefined4 *)(param_3 + 0x428);
    local_1ac = *(undefined4 *)(param_3 + 0x42c);
    local_1a8 = 3;
    local_1a4 = 2;
    FUN_00684270(local_1cc);
    FUN_00684250(local_1cc,param_4,1);
    FUN_00683fa0(local_1cc,1);
    piVar2 = (int *)FUN_0056e030(*(int *)(param_3 + 0x42c) << 2,
                                 s_D__DxLib_Develop_Source_Library__00a058f8,0x5b6);
    local_c = piVar2;
    if (piVar2 != (int *)0x0) {
      FUN_0056d380(piVar2,0,*(int *)(param_3 + 0x42c) << 2);
      local_8 = 0;
      if (0 < *(int *)(param_3 + 0x42c)) {
        local_14 = piVar2;
        do {
          puVar3 = (undefined1 *)
                   FUN_0056e030(*(int *)(param_3 + 0x428) * 3,
                                s_D__DxLib_Develop_Source_Library__00a058f8,0x5bb);
          *local_14 = (int)puVar3;
          if (puVar3 == (undefined1 *)0x0) goto LAB_005f6acc;
          iVar1 = 0;
          if (0 < *(int *)(param_3 + 0x428)) {
            do {
              FUN_00549840(param_3,iVar1,local_8,local_1c,local_18,local_20,local_24);
              *puVar3 = local_1c[0];
              puVar3[1] = local_18[0];
              puVar3[2] = local_20[0];
              iVar1 = iVar1 + 1;
              puVar3 = puVar3 + 3;
            } while (iVar1 < *(int *)(param_3 + 0x428));
          }
          local_8 = local_8 + 1;
          local_14 = local_14 + 1;
          piVar2 = local_c;
        } while (local_8 < *(int *)(param_3 + 0x42c));
      }
      FUN_00684020(local_1cc,piVar2,*(undefined4 *)(param_3 + 0x42c));
      FUN_00683e90(local_1cc);
      FUN_006835a0(local_1cc);
      thunk_FUN_005956d0(local_10);
      iVar1 = 0;
      if (0 < *(int *)(param_3 + 0x42c)) {
        do {
          FUN_0056e1d0(*piVar2);
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar1 < *(int *)(param_3 + 0x42c));
        piVar2 = local_c;
      }
      FUN_0056e1d0(piVar2);
      return 0;
    }
  }
  else {
    piVar2 = local_c;
LAB_005f6acc:
    if (piVar2 != (int *)0x0) {
      local_8 = 0;
      if (0 < *(int *)(param_3 + 0x42c)) {
        piVar4 = piVar2;
        do {
          if (*piVar4 != 0) {
            FUN_0056e1d0(*piVar4);
          }
          local_8 = local_8 + 1;
          piVar4 = piVar4 + 1;
        } while (local_8 < *(int *)(param_3 + 0x42c));
      }
      FUN_0056e1d0(piVar2);
    }
  }
  if (local_10 != 0) {
    thunk_FUN_005956d0(local_10);
  }
  FUN_006835a0(local_1cc);
  return 0xffffffff;
}

