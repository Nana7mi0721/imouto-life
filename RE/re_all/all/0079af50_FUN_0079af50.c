
void FUN_0079af50(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  short *psVar9;
  int local_b0;
  int local_ac;
  int local_a8;
  uint local_a0 [20];
  int aiStack_50 [20];
  
  iVar3 = FUN_007a2170(param_1,&DAT_00837b8c + (param_3 >> 1) * 9,8);
  local_b0 = param_5 >> 4;
  if (local_b0 * 0x10 < param_5) {
    local_b0 = local_b0 + 1;
  }
  iVar7 = 0;
  if (0 < local_b0) {
    do {
      aiStack_50[iVar7] = 0;
      uVar4 = FUN_007a2170(param_1,&DAT_00837a34 + iVar3 * 0x12,8);
      local_a0[iVar7] = uVar4;
      while (uVar4 == 0x11) {
        iVar1 = aiStack_50[iVar7];
        aiStack_50[iVar7] = iVar1 + 1;
        uVar4 = FUN_007a2170(param_1,&DAT_00837ad6 + (iVar1 + 1 == 10),8);
        local_a0[iVar7] = uVar4;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < local_b0);
  }
  iVar3 = 0;
  if (0 < local_b0) {
    puVar5 = local_a0;
    do {
      if ((int)*puVar5 < 1) {
        puVar8 = (undefined4 *)((short)iVar3 * 0x20 + param_2);
        for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
      }
      else {
        FUN_0079eba0((short)iVar3 * 0x20 + param_2,param_1,*puVar5);
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar3 < local_b0);
  }
  local_ac = 0;
  if (0 < local_b0) {
    do {
      iVar3 = aiStack_50[local_ac];
      if (0 < iVar3) {
        local_a8 = 0x10;
        psVar9 = (short *)((short)local_ac * 0x20 + param_2);
        do {
          sVar6 = *psVar9;
          if (0 < iVar3) {
            iVar7 = iVar3;
            do {
              sVar2 = FUN_007a2170(param_1,&DAT_008377bc,8);
              iVar7 = iVar7 + -1;
              sVar6 = sVar2 + sVar6 * 2;
            } while (iVar7 != 0);
          }
          *psVar9 = sVar6;
          psVar9 = psVar9 + 1;
          local_a8 = local_a8 + -1;
        } while (local_a8 != 0);
        local_a0[local_ac] = local_a0[local_ac] | iVar3 << 5;
      }
      local_ac = local_ac + 1;
    } while (local_ac < local_b0);
  }
  FUN_0079eae0(param_1,param_2,param_5,param_3,param_4,local_a0);
  return;
}

