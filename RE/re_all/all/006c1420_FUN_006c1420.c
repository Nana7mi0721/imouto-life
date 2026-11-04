
uint FUN_006c1420(int param_1,uint *param_2,uint param_3,uint param_4,uint param_5,
                 undefined4 param_6,undefined4 param_7)

{
  bool bVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  bool bVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  uint local_60;
  uint local_58;
  int local_54;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  undefined1 local_30 [16];
  uint local_20 [8];
  
  iVar6 = param_4;
  local_58 = param_3;
  local_54 = param_4;
  bVar1 = false;
  param_4 = 0xffffffff;
  local_60 = 0x10000;
  uVar3 = param_3;
  local_4c = iVar6;
  do {
    local_50 = uVar3 - local_60;
    bVar10 = SBORROW4(local_4c,(int)local_60 >> 0x1f);
    iVar5 = local_4c - ((int)local_60 >> 0x1f);
    local_4c = iVar5 - (uint)(uVar3 < local_60);
    if ((local_4c < 0) ||
       ((local_4c == 0 || bVar10 != SBORROW4(iVar5,(uint)(uVar3 < local_60)) && (local_50 == 0)))) {
      local_50 = 0;
      local_4c = 0;
    }
    uVar3 = FUN_006c16b0(param_1,local_50,local_4c);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (*(int *)(param_1 + 0x34) <= local_54) {
      lVar2 = CONCAT44(local_4c,local_50);
      if (local_54 <= *(int *)(param_1 + 0x34)) {
        lVar2 = CONCAT44(local_4c,local_50);
        if (local_58 <= *(uint *)(param_1 + 0x30)) goto LAB_006c15e0;
      }
      while( true ) {
        local_44 = (uint)((ulonglong)lVar2 >> 0x20);
        local_48 = (uint)lVar2;
        uVar11 = FUN_006c03f0(param_1,local_30,local_58,local_54);
        uVar7 = (uint)(uVar11 >> 0x20);
        uVar3 = (uint)uVar11;
        if (((longlong)uVar11 < -0x100000000) ||
           ((0x7fffffffffffffff < uVar11 && (uVar3 != 0xffffffff)))) {
          return uVar3;
        }
        if (uVar11 == 0xffffffffffffffff) break;
        uVar4 = FUN_006a8360(local_30);
        *param_2 = local_48;
        param_2[2] = uVar3;
        param_2[1] = local_44;
        param_2[3] = uVar7;
        param_2[5] = uVar4;
        param_2[4] = *(int *)(param_1 + 0x30) - uVar3;
        uVar12 = FUN_006a8280(local_30);
        *(undefined8 *)(param_2 + 6) = uVar12;
        if (uVar4 == param_5) {
          bVar1 = true;
          puVar8 = param_2;
          puVar9 = local_20;
          for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
        }
        iVar5 = FUN_006c08a0(uVar4,param_6,param_7);
        if (iVar5 == 0) {
          bVar1 = false;
        }
        lVar2 = uVar11 + 1;
        param_4 = uVar7;
        if ((local_54 <= *(int *)(param_1 + 0x34)) &&
           ((local_54 < *(int *)(param_1 + 0x34) || (local_58 <= *(uint *)(param_1 + 0x30)))))
        break;
      }
    }
LAB_006c15e0:
    if ((local_50 == 0 && local_4c == 0) && ((int)param_4 < 0)) {
      return 0xffffff77;
    }
    local_60 = local_60 * 2;
    if (0xfffff < (int)local_60) {
      local_60 = 0x100000;
    }
    local_58 = local_50 + 0xff1a;
    local_54 = local_4c + (uint)(0xffff00e5 < local_50);
    if ((iVar6 < local_54) || ((iVar6 <= local_54 && (param_3 <= local_58)))) {
      local_54 = iVar6;
      local_58 = param_3;
    }
    if ((0 < (int)param_4) || (-1 < (int)param_4)) {
      if (bVar1) {
        puVar8 = local_20;
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *param_2 = *puVar8;
          puVar8 = puVar8 + 1;
          param_2 = param_2 + 1;
        }
      }
      return 0;
    }
    uVar3 = local_50;
  } while( true );
}

