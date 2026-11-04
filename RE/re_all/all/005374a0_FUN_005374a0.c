
undefined4 __thiscall FUN_005374a0(uint *param_1,int param_2,short *param_3,int *param_4)

{
  short sVar1;
  bool bVar2;
  int in_EAX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint *local_20;
  int local_1c;
  uint *local_18;
  uint *local_14;
  int local_c;
  uint local_4;
  
  local_18 = (uint *)0x0;
  local_14 = (uint *)0x0;
  bVar2 = false;
  if (in_EAX < 0) {
    local_1c = 0;
    sVar1 = *param_3;
    while (sVar1 != 0) {
      local_1c = local_1c + 1;
      sVar1 = param_3[local_1c];
    }
  }
  else {
    local_1c = in_EAX;
  }
  if (0x400 < local_1c) {
    bVar2 = true;
    local_14 = (uint *)FUN_0056e030(local_1c * 8,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp"
                                    ,0x7db);
    local_18 = local_14 + local_1c;
    if (local_14 == (uint *)0x0) {
      return 0xffffffff;
    }
  }
  iVar9 = 0;
  local_c = 0;
  if (param_1 == (uint *)0x0) {
    if (bVar2) {
      param_1 = local_14;
      goto LAB_0053752d;
    }
    param_1 = (uint *)&DAT_00a4def8;
  }
  else {
LAB_0053752d:
    if (bVar2) {
      local_20 = local_14;
      goto LAB_0053755e;
    }
  }
  local_20 = &DAT_00a4cef8;
  local_18 = &DAT_00a4bef8;
LAB_0053755e:
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar6 = 0;
  if (0 < local_1c) {
    do {
      uVar3 = FUN_0052ed00(param_3,DAT_00aba250,&local_4);
      iVar6 = (local_4 >> 1) + iVar6;
      *param_1 = uVar3;
      if (local_1c < iVar6) break;
      local_c = local_c + 1;
      param_3 = param_3 + (local_4 >> 1);
      iVar5 = *(int *)(param_2 + 0x90d98);
      iVar4 = 0;
      if (0 < iVar5) {
        puVar7 = (uint *)(param_2 + 0x90d9c);
        do {
          if (*puVar7 == uVar3) break;
          iVar4 = iVar4 + 1;
          puVar7 = puVar7 + 8;
        } while (iVar4 < iVar5);
      }
      if ((iVar4 == iVar5) && (iVar9 != *(int *)(param_2 + 0x90d88))) {
        if (uVar3 < 0x10000) {
          if (*(int *)(param_2 + 0xfd80 + uVar3 * 8) == 0) {
            *(undefined4 *)(param_2 + 0xfd80 + uVar3 * 8) = 1;
            uVar3 = *param_1;
LAB_00537668:
            local_18[iVar9] = uVar3;
            iVar9 = iVar9 + 1;
            *local_20 = *param_1;
            local_20 = local_20 + 1;
          }
        }
        else {
          iVar5 = 0;
          if (0 < iVar9) {
            do {
              if (local_18[iVar5] == uVar3) break;
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar9);
          }
          if (iVar5 == iVar9) {
            iVar5 = *(int *)(param_2 + 0x8fd80);
            iVar4 = 0;
            if (0 < iVar5) {
              puVar8 = (undefined4 *)(param_2 + 0x8fd84);
              do {
                if (*(uint *)*puVar8 == uVar3) break;
                iVar4 = iVar4 + 1;
                puVar8 = puVar8 + 1;
              } while (iVar4 < iVar5);
            }
            if (iVar4 == iVar5) goto LAB_00537668;
          }
        }
      }
      param_1 = param_1 + 1;
    } while (iVar6 < local_1c);
  }
  iVar6 = 0;
  if (0 < iVar9) {
    do {
      if (local_18[iVar6] < 0x10000) {
        *(undefined4 *)(param_2 + 0xfd80 + local_18[iVar6] * 8) = 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar9);
  }
  if (iVar9 != 0) {
    puVar7 = local_14;
    if (!bVar2) {
      puVar7 = &DAT_00a4cef8;
    }
    FUN_00536310(iVar9,puVar7,param_2,1);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = local_c;
  }
  if (bVar2) {
    FUN_0056e1d0(local_14);
  }
  return 0;
}

