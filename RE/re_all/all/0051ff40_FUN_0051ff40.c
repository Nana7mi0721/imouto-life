
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0051ff40(float param_1,float param_2,double param_3,double param_4,uint param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 local_e4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  float local_c0;
  int *local_bc;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  float local_84 [5];
  double local_70;
  double local_68;
  double local_50;
  double local_48;
  
  iVar1 = (int)ROUND(param_1);
  iVar2 = (int)ROUND(param_2);
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_5 < 0)) || ((param_5 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_5 & 0xffff) ||
       (piVar3 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar3 == (int *)0x0)) ||
      ((*piVar3 * 0x10000 != (param_5 & 0x3ff0000) || (piVar3[4] != 0)))))) {
    return 0xffffffff;
  }
  local_e4 = 0;
  local_bc = piVar3;
  if (0 < (int)DAT_00a380d4) {
    if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
      local_e4 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
    }
    iVar9 = FUN_00514e90();
    if (iVar9 != 0) {
      return 0xffffffff;
    }
  }
  if (piVar3[0xd] != -1) {
    FUN_0057b670(piVar3[0xd],0);
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  uVar10 = SUB84(param_4,0);
  uVar13 = (undefined4)((ulonglong)param_4 >> 0x20);
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar3[0x13] + 8) != '\0')) {
    bVar8 = true;
  }
  else {
    bVar8 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar3[0x13] + 8) == '\0') {
        uVar10 = FUN_00515360();
        return uVar10;
      }
      uVar10 = FUN_00568e20(iVar1,iVar2,param_1,param_2,param_3,uVar10,uVar13,piVar3,local_e4,
                            param_6,param_7,param_8,0);
      return uVar10;
    }
  }
  local_98 = (double)iVar1;
  local_90 = (double)iVar2;
  local_c0 = (float)param_4;
  FUN_0056d4d0(local_c0,&local_c0,local_84);
  dVar4 = (double)local_c0;
  dVar6 = (double)local_84[0];
  iVar12 = piVar3[0x18] / 2;
  iVar11 = -iVar12;
  iVar9 = piVar3[0x19] / 2;
  iVar12 = piVar3[0x18] - iVar12;
  dVar5 = (double)-iVar9;
  local_70 = (double)iVar11;
  local_50 = (double)(piVar3[0x19] - iVar9);
  local_68 = (double)iVar12;
  local_a8 = ((double)iVar11 * dVar6 - dVar5 * dVar4) * param_3 + local_98;
  local_a0 = (dVar5 * dVar6 + (double)iVar11 * dVar4) * param_3 + local_90;
  dVar7 = ((double)iVar12 * dVar6 - dVar5 * dVar4) * param_3 + local_98;
  dVar5 = (dVar5 * dVar6 + (double)iVar12 * dVar4) * param_3 + local_90;
  local_b8 = local_a8;
  if (dVar7 < local_a8) {
    local_b8 = dVar7;
  }
  if (local_a8 < dVar7) {
    local_a8 = dVar7;
  }
  local_b0 = local_a0;
  if (dVar5 < local_a0) {
    local_b0 = dVar5;
  }
  if (local_a0 < dVar5) {
    local_a0 = dVar5;
  }
  dVar5 = (local_70 * dVar6 - local_50 * dVar4) * param_3 + local_98;
  dVar7 = (local_50 * dVar6 + local_70 * dVar4) * param_3 + local_90;
  if (dVar5 < local_b8) {
    local_b8 = dVar5;
  }
  if (local_a8 < dVar5) {
    local_a8 = dVar5;
  }
  if (dVar7 < local_b0) {
    local_b0 = dVar7;
  }
  if (local_a0 < dVar7) {
    local_a0 = dVar7;
  }
  dVar5 = (local_68 * dVar6 - local_50 * dVar4) * param_3 + local_98;
  dVar4 = (local_50 * dVar6 + local_68 * dVar4) * param_3 + local_90;
  if (dVar5 < local_b8) {
    local_b8 = dVar5;
  }
  if (local_a8 < dVar5) {
    local_a8 = dVar5;
  }
  if (dVar4 < local_b0) {
    local_b0 = dVar4;
  }
  if (local_a0 < dVar4) {
    local_a0 = dVar4;
  }
  local_b8 = local_b8 - _DAT_007d5558;
  local_b0 = local_b0 - _DAT_007d5558;
  local_a8 = local_a8 + _DAT_007d5558;
  local_a0 = _DAT_007d5558 + local_a0;
  local_48 = local_50;
  FUN_0056d610(&local_b8,&local_d0);
  if (-1 < (int)((local_c4 - DAT_00a381a0) - 1U & (DAT_00a38198 - local_cc) - 1U &
                 (DAT_00a38194 - local_d0) - 1U & (local_c8 - DAT_00a3819c) - 1U)) {
    if (local_d0 < DAT_00a38194) {
      local_d0 = DAT_00a38194;
    }
    if (local_c8 < DAT_00a38194) {
      local_c8 = DAT_00a38194;
    }
    if (DAT_00a3819c < local_d0) {
      local_d0 = DAT_00a3819c;
    }
    if (DAT_00a3819c < local_c8) {
      local_c8 = DAT_00a3819c;
    }
    if (local_cc < DAT_00a38198) {
      local_cc = DAT_00a38198;
    }
    if (local_c4 < DAT_00a38198) {
      local_c4 = DAT_00a38198;
    }
    if (DAT_00a381a0 < local_cc) {
      local_cc = DAT_00a381a0;
    }
    if (DAT_00a381a0 < local_c4) {
      local_c4 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170();
  }
  if (bVar8) {
    FUN_00519580();
    uVar10 = FUN_00568e20(iVar1,iVar2,param_1,param_2,param_3,uVar10,uVar13,local_bc,local_e4,
                          param_6,param_7,param_8,0);
    FUN_00519650();
  }
  else if (*(char *)(local_bc[0x13] + 8) == '\0') {
    uVar10 = FUN_00515360();
  }
  else {
    uVar10 = FUN_00568e20(iVar1,iVar2,param_1,param_2,param_3,uVar10,uVar13,local_bc,local_e4,
                          param_6,param_7,param_8,0);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10();
  }
  return uVar10;
}

