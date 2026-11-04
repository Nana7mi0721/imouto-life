
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006b70d0(int *param_1,int param_2,int *param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  int *piVar7;
  int iVar8;
  double local_20;
  double local_10;
  
  iVar8 = *param_1;
  local_20 = _DAT_007d0a60;
  iVar1 = param_1[param_2 * 0xe + -0xd];
  local_10 = 0.0;
  dVar3 = _DAT_007d0a60;
  dVar6 = _DAT_007d0a60;
  dVar5 = _DAT_007d0a60;
  if (0 < param_2) {
    piVar7 = param_1 + 8;
    do {
      iVar2 = piVar7[-1];
      param_2 = param_2 + -1;
      dVar4 = ((double)(piVar7[5] + iVar2) * (double)*(float *)(param_5 + 0x454)) /
              (double)(iVar2 + 1) + _DAT_00802e18;
      dVar3 = (double)piVar7[-6] * dVar4 + (double)*piVar7 + dVar3;
      dVar5 = (double)piVar7[-5] * dVar4 + (double)piVar7[1] + dVar5;
      dVar6 = (double)piVar7[-4] * dVar4 + (double)piVar7[2] + dVar6;
      local_20 = (double)piVar7[-2] * dVar4 + (double)piVar7[4] + local_20;
      local_10 = (double)iVar2 * dVar4 + (double)piVar7[5] + local_10;
      piVar7 = piVar7 + 0xe;
    } while (param_2 != 0);
  }
  iVar2 = *param_3;
  if (-1 < iVar2) {
    dVar3 = (double)iVar8 + dVar3;
    dVar5 = (double)iVar2 + dVar5;
    dVar6 = (double)(iVar8 * iVar8) + dVar6;
    local_20 = (double)(iVar2 * iVar8) + local_20;
    local_10 = local_10 + _DAT_00802e18;
  }
  iVar2 = *param_4;
  if (-1 < iVar2) {
    dVar3 = (double)iVar1 + dVar3;
    dVar5 = (double)iVar2 + dVar5;
    dVar6 = (double)(iVar1 * iVar1) + dVar6;
    local_20 = (double)(iVar2 * iVar1) + local_20;
    local_10 = local_10 + _DAT_00802e18;
  }
  dVar4 = local_10 * dVar6 - dVar3 * dVar3;
  if (dVar4 <= _DAT_007d0a60) {
    *param_3 = 0;
    *param_4 = 0;
    return 1;
  }
  dVar6 = (dVar6 * dVar5 - local_20 * dVar3) / dVar4;
  dVar4 = (local_10 * local_20 - dVar5 * dVar3) / dVar4;
  FUN_006c5af0((double)iVar8 * dVar4 + dVar6 + _DAT_00804a60);
  iVar8 = __ftol();
  *param_3 = iVar8;
  FUN_006c5af0((double)iVar1 * dVar4 + dVar6 + _DAT_00804a60);
  iVar8 = __ftol();
  *param_4 = iVar8;
  if (0x3ff < *param_3) {
    *param_3 = 0x3ff;
  }
  if (0x3ff < *param_4) {
    *param_4 = 0x3ff;
  }
  if (*param_3 < 0) {
    *param_3 = 0;
  }
  if (*param_4 < 0) {
    *param_4 = 0;
  }
  return 0;
}

