
undefined4 FUN_0058ed00(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005dba90(param_1);
    return 0;
  }
  iVar2 = FUN_00586970(param_1,1);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  pbVar3 = *(byte **)(param_1 + 0x48c);
  puVar4 = *(undefined1 **)(param_1 + 0xd0c);
  iVar2 = *(int *)(param_1 + 0x488);
  iVar5 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  iVar6 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(param_1 + 0xd08);
  iVar7 = iVar6;
  while( true ) {
    do {
      *puVar4 = (char)((uint)pbVar3[3] * (uint)*pbVar3 >> 8);
      puVar4[1] = (char)((uint)pbVar3[1] * (uint)pbVar3[3] >> 8);
      puVar4[2] = (char)((uint)pbVar3[3] * (uint)pbVar3[2] >> 8);
      puVar4[3] = pbVar3[3];
      pbVar3 = pbVar3 + 4;
      puVar4 = puVar4 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    pbVar3 = pbVar3 + iVar2 + iVar6 * -4;
    puVar4 = puVar4 + iVar1 + iVar6 * -4;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) break;
    iVar7 = iVar6;
  }
  FUN_00586b00();
  return 0;
}

