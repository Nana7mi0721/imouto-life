
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0055eb30(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  float local_4c;
  int local_48;
  uint local_44;
  float local_40;
  undefined4 local_3c [15];
  
  iVar8 = 0;
  uVar7 = 0xffffffff;
  local_48 = 0;
  if ((((DAT_00cc50a0 != 0) && (-1 < (int)param_3)) && ((param_3 & 0x7c000000) == DAT_00cc50c8)) &&
     ((int)(param_3 & 0xffff) < DAT_00cc50d0)) {
    iVar8 = *(int *)(DAT_00cc50a4 + (param_3 & 0xffff) * 4);
  }
  local_44 = (uint)*(ushort *)(iVar8 + 0x36);
  uVar9 = *(undefined4 *)(iVar8 + 0x48);
  uVar1 = *(undefined4 *)(iVar8 + 0x38);
  uVar3 = FUN_0052eb20();
  uVar4 = FUN_0055d900(0,local_44,0x20,uVar1,uVar9,1,0xffffffff,uVar3);
  if ((int)uVar4 < 0) {
    uVar9 = 0xffffffff;
  }
  else {
    if (*(short *)(iVar8 + 0x34) == 3) {
      FUN_0055ad40(param_3,uVar4);
    }
    else {
      FUN_0055ae40(param_3);
    }
    if (param_2[3] != 0) {
      local_4c = (float)param_2[4];
      if (_DAT_007d103c < local_4c) {
        iVar8 = FUN_00552640(uVar4);
        local_40 = (float)iVar8 + (float)iVar8;
        local_44 = (uint)ROUND(local_40);
        uVar7 = FUN_0055daf0(uVar4,local_44);
        if ((int)uVar7 < 0) {
          uVar9 = 0xfffffffe;
          goto LAB_0055ee2d;
        }
        do {
          FUN_00552750(uVar4,uVar7);
          FUN_0055db50(uVar7,uVar4);
          local_4c = local_4c * (float)_DAT_00804a60;
        } while (_DAT_007d103c < local_4c);
        FUN_005525d0(uVar7);
      }
      iVar8 = FUN_00552640(uVar4);
      local_40 = (float)iVar8 * local_4c;
      local_44 = (uint)ROUND(local_40);
      uVar9 = FUN_0052eb20();
      uVar7 = FUN_0055d900(0,0,0,0,local_44,0,uVar4,uVar9);
      if ((int)uVar7 < 0) {
        uVar9 = 0xfffffffd;
        goto LAB_0055ee2d;
      }
      FUN_00552750(uVar4,uVar7);
      FUN_0055db50(uVar7,uVar4);
    }
    uVar5 = uVar4;
    if (param_2[5] != 0) {
      iVar8 = FUN_00552640(uVar4);
      local_40 = (float)iVar8 * (float)param_2[6];
      local_44 = (uint)ROUND(local_40);
      uVar9 = FUN_0052eb20();
      uVar5 = FUN_0055d900(0,0,0,0,local_44,0,uVar4,uVar9);
      if ((int)uVar5 < 0) {
        uVar9 = 0xfffffffc;
        uVar7 = uVar5;
        goto LAB_0055ee2d;
      }
      FUN_00552750(uVar4,uVar5);
      uVar7 = uVar4;
    }
    uVar4 = uVar5;
    if (((((DAT_00cc50a0 == 0) || ((int)uVar5 < 0)) ||
         (((uVar5 & 0x7c000000) != DAT_00cc50c8 ||
          ((DAT_00cc50d0 <= (int)(uVar5 & 0xffff) ||
           (piVar2 = *(int **)(DAT_00cc50a4 + (uVar5 & 0xffff) * 4), piVar2 == (int *)0x0)))))) ||
        (*piVar2 * 0x10000 != (uVar5 & 0x3ff0000))) || (piVar2[4] != 0)) {
      uVar9 = 0xfffffffb;
    }
    else {
      iVar6 = FUN_0055b9b0(&local_48,&local_40,piVar2 + 0xd,0x12,piVar2[0x13],
                           (uint)*(ushort *)(piVar2 + 0x10) * piVar2[0x12]);
      iVar8 = local_48;
      if (iVar6 < 0) {
        uVar9 = 0xfffffffa;
      }
      else {
        puVar10 = local_3c;
        for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *param_2;
          param_2 = param_2 + 1;
          puVar10 = puVar10 + 1;
        }
        local_3c[4] = 0x3f800000;
        local_3c[6] = 0x3f800000;
        local_3c[2] = 0;
        local_3c[3] = 0;
        local_3c[5] = 0;
        iVar6 = FUN_00562e30(local_3c,0,param_1,local_48,local_40,param_4,0xffffffff,0,param_5);
        if (-1 < iVar6) {
          FUN_0056e1d0(iVar8);
          FUN_005525d0(uVar5);
          FUN_005525d0(uVar7);
          return 0;
        }
        uVar9 = 0xfffffff9;
      }
      if (iVar8 != 0) {
        FUN_0056e1d0(iVar8);
      }
    }
  }
LAB_0055ee2d:
  if (-1 < (int)uVar4) {
    FUN_005525d0(uVar4);
  }
  if (-1 < (int)uVar7) {
    FUN_005525d0(uVar7);
  }
  return uVar9;
}

