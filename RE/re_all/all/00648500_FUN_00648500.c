
void FUN_00648500(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,ushort *param_9)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  ushort *puVar6;
  
  uVar1 = *(ushort *)(param_1 + 0x1a);
  iVar3 = *(int *)(param_1 + 0x3c);
  if (param_6 != 0) {
    param_1 = param_6;
    do {
      puVar6 = param_9;
      if (param_5 != 0) {
        puVar6 = (ushort *)((int)param_9 + (uint)uVar1 * 2 * param_5);
        puVar4 = param_2;
        iVar5 = param_5;
        do {
          param_2 = puVar4 + 1;
          uVar2 = *param_9;
          param_9 = param_9 + uVar1;
          iVar5 = iVar5 + -1;
          *puVar4 = **(undefined4 **)(iVar3 + (uint)(uVar2 >> 8) * 4);
          puVar4 = param_2;
        } while (iVar5 != 0);
      }
      param_9 = (ushort *)((int)puVar6 + param_7);
      param_2 = param_2 + param_8;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

