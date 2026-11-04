
void FUN_0067f930(short *param_1,undefined4 *param_2)

{
  byte bVar1;
  short *psVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_8;
  int local_4;
  
  iVar3 = (int)param_1;
  psVar2 = (short *)*param_2;
  iVar8 = -1;
  iVar7 = *(int *)param_2[2];
  local_4 = ((int *)param_2[2])[3];
  iVar5 = 0;
  local_8 = -1;
  *(undefined4 *)((int)param_1 + 0x1450) = 0;
  *(undefined4 *)((int)param_1 + 0x1454) = 0x23d;
  if (0 < local_4) {
    psVar6 = psVar2;
    do {
      if (*psVar6 == 0) {
        psVar6[1] = 0;
      }
      else {
        iVar8 = *(int *)((int)param_1 + 0x1450) + 1;
        *(int *)((int)param_1 + 0x1450) = iVar8;
        *(int *)((int)param_1 + 0xb5c + iVar8 * 4) = iVar5;
        *(undefined1 *)(iVar5 + 0x1458 + (int)param_1) = 0;
        iVar8 = iVar5;
        local_8 = iVar5;
      }
      iVar5 = iVar5 + 1;
      psVar6 = psVar6 + 2;
    } while (iVar5 < local_4);
  }
  iVar5 = *(int *)((int)param_1 + 0x1450);
  if (iVar5 < 2) {
    do {
      if (iVar8 < 2) {
        iVar9 = iVar8 + 1;
        iVar8 = iVar9;
      }
      else {
        iVar9 = 0;
      }
      *(int *)((int)param_1 + 0x1450) = iVar5 + 1;
      *(int *)((int)param_1 + 0xb5c + (iVar5 + 1) * 4) = iVar9;
      psVar2[iVar9 * 2] = 1;
      *(undefined1 *)((int)param_1 + 0x1458 + iVar9) = 0;
      *(int *)((int)param_1 + 0x16a8) = *(int *)((int)param_1 + 0x16a8) + -1;
      if (iVar7 != 0) {
        *(uint *)((int)param_1 + 0x16ac) =
             *(int *)((int)param_1 + 0x16ac) - (uint)*(ushort *)(iVar7 + 2 + iVar9 * 4);
      }
      iVar5 = *(int *)((int)param_1 + 0x1450);
    } while (iVar5 < 2);
    local_8 = iVar8;
  }
  param_2[1] = iVar8;
  for (iVar7 = *(int *)((int)param_1 + 0x1450) / 2; 0 < iVar7; iVar7 = iVar7 + -1) {
    FUN_0067fb70(param_1,psVar2,iVar7);
  }
  param_1 = psVar2 + local_4 * 2;
  do {
    iVar7 = *(int *)(iVar3 + 0xb60);
    *(undefined4 *)(iVar3 + 0xb60) = *(undefined4 *)(iVar3 + 0xb5c + *(int *)(iVar3 + 0x1450) * 4);
    *(int *)(iVar3 + 0x1450) = *(int *)(iVar3 + 0x1450) + -1;
    FUN_0067fb70(iVar3,psVar2,1);
    iVar8 = *(int *)(iVar3 + 0xb60);
    iVar5 = *(int *)(iVar3 + 0x1454) + -1;
    *(int *)(iVar3 + 0x1454) = iVar5;
    *(int *)(iVar3 + 0xb5c + iVar5 * 4) = iVar7;
    iVar5 = *(int *)(iVar3 + 0x1454) + -1;
    *(int *)(iVar3 + 0x1454) = iVar5;
    *(int *)(iVar3 + 0xb5c + iVar5 * 4) = iVar8;
    *param_1 = psVar2[iVar8 * 2] + psVar2[iVar7 * 2];
    bVar1 = *(byte *)(iVar3 + 0x1458 + iVar7);
    bVar4 = *(byte *)(iVar3 + 0x1458 + iVar8);
    if (bVar4 <= bVar1) {
      bVar4 = bVar1;
    }
    *(byte *)(iVar3 + 0x1458 + local_4) = bVar4 + 1;
    psVar2[iVar8 * 2 + 1] = (short)local_4;
    psVar2[iVar7 * 2 + 1] = (short)local_4;
    *(int *)(iVar3 + 0xb60) = local_4;
    local_4 = local_4 + 1;
    param_1 = param_1 + 2;
    FUN_0067fb70(iVar3,psVar2,1);
  } while (1 < *(int *)(iVar3 + 0x1450));
  iVar7 = *(int *)(iVar3 + 0x1454) + -1;
  *(int *)(iVar3 + 0x1454) = iVar7;
  *(undefined4 *)(iVar3 + 0xb5c + iVar7 * 4) = *(undefined4 *)(iVar3 + 0xb60);
  FUN_0067fc50(iVar3,param_2);
  FUN_0067fe80(psVar2,local_8,iVar3 + 0xb3c);
  return;
}

