
void FUN_006bcd40(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  iVar9 = 0;
  local_c = 0;
  local_18 = param_3;
  iVar8 = param_5;
LAB_006bcd59:
  if (iVar8 < 5) {
    local_1c = iVar8;
    if (iVar8 < 1) {
      return;
    }
  }
  else {
    local_1c = 4;
  }
  param_5 = local_18;
  local_8 = (undefined4 *)(iVar9 * 0x40 + param_1);
  iVar10 = param_4;
  do {
    if (iVar10 < 5) {
      param_3 = iVar10;
      if (iVar10 < 1) break;
    }
    else {
      param_3 = 4;
    }
    puVar11 = local_8;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = 0xffffffff;
      puVar11 = puVar11 + 1;
    }
    if (0 < local_1c) {
      local_14 = &DAT_008322a4;
      iVar6 = param_5;
      local_10 = local_1c;
      do {
        iVar7 = 0;
        if (0 < param_3) {
          piVar4 = local_14;
          do {
            piVar1 = piVar4 + -1;
            iVar3 = *piVar4;
            iVar2 = iVar7 + iVar6;
            iVar7 = iVar7 + 1;
            piVar4 = piVar4 + 2;
            *(int *)(param_1 + (iVar3 + (*piVar1 + iVar9 * 4) * 4) * 4) = iVar2;
          } while (iVar7 < param_3);
          iVar9 = local_c;
        }
        iVar6 = iVar6 + param_4;
        local_14 = local_14 + 8;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
    }
    iVar6 = 0;
    do {
      iVar7 = FUN_006bceb0(local_8,iVar6);
      bVar5 = (byte)iVar6;
      iVar6 = iVar6 + 1;
      *(byte *)(iVar9 + param_2) =
           *(byte *)(iVar9 + param_2) | ((-1 < iVar7) << (bVar5 & 0x1f) & 0xfU) << 2;
    } while (iVar6 < 4);
    iVar10 = iVar10 + -4;
    param_5 = param_5 + 4;
    iVar9 = iVar9 + 1;
    local_8 = local_8 + 0x10;
    local_c = iVar9;
  } while( true );
  iVar8 = iVar8 + -4;
  local_18 = local_18 + param_4 * 4;
  goto LAB_006bcd59;
}

