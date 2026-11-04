
int FUN_00578f50(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                ,int param_8,int param_9,int param_10,int param_11,uint param_12,int param_13,
                int param_14,uint param_15,undefined4 param_16)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  undefined8 uVar10;
  uint local_430;
  undefined1 *local_42c;
  int local_428;
  undefined1 *local_424;
  undefined1 local_420 [1056];
  
  uVar1 = param_15;
  uVar7 = param_12;
  iVar8 = 0;
  local_424 = (undefined1 *)0x0;
  if (((int)param_12 < 0) || (param_12 < 0x400)) {
    local_42c = local_420;
  }
  else {
    local_424 = (undefined1 *)
                FUN_0056e030(param_12 + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",
                             0x1670);
    if (local_424 == (undefined1 *)0x0) {
      uVar7 = 0x400;
      param_12 = 0x400;
      local_42c = local_420;
    }
    else {
      local_42c = local_424;
    }
  }
  uVar3 = FUN_00573310(0,param_16,param_14,uVar1);
  uVar10 = CONCAT44(param_2,param_1);
  if (uVar3 == 0) goto LAB_005797a4;
  if (param_11 < 0) {
    param_11 = 0;
  }
  bVar9 = -1 < (int)uVar7;
  if (!bVar9) {
    uVar7 = 1;
    param_12 = 1;
  }
  if (param_5 == 10) {
    iVar6 = param_4;
  }
  else {
    iVar6 = 0;
  }
  if ((param_8 != 0) || (bVar9)) {
    param_7 = 0;
  }
  if (iVar6 == 0) {
    param_3 = 0;
LAB_00579062:
    param_9 = 0;
    param_10 = 0;
  }
  else {
    param_6 = 0;
    if (param_9 != 0) {
      param_10 = 0;
    }
    if (param_3 != 0) goto LAB_00579062;
  }
  local_430 = 0;
  if (param_1 == 0 && param_2 == 0) {
    if (uVar7 != 0) goto LAB_00579157;
    local_430 = 1;
    *local_42c = 0x30;
LAB_005790a4:
    local_428 = 0;
  }
  else {
    if ((param_2 != 0) || (param_1 != 0)) {
      iVar6 = param_13 * 0x10;
      do {
        do {
          _param_1 = uVar10;
          iVar5 = FUN_005f6f50(&param_1,param_5);
          local_42c[local_430] = s__Vf<q10123456789abcdef0123456789_0085e41a[iVar6 + iVar5 + 6];
          local_430 = local_430 + 1;
          uVar10 = __aulldiv(_param_1,param_5,0);
          param_1 = (int)uVar10;
        } while ((int)((ulonglong)uVar10 >> 0x20) != 0);
        param_2 = 0;
      } while (param_1 != 0);
    }
LAB_00579157:
    if (param_12 <= local_430) goto LAB_005790a4;
    local_428 = param_12 - local_430;
  }
  iVar6 = 0;
  if (param_6 != 0) {
    if (param_5 == 8) {
      iVar6 = 1;
    }
    else if (param_5 == 0x10) {
      iVar6 = 2;
    }
  }
  if (((param_10 == 0) && (param_9 == 0)) && (param_3 == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  param_11 = param_11 - (iVar5 + iVar6 + local_428 + local_430);
  if (param_8 == 0) {
    iVar6 = iVar8;
    if (param_7 == 0) {
      if ((0 < param_11) &&
         (iVar6 = FUN_00577c20(param_11,param_11 >> 0x1f,0x20,param_14,uVar1,param_16),
         iVar8 = iVar6, uVar1 - iVar6 <= uVar3)) goto LAB_005797a4;
      if (param_3 == 0) {
        if ((param_9 != 0) || (param_10 != 0)) {
          cVar2 = (-(param_9 != 0) & 0xbU) + 0x20;
          goto LAB_0057961b;
        }
      }
      else {
        cVar2 = '-';
LAB_0057961b:
        iVar5 = FUN_00573310(cVar2,param_16,iVar6 + param_14,uVar1 - iVar6);
        iVar8 = iVar6;
        if (((iVar5 == 0) || (uVar1 - iVar6 < iVar5 + uVar3)) ||
           (iVar6 = iVar6 + iVar5, iVar8 = iVar6, uVar1 - iVar6 <= uVar3)) goto LAB_005797a4;
      }
      if (param_6 != 0) {
        uVar7 = uVar1 - iVar6;
        iVar5 = FUN_00573310(0x30,param_16,iVar6 + param_14,uVar7);
        if (param_5 != 8) {
          iVar8 = iVar6;
          if ((iVar5 == 0) || (uVar7 < iVar5 + uVar3)) goto LAB_005797a4;
          iVar6 = iVar6 + iVar5;
          uVar7 = uVar1 - iVar6;
          iVar8 = iVar6;
          if (uVar7 <= uVar3) goto LAB_005797a4;
          iVar5 = FUN_00573310((-(uint)(param_13 != 0) & 0xffffffe0) + 0x78,param_16,
                               iVar6 + param_14,uVar7);
        }
        iVar8 = iVar6;
        if ((iVar5 == 0) || (uVar7 < iVar5 + uVar3)) goto LAB_005797a4;
        iVar6 = iVar6 + iVar5;
        goto LAB_00579710;
      }
    }
    else {
      if (param_3 == 0) {
        if ((param_9 != 0) || (param_10 != 0)) {
          cVar2 = (-(param_9 != 0) & 0xbU) + 0x20;
          goto LAB_00579428;
        }
      }
      else {
        cVar2 = '-';
LAB_00579428:
        iVar6 = FUN_00573310(cVar2,param_16,param_14,uVar1);
        if (((iVar6 == 0) || (uVar1 < iVar6 + uVar3)) || (iVar8 = iVar6, uVar1 - iVar6 <= uVar3))
        goto LAB_005797a4;
      }
      if (param_6 != 0) {
        uVar7 = uVar1 - iVar6;
        iVar8 = iVar6;
        if (param_5 == 8) {
          iVar5 = FUN_00573310(0x30,param_16,iVar6 + param_14,uVar7);
          if ((iVar5 == 0) || (uVar7 < iVar5 + uVar3)) goto LAB_005797a4;
          iVar6 = iVar6 + iVar5;
        }
        else {
          iVar5 = FUN_00573310(0x30,param_16,iVar6 + param_14,uVar7);
          if ((iVar5 == 0) || (uVar7 < iVar5 + uVar3)) goto LAB_005797a4;
          iVar8 = iVar6 + iVar5;
          uVar7 = uVar1 - iVar8;
          if ((uVar7 <= uVar3) ||
             ((iVar6 = FUN_00573310((-(uint)(param_13 != 0) & 0xffffffe0) + 0x78,param_16,
                                    iVar8 + param_14,uVar7), iVar6 == 0 || (uVar7 < iVar6 + uVar3)))
             ) goto LAB_005797a4;
          iVar6 = iVar8 + iVar6;
        }
        iVar8 = iVar6;
        if (uVar1 - iVar6 <= uVar3) goto LAB_005797a4;
      }
      if (0 < param_11) {
        iVar8 = FUN_00577c20(param_11,param_11 >> 0x1f,0x30,iVar6 + param_14,uVar1 - iVar6,param_16)
        ;
        iVar6 = iVar6 + iVar8;
LAB_00579710:
        iVar8 = iVar6;
        if (uVar1 - iVar6 <= uVar3) goto LAB_005797a4;
      }
    }
    if (local_428 != 0) {
      iVar8 = FUN_00577c20(local_428,0,0x30,iVar6 + param_14,uVar1 - iVar6,param_16);
      iVar6 = iVar6 + iVar8;
      iVar8 = iVar6;
      if (uVar1 - iVar6 <= uVar3) goto LAB_005797a4;
    }
    iVar5 = local_430 - 1;
    iVar8 = iVar6;
    if (-1 < iVar5) {
      uVar7 = uVar1 - iVar6;
      while ((iVar4 = FUN_00573310(local_42c[iVar5],param_16,iVar6 + param_14,uVar7), iVar8 = iVar6,
             iVar4 != 0 && (iVar4 + uVar3 <= uVar7))) {
        iVar6 = iVar6 + iVar4;
        uVar7 = uVar1 - iVar6;
        iVar8 = iVar6;
        if ((uVar7 <= uVar3) || (iVar5 = iVar5 + -1, iVar5 < 0)) break;
      }
    }
    goto LAB_005797a4;
  }
  if (param_3 == 0) {
    if ((param_9 != 0) || (iVar6 = iVar8, param_10 != 0)) {
      cVar2 = (-(param_9 != 0) & 0xbU) + 0x20;
      goto LAB_005791db;
    }
  }
  else {
    cVar2 = '-';
LAB_005791db:
    iVar6 = FUN_00573310(cVar2,param_16,param_14,uVar1);
    if (((iVar6 == 0) || (uVar1 < iVar6 + uVar3)) || (iVar8 = iVar6, uVar1 - iVar6 <= uVar3))
    goto LAB_005797a4;
  }
  if (param_6 != 0) {
    uVar7 = uVar1 - iVar6;
    iVar8 = iVar6;
    if (param_5 == 8) {
      iVar5 = FUN_00573310(0x30,param_16,iVar6 + param_14,uVar7);
      if ((iVar5 == 0) || (uVar7 < iVar5 + uVar3)) goto LAB_005797a4;
      iVar6 = iVar6 + iVar5;
    }
    else {
      iVar5 = FUN_00573310(0x30,param_16,iVar6 + param_14,uVar7);
      if ((iVar5 == 0) || (uVar7 < iVar5 + uVar3)) goto LAB_005797a4;
      iVar8 = iVar6 + iVar5;
      uVar7 = uVar1 - iVar8;
      if ((uVar7 <= uVar3) ||
         ((iVar6 = FUN_00573310((-(uint)(param_13 != 0) & 0xffffffe0) + 0x78,param_16,
                                iVar8 + param_14,uVar7), iVar6 == 0 || (uVar7 < iVar6 + uVar3))))
      goto LAB_005797a4;
      iVar6 = iVar8 + iVar6;
    }
    iVar8 = iVar6;
    if (uVar1 - iVar6 <= uVar3) goto LAB_005797a4;
  }
  if (local_428 != 0) {
    iVar8 = FUN_00577c20(local_428,0,0x30,iVar6 + param_14,uVar1 - iVar6,param_16);
    iVar6 = iVar6 + iVar8;
    iVar8 = iVar6;
    if (uVar1 - iVar6 <= uVar3) goto LAB_005797a4;
  }
  iVar5 = local_430 - 1;
  if (-1 < iVar5) {
    uVar7 = uVar1 - iVar6;
    do {
      iVar4 = FUN_00573310(local_42c[iVar5],param_16,iVar6 + param_14,uVar7);
      iVar8 = iVar6;
      if ((iVar4 == 0) || (uVar7 < iVar4 + uVar3)) goto LAB_005797a4;
      iVar6 = iVar6 + iVar4;
      uVar7 = uVar1 - iVar6;
      iVar8 = iVar6;
      if (uVar7 <= uVar3) goto LAB_005797a4;
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  iVar8 = iVar6;
  if (0 < param_11) {
    iVar8 = FUN_00577c20(param_11,param_11 >> 0x1f,0x20,iVar6 + param_14,uVar1 - iVar6,param_16);
    iVar8 = iVar6 + iVar8;
  }
LAB_005797a4:
  if (local_424 != (undefined1 *)0x0) {
    FUN_0056e1d0(local_424);
  }
  return iVar8;
}

