
void FUN_00597e70(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00a37dc8 != 0) {
    iVar8 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    DAT_00e06944 = 0;
    if (DAT_00e804a0 != 0) {
      if (DAT_00e798a0 != 0) {
        iVar8 = DAT_00e79ca0;
      }
      if (DAT_00e798a4 != 0) {
        local_14 = DAT_00e79d08;
      }
      if (DAT_00e798a8 != 0) {
        local_10 = DAT_00e79d70;
      }
      if (DAT_00e798ac != 0) {
        local_c = DAT_00e79dd8;
      }
      DAT_00e06944 = (uint)(DAT_00e798ac != 0);
      if (DAT_00e798b0 != 0) {
        local_8 = DAT_00e79e40;
        DAT_00e06944 = 1;
      }
      if (DAT_00e798b4 != 0) {
        local_4 = DAT_00e79ea8;
        DAT_00e06944 = 1;
      }
    }
    bVar3 = 0;
    piVar4 = &DAT_00a380f8;
    do {
      if (0 < *piVar4) {
        bVar3 = 1;
        break;
      }
      piVar4 = piVar4 + 1;
    } while ((int)piVar4 < 0xa38104);
    uVar5 = (uint)bVar3;
    iVar1 = local_10 + (local_14 + iVar8 * 4) * 4;
    iVar2 = uVar5 + (uint)(DAT_00a3810c != 0) * 4;
    uVar6 = -(uint)(DAT_00e79874 != 0) & DAT_00e79878;
    DAT_00e06934 = ((int)(short)(&DAT_00e8b594)[iVar1] + (uVar6 + iVar2 * 0x18) * 0x14) * 2;
    if (iVar8 == 3) {
      uVar9 = 2;
    }
    else {
      uVar9 = (uint)(iVar8 != 0);
    }
    if (local_14 == 3) {
      local_1c = 2;
    }
    else {
      local_1c = (uint)(local_14 != 0);
    }
    if (local_10 == 3) {
      uVar7 = 2;
    }
    else {
      uVar7 = (uint)(local_10 != 0);
    }
    DAT_00e06938 = ((int)(short)(&DAT_00e8b614)[uVar7 + (local_1c + uVar9 * 3) * 3] + iVar2 * 0x2580
                   ) * 2;
    DAT_00e0693c = uVar6 + uVar5 * 0x18;
    DAT_00e06940 = ((int)(short)(&DAT_00e89594)[local_4 + (local_8 + (local_c + iVar1 * 4) * 4) * 4]
                   + uVar5 * 0x9d80) * 2;
  }
  return;
}

