
ulonglong FUN_006c1f50(int param_1,longlong *param_2,uint param_3,int param_4,int param_5,
                      undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint local_30;
  uint local_28;
  int local_24;
  undefined1 local_10 [16];
  
  iVar4 = param_4;
  uVar3 = 0xffffffffffffffff;
  lVar2 = -1;
  local_30 = 0x10000;
  iVar6 = param_4;
  uVar7 = param_3;
  uVar8 = param_3;
  do {
    local_28 = uVar8 - local_30;
    iVar5 = param_4 - ((int)local_30 >> 0x1f);
    local_24 = iVar5 - (uint)(uVar8 < local_30);
    if ((local_24 < 0) ||
       ((local_24 == 0 ||
         SBORROW4(param_4,(int)local_30 >> 0x1f) != SBORROW4(iVar5,(uint)(uVar8 < local_30)) &&
        (local_28 == 0)))) {
      local_28 = 0;
      local_24 = 0;
    }
    iVar5 = FUN_006c16b0(param_1,local_28,local_24);
    if (iVar5 < 0) {
      return (longlong)iVar5;
    }
    bVar1 = false;
    if ((iVar6 < *(int *)(param_1 + 0x34)) ||
       ((iVar6 <= *(int *)(param_1 + 0x34) && (uVar7 <= *(uint *)(param_1 + 0x30))))) {
LAB_006c20a9:
      if (local_28 == 0 && local_24 == 0) goto LAB_006c20b5;
    }
    else {
      while( true ) {
        uVar9 = FUN_006c03f0(param_1,local_10,uVar7,iVar6);
        if (((longlong)uVar9 < -0x100000000) || ((0x7fffffffffffffff < uVar9 && ((int)uVar9 != -1)))
           ) {
          return uVar9;
        }
        if (uVar9 == 0xffffffffffffffff) break;
        iVar5 = FUN_006a8360(local_10);
        if (iVar5 == param_5) {
          lVar10 = FUN_006a8280(local_10);
          if (lVar10 != -1) {
            lVar2 = lVar10;
            uVar3 = uVar9;
          }
        }
        else {
          iVar5 = FUN_006c08a0(iVar5,param_6,param_7);
          if (iVar5 == 0) {
            bVar1 = true;
          }
        }
        if ((iVar6 <= *(int *)(param_1 + 0x34)) &&
           ((iVar6 < *(int *)(param_1 + 0x34) || (uVar7 <= *(uint *)(param_1 + 0x30))))) break;
      }
      if (!bVar1) goto LAB_006c20a9;
LAB_006c20b5:
      if ((longlong)uVar3 < 0) {
        return 0xffffffffffffff77;
      }
    }
    param_4 = (int)(uVar3 >> 0x20);
    local_30 = local_30 * 2;
    if (0xfffff < (int)local_30) {
      local_30 = 0x100000;
    }
    iVar6 = local_24 + (uint)(0xffff00e5 < local_28);
    if ((iVar4 < iVar6) || ((iVar4 <= iVar6 && (param_3 <= local_28 + 0xff1a)))) {
      iVar6 = iVar4;
      uVar7 = param_3;
    }
    else {
      uVar7 = local_28 + 0xff1a;
    }
    if ((0 < param_4) || (-1 < (longlong)uVar3)) {
      *param_2 = lVar2;
      return uVar3;
    }
    uVar8 = local_28;
    param_4 = local_24;
  } while( true );
}

