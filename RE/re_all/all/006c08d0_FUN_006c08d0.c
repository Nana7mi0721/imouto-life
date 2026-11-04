
int FUN_006c08d0(int param_1,int param_2,undefined1 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  bool bVar9;
  bool bVar10;
  ulonglong uVar11;
  int local_444;
  int local_440;
  uint *local_43c;
  uint local_430;
  uint local_42c;
  uint local_428;
  uint local_424;
  uint local_420;
  int local_41c;
  uint local_414;
  int local_410;
  undefined1 local_40c [16];
  uint local_3fc [255];
  
  if (param_3 == (undefined1 *)0x0) {
    param_3 = local_40c;
  }
  iVar4 = 0;
  local_440 = 0;
  iVar7 = 0;
  iVar3 = *(int *)(param_1 + 0x1d8);
  uVar11 = FUN_006c03f0(param_1,param_3,*(undefined4 *)(param_1 + 0x38),
                        *(undefined4 *)(param_1 + 0x3c));
  do {
    if ((longlong)uVar11 < 0) {
      iVar3 = (int)uVar11;
      if (0x7fffffffffffffff < uVar11) {
        if ((longlong)uVar11 < -0x100000000) {
          return iVar3;
        }
        if (iVar3 != -1) {
          return iVar3;
        }
      }
      if (*(int *)(param_2 + 0x34) == 0) {
        *(undefined4 *)(param_2 + 0x18) = 0;
        *(undefined4 *)(param_2 + 0x20) = 0;
        *(undefined4 *)(param_2 + 0x1c) = 0;
        *(undefined4 *)(param_2 + 0x24) = 0;
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0xc);
        return 0;
      }
      return -0x8b;
    }
    do {
      iVar2 = FUN_006a8260(param_3);
      if (iVar2 != 0) {
        if (*(int *)(param_2 + 0x34) == 0) {
          *(undefined4 *)(param_2 + 0x20) = 0;
          *(undefined4 *)(param_2 + 0x18) = 0;
          *(undefined4 *)(param_2 + 0x24) = 0;
          *(undefined4 *)(param_2 + 0x1c) = 0;
          *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 8);
          *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0xc);
          return 1;
        }
        return -0x8b;
      }
      iVar2 = FUN_006a8360(param_3);
      if (iVar3 == iVar2) {
        FUN_006a89a0(param_1 + 0x88,param_3);
        uVar5 = *(uint *)(param_3 + 4);
        uVar6 = *(uint *)(param_1 + 0x78);
        *(uint *)(param_1 + 0x78) = uVar6 + uVar5;
        *(uint *)(param_1 + 0x7c) =
             *(int *)(param_1 + 0x7c) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar6,uVar5);
        do {
          iVar7 = FUN_006c0dc0(param_1,local_3fc);
        } while (iVar7 < 0);
        iVar4 = *(int *)(param_1 + 0x21d4);
        local_440 = iVar4;
      }
      if (0 < iVar4) {
        iVar3 = (iVar4 + 0xf) * 0x20;
        uVar5 = *(uint *)(iVar3 + param_1);
        uVar6 = *(uint *)(iVar3 + 4 + param_1);
        if ((uVar5 & uVar6) == 0xffffffff) {
          return -0x8b;
        }
        local_410 = *(int *)(local_440 * 0x20 + 0x1dc + param_1);
        local_428 = uVar5;
        local_424 = uVar6;
        if (local_410 == 0) {
          iVar3 = FUN_006bff30(&local_430,uVar5,uVar6,-iVar7);
          if (iVar3 < 0) {
            return -0x8b;
          }
        }
        else {
          iVar3 = FUN_006bff30(&local_430,uVar5,uVar6,-iVar7);
          if (iVar3 < 0) {
            local_430 = 0;
            local_42c = 0;
            iVar3 = FUN_006c0d50(uVar5,uVar6,*(undefined4 *)(param_2 + 0x34),0);
            if (iVar3 < 0) {
              return -0x8b;
            }
          }
        }
        local_414 = local_42c;
        local_444 = 0;
        if (local_440 < 1) goto LAB_006c0c19;
        local_43c = local_3fc;
        puVar8 = (uint *)(param_1 + 0x200);
        uVar6 = local_430;
        goto LAB_006c0b58;
      }
      uVar11 = FUN_006c03f0(param_1,param_3,*(undefined4 *)(param_1 + 0x38),
                            *(undefined4 *)(param_1 + 0x3c));
    } while (0xffffffff < (longlong)uVar11);
  } while( true );
LAB_006c0b58:
  do {
    if (local_410 == 0) {
LAB_006c0bc8:
      FUN_006bff30(puVar8,uVar6,local_414,*local_43c);
      local_414 = puVar8[1];
      uVar6 = *puVar8;
    }
    else {
      FUN_006c0c50(&local_420,uVar5,local_424,uVar6,local_414);
      uVar1 = *local_43c;
      iVar4 = (int)uVar1 >> 0x1f;
      bVar9 = uVar1 < local_420;
      local_420 = uVar1 - local_420;
      bVar10 = SBORROW4(iVar4,local_41c);
      iVar3 = iVar4 - local_41c;
      local_41c = iVar3 - (uint)bVar9;
      uVar5 = local_428;
      if ((local_41c < 0) ||
         ((local_41c == 0 || bVar10 != SBORROW4(iVar3,(uint)bVar9) && (local_420 == 0))))
      goto LAB_006c0bc8;
      if ((iVar4 < local_41c) || ((iVar4 <= local_41c && (uVar1 < local_420)))) break;
      *puVar8 = local_428;
      puVar8[1] = local_424;
      local_414 = local_424;
      puVar8[-1] = 1;
      uVar6 = local_428;
    }
    local_444 = local_444 + 1;
    puVar8 = puVar8 + 8;
    local_43c = local_43c + 1;
  } while (local_444 < local_440);
LAB_006c0c19:
  *(int *)(param_1 + 0x21d4) = local_444;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 0x34);
  *(uint *)(param_2 + 0x20) = local_430;
  *(uint *)(param_2 + 0x24) = local_42c;
  *(uint *)(param_1 + 0x68) = local_430;
  *(uint *)(param_1 + 0x6c) = local_42c;
  *(ulonglong *)(param_1 + 0x70) = uVar11;
  return 0;
}

