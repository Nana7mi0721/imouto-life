
void FUN_0079e890(int param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  short local_40 [16];
  short local_20 [16];
  
  FUN_0079fcd0(param_2 + 4,param_1 + 0xab0,param_1 + 0x908,param_3 == 2,
               *(undefined4 *)(param_1 + 0x914));
  FUN_0079fae0(local_40,param_1 + 0xab8,*(undefined4 *)(param_1 + 0xaac));
  FUN_0079f570(param_2 + 0x10,local_40,*(undefined4 *)(param_1 + 0x924));
  if (*(int *)(param_1 + 0x948) == 1) {
    *(undefined1 *)(param_1 + 0xacf) = 4;
  }
  cVar1 = *(char *)(param_1 + 0xacf);
  if (cVar1 < '\x04') {
    iVar6 = *(int *)(param_1 + 0x924);
    iVar4 = 0;
    if (0 < iVar6) {
      psVar7 = (short *)(param_1 + 0x928);
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
        local_20[iVar4] = (short)(((int)local_40[iVar4] - (int)sVar2) * (int)cVar1 >> 2) + sVar2;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar6);
    }
    FUN_0079f570(param_2 + 8,local_20,iVar6);
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x924);
    puVar9 = param_2 + 0x10;
    puVar10 = param_2 + 8;
    for (uVar5 = (uVar8 & 0x7fffffff) >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar6 = (uVar8 & 1) << 1; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
  }
  uVar8 = *(uint *)(param_1 + 0x924);
  psVar7 = local_40;
  puVar9 = (undefined4 *)(param_1 + 0x928);
  for (uVar5 = (uVar8 & 0x7fffffff) >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar9 = *(undefined4 *)psVar7;
    psVar7 = psVar7 + 2;
    puVar9 = puVar9 + 1;
  }
  for (iVar6 = (uVar8 & 1) << 1; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(char *)puVar9 = (char)*psVar7;
    psVar7 = (short *)((int)psVar7 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  }
  if (*(int *)(param_1 + 0x1040) != 0) {
    FUN_0079f430(param_2 + 8,*(undefined4 *)(param_1 + 0x924),0xf852);
    FUN_0079f430(param_2 + 0x10,*(undefined4 *)(param_1 + 0x924),0xf852);
  }
  if (*(char *)(param_1 + 0xacd) != '\x02') {
    puVar9 = param_2;
    for (uVar8 = *(uint *)(param_1 + 0x914) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    uVar5 = *(int *)(param_1 + 0x914) * 10;
    puVar9 = param_2 + 0x18;
    for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    *(undefined1 *)(param_1 + 0xad0) = 0;
    param_2[0x22] = 0;
    return;
  }
  FUN_0079fa20(CONCAT22((short)((uint)*(undefined4 *)(param_1 + 0x914) >> 0x10),
                        *(undefined2 *)(param_1 + 0xaca)),*(undefined1 *)(param_1 + 0xacc),param_2,
               *(undefined4 *)(param_1 + 0x90c),*(undefined4 *)(param_1 + 0x914));
  iVar6 = 0;
  puVar3 = (&PTR_DAT_00837ffc)[*(char *)(param_1 + 0xad0)];
  if (0 < *(int *)(param_1 + 0x914)) {
    psVar7 = (short *)(param_2 + 0x18);
    do {
      cVar1 = *(char *)(iVar6 + 0xab4 + param_1);
      iVar4 = 0;
      do {
        *psVar7 = (short)(char)puVar3[iVar4 + cVar1 * 5] << 7;
        iVar4 = iVar4 + 1;
        psVar7 = psVar7 + 1;
      } while (iVar4 < 5);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x914));
  }
  param_2[0x22] = (int)*(short *)(&DAT_008377dc + *(char *)(param_1 + 0xad1) * 2);
  return;
}

