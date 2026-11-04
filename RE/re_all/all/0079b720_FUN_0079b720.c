
void FUN_0079b720(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x90c) != *(int *)(param_1 + 0x1098)) {
    FUN_0079b6e0(param_1);
    *(undefined4 *)(param_1 + 0x1098) = *(undefined4 *)(param_1 + 0x90c);
  }
  if (param_4 != 0) {
    FUN_0079b950(param_1,param_2,param_3,param_5);
    *(int *)(param_1 + 0x1040) = *(int *)(param_1 + 0x1040) + 1;
    return;
  }
  pcVar1 = (char *)(param_1 + 0xacd);
  *(int *)(param_1 + 0x1044) = (int)*pcVar1;
  param_1 = 0;
  if (*pcVar1 == '\x02') {
    iVar6 = *(int *)(iVar3 + 0x914);
    iVar5 = 0;
    iVar8 = 0;
    if (0 < *(int *)(param_2 + -4 + iVar6 * 4)) {
      do {
        iVar8 = param_1;
        if (iVar5 == iVar6) break;
        iVar8 = 0;
        iVar9 = 5;
        psVar4 = (short *)(param_2 + 0x56 + (iVar6 - iVar5) * 10);
        do {
          iVar8 = iVar8 + *psVar4;
          psVar4 = psVar4 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (param_1 < iVar8) {
          puVar10 = (undefined4 *)
                    (param_2 + 0x60 + (short)((*(short *)(iVar3 + 0x914) - (short)iVar5) + -1) * 10)
          ;
          *(undefined4 *)(iVar3 + 0x104c) = *puVar10;
          *(undefined4 *)(iVar3 + 0x1050) = puVar10[1];
          *(undefined2 *)(iVar3 + 0x1054) = *(undefined2 *)(puVar10 + 2);
          *(int *)(iVar3 + 0x1048) =
               *(int *)(param_2 + -4 + (*(int *)(iVar3 + 0x914) - iVar5) * 4) << 8;
          param_1 = iVar8;
        }
        iVar5 = iVar5 + 1;
        iVar6 = *(int *)(iVar3 + 0x914);
        iVar8 = param_1;
      } while (*(int *)(iVar3 + 0x91c) * iVar5 < *(int *)(param_2 + -4 + iVar6 * 4));
    }
    psVar4 = (short *)(iVar3 + 0x104c);
    psVar4[0] = 0;
    psVar4[1] = 0;
    *(undefined4 *)(iVar3 + 0x1050) = 0;
    *(undefined2 *)(iVar3 + 0x1054) = 0;
    *(short *)(iVar3 + 0x1050) = (short)iVar8;
    if (iVar8 < 0x2ccd) {
      if (iVar8 < 2) {
        iVar8 = 1;
      }
      iVar6 = 5;
      do {
        *psVar4 = (short)((int)*psVar4 * (int)(short)(0xb33400 / (longlong)iVar8) >> 10);
        psVar4 = psVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else if (0x3ccd < iVar8) {
      if (iVar8 < 2) {
        iVar8 = 1;
      }
      iVar6 = 5;
      do {
        *psVar4 = (short)((int)*psVar4 * (int)(short)(0xf334000 / (longlong)iVar8) >> 0xe);
        psVar4 = psVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    *(int *)(iVar3 + 0x1048) = *(short *)(iVar3 + 0x90c) * 0x1200;
    *(undefined4 *)(iVar3 + 0x104c) = 0;
    *(undefined4 *)(iVar3 + 0x1050) = 0;
    *(undefined2 *)(iVar3 + 0x1054) = 0;
  }
  uVar2 = *(uint *)(iVar3 + 0x924);
  puVar10 = (undefined4 *)(param_2 + 0x40);
  puVar11 = (undefined4 *)(iVar3 + 0x1056);
  for (uVar7 = (uVar2 & 0x7fffffff) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  for (iVar6 = (uVar2 & 1) << 1; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
    puVar11 = (undefined4 *)((int)puVar11 + 1);
  }
  *(undefined2 *)(iVar3 + 0x108c) = *(undefined2 *)(param_2 + 0x88);
  *(undefined4 *)(iVar3 + 0x1090) = *(undefined4 *)(param_2 + 8 + *(int *)(iVar3 + 0x914) * 4);
  *(undefined4 *)(iVar3 + 0x1094) = *(undefined4 *)(param_2 + 0xc + *(int *)(iVar3 + 0x914) * 4);
  *(undefined4 *)(iVar3 + 0x10a0) = *(undefined4 *)(iVar3 + 0x91c);
  *(undefined4 *)(iVar3 + 0x109c) = *(undefined4 *)(iVar3 + 0x914);
  return;
}

