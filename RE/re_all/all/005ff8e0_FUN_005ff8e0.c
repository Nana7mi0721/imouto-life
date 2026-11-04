
/* WARNING: Removing unreachable block (ram,0x005ffb08) */

longlong FUN_005ff8e0(int param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6,
                     uint param_7,uint param_8)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint extraout_EDX;
  uint uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  undefined8 uVar16;
  int local_30;
  int local_2c;
  int local_24;
  uint local_20;
  uint local_18;
  int local_14;
  uint local_10;
  
  if (param_2 < 0) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    local_24 = -(param_2 + (uint)bVar12);
  }
  else {
    local_24 = param_2;
  }
  if (param_4 < 0) {
    local_30 = -param_3;
    local_2c = -(param_4 + (uint)(param_3 != 0));
  }
  else {
    local_30 = param_3;
    local_2c = param_4;
  }
  if ((int)param_6 < 0) {
    param_3 = -param_5;
    uVar3 = -(param_6 + (param_5 != 0));
  }
  else {
    param_3 = param_5;
    uVar3 = param_6;
  }
  if ((param_2 < 1) && (param_2 < 0)) {
    bVar1 = 1;
  }
  else {
    bVar1 = 0;
  }
  if ((param_4 < 1) && (param_4 < 0)) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  bVar12 = (bool)(bVar2 ^ bVar1);
  uVar13 = __allmul(param_1,0,local_30,0);
  local_10 = (uint)uVar13;
  lVar14 = __allmul(local_2c,0,param_1,0);
  lVar15 = __allmul(local_24,0,local_30,0);
  uVar13 = lVar14 + lVar15 + (uVar13 >> 0x20);
  uVar8 = (uint)uVar13;
  lVar14 = __allmul(local_2c,0,local_24,0);
  uVar13 = lVar14 + (uVar13 >> 0x20);
  if (param_7 == 0 && param_8 == 0) goto LAB_005ffadd;
  if (bVar12) {
    local_20 = -param_7;
    uVar4 = -(param_8 + (param_7 != 0));
    if (-1 < (int)param_8) {
      bVar10 = 0 < (int)param_8;
      param_8 = uVar4;
      if (bVar10) goto LAB_005ffa57;
      if (param_7 != 0) {
        local_18 = 0xffffffff;
        local_14 = -1;
        goto LAB_005ffa6c;
      }
    }
LAB_005ffa64:
    local_18 = 0;
    local_14 = 0;
    param_8 = uVar4;
  }
  else {
    local_20 = param_7;
    uVar4 = param_8;
    if ((0 < (int)param_8) || (-1 < (int)param_8)) goto LAB_005ffa64;
LAB_005ffa57:
    local_18 = 0xffffffff;
    local_14 = -1;
  }
LAB_005ffa6c:
  bVar10 = CARRY4(local_10,local_20);
  local_10 = local_10 + local_20;
  bVar11 = CARRY4(param_8,uVar8);
  param_8 = param_8 + uVar8;
  uVar8 = bVar10 + param_8;
  uVar4 = (uint)bVar11 + (uint)CARRY4((uint)bVar10,param_8);
  lVar14 = CONCAT44(local_14 + (uint)CARRY4(uVar4,local_18),uVar4 + local_18);
  lVar15 = uVar13 + lVar14;
  uVar13 = uVar13 + lVar14;
  if (lVar15 < 0) {
    bVar12 = !bVar12;
    uVar4 = ~local_10;
    local_10 = uVar4 + 1;
    uVar8 = ~uVar8 + (uint)(0xfffffffe < uVar4);
    uVar4 = (uint)(local_10 == 0 && uVar8 == 0);
    uVar13 = CONCAT44(~(uint)((ulonglong)lVar15 >> 0x20) + (uint)CARRY4(~(uint)lVar15,uVar4),
                      ~(uint)lVar15 + uVar4);
  }
LAB_005ffadd:
  if (((int)param_6 < 1) && ((int)param_6 < 0)) {
    bVar12 = !bVar12;
  }
  if (CONCAT44(uVar3,param_3) <= uVar13) {
    if (!bVar12) {
      return 0x7fffffffffffffff;
    }
    return -0x8000000000000000;
  }
  if (uVar13 == 0) {
    lVar14 = __aulldiv(local_10,uVar8,param_3,uVar3);
    if (bVar12) {
      return CONCAT44(-((int)((ulonglong)lVar14 >> 0x20) + (uint)((int)lVar14 != 0)),-(int)lVar14);
    }
  }
  else {
    if (uVar3 == 0) {
      iVar5 = __aulldiv(uVar8,(int)uVar13,param_3,0);
      uVar6 = __aullrem(uVar8,(int)uVar13,param_3,0);
      uVar16 = __aulldiv(local_10,uVar6,param_3,0);
      iVar9 = (int)uVar16;
      iVar5 = iVar5 + (int)((ulonglong)uVar16 >> 0x20);
      if (bVar12) {
        bVar12 = iVar9 != 0;
        iVar9 = -iVar9;
        iVar5 = -(iVar5 + (uint)bVar12);
      }
      return CONCAT44(iVar5,iVar9);
    }
    param_5 = 0x40;
    do {
      lVar14 = __allshl();
      uVar16 = __allshl();
      uVar7 = (uint)((ulonglong)uVar16 >> 0x20);
      uVar4 = (uint)uVar16;
      if ((uVar8 & 0x80000000) != 0) {
        uVar4 = uVar4 + 1;
      }
      __allshl();
      if ((uVar3 <= uVar7) && ((uVar3 < uVar7 || (param_3 <= uVar4)))) {
        lVar14 = lVar14 + 1;
      }
      param_7 = (uint)lVar14;
      param_5 = param_5 + -1;
      uVar8 = extraout_EDX;
    } while (param_5 != 0);
    if (bVar12) {
      lVar14 = CONCAT44(-((int)((ulonglong)lVar14 >> 0x20) + (uint)(param_7 != 0)),-param_7);
    }
  }
  return lVar14;
}

