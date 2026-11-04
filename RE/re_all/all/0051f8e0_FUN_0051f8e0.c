
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0051f8e0(int param_1,int param_2,double param_3,double param_4,uint param_5,undefined4 param_6,
            undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  undefined4 local_c4;
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
  
  if (DAT_00a37fd0 != 0) {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if ((((DAT_00cc47d0 == 0) || ((int)param_5 < 0)) || ((param_5 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_5 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_5 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  uVar9 = 0;
  local_c4 = 0;
  local_bc = piVar1;
  if (0 < (int)DAT_00a380d4) {
    if (((-1 < (int)DAT_00a380d4) && ((DAT_00a380d4 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a380d4 & 0xffff) < DAT_00cc4800)) {
      local_c4 = *(undefined4 *)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4);
    }
    uVar9 = local_c4;
    iVar7 = FUN_00514e90();
    if (iVar7 != 0) {
      return 0xffffffff;
    }
  }
  if (piVar1[0xd] != -1) {
    FUN_0057b670(piVar1[0xd],0);
  }
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  uVar11 = SUB84(param_4,0);
  uVar12 = (undefined4)((ulonglong)param_4 >> 0x20);
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(char *)(piVar1[0x13] + 8) != '\0')) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
    if (DAT_00ca39f4 == 0) {
      if (*(char *)(piVar1[0x13] + 8) == '\0') {
        uVar9 = FUN_00515360();
        return uVar9;
      }
      uVar9 = FUN_00568e20(param_1,param_2,(float)param_1,(float)param_2,param_3,uVar11,uVar12,
                           piVar1,uVar9,param_6,param_7,param_8,1);
      return uVar9;
    }
  }
  local_98 = (double)param_1;
  local_90 = (double)param_2;
  local_c0 = (float)param_4;
  FUN_0056d4d0(local_c0,&local_c0,local_84);
  dVar2 = (double)local_c0;
  dVar4 = (double)local_84[0];
  iVar10 = piVar1[0x18] / 2;
  iVar8 = -iVar10;
  iVar7 = piVar1[0x19] / 2;
  iVar10 = piVar1[0x18] - iVar10;
  dVar3 = (double)-iVar7;
  local_70 = (double)iVar8;
  local_50 = (double)(piVar1[0x19] - iVar7);
  local_68 = (double)iVar10;
  local_a8 = ((double)iVar8 * dVar4 - dVar3 * dVar2) * param_3 + local_98;
  local_a0 = (dVar3 * dVar4 + (double)iVar8 * dVar2) * param_3 + local_90;
  dVar5 = ((double)iVar10 * dVar4 - dVar3 * dVar2) * param_3 + local_98;
  dVar3 = (dVar3 * dVar4 + (double)iVar10 * dVar2) * param_3 + local_90;
  local_b8 = local_a8;
  if (dVar5 < local_a8) {
    local_b8 = dVar5;
  }
  if (local_a8 < dVar5) {
    local_a8 = dVar5;
  }
  local_b0 = local_a0;
  if (dVar3 < local_a0) {
    local_b0 = dVar3;
  }
  if (local_a0 < dVar3) {
    local_a0 = dVar3;
  }
  dVar3 = (local_70 * dVar4 - local_50 * dVar2) * param_3 + local_98;
  dVar5 = (local_50 * dVar4 + local_70 * dVar2) * param_3 + local_90;
  if (dVar3 < local_b8) {
    local_b8 = dVar3;
  }
  if (local_a8 < dVar3) {
    local_a8 = dVar3;
  }
  if (dVar5 < local_b0) {
    local_b0 = dVar5;
  }
  if (local_a0 < dVar5) {
    local_a0 = dVar5;
  }
  dVar3 = (local_68 * dVar4 - local_50 * dVar2) * param_3 + local_98;
  dVar2 = (local_50 * dVar4 + local_68 * dVar2) * param_3 + local_90;
  if (dVar3 < local_b8) {
    local_b8 = dVar3;
  }
  if (local_a8 < dVar3) {
    local_a8 = dVar3;
  }
  if (dVar2 < local_b0) {
    local_b0 = dVar2;
  }
  if (local_a0 < dVar2) {
    local_a0 = dVar2;
  }
  local_b8 = local_b8 - _DAT_007d5558;
  local_b0 = local_b0 - _DAT_007d5558;
  local_a8 = local_a8 + _DAT_007d5558;
  local_a0 = _DAT_007d5558 + local_a0;
  local_48 = local_50;
  FUN_0056d610(&local_b8,&local_d4);
  if (-1 < (int)((local_c8 - DAT_00a381a0) - 1U & (DAT_00a38198 - local_d0) - 1U &
                 (DAT_00a38194 - local_d4) - 1U & (local_cc - DAT_00a3819c) - 1U)) {
    if (local_d4 < DAT_00a38194) {
      local_d4 = DAT_00a38194;
    }
    if (local_cc < DAT_00a38194) {
      local_cc = DAT_00a38194;
    }
    if (DAT_00a3819c < local_d4) {
      local_d4 = DAT_00a3819c;
    }
    if (DAT_00a3819c < local_cc) {
      local_cc = DAT_00a3819c;
    }
    if (local_d0 < DAT_00a38198) {
      local_d0 = DAT_00a38198;
    }
    if (local_c8 < DAT_00a38198) {
      local_c8 = DAT_00a38198;
    }
    if (DAT_00a381a0 < local_d0) {
      local_d0 = DAT_00a381a0;
    }
    if (DAT_00a381a0 < local_c8) {
      local_c8 = DAT_00a381a0;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170();
  }
  if (bVar6) {
    FUN_00519580();
    uVar9 = FUN_00568e20(param_1,param_2,(float)param_1,(float)param_2,param_3,uVar11,uVar12,
                         local_bc,local_c4,param_6,param_7,param_8,1);
    FUN_00519650();
  }
  else if (*(char *)(local_bc[0x13] + 8) == '\0') {
    uVar9 = FUN_00515360();
  }
  else {
    uVar9 = FUN_00568e20(param_1,param_2,(float)param_1,(float)param_2,param_3,uVar11,uVar12,
                         local_bc,local_c4,param_6,param_7,param_8,1);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10();
  }
  return uVar9;
}

