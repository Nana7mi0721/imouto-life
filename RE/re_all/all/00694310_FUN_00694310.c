
void FUN_00694310(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)(param_2 + 0x24) * *(int *)(param_2 + 0x1c);
  FUN_00694260(param_3,*(undefined4 *)(param_1 + 0x104),*(undefined4 *)(param_1 + 0x1c),iVar6 * 2);
  param_2 = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    param_4 = param_4 - (int)param_3;
    do {
      puVar5 = *(undefined1 **)(param_4 + (int)param_3);
      pbVar4 = (byte *)*param_3;
      uVar3 = 0;
      for (iVar7 = iVar6; iVar7 != 0; iVar7 = iVar7 + -1) {
        pbVar1 = pbVar4 + 1;
        bVar2 = *pbVar4;
        pbVar4 = pbVar4 + 2;
        *puVar5 = (char)((int)((uint)bVar2 + uVar3 + *pbVar1) >> 1);
        puVar5 = puVar5 + 1;
        uVar3 = uVar3 ^ 1;
      }
      param_2 = param_2 + 1;
      param_3 = param_3 + 1;
    } while (param_2 < *(int *)(param_1 + 0x104));
  }
  return;
}

